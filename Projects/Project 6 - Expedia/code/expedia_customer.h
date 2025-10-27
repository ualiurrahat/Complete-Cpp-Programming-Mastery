/**
 * @file expedia_customer.h
 * @brief Customer user with cards and reservations
 */

#ifndef EXPEDIA_CUSTOMER_H_
#define EXPEDIA_CUSTOMER_H_

#include "expedia_payment_card.h"
#include "expedia_common_reservation.h"
#include "expedia_user.h"

using namespace std;

/**
 * @class Customer
 * @brief User with payment cards and reservation history.
 */
class Customer : public User
{
protected:
    vector<PaymentCard *> cards;
    ReservationsSet reservations;

public:
    Customer(const Customer &) = delete;
    void operator=(const Customer &) = delete;

    Customer() { SetType(UserType::CustomerUser); }

    ~Customer()
    {
        for (PaymentCard *card : cards)
            delete card;
        cards.clear();
    }

    void AddPaymentCard(const PaymentCard &card)
    {
        cards.push_back(card.Clone());
    }

    void AddReservation(const Reservation &reservation)
    {
        reservations.AddReservation(*reservation.Clone());
    }

    const vector<PaymentCard *> &GetCards() const { return cards; }
    const ReservationsSet &GetReservations() const { return reservations; }
};

#endif /* EXPEDIA_CUSTOMER_H_ */