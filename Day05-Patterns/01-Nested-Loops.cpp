#include <iostream>
using namespace std;

int main()
{
    /*
        Draw this patter using loops:
        1111
        2222
        3333
        4444
    */
    int n = 4;
    // Outer loop to print rows
    for (int i = 1; i <= n; i++)
    {
        // Inner loop to print columns
        for (int j = 1; j <= n; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
    Nested Loops:
    - A loop inside another loop is called a nested loop.
    - The inner loop will be executed 'n' times for every iteration of the outer loop.
    - Nested loops can be used to print a pattern, calculate the sum of elements, or perform other complex tasks.
    - Pattern is a sequence of numbers or characters arranged in a specific order.
    - Syntax:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // code
            }
        }
        // The inner loop will be executed 'n' times for every iteration of the outer loop.
    - Example:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << i << " " << j << endl;
            }
        }
        // Output:
        // 0 0
        // 0 1
        // 0 2
        // 1 0
        // 1 1
        // 1 2
        // 2 0
        // 2 1
        // 2 2
*/