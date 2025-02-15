#include <iostream>
#include <climits>
using namespace std;

int trappingRainWater(int *arr, int n);

int main()
{
    int arr[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << trappingRainWater(arr, n) << endl;

    return 0;
}

int trappingRainWater(int *arr, int n)
{
    if (n < 3)
    {
        return 0;
    }

    int leftMax[20000], rightMax[20000];
    leftMax[0] = arr[0];
    rightMax[n - 1] = arr[n - 1];

    // Left max
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }

    // Right max
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    int totalWater = 0;
    for (int i = 0; i < n; i++)
    {
        int currWater = min(leftMax[i], rightMax[i]) - arr[i];
        if (currWater < 0)
        {
            currWater = 0;
        }
        totalWater += currWater;
    }

    return totalWater;
}
// Time Complexity: O(n+n+n) => O(3n) => O(n)