#include <iostream>
using namespace std;

int tileFloor(int n);

int main(void)
{
    // Count total number of ways to tile a floor of size 2 x n using 2 x 1 tiles
    int n;
    cout << "Enter the size of the floor (in terms of number of 2 x 1 tiles): ";
    cin >> n;

    cout << "Total number of ways to tile the floor of size 2 x " << n << " using 2 x 1 tiles: " << tileFloor(n) << endl;

    return 0;
}
int tileFloor(int n) // 2 x n
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return tileFloor(n - 1) + tileFloor(n - 2); // Number of ways to tile (n-1) x n floor = Number of ways to tile (n-2) x n floor + Number of ways to tile (n-1) x (n-1) floor
}