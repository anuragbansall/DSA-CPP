#include <iostream>
using namespace std;

void clearIthBit(int n, int i);

int main()
{
    int n, i;
    cout << "Enter a number and an index: ";
    cin >> n >> i;

    clearIthBit(n, i);

    return 0;
}

void clearIthBit(int n, int i)
{
    int bitMask = ~(1 << i);
    int result = n & bitMask;

    cout << "Clear " << i << "th bit of " << n << ": " << result << endl;
}