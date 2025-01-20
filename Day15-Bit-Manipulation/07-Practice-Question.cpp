#include <iostream>
using namespace std;

void updateIthBit(int n, int i, int val);
void clearLastIBits(int n, int i);

int main()
{
    /*
        WAF to update the ith bit in a number according to the given value(0 or 1).
        num = 7, i = 2, val = 0
        num = 7, i = 3, val = 1
    */
    int n, i, val;
    cout << "Enter a number, an index, and a value: ";
    cin >> n >> i >> val;

    updateIthBit(n, i, val);

    /*
        WAF to clear last i bits of a number.
        num = 15, i = 2
    */
    cout << "Enter a number and a value: ";
    cin >> n >> i;

    clearLastIBits(n, i);

    return 0;
}
void updateIthBit(int n, int i, int val)
{
    int bitMask = ~(1 << i);
    int clearedBit = n & bitMask;
    int result = clearedBit | (val << i);

    cout << "Update " << i << "th bit of " << n << " to " << val << ": " << result << endl;
}

void clearLastIBits(int n, int i)
{
    int bitMask = ~0 << i;
    int result = n & bitMask;

    cout << "Clear last " << i << " bits of " << n << ": " << result << endl;
}