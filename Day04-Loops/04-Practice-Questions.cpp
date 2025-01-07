#include <iostream>
using namespace std;

int main()
{
    // Print the sum of digits, sum of odd digits and reverse of a number using while loop
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int sum = 0;
    int oddSum = 0;
    int reverse = 0;
    int numCopy = num;

    while (numCopy > 0)
    {
        int lastDigit = numCopy % 10;
        numCopy /= 10; // Remove the last digit from the number to get the next digit
        if (lastDigit % 2 != 0)
        {
            oddSum += lastDigit;
        }
        sum += lastDigit;
        reverse = reverse * 10 + lastDigit;
    }
    cout << "Sum of digits: " << sum << endl;
    cout << "Sum of odd digits: " << oddSum << endl;
    cout << "Reverse of the number: " << reverse << endl;

    return 0;
}