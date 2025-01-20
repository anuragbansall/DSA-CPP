#include <iostream>
using namespace std;

void getIthBit(int n, int i);

int main()
{
    int n, i;
    cout << "Enter a number and an index: ";
    cin >> n >> i;
 
    getIthBit(n, i);

    return 0;
}

void getIthBit(int n, int i)
{
    int bitMask = 1 << i; // 1 is shifted i times to the left
    int bit = (n & bitMask) > 0 ? 1 : 0;

    cout << "The " << i << "th bit of " << n << " is: " << bit << endl;
}