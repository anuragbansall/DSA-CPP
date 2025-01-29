#include <iostream>
using namespace std;

int nthFibonacci(int n);

int main(void)
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "The " << n << "th Fibonacci number is: " << nthFibonacci(n) << endl;

    return 0;
}

int nthFibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}