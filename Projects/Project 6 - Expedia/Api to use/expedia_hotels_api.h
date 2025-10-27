/**
 * @file expedia_hotels_api.h
 * @brief Mock hotel provider APIs (Hilton & Marriott)
 *
 * Provides dummy room-search APIs for two hotel chains.  Used by the
 * Expedia system to retrieve available rooms for a given stay.
 */

#ifndef EXPEDIA_HOTELS_API_H_
#define EXPEDIA_HOTELS_API_H_

#include <string>
#include <vector>

using namespace std;

/**
 * @struct HiltonRoom
 * @brief Represents a room option returned by Hilton.
 */
class HiltonRoom
{
public:
    string room_type;       ///< e.g., "City View"
    int available;          ///< Number of rooms of this type
    double price_per_night; ///< Price per night in USD
    string date_from;       ///< Check-in date (DD-MM-YYYY)
    string date_to;         ///< Check-out date (DD-MM-YYYY)
};

/**
 * @class HiltonHotelAPI
 * @brief Mock API for Hilton room searches.
 */
class HiltonHotelAPI
{
public:
    /**
     * @brief Searches for available rooms at Hilton properties.
     * @param country       Country of the hotel
     * @param city          City of the hotel
     * @param from_date     Check-in date
     * @param to_date       Check-out date
     * @param adults        Number of adult guests
     * @param children      Number of child guests
     * @param needed_rooms  Number of rooms required
     * @return Vector of available room options (dummy data)
     */
    static vector<HiltonRoom> SearchRooms(
        const string &country, const string &city,
        const string &from_date, const string &to_date,
        int adults, int children, int needed_rooms)
    {

        vector<HiltonRoom> rooms;

        // Hard-coded mock results
        rooms.push_back({"Interior View", 6, 200.0, "29-01-2022", "10-02-2022"});
        rooms.push_back({"City View", 3, 300.0, "29-01-2022", "10-02-2022"});
        rooms.push_back({"Deluxe View", 8, 500.0, "29-01-2022", "10-02-2022"});

        return rooms;
    }
};

/**
 * @struct MarriottFoundRoom
 * @brief Represents a room option returned by Marriott.
 */
class MarriottFoundRoom
{
public:
    string room_type;
    int available;
    double price_per_night;
    string date_from;
    string date_to;
};

/**
 * @class MarriottHotelAPI
 * @brief Mock API for Marriott room searches.
 */
class MarriottHotelAPI
{
public:
    /**
     * @brief Finds available rooms at Marriott hotels.
     * @param from_date     Check-in date
     * @param to_date       Check-out date
     * @param country       Country
     * @param city          City
     * @param needed_rooms  Number of rooms needed
     * @param adults        Number of adults
     * @param children      Number of children
     * @return Vector of room options (dummy data)
     */
    static vector<MarriottFoundRoom> FindRooms(
        const string &from_date, const string &to_date,
        const string &country, const string &city,
        int needed_rooms, int adults, int children)
    {

        vector<MarriottFoundRoom> rooms;

        // Mock results
        rooms.push_back({"City View", 8, 320.0, "29-01-2022", "10-02-2022"});
        rooms.push_back({"Interior View", 8, 220.0, "29-01-2022", "10-02-2022"});
        rooms.push_back({"Private View", 5, 600.0, "29-01-2022", "10-02-2022"});

        return rooms;
    }
};

#endif /* EXPEDIA_HOTELS_API_H_ */