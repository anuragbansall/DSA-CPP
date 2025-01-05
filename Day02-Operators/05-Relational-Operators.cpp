#include <iostream>
using namespace std;

int main()
{
    // Relational Operators
    int a = 10, b = 5;
    cout << "a == b: " << (a == b) << endl; // Output: 0 (false)
    cout << "a!= b: " << (a != b) << endl;  // Output: 1 (true)
    cout << "a > b: " << (a > b) << endl;   // Output: 1 (true)
    cout << "a < b: " << (a < b) << endl;   // Output: 0 (false)
    cout << "a >= b: " << (a >= b) << endl; // Output: 1 (true)
    cout << "a <= b: " << (a <= b) << endl; // Output: 0 (false)

    return 0;
}

/*
    Relational Operators:
    - Relational operators compare two operands and return true or false based on their values.
    - Relational operators are also known as comparison operators.
    - Available operators:
        - Equal to (==)
        - Not equal to (!=)
        - Greater than (>)
        - Less than (<)
        - Greater than or equal to (>=)
        - Less than or equal to (<=)
    - Example:
        int a = 10, b = 5;
        cout << (a == b) << endl; // Output: 0 (false)
        cout << (a != b) << endl; // Output: 1 (true)
        cout << (a > b) << endl;  // Output: 1 (true)
        cout << (a < b) << endl;  // Output: 0 (false)
        cout << (a >= b) << endl; // Output: 1 (true)
        cout << (a <= b) << endl; // Output: 0 (false)
*/