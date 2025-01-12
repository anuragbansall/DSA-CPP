#include <iostream>
using namespace std;

int binarySearch(int *arr, int n, int key);

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    int result = binarySearch(arr, n, key);
    cout << "Element found at index: " << result << endl;

    return 0;
}

int binarySearch(int *arr, int n, int key)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1; // Not Found
}

/*
    Time complexity: O(log n) - Binary search algorithm reduces the search space in half at each step.
    Space complexity: O(1) - No extra space is used.

    Note: The binary search algorithm assumes that the input array is sorted in ascending order. If the array is not sorted, the search may not be efficient.
*/