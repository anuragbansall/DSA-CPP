#include <iostream>
using namespace std;

void insertionSort(int *arr, int n);
void printArr(int *arr, int n);

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArr(arr, n);
    insertionSort(arr, n);
    cout << "Sorted array: ";
    printArr(arr, n);

    return 0;
}

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > current)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current; // Insert the current at its correct position
    }
}
// Time Complexity: O(n^2)

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}