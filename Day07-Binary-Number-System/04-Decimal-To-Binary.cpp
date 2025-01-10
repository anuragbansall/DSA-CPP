#include <iostream>
using namespace std;

// Function to convert binary to decimal
int decimalToBinary(int decimalNumber);

int main()
{
    // Decimal to Binary Conversion Code
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;
    int binaryNumber = decimalToBinary(decimalNumber);
    cout << "Binary representation: " << binaryNumber << endl;

    return 0;
}

int decimalToBinary(int decimalNumber)
{
    int binaryNumber = 0;
    int pow = 1;

    while (decimalNumber > 0)
    {
        int remainder = decimalNumber % 2;
        decimalNumber /= 2;
        binaryNumber += remainder * pow;
        pow *= 10;
    }

    return binaryNumber;
}