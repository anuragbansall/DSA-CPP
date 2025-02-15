#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Check if a number is prime or not (optimized)
    int num;
    cout << "Enter a number: ";
    cin >> num;
    bool isPrime = true;

    for (int i = 2; i <= sqrt(num); i++) // Optimized to run until square root of num because factors repeat after square root of num
    {
        if (num % i == 0) // i is a factor of num; num is not a prime number
        {
            isPrime = false;
            break;
        }
    }

    if (isPrime)
    {
        cout << num << " is a prime number." << endl;
    }
    else
    {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}