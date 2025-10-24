/**
 * @file 13_SharedPtr_CustomDeleter.cpp
 * @brief Custom cleanup with `shared_ptr`.
 *
 * Problem Statement:
 * Handle non-`delete` cleanup (e.g. legacy APIs).
 *
 * New Topics Introduced:
 * - Custom deleter as lambda or function
 * - Works with `unique_ptr` and `shared_ptr`
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <memory>
using namespace std;

struct LegacyDB {
    void close() { cout << "DB closed\n"; }
    ~LegacyDB() { cout << "DB dtor\n"; }
};

int main() {
    auto deleter = [](LegacyDB* db) {
        db->close();
        delete db;
    };

    {
        shared_ptr<LegacyDB> p(new LegacyDB(), deleter);
    }  // close → dtor

    return 0;
}