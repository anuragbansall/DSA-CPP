#include <iostream>
using namespace std;

void countSetBits(int n);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    countSetBits(n);

    return 0;
}

void countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        int lastBit = n & 1;
        count += lastBit;
        n = n >> 1;
    }

    cout << "Number of set bits: " << count << endl;
}