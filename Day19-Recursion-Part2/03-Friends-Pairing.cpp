#include <iostream>
using namespace std;

int friendsPairing(int n);

int main(void)
{
    // Find the number of ways to pair n friends such that each friend can go alone or can pair up with any other friend

    int n;
    cout << "Enter the number of friends: ";
    cin >> n;

    cout << "Number of ways to pair " << n << " friends: " << friendsPairing(n) << endl;

    return 0;
}

int friendsPairing(int n)
{

    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }

    return friendsPairing(n - 1) + friendsPairing(n - 2) * (n - 1);
}

// friendsPairing(n-1) + friendsPairing(n-2) * (n-1) = Number of ways to pair n friends = Number of ways to pair (n-1) friends + Number of ways to pair (n-2) friends * (n-1) ways to pair the remaining friend with any of the n-1 friends