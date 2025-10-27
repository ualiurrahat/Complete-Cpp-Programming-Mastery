/**
 * @file expedia_flights_api.h
 * @brief Mock flight provider APIs (Air Canada & Turkish Airlines)
 *
 * This header defines **dummy** flight-search and reservation APIs for two
 * airlines.  They are used by the Expedia system to fetch available flights
 * and attempt reservations.  No real network calls are performed.
 */

#ifndef EXPEDIA_FLIGHTS_API_H_
#define EXPEDIA_FLIGHTS_API_H_

#include <string>
#include <vector>

using namespace std;

/**
 * @class AirCanadaCustomerInfo
 * @brief Placeholder for customer information required by Air Canada.
 *
 * Currently empty – the real API would contain name, passport, etc.
 */
class AirCanadaCustomerInfo
{
};

/**
 * @struct AirCanadaFlight
 * @brief Represents a single flight result from Air Canada.
 */
class AirCanadaFlight
{
public:
    double price;          ///< Ticket price in USD
    string date_time_from; ///< Departure date-time (format: DD-MM-YYYY)
    string date_time_to;   ///< Arrival date-time (format: DD-MM-YYYY)
};

/**
 * @class AirCanadaOnlineAPI
 * @brief Mock API for Air Canada flight operations.
 */
class AirCanadaOnlineAPI
{
public:
    /**
     * @brief Searches for available flights.
     * @param from          Departure city/airport
     * @param from_date     Departure date (DD-MM-YYYY)
     * @param to            Arrival city/airport
     * @param to_date       Arrival date (DD-MM-YYYY)
     * @param adults        Number of adult passengers
     * @param children      Number of child passengers
     * @return Vector of matching flights (hard-coded dummy data)
     */
    static vector<AirCanadaFlight> GetFlights(
        const string &from, const string &from_date,
        const string &to, const string &to_date,
        int adults, int children)
    {

        vector<AirCanadaFlight> flights;

        // Dummy data – in a real system this would call an external service
        flights.push_back({200.0, "25-01-2022", "10-02-2022"});
        flights.push_back({250.0, "29-01-2022", "10-02-2022"});

        return flights;
    }

    /**
     * @brief Attempts to reserve a selected flight.
     * @param flight Selected flight details
     * @param info   Customer information
     * @return true if reservation succeeded (always true in mock)
     */
    static bool ReserveFlight(const AirCanadaFlight &flight,
                              const AirCanadaCustomerInfo &info)
    {
        // In mock implementation, reservation always succeeds
        return true;
    }
};

/**
 * @struct TurkishFlight
 * @brief Represents a single flight result from Turkish Airlines.
 */
class TurkishFlight
{
public:
    double cost;          ///< Ticket cost in USD
    string datetime_from; ///< Departure date-time
    string datetime_to;   ///< Arrival date-time
};

/**
 * @class TurkishCustomerInfo
 * @brief Placeholder for customer data required by Turkish Airlines.
 */
class TurkishCustomerInfo
{
};

/**
 * @class TurkishAirlinesOnlineAPI
 * @brief Mock API for Turkish Airlines flight operations.
 */
class TurkishAirlinesOnlineAPI
{
public:
    /**
     * @brief Configures the search parameters (from/to + dates).
     * @param datetime_from Departure date-time
     * @param from          Origin
     * @param datetime_to   Arrival date-time
     * @param to            Destination
     *
     * In a real API this would store the query for GetAvailableFlights().
     */
    void SetFromToInfo(const string &datetime_from, const string &from,
                       const string &datetime_to, const string &to)
    {
        // No-op in mock version
    }

    /**
     * @brief Sets passenger counts for the search.
     * @param infants  Number of infants
     * @param children Number of children
     * @param adults   Number of adults
     */
    void SetPassengersInfo(int infants, int children, int adults)
    {
        // No-op in mock version
    }

    /**
     * @brief Returns available flights based on previously set parameters.
     * @return Vector of TurkishFlight objects (dummy data)
     */
    vector<TurkishFlight> GetAvailableFlights() const
    {
        vector<TurkishFlight> flights;

        // Hard-coded mock results
        flights.push_back({300.0, "10-01-2022", "10-02-2022"});
        flights.push_back({320.0, "12-01-2022", "10-02-2022"});

        return flights;
    }

    /**
     * @brief Attempts to reserve a flight.
     * @param info   Customer information
     * @param flight Selected flight
     * @return true on success (always false in mock to simulate failure)
     */
    static bool ReserveFlight(const TurkishCustomerInfo &info,
                              const TurkishFlight &flight)
    {
        // Mock failure – useful for testing rollback logic
        return false;
    }
};

#endif /* EXPEDIA_FLIGHTS_API_H_ */