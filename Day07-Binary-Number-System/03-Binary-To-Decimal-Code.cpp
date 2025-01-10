#include <iostream>
using namespace std;

// Function to convert binary to decimal
int binaryToDecimal(int binaryNumber);

int main()
{
    // Binary to Decimal Conversion Code
    int binaryNumber;
    cout << "Enter a binary number: ";
    cin >> binaryNumber;
    int decimalNumber = binaryToDecimal(binaryNumber);
    cout << "Decimal representation: " << decimalNumber << endl;

    return 0;
}

int binaryToDecimal(int binaryNumber)
{
    int decimalNumber = 0;
    int pow = 1;

    while (binaryNumber > 0)
    {
        int lastDigit = binaryNumber % 10;
        binaryNumber /= 10;
        if (lastDigit == 1)
        {
            decimalNumber += lastDigit * pow;
        }
        else if (lastDigit != 0)
        {
            cout << "Invalid binary number!" << endl;
            return 0;
        }
        pow *= 2;
    }

    return decimalNumber;
}

/*
    1010 => 1^3 + 0^2 + 1^1 + 0^0 = 10
*/