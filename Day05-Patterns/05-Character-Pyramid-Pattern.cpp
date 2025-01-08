#include <iostream>
using namespace std;

int main()
{
    /*
        Draw Character Pyramid Pattern:
        A
        B C
        D E F
        G H I J
    */
    int n = 10;
    char ch = 'A';

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
            ch++;         // Increment the character
            if (ch > 'Z') // If ch is greater than 'Z', reset it to 'A'
            {
                ch = 'A';
            }
        }
        cout << endl;
    }

    return 0;
}