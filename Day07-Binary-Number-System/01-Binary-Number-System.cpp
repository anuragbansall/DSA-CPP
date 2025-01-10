#include <iostream>
using namespace std;

int main()
{

    return 0;
}

/*
    Binary Number System:
    - A number system that uses only two digits, 0 and 1, to represent numbers.
    - Bi means 2, so it is called a binary number system.
    - The base of the binary number system is 2.
    - In binary, the position of each digit (from right to left) represents a power of 2.
    - For example, the binary number 1010 represents the decimal number 10.
    - Like decimal numbers, binary numbers can be added, subtracted, multiplied, and divided.

    Binary to Decimal Conversion:
    - To convert a binary number to decimal, we multiply each digit by its respective power of 2 and then sum up the results.
    - For example, the binary number 1010 is equivalent to (1 * 2^3) + (0 * 2^2) + (1 * 2^1) + (0 * 2^0) = 8 + 0 + 2 + 0 = 10.
    - In binary to decimal conversion, the power of 2 starts from 0 (for the least significant bit) and goes up to the number of bits in the binary number.

    Decimal to Binary Conversion:
    - To convert a decimal number to binary, we divide the number by 2 repeatedly until the result is 0.
    - For each division, we take the remainder (which is the least significant bit) and write it to the left of the binary number.
    - Then, we divide the quotient by 2 and repeat the process.
    - The process stops when the quotient is 0.
    - For example, to convert the decimal number 10 to binary:
        10 / 2 = 5, remainder = 0
        5 / 2 = 2, remainder = 1
        2 / 2 = 1, remainder = 0
        1 / 2 = 0, remainder = 1
        The binary number is 1010.
*/