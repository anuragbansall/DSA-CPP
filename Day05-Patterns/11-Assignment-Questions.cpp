#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    /*
        Question 1: Print the 0-1 Triangle Pattern.
        For n = 5
        1
        01
        101
        0101
        10101
    */
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << flag << " ";
            flag = !flag;
        }
        cout << endl;
    }

    /*
        Question 2: Print the Rhombus Pattern.
        For n = 5
                * * * * *
              * * * * *
            * * * * *
          * * * * *
        * * * * *
    */
    for (int i = 1; i <= n; i++)
    {
        // Print spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }

        // Print stars
        for (int j = 1; j <= n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    /*
        Question 3: Print the Palindromic Pattern with Numbers.
        For n = 5
                1
              2 1 1
            3 2 1 2 3
          4 3 2 1 2 3 4
        5 4 3 2 1 2 3 4 5
    */

    for (int i = 1; i <= n; i++)
    {
        // print spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }

        // print numbers in decreasing order
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }

        // print numbers in increasing order
        for (int j = 2; j <= i; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}