#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[10] = {0};

    cout << "arr[0]: " << arr[0] << endl;   // Output: 1
    cout << "arr2[0]: " << arr2[0] << endl; // Output: 1
    cout << "arr3[0]: " << arr3[0] << endl; // Output: 0

    cout << "Size of arr: " << sizeof(arr) << endl;   // Output: 20 bytes
    cout << "Size of arr2: " << sizeof(arr2) << endl; // Output: 20 bytes
    cout << "Size of arr3: " << sizeof(arr3) << endl; // Output: 40 bytes

    cout << "Number of elements in arr: " << sizeof(arr) / sizeof(arr[0]) << endl;    // Output: 5
    cout << "Number of elements in arr2: " << sizeof(arr2) / sizeof(arr2[0]) << endl; // Output: 5
    cout << "Number of elements in arr3: " << sizeof(arr3) / sizeof(arr3[0]) << endl; // Output: 10

    return 0;
}

/*
    Arrays:
    - A collection of elements of the same data type stored in contiguous memory locations.
    - The elements of an array can be accessed using an index.
    - Indexing starts from 0.
    - The size of an array must be a constant value.
    - Size of an array is number of elements * size of data type. (e.g. int arr[5] -> 5 * 4 = 20 bytes)
    - To calculate number of elements in an array: sizeof(arr) / sizeof(arr[0])
    - Syntax:
        data_type array_name[size];
    - Example:
        int arr[5] = {1, 2, 3, 4, 5};
        // Accessing elements
        cout << arr[0] << endl; // Output: 1
        cout << arr[4] << endl; // Output: 5

    - Ways to initialize an array:
        1. int arr[5] = {1, 2, 3, 4, 5};
        2. int arr[] = {1, 2, 3, 4, 5}; // Size of the array will be determined by the number of elements
        3. int arr[5] = {0}; // All elements will be initialized to 0
        4. int arr[5] = {1}; // First element will be 1 and rest will be 0
        5. int arr[5] = {1, 2}; // First two elements will be 1 and 2 and rest will be 0
        6. int arr[5] = {}; // All elements will be initialized to 0
        7. int arr[5]; // Elements will be garbage values
*/