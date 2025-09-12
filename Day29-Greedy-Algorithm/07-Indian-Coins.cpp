#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Indian Coins:
    We are given an Infinity supply of denominations [1, 2, 5, 10, 20, 50, 100, 200, 500, 2000].

    Find the minimum number of coins to make a change for 'N' rupees.

    Example 1:
    Input: N = 121
    Output: 3
    Explanation: 3 coins of denominations [100, 20, 1] are needed to make 121.

    Approach:
    1. Sort the denominations in descending order.
    2. Start from the largest denomination and keep subtracting it from N until N becomes less than that denomination.
    3. Move to the next smaller denomination and repeat step 2.
    4. Keep a count of the number of coins used.
    5. Return the count when N becomes 0.
*/

int minCoins(int N)
{
    vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int count = 0;

    for (int coin : denominations)
    {
        int numCoins = N / coin; // Number of coins of this denomination
        count += numCoins;       // Add to the total count
        N -= numCoins * coin;    // Reduce N by the total value of these coins
    }

    return count;
}

int main(void)
{
    int N = 121;

    int result = minCoins(N); // 100 + 20 + 1 = 3 coins
    cout << "Minimum number of coins: " << result << endl;

    return 0;
}