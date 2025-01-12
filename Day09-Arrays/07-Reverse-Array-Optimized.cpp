#include <iostream>
using namespace std;

void printArr(int *arr, int n);

// Reverse array - without extra space (2 pointers approach)
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
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
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
    Space complexity: O(1) - No extra space is used.
    Time complexity: O(n/2) = O(n) - Only one loop is used to reverse the array.
*/