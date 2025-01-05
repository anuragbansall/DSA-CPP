#include <iostream>
using namespace std;

int main()
{
    const int MAX_VALUE = 100;
    cout << MAX_VALUE << endl; // Output: 100
    // MAX_VALUE = 200; // Error: assignment of read-only variable 'MAX_VALUE'

    return 0;
}

/*
    Constants:
    - Constants are like variables, except that their value never changes during execution.
    - Constants must be initialized at the time of declaration.
    - They are declared using the keyword `const`.
    - Syntax:
        const type variable = value;
    - Example:
        const int MAX_VALUE = 100;
*/