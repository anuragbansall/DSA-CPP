#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> pairSum(const vector<int> &arr, int k)
{
    unordered_map<int, int> hashMap;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {
        int diff = k - arr[i];

        if (hashMap.find(diff) != hashMap.end())
        {
            result.push_back(hashMap[diff]);
            result.push_back(i);
            break;
        }

        hashMap[arr[i]] = i;
    }

    return result;
}

int main(void)
{
    /*
        Find if there exists a pair in the array whose sum is equal to k.
        Input: arr[] = {10, 15, 3, 7}, k = 17
        Output: [0, 3]
        Explanation: arr[0] + arr[3] = 10 + 7 = 17
    */

    vector<int> arr = {10, 15, 3, 7};
    int k = 17;

    vector<int> indices = pairSum(arr, k);
    for (int i = 0; i < indices.size(); i += 2)
    {
        cout << "[" << indices[i] << ", " << indices[i + 1] << "]" << endl;
    }

    return 0;
}