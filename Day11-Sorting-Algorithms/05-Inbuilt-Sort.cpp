#include <iostream>
#include <algorithm> // For inbuilt sort function
using namespace std;

void printArr(int *arr, int n);

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArr(arr, n);
    
    cout << "Ascending Sorted array: ";
    sort(arr, arr + n); // Takes two arguments: start and end of the array
    printArr(arr, n);
    
    cout << "Descending Sorted array: ";
    sort(arr, arr + n, greater<int>()); // Takes three arguments: start, end and comparator function (greater<int>() for descending order)
    printArr(arr, n);

    return 0;
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}