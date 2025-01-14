#include <iostream>
#include <climits>
using namespace std;

int maxProfit(int *arr, int n);

int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProfit(arr, n) << endl;

    return 0;
}

int maxProfit(int *arr, int n)
{
    int bestBuyPrices[100000];
    bestBuyPrices[0] = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        bestBuyPrices[i] = min(bestBuyPrices[i - 1], arr[i - 1]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int currProfit = arr[i] - bestBuyPrices[i];
        maxProfit = max(maxProfit, currProfit);
    }

    return maxProfit;
}
// Time Complexity: O(n+n) => O(2n) => O(n)