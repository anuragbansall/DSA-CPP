#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    while (i <= 5)
    {
        cout << i << " ";
        i++;
    }
    cout << endl;

    return 0;
}

/*
    While Loop:
    - While loop is used to iterate a statement or a block of statements repeatedly until a certain condition becomes false.
    - It is used when the number of iterations is unknown.
    - The condition is checked at the beginning of each iteration.
    - Syntax:
        while (condition)
        {
            // code to be executed
        }
    - Example:
        int i = 0;
        while (i < 5)
        {
            cout << i << endl;
            i++;
        }
        // The above code will print the numbers from 0 to 4.
*/