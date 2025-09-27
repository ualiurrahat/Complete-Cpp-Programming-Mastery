/*
Problem Statement:

Virtual Base Class in C++

- The virtual base class is used in multiple inheritance to prevent ambiguity
  when the same base class is inherited more than once through different paths.

Example Scenario:
    - Suppose class A is a base class.
    - Classes B and C inherit from A.
    - Class D inherits from both B and C.

Inheritance Diagram:
    A --> B
    A --> C
    B --> D, C --> D

Issue:
    - Data members and functions of A will be inherited twice into D
      (once via B and once via C).
    - This causes ambiguity when class D tries to access A's members.

Solution:
    - Declare A as a "virtual" base class.
    - Then, only one copy of A's members will be shared among all derived classes.
    - This resolves ambiguity.

@note
Time Complexity: O(1) for function calls
Space Complexity: O(1) extra space (only one copy of base class members)
*/
