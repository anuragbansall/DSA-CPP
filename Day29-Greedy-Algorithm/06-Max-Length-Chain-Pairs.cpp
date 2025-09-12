#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    Maximum Length of Pair Chain:

    You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
    A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
    Return the length longest chain which can be formed.
    You do not need to use up all the given intervals. You can select pairs in any order.

    Example 1:

    Input: pairs = [[1,2],[2,3],[3,4]]
    Output: 2

    Approach:
    1. Sort the pairs based on the second element of each pair.
    2. Initialize a variable to keep track of the end of the last added pair in the chain.
    3. Iterate through the sorted pairs and for each pair, check if its first element is greater than the end of the last added pair.
    4. If it is, add this pair to the chain and update the end variable.
    5. Return the length of the chain.
*/

bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[1] < b[1];
}

int findLongestChain(vector<vector<int>> &pairs)
{
    // Sort pairs based on the second element of each pair
    sort(pairs.begin(), pairs.end(), compare);

    int chainLength = 0;
    int currentEnd = INT_MIN;

    for (const auto &pair : pairs)
    {
        if (pair[0] > currentEnd)
        {
            chainLength++;
            currentEnd = pair[1];
        }
    }

    return chainLength;
}

int main(void)
{
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};

    int result = findLongestChain(pairs); // |1,2| and |3,4| = 2
    cout << "Length of longest chain: " << result << endl;

    return 0;
}