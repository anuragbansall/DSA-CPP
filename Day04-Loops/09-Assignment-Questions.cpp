#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    /*
        Question 1: WAP to find the Factorial of a number entered by the user.
        Hint: factorial of a number (n) = n * (n-1) * (n-2) * (n-3) * ...... * 1 and exists for positive numbers only.
        We write factorial as n! So, factorial of 0! = 1, 1! = 1, 2! = 2, 3! = 6, 4! = 24 and so on.
        Note - Please do not confuse factorial with NOT EQUAL TO operator, they are not the same.
    */

    cout << "Factorial of a number" << endl;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int fact = 1;

    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    cout << "Factorial of " << num << " is: " << fact << endl;

    /*
        Question 2: WAP to print the multiplication table of a number, entered by the user.
    */

    cout << "Multiplication Table of a number" << endl;
    int num2;
    cout << "Enter a number: ";
    cin >> num2;

    for (int i = 1; i <= 10; i++)
    {
        cout << num2 << " X " << i << " = " << num2 * i << endl;
    }

    /*
        Question 3: WAP to input a number and check whether the number is an Armstrong number or not.
        An Armstrong number is a number that is equal to the sum of cubes of its digits.
    */

    cout << "Armstrong Number" << endl;
    int num3;
    cout << "Enter a number: ";
    cin >> num3;
    int numCopy = num3;
    int sum = 0;
    while (numCopy > 0)
    {
        int lastDigit = numCopy % 10;
        numCopy /= 10;
        sum += lastDigit * lastDigit * lastDigit;
    }

    if (sum == num3)
    {
        cout << num3 << " is an Armstrong number." << endl;
    }
    else
    {
        cout << num3 << " is not an Armstrong number." << endl;
    }

    /*
        Question 4: For a positive N, WAP that prints all the prime numbers from 2 to N. (Assume N >= 2)
    */

    cout << "Prime Numbers from 2 to N" << endl;
    int num4;
    cout << "Enter a positive number: ";
    cin >> num4;

    for (int i = 2; i <= num4; i++)
    {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    /*
        Question 5: For a positive N, WAP that prints the first N Fibonacci numbers. (Assume N >= 2)
        Fibonacci series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34....
        This is a series where each number is a sum of previous 2 numbers in the series.
        Eg: 1 = 0 + 1, 2 = 1 + 1, 3 = 1 + 2, 5 = 2 + 3, 8 = 3 + 5 & so on.
    */

    cout << "First N Fibonacci numbers" << endl;
    int num5;
    cout << "Enter a positive number: ";
    cin >> num5;

    int a = 0, b = 1;
    cout << a << " " << b << " ";
    for (int i = 0; i < num5 - 2; i++)
    {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;

    return 0;
}