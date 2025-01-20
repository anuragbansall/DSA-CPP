#include <iostream>
using namespace std;

void setIthBit(int n, int i);

int main()
{
    int n, i;
    cout << "Enter a number and an index: ";
    cin >> n >> i;

    setIthBit(n, i);

    return 0;
}

void setIthBit(int n, int i)
{
    int bitMask = 1 << i;
    int result = n | bitMask;

    cout << "Set " << i << "th bit of " << n << " to 1: " << result << endl;
}