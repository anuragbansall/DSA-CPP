#include <iostream>
using namespace std;

// WAF to find the factorial of a number
int factorial(int num);

int main()
{
    cout << factorial(5) << endl; // Output: 120

    return 0;
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