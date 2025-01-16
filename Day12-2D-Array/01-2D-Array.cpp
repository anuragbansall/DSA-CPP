#include <iostream>
using namespace std;

int main()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "arr[0][0]: " << arr[0][0] << endl; // 1
    cout << "arr[0][1]: " << arr[0][1] << endl; // 2
    cout << "arr[0][2]: " << arr[0][2] << endl; // 3
    cout << "arr[1][0]: " << arr[1][0] << endl; // 4
    cout << "arr[1][1]: " << arr[1][1] << endl; // 5
    cout << "arr[1][2]: " << arr[1][2] << endl; // 6

    return 0;
}

/*
    2D Array:
    - 2D array is an array of arrays.
    - It is a collection of elements arranged in rows and columns.
    - It is also known as a matrix.
    - Syntax:
        data_type array_name[row_size][column_size];
    - Example:
        int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
*/