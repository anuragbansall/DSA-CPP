#include <iostream>
using namespace std;

// From n to 1
void printN(int n);

int main(void)
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    printN(n); // Recursive function to print n in decreasing order

    return 0;
}

void printN(int n)
{
    if (n == 0)
    {
        cout << endl;
        return;
    } // Base case

    cout << n << " ";

    printN(n - 1);
}