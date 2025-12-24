#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    /*
        Maximum of all subarrays of size k
        Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.
        Input: arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
        k = 3
        Output: 3 4 5 6 7 8 9 10
        Explanation:
        1st contiguous subarray = {1, 2, 3} = > Maximum = 3
        2nd contiguous subarray = {2, 3, 4} = > Maximum = 4
        3rd contiguous subarray = {3, 4, 5} = > Maximum = 5
        4th contiguous subarray = {4, 5, 6} = > Maximum = 6
        5th contiguous subarray = {5, 6, 7} = > Maximum = 7
        6th contiguous subarray = {6, 7, 8} = > Maximum = 8
        7th contiguous subarray = {7, 8, 9} = > Maximum = 9
        8th contiguous subarray = {8, 9, 10} = > Maximum = 10

        Approach:
        1. Create a max-heap to store elements of the current window along with their indices.
        2. Iterate through the array, adding elements to the max-heap.
        3. Once we have added k elements, the top of the max-heap will be the maximum for the current window.
        4. Before adding a new element, remove elements from the heap that are out of the current window.
        5. Continue this process until the end of the array is reached.
    */

    vector<int> arr = {10, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 3;

    priority_queue<pair<int, int>> maxHeap; // {value, index}
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {
        // Add current element to the max-heap
        maxHeap.push({arr[i], i});

        // Remove elements that are out of the current window
        while (!maxHeap.empty() && maxHeap.top().second <= i - k)
        {
            cout << maxHeap.top().second << " <= " << i - k << endl;
            cout << "Removing element " << maxHeap.top().first << " at index " << maxHeap.top().second << " as it is out of the window ending at index " << i << endl;
            maxHeap.pop();
        }

        // If we have processed at least k elements, record the maximum for the current window
        if (i >= k - 1)
        {
            result.push_back(maxHeap.top().first);
        }
    }

    // Print the result
    for (int maxVal : result)
    {
        cout << maxVal << " ";
    }
    cout << endl;

    return 0;
}