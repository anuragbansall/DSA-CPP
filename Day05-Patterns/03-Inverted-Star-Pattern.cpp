#include <iostream>
using namespace std;

int main()
{
    /*
        Draw Inverted Star Pattern:
        * * * *
        * * *
        * *
        *
    */
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++) // (n - i + 1) is the key to this pattern
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}