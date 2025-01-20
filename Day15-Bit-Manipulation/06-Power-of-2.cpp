#include <iostream>
using namespace std;

void isPowerOf2(int n);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    isPowerOf2(n);

    return 0;
}

void isPowerOf2(int n)
{
    if (n == 0)
    {
        cout << n << " is not a power of 2." << endl;
        return;
    }
    int bitMask = n - 1;
    if (!(n & bitMask))
    {
        cout << n << " is a power of 2." << endl;
    }
    else
    {
        cout << n << " is not a power of 2." << endl;
    }
}