#include <iostream>
using namespace std;

int main()
{
    /*
        Print the square pattern using for loop:
        ****
        ****
        ****
        ****
    */
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // Print numbers from n to 1
    int num;
    cout << "Enter a number: ";
    cin >> num;

    for (int i = num; i >= 1; i--)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}