#include <iostream>
using namespace std;

int power(int x, int n);

int main(void)
{
    int x, n;
    cout << "Enter two numbers: ";
    cin >> x >> n;

    cout << x << " raised to the power " << n << " is: " << power(x, n) << endl;

    return 0;
}

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    return x * power(x, n - 1);
}
// Time Complexity: O(n)

/*
    2^5 = 2 * 2^4
    2^4 = 2 * 2^3
    2^3 = 2 * 2^2
    2^2 = 2 * 2^1
    2^1 = 2 * 2^0
    2^0 = 1
*/