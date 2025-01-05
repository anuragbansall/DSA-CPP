#include <iostream>
using namespace std;

int main()
{
    // Implicit Typecasting
    int a = 10;
    float b = 3.0;
    cout << a / b << endl;            // Output: 3.33333
    cout << (23.5 + 2 + 'A') << endl; // Output: 90.5
    // Explanation: 'A' will be converted to 65 and 23.5 + 2 + 65 = 90.5

    // Explicit Typecasting
    int x = 65;
    cout << (char)x << endl;     // Output: A
    cout << (bool)3 + 2 << endl; // Output: 3
    // Explanation: 3 will be converted to true (1) and 1 + 2 = 3

    return 0;
}

/*
    Typecasting:

    - Typecasting is a way to convert a variable from one data type to another data type.
    - Syntax:
        (data_type) expression
    - Example:
        int a = (int) 'A';
        cout << a << endl; // Output: 65

    - There are two types of typecasting:
        - Implicit Typecasting:
            - The compiler automatically converts one data type to another.
            - It is also known as automatic type conversion.
            - It is done when:
                - Two data types are compatible.
                - The target type is larger than the source type.
                bool -> char -> int -> float -> double
            - Example:
                int a = 10;
                float b = a;
                cout << b << endl; // Output: 10.0

        - Explicit Typecasting:
            - The programmer manually converts one data type to another.
            - It is also known as manual type conversion.
            - It is done when:
                - Two data types are not compatible.
                - The target type is smaller than the source type.
            - Example:
                float b = 10.5;
                int a = (int) b;
                cout << a << endl; // Output: 10
*/