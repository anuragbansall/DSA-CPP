#include <iostream>
using namespace std;

int main()
{
    // Binary Arithmetic Operators
    int a = 10, b = 5;
    cout << "Addition: " << a + b << endl;       // Output: 15
    cout << "Subtraction: " << a - b << endl;    // Output: 5
    cout << "Multiplication: " << a * b << endl; // Output: 50
    cout << "Division: " << a / b << endl;       // Output: 2
    cout << "Modulus: " << a % b << endl;        // Output: 0

    // Unary Arithmetic Operators
    int x = 10, y = 10;
    cout << "Pre-increment: " << ++x << endl;  // Output: 11
    cout << "Post-increment: " << x++ << endl; // Output: 11
    cout << "x: " << x << endl;                // Output: 12
    cout << "Pre-decrement: " << --y << endl;  // Output: 9
    cout << "Post-decrement: " << y-- << endl; // Output: 9
    cout << "y: " << y << endl;                // Output: 8

    return 0;
}

/*
    Operators:
    - Operators are symbols that perform operations on operands.
    - There are different types of operators:
        - Arithmetic Operators
        - Assignment Operators
        - Relational Operators
        - Logical Operators
        - Bitwise Operators

    Binary Arithmetic Operators (Operate on two operands):
        - Addition (+) // Sum
        - Subtraction (-) // Difference
        - Multiplication (*) // Product
        - Division (/) // Quotient
        - Modulus (%) // Remainder
        - Exponentiation (**) // Power

    Unary Arithmetic Operators (Operate on one operand):
        - Increment (++) // Pre-increment and Post-increment
        - Decrement (--) // Pre-decrement and Post-decrement
        - Unary Plus (+) // No effect
        - Unary Minus (-) // Negates the value
*/