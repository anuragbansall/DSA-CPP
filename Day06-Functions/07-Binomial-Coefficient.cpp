#include <iostream>
using namespace std;

// WAF to find the binomial coefficient for given n & r.
int binomialCoefficient(int n, int r);
int factorial(int num);

int main()
{
    cout << binomialCoefficient(4, 2) << endl; // Output: 6
    cout << binomialCoefficient(5, 2) << endl; // Output: 10

    return 0;
}

int binomialCoefficient(int n, int r)
{
    int result = factorial(n) / (factorial(r) * factorial(n - r));
    return result;
}

int factorial(int num)
{
    int fact = 1;
    for (int i = 2; i <= num; i++)
    {
        fact *= i;
    }

    return fact;
}