#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int largestSubarrayWithZeroSum(const vector<int> &arr)
{
    unordered_map<int, int> prefixSum; // sum -> first occurrence index
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            maxLength = i + 1;
        }

        if (prefixSum.find(sum) != prefixSum.end())
        {
            int length = i - prefixSum[sum];
            maxLength = max(maxLength, length);
        }
        else
        {
            prefixSum[sum] = i;
        }
    }

    return maxLength;
}

int main(void)
{
    /*
        Given an array of integers, find the length of the largest subarray with sum equal to 0.
        Example:
        Input: {15, -2, 2, -8, 1, 7, 10, 23}
        Output: 5
        Explanation: The largest subarray with sum 0 is {-2, 2, -8, 1, 7}

        Approach: (2 pointers + hashing)
        1. Initialize a hash map to store the cumulative sum and its first occurrence index.
        2. Initialize variables to keep track of the cumulative sum and the maximum length found.
        3. Iterate through the array, updating the cumulative sum.
        4. If the cumulative sum is 0, update the maximum length to the current index + 1.
        5. If the cumulative sum has been seen before, calculate the length of the subarray and update the maximum length if it's larger.
        6. If the cumulative sum is not in the hash map, store it with the current index.
        7. Return the maximum length found.
    */

    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    int result = largestSubarrayWithZeroSum(arr);

    cout << "Length of the largest subarray with sum 0: " << result << endl;

    return 0;
}