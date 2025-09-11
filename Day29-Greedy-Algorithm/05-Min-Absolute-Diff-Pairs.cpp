#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Minimum Absolute Difference Pairs:
    Pair elements of A & B to minimize the sum of absolute differences between pairs.

    A[n] = {1, 2, 3}
    B[n] = {2, 1, 3}

    Answer = |1-1| + |2-2| + |3-3| = 0

    Approach:
    1. Sort both arrays.
    2. Pair elements at same index.
    3. Calculate sum of absolute differences.
*/

int minAbsDiffPairs(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += abs(A[i] - B[i]);
    }

    return sum;
}

int main(void)
{
    vector<int> A = {1, 4, 2};
    vector<int> B = {3, 2, 1};

    int result = minAbsDiffPairs(A, B); // | 1-1 | + |2 - 2| + |4 - 3| = 1
    cout << "Minimum Absolute Difference: " << result << endl;

    return 0;
}