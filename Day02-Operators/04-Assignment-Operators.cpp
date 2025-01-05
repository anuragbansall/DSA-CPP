#include <iostream>
using namespace std;

int main()
{
    // Assignment Operators
    int a = 10;        // Initialization
    a += 5;            // Equivalent to a = a + 5;
    cout << a << endl; // Output: 15
    a -= 5;            // Equivalent to a = a - 5;
    cout << a << endl; // Output: 10
    a *= 5;            // Equivalent to a = a * 5;
    cout << a << endl; // Output: 50
    a /= 5;            // Equivalent to a = a / 5;
    cout << a << endl; // Output: 10
    a %= 5;            // Equivalent to a = a % 5;
    cout << a << endl; // Output: 0

    return 0;
}

/*
    Assignment Operators:
    - Assignment operators are used to assign values to variables.
    - Assignment operators can be combined with arithmetic operators.
    - Syntax:
        variable = expression;
        variable += expression;
        variable -= expression;
    - Example:
        int a = 10;
        a += 5; // Equivalent to a = a + 5;
        cout << a << endl; // Output: 15
*/