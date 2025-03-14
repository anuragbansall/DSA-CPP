#include <iostream>
#include <vector>
using namespace std;

// Optimized version of gridWays function
int gridWays(int n, int m);
int fact(int n);

int main(void)
{
    /*
        Find number of ways to reach from (0, 0) to (N-1, M-1) in a NxM grid.
        Allowed moves: Right, Down
    */

    int n = 3, m = 3;

    cout << gridWays(n, m) << endl;

    return 0;
}

int gridWays(int n, int m)
{
    return fact(n + m - 2) / (fact(n - 1) * fact(m - 1));
} // Time Complexity: O(N+M) and Space Complexity: O(1)

int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
} // Time Complexity: O(N) and Space Complexity: O(1)