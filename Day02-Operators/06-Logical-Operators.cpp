#include <iostream>
using namespace std;

int main()
{
    // Logical Operators
    int a = 10, b = 5;
    cout << (a > b && a < 20) << endl; // Output: 1 (true)
    cout << (a < b && a < 20) << endl; // Output: 0 (false)
    cout << (a > b || a == 5) << endl; // Output: 1 (true)
    cout << !(a > b) << endl;          // Output: 0 (false)

    return 0;
}

/*
    Logical Operators:
    - Logical operators are used to combine multiple conditions and perform logical operations.
    - Logical operators are also known as boolean operators.
    - Available operators:
        - Logical AND (&&)
        - Logical OR (||)
        - Logical NOT (!)
    - Example:
        int a = 10, b = 5;
        cout << (a > b && a < 20) << endl; // Output: 1 (true)
        cout << (a > b || a == 5) << endl; // Output: 1 (true)
        cout << !(a > b) << endl;          // Output: 0 (false)

    Truth Table for Logical AND (&&):
    // a | b | a && b
    // __|___|_______
    // 0 | 0 | 0
    // 0 | 1 | 0
    // 1 | 0 | 0
    // 1 | 1 | 1

    Truth Table for Logical OR (||):
    // a | b | a || b
    // __|___|_______
    // 0 | 0 | 0
    // 0 | 1 | 1
    // 1 | 0 | 1
    // 1 | 1 | 1

    Truth Table for Logical NOT (!):
    // a | !a
    // __|___
    // 0 | 1
    // 1 | 0
*/