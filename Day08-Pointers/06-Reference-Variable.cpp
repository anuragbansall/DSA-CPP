#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &b = a;
    cout << "Value of a: " << a << endl; // Output: 10
    cout << "Value of b: " << b << endl; // Output: 10

    b = 20;
    cout << "Value of a: " << a << endl; // Output: 20
    cout << "Value of b: " << b << endl; // Output: 20

    return 0;
}

/*
    Reference Variable:
    - A reference variable is a variable that holds the address of another variable.
    - It is an alias (alternative name) for the variable it references.
    - It allows us to use the same name to refer to different variables.
    - It is declared using the reference operator (&) in the variable declaration.
    - Syntax:
        data_type &reference_variable = variable;
    - Example:
        int a = 10;
        int &b = a;
        // Here, b is a reference variable that holds the address of a.
    - Note: Reference variables cannot be NULL. They must be initialized when declared and its data type should match the data type of the variable it references.
*/