#include <iostream>
#include <algorithm>
using namespace std;

bool containsDuplicate(int *nums, int n);
int search(int *nums, int n, int target);
int maxProduct(int *nums, int n);

int main()
{
    /*
    EASY-
    Question 1: Given an integer array nums, return true if any value appears at least twice in the array,
    and return false if every element is distinct.

    Examples:
    Input: nums = [1, 2, 3, 4]
    Output: false
    Input: nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
    Output: true
    */
    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << containsDuplicate(nums, n) << endl; // Output: false

    /*
    MEDIUM-
    Question 2: There is an integer array nums sorted in ascending order (with distinct values).
    Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
    such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
    For example, [0, 1, 2, 4, 5, 6, 7] might be rotated at pivot index 3 and become [4, 5, 6, 7, 0, 1, 2].
    Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums,
    or -1 if it is not in nums.
    You must write an algorithm with O(log n) runtime complexity.

    Examples:
    Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
    Output: 4
    Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 3
    Output: -1
    */
    int nums2[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    cout << search(nums2, n2, target) << endl; // Output: 4

    /*
    MEDIUM-
    Question 3: Given an integer array nums, find a subarray that has the largest product, and return the product.
    The test cases are generated so that the answer will fit in a 32-bit integer.

    Note - This question might feel difficult as a beginner because it uses DP approach.
    Examples:
    Input: nums = [2, 3, -2, 4]
    Output: 6
    Explanation: [2, 3] has the largest product 6.
    Input: nums = [-2, 0, -1]
    Output: 0
    Explanation: The result cannot be 2, because [-2, -1] is not a subarray.
    */
    int nums3[] = {2, 3, -2, 4};
    int n3 = sizeof(nums3) / sizeof(nums3[0]);
    cout << maxProduct(nums3, n3) << endl; // Output: 6

    return 0;
}

bool containsDuplicate(int *nums, int n)
{
    sort(nums, nums + n);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            return true;
        }
    }

    return false;
}

int search(int *nums, int n, int target)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[start] <= nums[mid])
        {
            if (target >= nums[start] && target <= nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (target >= nums[mid] && target <= nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int maxProduct(int *nums, int n)
{
    int maxTillNow = nums[0];
    int minTillNow = nums[0];
    int ans = maxTillNow;

    for (int i = 1; i < n; i++)
    {
        int curr = nums[i];

        // Calculate the temporary max considering the current value, maxTillNow * curr, and minTillNow * curr
        int tempMaxTillNow = max(curr, max(maxTillNow * curr, minTillNow * curr));

        // Update minTillNow
        minTillNow = min(curr, min(maxTillNow * curr, minTillNow * curr));

        // Update maxTillNow
        maxTillNow = tempMaxTillNow;

        // Update the global answer
        ans = max(maxTillNow, ans);
    }

    return ans;
}
