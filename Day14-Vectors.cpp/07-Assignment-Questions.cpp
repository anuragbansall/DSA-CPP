#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findErrorNums(vector<int> &nums);
int maxWaterContainer(vector<int> &height);
vector<vector<int>> threeSum(vector<int> &nums);

int main()
{
    /*
    Question 1:
    You have a set of integers, which originally contains all the numbers from 1 to n.
    Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set,
    which results in repetition of one number and loss of another number.
    You are given an integer array nums representing the data status of this set after the error.
    Find the number that occurs twice and the number that is missing and return them in the form of an array.
    Example:
    Input: nums = [1, 2, 2, 4]
    Output: [2, 3]
    */
    vector<int> nums = {1, 2, 2, 4};
    vector<int> result = findErrorNums(nums);
    cout << "Number that occurs twice: " << result[0] << endl;
    cout << "Number that is missing: " << result[1] << endl;

    /*
    Question 2:
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container,
    such that the container contains the most water. Return the maximum amount of water a container can store.
    Notice that you may not slant the container.
    Input: height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1, 8, 6, 2, 5, 4, 8, 3, 7].
    In this case, the max area of water (blue section) the container can contain is 49.
    */
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max water container: " << maxWaterContainer(height) << endl;

    /*
    Question 3:
    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
    and nums[i] + nums[j] + nums[k] == 0. Notice that the solution set must not contain duplicate triplets.
    Input: nums = [-1, 0, 1, 2, -1, -4]
    Output: [[-1, -1, 2], [-1, 0, 1]]
    Explanation: nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
                 nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
                 nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
                 The distinct triplets are [-1, 0, 1] and [-1, -1, 2].
                 Notice that the order of the output and the order of the triplets does not matter.
    Input: nums = [0, 1, 1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.
    Note: Read up about the in-built sorting of vectors.
    */
    vector<int> nums2 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> threeSumResult = threeSum(nums2);
    for (auto &triplet : threeSumResult)
    {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++)
        {
            cout << triplet[i];
            if (i != triplet.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}

vector<int> findErrorNums(vector<int> &nums)
{
    vector<int> result;
    vector<bool> isPresent(nums.size(), false);

    for (int i = 0; i < nums.size(); i++)
    {
        if (isPresent[nums[i] - 1])
        {
            result.push_back(nums[i]);
        }
        isPresent[nums[i] - 1] = true;
    }

    for (int i = 0; i < isPresent.size(); i++)
    {
        if (!isPresent[i])
        {
            result.push_back(i + 1);
            break;
        }
    }

    return result;
}

int maxWaterContainer(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right)
    {
        int currentArea = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, currentArea);
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxArea;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int current = nums[i];
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = current + nums[left] + nums[right];
            if (sum == 0)
            {
                result.push_back({current, nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }

                while (left < right && nums[right] == nums[right - 1])
                {

                    right--;
                }
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
}
