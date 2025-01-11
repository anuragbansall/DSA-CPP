#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    cout << "Address of a: " << &a << endl; // Address of a: 0x61ff0c
    cout << "Address of b: " << &b << endl; // Address of b: 0x61ff08

    return 0;
}

/*
    Address of Operator (&):
    - The address of operator is used to get the address of a variable.
    - It is denoted by the symbol &.
    - It is also called reference operator.
    - Address is stored in a pointer variable.
    - Example:
        int a = 10;
        cout << &a;
        Output: 0x61ff0c // Address of a in hexadecimal form.
*/