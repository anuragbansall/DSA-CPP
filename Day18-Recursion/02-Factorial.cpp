#include <iostream>
using namespace std;

int factorial(int n);

int main(void)
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial of " << n << " is " << factorial(n) << endl;

    return 0;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}