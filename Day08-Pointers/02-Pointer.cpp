#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p;                                           // Pointer declaration.
    p = &a;                                           // Storing the address of a in p using the address of operator.
    cout << "Address of a: " << p << endl;            // Address of a: 0x61ff0c
    cout << "Value of a: " << *p << endl;             // Value of a: 10 // Dereferencing the pointer to get the value of a.
    cout << "Size of pointer: " << sizeof(p) << endl; // Size of pointer: 4 // Size of pointer is 4 bytes in 32-bit system and 8 bytes in 64-bit system.

    // Pointer to Pointer
    int x = 10;
    int *ptr = &x;
    int **pptr = &ptr;
    cout << "Address of x: " << *pptr << endl; // Address of x: 0x61ff0c // Address of x is stored in ptr.
    cout << "Value of x: " << **pptr << endl;  // Value of x: 10 // first * is used to get the address of x and second * is used to get the value of x.

    return 0;
}

/*
    Pointer:
    - A pointer is a special variable that stores the memory address of another variable.
    - It is declared using the type of the pointed variable followed by the asterisk (*).
    - Pointers are used to access and modify the value of variables indirectly.
    - Size of pointer is 4 bytes in 32-bit system and 8 bytes in 64-bit system.
    - Note: Pointers data type should match the data type of the variable it is pointing to. Otherwise, it will throw a compilation error.
    Syntax:
        data_type *pointer_variable;

    - Example:
        int a = 10;
        int *p; // Pointer declaration.
        p = &a; // Storing the address of a in p.
        cout << *p; // Dereferencing the pointer to get the value of a.
        cout << *(&a); // Dereferencing the address of a to get the value of a.

        Output: 10 // Value of a.

    Pointer to Pointer:
    - A pointer that stores the address of another pointer is called a pointer to pointer.
    - It is declared using two asterisks (**).
    - Syntax:
        data_type **pointer_to_pointer_variable;
    - Example:
        int a = 10;
        int *p;
        int **q;
        p = &a;
        q = &p;
        cout << **q;

        Output: 10 // Value of a.
*/