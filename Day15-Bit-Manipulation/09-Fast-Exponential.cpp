#include <iostream>
using namespace std;

void fastExpo(int x, int n);

int main()
{
    int x, n;
    cout << "Enter a number and its power: ";
    cin >> x >> n;

    fastExpo(x, n);

    return 0;
}

void fastExpo(int x, int n)
{
    int result = 1;
    while (n > 0)
    {
        int lastBit = n & 1;
        if (lastBit)
        {
            result *= x;
        }
        x *= x;
        n = n >> 1;
    }

    cout << "Result: " << result << endl;
}