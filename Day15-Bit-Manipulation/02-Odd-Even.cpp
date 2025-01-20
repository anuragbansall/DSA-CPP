#include <iostream>
using namespace std;

void oddEven(int n);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    oddEven(n);

    return 0;
}

void oddEven(int n)
{
    int bitMask = 1;
    if (n & bitMask)
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
}