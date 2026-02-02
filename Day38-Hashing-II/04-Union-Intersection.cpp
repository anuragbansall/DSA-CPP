#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

pair<unordered_set<int>, unordered_set<int>> unionAndIntersection(const vector<int> &nums1, const vector<int> &nums2)
{
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    unordered_set<int> unionSet = set1;
    for (int num : set2)
    {
        unionSet.insert(num);
    }

    unordered_set<int> intersectionSet;
    for (int num : set1)
    {
        if (set2.find(num) != set2.end())
        {
            intersectionSet.insert(num);
        }
    }

    return {unionSet, intersectionSet};
}

int main(void)
{
    /*
        Given two arrays, find their union and intersection.
        Example 1:
        Input: nums1 = [1,2,2,3], nums2 = [2,3,4]
        Output:
        Union: [1,2,3,4]
        Intersection: [2,3]
        Example 2:
        Input: nums1 = [1,1,1], nums2 = [1,
        Output:
        Union: [1]
        Intersection: [1]

        Union is the set of all distinct elements present in either array.
        Intersection is the set of elements present in both arrays.
    */

    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {2, 3, 4};
    auto result = unionAndIntersection(nums1, nums2);

    cout << "Union: ";
    for (int num : result.first)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Intersection: ";
    for (int num : result.second)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}