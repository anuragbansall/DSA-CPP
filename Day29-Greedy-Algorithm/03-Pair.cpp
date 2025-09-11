#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main(void)
{
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {9, 2, 4};

    vector<pair<int, int>> ans;

    for (int i = 0; i < arr1.size(); i++)
    {
        ans.push_back(make_pair(arr1[i], arr2[i]));
    }

    // Sort pairs based on the last element
    sort(ans.begin(), ans.end(), compare);

    for (auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}