#include <iostream>
using namespace std;

// Optimized version of x raised to the power n
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

    int temp = power(x, n / 2);
    int result = temp * temp;

    if (n % 2 == 0)
    {
        return result;
    }
    else
    {
        return x * result;
    }
}
// Time Complexity: O(log(n))

/*
    If n is even:
        x^n = x^(n/2) * x^(n/2)
    If n is odd:
        x^n = x * x^(n/2) * x^(n/2)
*/