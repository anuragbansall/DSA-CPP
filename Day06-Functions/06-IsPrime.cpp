#include <iostream>
#include <cmath>
using namespace std;

// WAF to check if a number is prime or not;
bool checkIsPrime(int num);

int main()
{
    cout << checkIsPrime(7) << endl;  // Output: 1 (true)
    cout << checkIsPrime(10) << endl; // Output: 0 (false)

    return 0;
}

bool checkIsPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }

    bool isPrime = true;
    for (int i = 2; i <= sqrt(num); i++) // we can also use (i * i <= num) instead of (i <= sqrt(num))
    {
        if (num % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}