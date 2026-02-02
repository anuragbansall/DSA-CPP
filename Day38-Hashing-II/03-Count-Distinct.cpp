#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countDistinct(const vector<int> &nums)
{
    unordered_set<int> distinctElements;

    for (int num : nums)
    {
        distinctElements.insert(num);
    }

    return distinctElements.size();
}

int main(void)
{
    /*
        Given an array of integers, return the number of distinct integers in the array.
        Example 1:
        Input: nums = [1,2,2,3,4,4,5]
        Output: 5
        Explanation: The distinct integers are [1,2,3,4,5].
        Example 2:
        Input: nums = [1,1,1,1]
        Output: 1
        Explanation: The distinct integer is [1].
    */

    vector<int> nums = {1, 2, 2, 3, 4, 4, 5};
    int result = countDistinct(nums);

    cout << "Number of distinct integers: " << result << endl;

    return 0;
}