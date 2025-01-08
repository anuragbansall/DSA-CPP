#include <iostream>
using namespace std;

int main()
{
    /*
        Draw Hollow Rectangle Pattern:
        * * * * *
        *       *
        *       *
        * * * * *
    */
    int n = 4;

    for (int i = 1; i <= n; i++)
    {
        cout << "* "; // First star of each row
        for (int j = 1; j <= n - 1; j++)
        {
            if (i > 1 && i < n) // Print spaces for rows other than the first and last rows
            {
                cout << "  ";
            }
            else // Print stars for the first and last rows
            {
                cout << "* ";
            }
        }
        cout << "* "; // Last star of each row
        cout << endl;
    }

    return 0;
}