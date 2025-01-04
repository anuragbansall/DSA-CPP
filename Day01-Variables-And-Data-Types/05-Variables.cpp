#include <iostream>
using namespace std;

int main()
{
    int a = 10; // Variable declaration and initialization
    int b = 20;
    int sum = a + b;

    cout << sum << endl; // Output: 30

    int c;             // Variable declaration
    cout << c << endl; // Output: Garbage value
    c = 50;            // Variable initialization
    cout << c << endl; // Output: 50

    return 0;
}

/*
    Variables:
    - Variables are named locations in memory where data is stored.
    - They can store different data types (e.g., integers, floating-point numbers, strings).
    - Variables must be declared before they can be used.
    - Variable names can contain letters, digits, and underscores (_).
    - Variable names must start with a letter or an underscore (_).
    - Variable names are case-sensitive.
    - Variables can be initialized at the time of declaration.
    - Variables can be assigned new values using the assignment operator (=).
    - Identifiers are names given to variables, functions, classes, etc.
    - Variables are stored in memory locations(RAM), and each variable has an address.
    - Keywords are reserved words that have special meaning in the C++ language and cannot be used as identifiers.
*/