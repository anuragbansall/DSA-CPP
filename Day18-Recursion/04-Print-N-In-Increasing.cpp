#include <iostream>
using namespace std;

// From 1 to n
void printN(int n);

int main(void)
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    printN(n); // Recursive function to print n in increasing order

    return 0;
}

void printN(int n)
{
    if (n == 0)
    {
        cout << endl;
        return;
    } // Base case

    printN(n - 1);
    cout << n << " ";
}