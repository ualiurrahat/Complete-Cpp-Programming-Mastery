/**
 * @file expedia_common_reservation.h
 */

#ifndef EXPEDIA_COMMON_RESERVATION_H_
#define EXPEDIA_COMMON_RESERVATION_H_

#include <sstream>
#include <cassert>

using namespace std;

/**
 * @class Reservation
 * @brief Abstract base for all reservation types.
 */
class Reservation
{
public:
    virtual ~Reservation() = default;
    virtual Reservation *Clone() const = 0;
    virtual double TotalCost() const = 0;
    virtual string ToString() const = 0;
};

/**
 * @class ItineraryReservation
 * @brief Composite pattern: group of reservations.
 */
class ItineraryReservation : public Reservation
{
protected:
    vector<Reservation *> reservations;

public:
    ItineraryReservation() = default;

    // Deep copy
    ItineraryReservation(const ItineraryReservation &other)
    {
        for (const Reservation *res : other.reservations)
            AddReservation(*res);
    }

    void AddReservation(const Reservation &reservation)
    {
        reservations.push_back(reservation.Clone());
    }

    virtual double TotalCost() const override
    {
        double cost = 0;
        for (const Reservation *res : reservations)
            cost += res->TotalCost();
        return cost;
    }

    ~ItineraryReservation() { Clear(); }

    const vector<Reservation *> &GetReservations() const { return reservations; }

    void Clear()
    {
        for (Reservation *res : reservations)
            delete res;
        reservations.clear();
    }

    virtual string ToString() const override
    {
        ostringstream oss;
        oss << "**********************************************\n";
        oss << "Itinerary with " << reservations.size() << " reservations\n";
        for (const Reservation *res : reservations)
            oss << res->ToString() << "\n";
        oss << "Total Cost: " << TotalCost() << "\n";
        oss << "**********************************************\n";
        return oss.str();
    }

    virtual Reservation *Clone() const override
    {
        return new ItineraryReservation(*this);
    }
};

/**
 * @class ReservationsSet
 * @brief Semantic wrapper for customer's reservations.
 */
class ReservationsSet : public ItineraryReservation
{
public:
    using ItineraryReservation::ItineraryReservation;
    virtual Reservation *Clone() const override
    {
        return new ReservationsSet(*this);
    }
};

#endif /* EXPEDIA_COMMON_RESERVATION_H_ */