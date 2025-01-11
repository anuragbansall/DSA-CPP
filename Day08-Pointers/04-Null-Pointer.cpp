#include <iostream>
using namespace std;

int main()
{
    int *ptr;                                                     // Pointer declaration.
    cout << "Value of ptr: " << ptr << endl;                      // Value of ptr: 0x401a5b // Random address.
    ptr = NULL;                                                   // Assigning NULL to ptr.
    cout << "Value of ptr after assigning NULL: " << ptr << endl; // Value of ptr after assigning NULL: 0x0 // NULL pointer.

    return 0;
}

/*
    Null Pointer:
    - A null pointer is a pointer that does not point to any memory location.
    - It is used to initialize a pointer when we do not have the exact address to assign.
    - It is denoted by the value 0 or NULL.
    - Example:
        int *p = NULL;
        int *q = 0;
        // Both p and q are null pointers.
    - Note: Dereferencing a null pointer will cause a runtime error.
*/