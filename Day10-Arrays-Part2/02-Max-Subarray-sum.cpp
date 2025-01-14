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

// Brute force
int maxSubarraySum(int *arr, int n)
{
    int maxSum = INT_MIN;
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int sum = 0;
            for (int i = start; i <= end; i++)
            {
                sum += arr[i];
            }
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}