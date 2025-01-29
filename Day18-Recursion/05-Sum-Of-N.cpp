#include <iostream>
using namespace std;

int sumOfN(int n);

int main(void)
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Sum of first " << n << " natural numbers is: " << sumOfN(n) << endl;

    return 0;
}

int sumOfN(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int sum = n + sumOfN(n - 1);

    return sum;
}