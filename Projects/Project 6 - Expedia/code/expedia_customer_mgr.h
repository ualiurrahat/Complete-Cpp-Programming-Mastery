/**
 * @file expedia_customer_mgr.h
 * @brief Customer-facing operations (search, book, view)

 */

#ifndef EXPEDIA_CUSTOMER_MGR_H_
#define EXPEDIA_CUSTOMER_MGR_H_

#include "expedia_backend.h"
#include "expedia_payment_card.h"
#include "expedia_common_reservation.h"
#include "expedia_customer.h"

using namespace std;

/**
 * @class CustomerManager
 * @brief Bridges Customer object with ExpediaBackend.
 *
 * Provides high-level operations:
 * - Search flights/hotels
 * - Make reservations with payment
 * - List itineraries
 */
class CustomerManager
{
private:
    Customer *customer;              ///< Current logged-in customer
    ExpediaBackend &expedia_manager; ///< Backend reference

public:
    /**
     * @brief Constructor with validation.
     * @param user Must be Customer*
     * @throws assert if null or wrong type
     */
    CustomerManager(User *user, ExpediaBackend &expedia_manager)
        : customer(dynamic_cast<Customer *>(user)), expedia_manager(expedia_manager)
    {

        if (!customer)
        {
            cout << "Error: User is null or not Customer\n";
            assert(false);
        }
    }

    /** @brief Delegates flight search to backend */
    vector<Flight> FindFlights(const FlightRequest &request) const
    {
        return expedia_manager.FindFlights(request);
    }

    /** @brief Delegates hotel search to backend */
    vector<HotelRoom> FindHotels(const HotelRequest &request) const
    {
        return expedia_manager.FindHotels(request);
    }

    /** @brief Returns string representations of user's cards */
    vector<string> GetPaymentChoices() const
    {
        vector<string> cards_info;
        for (PaymentCard *card : customer->GetCards())
            cards_info.push_back(card->ToString());
        return cards_info;
    }

    /**
     * @brief Attempts to book a reservation.
     * @param reservation What to book
     * @param payment_card Card to use
     * @return true if fully confirmed
     *
     * Flow: Charge → Confirm → Add to customer (on success)
     *       On failure: Uncharge + rollback
     */
    bool MakeReservation(const Reservation &reservation, PaymentCard &payment_card)
    {
        bool is_paid = expedia_manager.ChargeCost(reservation.TotalCost(), payment_card);

        if (is_paid)
        {
            cout << "Money withdrawn successfully\n";

            bool is_confirmed = expedia_manager.ConfirmReservation(reservation);

            if (is_confirmed)
            {
                cout << "Reservation confirmed\n";
                customer->AddReservation(reservation);
                return true;
            }
            else
            {
                cout << "Failed to confirm reservation\n";
                cout << "Canceling payment...\n";
                expedia_manager.UnchargeCost(reservation.TotalCost(), payment_card);
            }
        }
        else
        {
            cout << "Failed to withdraw money\n";
        }
        return false;
    }

    /** @brief Gets all itineraries as strings */
    vector<string> GetItineraries() const
    {
        vector<string> itineraries;
        for (const Reservation *res : customer->GetReservations().GetReservations())
            itineraries.push_back(res->ToString());
        return itineraries;
    }

    /** @brief Access to customer object */
    const Customer *GetCustomer() const { return customer; }
};

#endif /* EXPEDIA_CUSTOMER_MGR_H_ */