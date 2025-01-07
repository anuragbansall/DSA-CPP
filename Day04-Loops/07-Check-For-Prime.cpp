#include <iostream>
using namespace std;

int main()
{
    // Check if a number is prime or not
    int num;
    cout << "Enter a number: ";
    cin >> num;
    bool isPrime = true;

    for (int i = 2; i < num; i++)
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