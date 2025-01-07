#include <iostream>
using namespace std;

int main()
{
    // Print "Hello World" 5 times
    int count = 1;
    do
    {
        cout << "Hello World" << endl;
        count++;
    } while (count <= 5);

    return 0;
}

/*
    Do While Loop:
    - Do while loop is used to iterate a statement or a block of statements repeatedly until a certain condition becomes false.
    - Similar to while loop but it executes the loop block at least once before checking the condition.
    - The condition is checked at the end of each iteration.
    - Work gets done at least once irrespective of the condition.
    - Syntax:
        do
        {
            // code to be executed
        } while (condition);
    - Example:
        int i = 0;
        do
        {
            cout << i << endl;
            i++;
        } while (i < 5);
        // The above code will print the numbers from 0 to 4.

    // Note: Unlike while loop, do while loop will execute the loop block at least once before checking the condition.
*/