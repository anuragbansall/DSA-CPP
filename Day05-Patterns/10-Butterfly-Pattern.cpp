#include <iostream>
using namespace std;

int main()
{
    /*
        Draw Butterfly Pattern:
        *             *
        * *         * *
        * * *     * * *
        * * * * * * * *
        * * * * * * * *
        * * *     * * *
        * *         * *
        *             *

    */
    int n = 4;

    // Upper part of the butterfly
    for (int i = 1; i <= n; i++)
    {
        // Print Stars
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }

        // Print Spaces
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << "  ";
        }

        // Print Stars
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Lower part of the butterfly
    for (int i = 1; i <= n; i++)
    {
        // Print Stars
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }

        // Print Spaces
        // 0 2 4 6
        for (int j = 1; j <= 2 * (i - 1); j++)
        {
            cout << "  ";
        }

        // Print Stars
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}