/**
 * @file expedia_backend.h
 * @brief Core backend orchestrator for Expedia system
 *
 * This class integrates:
 * - Flight providers (via IFlighsManager)
 * - Hotel providers (via IHotelsManager)
 * - Payment gateway (via IPayment)
 *
 * It performs:
 * - Search aggregation
 * - Payment processing
 * - Reservation confirmation with rollback
 */

#ifndef EXPEDIA_BACKEND_H_
#define EXPEDIA_BACKEND_H_

#include "expedia_payments_api.h"
#include "expedia_payment_card.h"
#include "expedia_flights_api.h"
#include "expedia_utils.h"
#include "expedia_user.h"
#include "expedia_hotels_api.h"
#include "expedia_flights.h"
#include "expedia_hotels.h"
#include "expedia_reservations.h"

using namespace std;

/**
 * @class ExpediaBackend
 * @brief Central system that coordinates flights, hotels, and payments.
 *
 * Uses factories to instantiate providers. Aggregates results and handles
 * reservation lifecycle (charge → confirm → rollback on failure).
 */
class ExpediaBackend
{
private:
    vector<IFlighsManager *> flights_managers; ///< All registered flight providers
    IPayment *payment_helper;                  ///< Current payment processor
    vector<IHotelsManager *> hotels_managers;  ///< All registered hotel providers

public:
    // Prevent copying – singleton-like ownership
    ExpediaBackend(const ExpediaBackend &) = delete;
    void operator=(const ExpediaBackend &) = delete;

    /**
     * @brief Constructor – initializes all managers via factories.
     */
    ExpediaBackend()
    {
        flights_managers = FlightsFactory::GetManagers();
        payment_helper = PaymentFactory::GetPaymentHelper();
        hotels_managers = HotelsFactory::GetManagers();
    }

    /**
     * @brief Searches all flight providers for matching flights.
     * @param requestrequest User flight criteria
     * @return Combined list of flights from all providers
     */
    vector<Flight> FindFlights(const FlightRequest &request) const
    {
        vector<Flight> flights;

        for (IFlighsManager *manager : flights_managers)
        {
            manager->SetFlightRequest(request);
            vector<Flight> more_flights = manager->SearchFlights();
            flights.insert(flights.end(), more_flights.begin(), more_flights.end());
        }
        return flights;
    }

    /**
     * @brief Searches all hotel providers for available rooms.
     * @param request User hotel criteria
     * @return Combined list of rooms
     */
    vector<HotelRoom> FindHotels(const HotelRequest &request) const
    {
        vector<HotelRoom> rooms;

        for (IHotelsManager *manager : hotels_managers)
        {
            manager->SetHotelRequest(request);
            vector<HotelRoom> more_rooms = manager->SearchHotelRooms();
            rooms.insert(rooms.end(), more_rooms.begin(), more_rooms.end());
        }
        return rooms;
    }

    /**
     * @brief Charges user via current payment helper.
     * @param cost Total amount to charge
     * @param payment_card Card to use
     * @return true if payment succeeded
     *
     * Configures payment helper based on card type (credit/debit).
     */
    bool ChargeCost(double cost, PaymentCard &payment_card) const
    {
        CreditCard *creditCard = nullptr;
        DebitCard *debitCard = nullptr;

        // Configure payment helper based on card type
        if ((creditCard = dynamic_cast<CreditCard *>(&payment_card)))
        {
            payment_helper->SetUserInfo(payment_card.GetOwnerName(), "");
        }
        else if ((debitCard = dynamic_cast<DebitCard *>(&payment_card)))
        {
            payment_helper->SetUserInfo(payment_card.GetOwnerName(), debitCard->GetBillingAddress());
        }

        payment_helper->SetCardInfo(
            payment_card.GetCardNumber(),
            payment_card.GetExpiryDate(),
            payment_card.GetSecurityCode());

        return payment_helper->MakePayment(cost);
    }

    /**
     * @brief Refunds the charged amount (mock implementation).
     * @return Always true in mock
     */
    bool UnchargeCost(double cost, PaymentCard &payment_card) const
    {
        return true;
    }

    /**
     * @brief Cancels a confirmed reservation (mock).
     * @return Always true
     */
    bool CancelReservation(const Reservation &reservation)
    {
        return true;
    }

    /**
     * @brief Confirms a reservation with rollback on failure.
     * @param reservation Reservation to confirm
     * @return true if all sub-reservations confirmed
     *
     * For Itinerary: confirms each part; rolls back on any failure.
     */
    bool ConfirmReservation(const Reservation &reservation)
    {
        Reservation *reservationCpy = reservation.Clone();

        // Handle Flight Reservation
        if (auto flight = dynamic_cast<FlightReservation *>(reservationCpy))
        {
            string name = flight->GetFlight().GetAirlineName();
            IFlighsManager *mgr = FlightsFactory::GetManager(name);

            if (mgr && mgr->ReserveFlight(*flight))
            {
                delete reservationCpy;
                return true;
            }
            delete reservationCpy;
            return false;
        }

        // Handle Hotel Reservation
        if (auto hotel = dynamic_cast<HotelReservation *>(reservationCpy))
        {
            string name = hotel->GetRoom().GetHotelName();
            IHotelsManager *mgr = HotelsFactory::GetManager(name);

            if (mgr && mgr->ReserveRoom(*hotel))
            {
                delete reservationCpy;
                return true;
            }
            delete reservationCpy;
            return false;
        }

        // Handle Itinerary (multiple reservations)
        if (auto itinerary = dynamic_cast<ItineraryReservation *>(reservationCpy))
        {
            vector<Reservation *> confirmed;

            for (Reservation *sub : itinerary->GetReservations())
            {
                if (ConfirmReservation(*sub))
                {
                    confirmed.push_back(sub);
                }
                else
                {
                    // Rollback all confirmed
                    for (Reservation *conf : confirmed)
                        CancelReservation(*conf);
                    delete reservationCpy;
                    return false;
                }
            }
            delete reservationCpy;
            return true;
        }

        delete reservationCpy;
        assert(false);
        return false;
    }
};

#endif /* EXPEDIA_BACKEND_H_ */