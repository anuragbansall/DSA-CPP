#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> majorityElements(vector<int> &nums)
{
    unordered_map<int, int> freq; // element -> frequency
    vector<int> result;

    int n = nums.size();

    for (int num : nums)
    {
        freq[num]++;
    }

    for (const auto &pair : freq)
    {
        if (pair.second > n / 3)
        {
            result.push_back(pair.first);
        }
    }

    return result;
}

int main(void)
{
    /*
        Find elements that appear more than n/3 times in an array of size n.
        Example:
        Input: [3,2,3]
        Output: [3]
        Input: [1,1,1,3,3,2,2,2]
        Output: [1,2]
    */

    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> result = majorityElements(nums);
    cout << "Majority elements (more than n/3 times): ";
    for (int elem : result)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}