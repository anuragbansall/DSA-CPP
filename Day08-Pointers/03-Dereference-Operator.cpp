#include <iostream>
using namespace std;

int main()
{
    int a = 20;
    int *ptr = &a;
    cout << "Value of a: " << *ptr << endl;  // Value of a: 20
    cout << "Value of a: " << *(&a) << endl; // Value of a: 20

    *ptr = 30;                                              // Changing the value of a using pointer. // We can also use *(&a) = 30;
    cout << "Value of a after modification: " << a << endl; // Value of a after modification: 30

    return 0;
}

/*
    Dereference Operator (*):
    - The dereference operator is used to get the value of a variable through a pointer.
    - It is denoted by the symbol *.
    - It is also called the indirection operator.
    - Example:
        int a = 10;
        int *p; // Pointer declaration.
        p = &a; // Storing the address of a in p using the address of operator.
        cout << *p; // Dereferencing the pointer to get the value of a.
        cout << *(&a); // Dereferencing the address of a to get the value of a.

        Output: 10 // Value of a.
*/