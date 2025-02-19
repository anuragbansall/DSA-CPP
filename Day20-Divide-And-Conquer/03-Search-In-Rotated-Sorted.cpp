#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &arr, int start, int end, int target);

int main(void)
{
    /*
        Problem: Given a rotated sorted at an unknown pivot, find the target element in the array.
        Approach: Modified Binary Search
        Example: arr = [4, 5, 6, 7, 0, 1, 2], target = 6
        Output: 2
    */
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    int target;
    cout << "Enter the target element: ";
    cin >> target;

    int result = search(arr, 0, arr.size() - 1, target);

    if (result != -1)
    {

        cout << "Target found at index: " << result << endl;
    }
    else
    {

        cout << "Target not found" << endl;
    }

    return 0;
}

int search(vector<int> &arr, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }

    if (arr[start] <= arr[mid]) // left half is sorted
    {
        if (arr[start] <= target && target < arr[mid])
        {
            return search(arr, start, mid - 1, target); // search in left half
        }
        else
        {
            return search(arr, mid + 1, end, target); // search in right half
        }
    }
    else // Right half is sorted
    {
        if (arr[mid] < target && target <= arr[end])
        {
            return search(arr, mid + 1, end, target); // search in right half
        }
        else
        {
            return search(arr, start, mid - 1, target); // search in left half
        }
    }
} // Time Complexity: O(log n)
