#include <iostream>
using namespace std;

// WAF to print all prime numbers in a given range from 2 to n
bool isPrime(int num);
void printPrimes(int n);

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    printPrimes(n); // Function call to print prime numbers in the given range

    return 0;
}

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

void printPrimes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}