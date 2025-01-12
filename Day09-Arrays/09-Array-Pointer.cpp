#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int a = 5;
    // arr = &a; // Error: Cannot assign to an array from an integer

    return 0;
}

/*
    Array Pointer acts like a constant pointer that points to the first element of the array and cannot be changed.
*/