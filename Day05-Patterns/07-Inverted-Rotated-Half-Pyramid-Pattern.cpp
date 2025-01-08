#include <iostream>
using namespace std;

int main()
{
    /*
        Draw Inverted & Rotated Half Pyramid Pattern:
              *
            * *
          * * *
        * * * *
    */
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        // Print spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }

        // Print stars
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}