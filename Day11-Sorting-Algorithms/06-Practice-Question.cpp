#include <iostream>
using namespace std;

void printArr(char *arr, int n);
void sortChars(char *arr, int n);

int main()
{
    // Sort this array of chars using insertion sort in descending order.
    char arr[] = {'a', 'z', 'b', 'y', 'c', 'x', 'd', 'w', 'e', 'v'};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArr(arr, n);

    cout << "Descending Sorted array: ";
    sortChars(arr, n);
    printArr(arr, n);

    return 0;
}

void sortChars(char *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] < current)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current; // Insert the current at its correct position
    }
}

void printArr(char *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}