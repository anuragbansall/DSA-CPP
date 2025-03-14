#include <iostream>
#include <vector>
using namespace std;

int gridWays(int n, int m);

int main(void)
{
    /*
        Find number of ways to reach from (0, 0) to (N-1, M-1) in a NxM grid.
        Allowed moves: Right, Down
    */

    int n = 4, m = 4;

    cout << gridWays(n, m) << endl;

    return 0;
}

int gridWays(int n, int m)
{
    if (n == 1 || m == 1)
    {
        return 1;
    }

    return gridWays(n - 1, m) + gridWays(n, m - 1); // Right, Down
} // Time Complexity: O(2^(N+M)) and Space Complexity: O(N+M) 