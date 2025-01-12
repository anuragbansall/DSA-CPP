#include <iostream>
using namespace std;

void changeArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] * 2;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << arr << endl;        // Output: Address of the first element of the array
    cout << *arr << endl;       // Output: Value of the first element of the array
    cout << *(arr + 1) << endl; // Output: Value of the second element of the array
    cout << *(arr + 2) << endl; // Output: Value of the third element of the array
    cout << *(arr + 3) << endl; // Output: Value of the fourth element of the array
    cout << *(arr + 4) << endl; // Output: Value of the fifth element of the array

    changeArray(arr, n); // Function call to change the values of the array elements
    cout << "Array after change: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
    Array are passed by reference:
    - When an array is passed as a function argument, it is passed by reference. This means that changes made to the array inside the function will be reflected in the original array.
    - This is because the address of the first element of the array is passed to the function and not the entire array.
    - Passing array as name and passing array as pointer are equivalent. (e.g. int arr[] and int *arr)
*/