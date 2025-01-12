#include <iostream>
using namespace std;

void printArr(int *arr, int n);

// Reverse array - with extra space
void reverseArray(int *arr, int n);

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArr(arr, n);
    reverseArray(arr, n);
    cout << "Reversed array: ";
    printArr(arr, n);

    return 0;
}

void reverseArray(int *arr, int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[n - i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
    Space complexity: O(n) - Extra space is used to store the reversed array.
    Time complexity: O(n + n) = O(2n) = O(n) - Two loops are used to reverse the array. Constant time operations are ignored.
*/