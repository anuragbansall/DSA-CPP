#include <iostream>
#include <array>
#include <string>
using namespace std;

int main()
{
    // Primitive Data Types
    int a = 10;         // Declare and initialize an integer variable
    float b = 3.14;     // Declare and initialize a float variable
    double c = 3.14159; // Declare and initialize a double variable
    char d = 'A';       // Declare and initialize a character variable
    bool e = true;      // Declare and initialize a boolean variable

    cout << "Integer: " << a << ", Size: " << sizeof(a) << " bytes" << endl;
    cout << "Float: " << b << ", Size: " << sizeof(b) << " bytes" << endl;
    cout << "Double: " << c << ", Size: " << sizeof(c) << " bytes" << endl;
    ;
    cout << "Character: " << d << ", Size: " << sizeof(d) << " bytes" << endl;
    ;
    cout << "Boolean: " << e << ", Size: " << sizeof(e) << " bytes" << endl;
    ;

    // Non-Primitive Data Types
    string f = "Hello";                  // Declare and initialize a string variable
    array<int, 5> arr = {1, 2, 3, 4, 5}; // Declare and initialize an array

    cout << "String: " << f << ", Size: " << sizeof(f) << " bytes" << endl;
    ;
    cout << "Array: " << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3] << ", " << arr[4] << ", Size: " << sizeof(arr) << " bytes" << endl;
    ;

    return 0;
}

/*
    Data Types:
        Primitive Data Types:
            int: Stores integer values (e.g., -100, 0, 100) ~ 4 bytes / 32 bits
            float: Stores floating-point values (e.g., 3.14, 2.71) ~ 4 bytes / 32 bits
            double: Stores double-precision floating-point values (e.g., 3.14159, 2.71828) ~ 8 bytes / 64 bits
            char: Stores single characters (e.g., 'A', 'B', '0') ~ 1 byte / 8 bits
            bool: Stores boolean values (e.g., true, false) ~ 1 byte / 8 bits
            void: Represents the absence of type (e.g., void func()) ~ N/A

        Non-Primitive Data Types:
            string: Stores sequences of characters (e.g., "Hello", "World") ~ N bytes
            array: Stores a fixed-size collection of elements (e.g., int arr[5]) ~ N bytes
*/