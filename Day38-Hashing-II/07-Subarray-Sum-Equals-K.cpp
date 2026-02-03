#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> prefixSum; // sum -> frequency
    prefixSum[0] = 1;                  // Base case: one way to have sum 0

    int cumulativeSum = 0;
    int count = 0;

    for (int num : nums)
    {
        cumulativeSum += num;

        if (prefixSum.find(cumulativeSum - k) != prefixSum.end())
        {
            count += prefixSum[cumulativeSum - k];
        }

        prefixSum[cumulativeSum]++;
    }

    return count;
}

int main(void)
{
    /*
        Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

        Example 1:
        Input:nums = [1,1,1], k = 2
        Output: 2 ([1,1] at index 0 and [1,1] at index 1)

        Example 2:
        Input:nums = [1,2,3], k = 3
        Output: 2 ([1,2] and [3])

        Approach:
        1. Use a hashmap to store the cumulative sum and its frequency.
        2. Initialize cumulative sum as 0 and result count as 0.
        3. Iterate through the array, updating the cumulative sum.
        4. For each cumulative sum, check if (cumulative sum - k) exists in the hashmap.
           If it does, it means there are subarrays ending at the current index which sum to k.
        5. Update the hashmap with the current cumulative sum.
    */

    vector<int> nums = {1, 2, 3};
    int k = 3;

    cout << "Total subarrays with sum " << k << " : " << subarraySum(nums, k) << endl;

    return 0;
}