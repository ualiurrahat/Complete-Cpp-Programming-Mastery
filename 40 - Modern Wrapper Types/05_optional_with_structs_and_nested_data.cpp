// 05_optional_with_structs_and_nested_data.cpp
/**
 * @file 05_optional_with_structs_and_nested_data.cpp
 * @brief Models optional ownership using std::optional in structs.
 *
 * A Person may or may not have a pet. Using optional<Animal> expresses this
 * naturally. No null pointers. No default-constructed pets.
 */

#include <iostream>
#include <optional>
#include <string>
using namespace std;

struct Animal
{
    string name;
};

struct Person
{
    string name;
    optional<Animal> pet; // May or may not have a pet
};

int main()
{
    Person person;
    person.name = "John";
    // person.pet is default-constructed → nullopt (no pet)

    if (person.pet)
    {
        // Safe dereference only if pet exists
        cout << person.name << "'s pet's name is "
             << person.pet->name << endl;
    }
    else
    {
        cout << person.name << " is alone." << endl;
    }

    // Now give John a pet
    person.pet = Animal{"Rex"};
    if (person.pet)
    {
        cout << person.name << "'s pet is now " << person.pet->name << endl;
    }

    return 0;
}