#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;                           // Pointer to the first element of the array
    cout << "Value at ptr: " << *ptr << endl; // Output: 1
    // Incrementing the pointer
    cout << "Incrementing the pointer" << endl;
    ptr++;
    cout << "Value at ptr: " << *ptr << endl; // Output: 2

    cout << endl;
    // Decrementing the pointer
    cout << "Decrementing the pointer" << endl;
    ptr--;
    cout << "Value at ptr: " << *ptr << endl; // Output: 1

    cout << endl;
    // Adding constant to the pointer
    cout << "Adding constant to the pointer" << endl;
    ptr += 2;
    cout << "Value at ptr: " << *ptr << endl; // Output: 3

    // Subtracting constant from the pointer
    cout << "Subtracting constant from the pointer" << endl;
    ptr -= 2;
    cout << "Value at ptr: " << *ptr << endl; // Output: 1

    cout << endl;
    // Subtraction of two pointers
    cout << "Subtraction of two pointers" << endl;
    int *ptr2 = arr + 4;
    int diff = ptr2 - ptr;
    cout << "Difference: " << diff << endl; // Output: 4 (Number of elements between ptr and ptr2)

    cout << endl;
    // Comparison of pointers
    cout << "Comparison of pointers" << endl;
    ptr2 = arr + 4;
    cout << "ptr > ptr2: " << (ptr > ptr2) << endl;   // Output: 0 (False)
    cout << "ptr < ptr2: " << (ptr < ptr2) << endl;   // Output: 1 (True)
    cout << "ptr == ptr2: " << (ptr == ptr2) << endl; // Output: 0 (False)
    cout << "ptr!= ptr2: " << (ptr != ptr2) << endl;  // Output: 1 (True)

    return 0;
}

/*
    Pointer Arithmetic:
    1. Incrementing a pointer:
        - When a pointer is incremented, it points to the next memory location of the same data type.
        - The size of the data type determines the number of bytes the pointer is incremented by.
        - Syntax: pointer_name++;
        - Example:
            int arr[5] = {1, 2, 3, 4, 5};
            int* ptr = arr; // ptr points to the first element of the array
            ptr++; // ptr now points to the second element of the array

    2. Decrementing a pointer:
        - When a pointer is decremented, it points to the previous memory location of the same data type.
        - Syntax: pointer_name--;
        - Example:
            int arr[5] = {1, 2, 3, 4, 5};
            int* ptr = &arr[4]; // ptr points to the last element of the array
            ptr--; // ptr now points to the second last element of the array

    3. Addition of Constant to a pointer:
        - When a constant value is added to a pointer, the pointer is incremented by the product of the constant value and the size of the data type.
        - Syntax: pointer_name = pointer_name + constant_value;
        - Example:
            int arr[5] = {1, 2, 3, 4, 5};
            int* ptr = arr; // ptr points to the first element of the array
            ptr = ptr + 2; // ptr now points to the third element of the array

    4. Subtraction of Constant from a pointer:
        - When a constant value is subtracted from a pointer, the pointer is decremented by the product of the constant value and the size of the data type.
        - Syntax: pointer_name = pointer_name - constant_value;
        - Example:
            int arr[5] = {1, 2, 3, 4, 5};
            int* ptr = &arr[4]; // ptr points to the last element of the array
            ptr = ptr - 2; // ptr now points to the third last element of the array

    5. Addition of two pointers: Not allowed
    6. Subtraction of two pointers:
        - The difference between two pointers gives the number of elements between them.
        - Syntax: difference = pointer1 - pointer2;
        - Example:
            int arr[5] = {1, 2, 3, 4, 5};
            int* ptr1 = arr; // ptr1 points to the first element of the array
            int* ptr2 = &arr[3]; // ptr2 points to the fourth element of the array
            int diff = ptr2 - ptr1; // diff = 3 (Number of elements between ptr1 and ptr2)
        - Note: Pointer should be of the same data type.

    7. Comparison of pointers:
        - Pointers can be compared using relational operators (<, >, <=, >=).
        - Pointers can be compared for equality (==, !=).
        - Pointers can be compared only if they point to the same array.
        - Example:
            int arr[5] = {1, 2, 3, 4, 5};
            int* ptr1 = arr; // ptr1 points to the first element of the array
            int* ptr2 = &arr[3]; // ptr2 points to the fourth element of the array
            if (ptr1 < ptr2)
            {
                cout << "ptr1 is less than ptr2" << endl;
            }
            else
            {
                cout << "ptr1 is greater than ptr2" << endl;
            }
*/