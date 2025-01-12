#include <iostream>
using namespace std;

int linear_search(int *arr, int n, int key);

int main()
{
    int arr[10] = {12, 34, 45, 67, 89, 23, 56, 78, 90, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int index = linear_search(arr, n, key);
    cout << "Element found at index: " << index << endl;

    return 0;
}

int linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1; // Not found
}
/*
    Linear Search time complexity:
    - Best case: O(1) (When the element is found at the first position)
    - Average case: O(n) (When the element is found in the middle of the array)
    - Worst case: O(n) (When the element is not present in the array or found at the last position)
    - Linear search is not efficient for large arrays.
*/