#include <iostream>
#include <climits>
using namespace std;

int maxSubarraySum(int *arr, int n);

int main()
{
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxSubarraySum(arr, n) << endl;

    return 0;
}

// Kadane's Algorithm
int maxSubarraySum(int *arr, int n)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxSum;
}
/*
    Time Complexity: O(n)
*/