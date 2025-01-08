#include <iostream>
using namespace std;

int main()
{
    /*
        Draw Diamond Pattern:
              *
            * * *
          * * * * *
        * * * * * * *
        * * * * * * *
          * * * * *
            * * *
              *
    */
    int n = 4;

    // Upper part of the diamond
    for (int i = 1; i <= n; i++)
    {
        // Print spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }

        // Print stars
        for (int j = 1; j <= 2 * i - 1; j++) // (2 * i - 1) is the key to this pattern
        {
            cout << "* ";
        }
        cout << endl;
    }

    // lower part of the diamond
    for (int i = 1; i <= n; i++)
    {
        // Print spaces
        for (int j = 1; j <= i - 1; j++)
        {
            cout << "  ";
        }

        // Print stars
        for (int j = 1; j < 2 * (n - i + 1); j++) // (2 * (n - i + 1)) is the key to this pattern
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}