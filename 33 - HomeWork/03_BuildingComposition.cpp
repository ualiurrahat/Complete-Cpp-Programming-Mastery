/**
 * @file 03_BuildingComposition.cpp
 * @brief Homework: Model a Building with Apartments, Rooms, and Elevators.
 *
 * @section problem Problem Statement
 * Design classes:
 * - `Room`: width, height, color
 * - `Apartment`: list of rooms, bathrooms, floor#, apartment#
 * - `Elevator`: width, height, max people, max weight
 * - `Building`: list of apartments and elevators
 *
 * Use composition and proper encapsulation.
 *
 * @section intuition Intuition
 * Real-world systems are **hierarchical**.
 * A `Building` **has** `Apartments`, which **have** `Rooms`.
 * This is **composition** — "has-a" relationship.
 *
 * @section logic Logic & Flow
 * 1. `Room` → basic unit
 * 2. `Apartment` → aggregates multiple `Room`s
 * 3. `Building` → top-level container
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Room
{
private:
    int width, height;
    string color;

public:
    const string &GetColor() const { return color; }
    void SetColor(const string &c) { color = c; }
    int GetHeight() const { return height; }
    void SetHeight(int h) { height = h; }
    int GetWidth() const { return width; }
    void SetWidth(int w) { width = w; }
};

class Apartment
{
private:
    vector<Room> rooms;
    vector<Room> bathrooms;
    int floor_number;
    int apartment_number;

public:
    int GetApartmentNumber() const { return apartment_number; }
    void SetApartmentNumber(int n) { apartment_number = n; }
    int GetFloorNumber() const { return floor_number; }
    void SetFloorNumber(int f) { floor_number = f; }
    const vector<Room> &GetRooms() const { return rooms; }
    void SetRooms(const vector<Room> &r) { rooms = r; }
    const vector<Room> &GetBathroom() const { return bathrooms; }
    void SetBathroom(const vector<Room> &b) { bathrooms = b; }
};

class Elevator
{
private:
    int width, height, max_people, max_weight;

public:
    int GetHeight() const { return height; }
    void SetHeight(int h) { height = h; }
    int GetMaxPeople() const { return max_people; }
    void SetMaxPeople(int p) { max_people = p; }
    int GetMaxWeight() const { return max_weight; }
    void SetMaxWeight(int w) { max_weight = w; }
    int GetWidth() const { return width; }
    void SetWidth(int w) { width = w; }
};

class Building
{
private:
    vector<Apartment> apartments;
    vector<Elevator> elevators;
    // Could add: address, floors, name, etc.
};

int main()
{
    return 0;
}