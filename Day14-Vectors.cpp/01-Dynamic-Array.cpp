#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The elements of the array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Deallocate the dynamic array

    return 0;
}

/*
    Dynamic Array:
    - Dynamic arrays are arrays that can grow and shrink in size dynamically.
    - They are allocated in the heap memory, and their size can be changed during the runtime.
    - The size of the dynamic array is not fixed, and it can be changed during the runtime.
    - The dynamic array is created using the new operator.
    - To delete an element from a dynamic array, use the delete operator.
    - To delete the entire dynamic array, use the delete[] operator.
    - Syntax:
        data_type *array_name = new data_type[size];
    - Example:
        int *arr = new int[5];
        // To delete an element from a dynamic array:
        delete arr[index];
        // To delete the entire dynamic array:
        delete[] arr;

    Dynamic Memory Allocation vs Static Memory Allocation:
    - Dynamic Memory Allocation:
        - The size of the memory is allocated during the runtime.
        - The size of the memory can be changed during the runtime.
        - The memory is allocated in the heap memory.
        - The memory is allocated using the new operator.
        - The memory is deallocated using the delete operator.

    - Static Memory Allocation:
        - The size of the memory is allocated during the compile time.
        - The size of the memory cannot be changed during the runtime.
        - The memory is allocated in the stack memory.
        - The memory is allocated using the array declaration.
        - The memory is deallocated automatically when the program terminates.

    Memory Leak:
    - Memory leak is a situation where the memory is allocated but not deallocated.
    - It occurs when the memory is allocated in the heap memory but not deallocated.
    - It leads to the wastage of memory and can cause the program to run out of memory.
    - To avoid memory leaks, always deallocate the memory after its use.
    - Use the delete operator to deallocate the memory allocated using the new operator.
    - Use the delete[] operator to deallocate the memory allocated using the new[] operator.
    - Example:
        int *arr = new int[5];
        delete[] arr;
        // If the memory allocation is not deallocated, a memory leak will occur.
*/