/**
 * @file expedia_customer_view.h
 * @brief UI for customer interactions
 * @author Rahat (Original: moustafa)
 * @date 2025
 */

#ifndef EXPEDIA_CUSTOMER_VIEW_H_
#define EXPEDIA_CUSTOMER_VIEW_H_

#include "expedia_cusomter_mgr.h"
#include "expedia_utils.h"

using namespace std;

/**
 * @class CustomerView
 * @brief Menu-driven interface for customers.
 */
class CustomerView
{
private:
    CustomerManager &customer_manager;
    const Customer &customer;
    ItineraryReservation current_itinerary;

    void ReadFlightRequest(FlightRequest &request) const
    {
        string str;
        int val;
        cout << "Enter From: ";
        cin >> str;
        request.SetFrom(str);
        cout << "Enter From Date (dd-mm-yy): ";
        cin >> str;
        request.SetDatetimeFrom(str);
        cout << "Enter To: ";
        cin >> str;
        request.SetTo(str);
        cout << "Enter To Date (dd-mm-yy): ";
        cin >> str;
        request.SetDatetimeTo(str);
        cout << "Adults, Children, Infants: ";
        cin >> val;
        request.SetAdults(val);
        cin >> val;
        request.SetChildren(val);
        cin >> val;
        request.SetInfants(val);
    }

    void ReadHotelRequest(HotelRequest &request) const
    {
        string str;
        int val;
        cout << "From Date (dd-mm-yy): ";
        cin >> str;
        request.SetFromDate(str);
        cout << "To Date (dd-mm-yy): ";
        cin >> str;
        request.SetToDate(str);
        cout << "Country: ";
        cin >> str;
        request.SetCountry(str);
        cout << "City: ";
        cin >> str;
        request.SetCity(str);
        cout << "Adults, Children: ";
        cin >> val;
        request.SetAdults(val);
        cin >> val;
        request.SetChildren(val);
    }

    int ChooseFlight(const vector<Flight> &flights) const
    {
        if (flights.empty())
        {
            cout << "No flights found\n";
            return -1;
        }
        for (int i = 0; i < flights.size(); ++i)
            cout << i + 1 << ": " << flights[i].ToString() << "\n";
        return ReadInt(1, flights.size(), true);
    }

    int ChooseRoom(const vector<HotelRoom> &rooms) const
    {
        if (rooms.empty())
        {
            cout << "No rooms found\n";
            return -1;
        }
        for (int i = 0; i < rooms.size(); ++i)
            cout << i + 1 << ": " << rooms[i].ToString() << "\n";
        return ReadInt(1, rooms.size(), true);
    }

    void AddFlight()
    {
        FlightRequest request;
        ReadFlightRequest(request);
        auto flights = customer_manager.FindFlights(request);
        int choice = ChooseFlight(flights);
        if (choice == -1)
            return;
        FlightReservation res(request, flights[choice - 1]);
        current_itinerary.AddReservation(res);
    }

    void AddHotel()
    {
        HotelRequest request;
        ReadHotelRequest(request);
        auto rooms = customer_manager.FindHotels(request);
        int choice = ChooseRoom(rooms);
        if (choice == -1)
            return;
        HotelReservation res(request, rooms[choice - 1]);
        current_itinerary.AddReservation(res);
    }

    void PayItinerary()
    {
        auto choices = customer_manager.GetPaymentChoices();
        int choice = ShowReadMenu(choices, "Select payment");
        PaymentCard *card = const_cast<Customer &>(customer).GetCards()[choice - 1];
        bool success = customer_manager.MakeReservation(current_itinerary, *card);
        cout << (success ? "Itinerary booked!\n" : "Booking failed\n");
    }

public:
    CustomerView(CustomerManager &mgr)
        : customer_manager(mgr), customer(*mgr.GetCustomer()) {}

    void Display()
    {
        cout << "\n\nHello " << customer.GetName() << " | Customer View\n";
        vector<string> menu = {
            "View Profile", "Build Itinerary", "My Itineraries", "Logout"};

        while (true)
        {
            int choice = ShowReadMenu(menu);
            if (choice == 1)
                ViewProfile();
            else if (choice == 2)
                MakeItinerary();
            else if (choice == 3)
                ListItineraries();
            else
                break;
        }
    }

    void ViewProfile() const
    {
        cout << "\n"
             << customer.ToString() << "\n";
    }

    void MakeItinerary()
    {
        vector<string> menu = {"Add Flight", "Add Hotel", "Done", "Cancel"};
        while (true)
        {
            int choice = ShowReadMenu(menu);
            if (choice == 1)
                AddFlight();
            else if (choice == 2)
                AddHotel();
            else if (choice == 3)
            {
                PayItinerary();
                current_itinerary.Clear();
                break;
            }
            else
            {
                current_itinerary.Clear();
                break;
            }
        }
    }

    void ListItineraries() const
    {
        auto itineraries = customer_manager.GetItineraries();
        if (itineraries.empty())
            cout << "No itineraries yet!\n";
        for (const string &s : itineraries)
            cout << s << "\n";
    }
};

#endif /* EXPEDIA_CUSTOMER_VIEW_H_ */