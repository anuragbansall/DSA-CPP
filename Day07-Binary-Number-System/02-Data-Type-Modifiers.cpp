#include <iostream>
using namespace std;

int main()
{
    long int a = 10;
    short int b = 1000;
    signed int c = -1000;
    unsigned int d = 4294967295;
    long long int e = 1000000000000;

    cout << "Long Integer: " << a << " Size: " << sizeof(a) << " bytes" << endl; // Size of a is 4 bytes
    cout << "Short Integer: " << b << " Size: " << sizeof(b) << " bytes" << endl; // Size of b is 2 bytes
    cout << "Signed Integer: " << c << " Size: " << sizeof(c) << " bytes" << endl; // Size of c is 4 bytes
    cout << "Unsigned Integer: " << d << " Size: " << sizeof(d) << " bytes" << endl; // Size of d is 4 bytes
    cout << "Long Long Integer: " << e << " Size: " << sizeof(e) << " bytes" << endl; // Size of e is 8 bytes

    return 0;
}

/*
    Data Type Modifiers:
    - Data type modifiers are keywords used to modify the properties of a data type.
    - Data type modifiers can change the size, range, and behavior of a data type.
    - Some common data type modifiers in C++ are:
        - long: Increases the size of a data type (usually to double the size of the default data type). Only available for integer and double data types.

        - short: Reduces the size of a data type (usually to half the size of the default data type). Only available for integer data types.

        - signed: Allows a data type to represent both positive and negative numbers. This is the default behavior for most data types.

        - unsigned: Allows a data type to represent only non-negative numbers (zero and positive numbers).

        - long long: Increases the size of a data type (usually to at least 64 bits). Only available for integer data types.

    Example:
    - The following example demonstrates the use of data type modifiers in C++:
        short int a; // 2 bytes
        long int b; // 4 bytes
        unsigned int c; // 4 bytes
        long long int d; // 8 bytes

        a = 10;
        b = 1000;
        c = 4294967295;
        d = 1000000000000;

        cout << "Short Integer: " << a << endl;
        cout << "Long Integer: " << b << endl;
        cout << "Unsigned Integer: " << c << endl;
        cout << "Long Long Integer: " << d << endl;

*/