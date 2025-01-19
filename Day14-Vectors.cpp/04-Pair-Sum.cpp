#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> vec, int sum);

int main()
{
    vector<int> vec = {2, 7, 11, 15};
    int sum = 9;
    vector<int> result = pairSum(vec, sum);
    cout << "Pair with given sum: (" << result[0] << ", " << result[1] << ")" << endl;

    return 0;
}

vector<int> pairSum(vector<int> vec, int sum)
{
    vector<int> ans;
    int start = 0;
    int end = vec.size() - 1;

    while (start < end)
    {
        int currSum = vec[start] + vec[end];
        if (currSum == sum)
        {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
        else if (currSum < sum)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    return ans;
}