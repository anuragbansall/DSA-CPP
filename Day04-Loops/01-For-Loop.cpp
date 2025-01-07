#include <iostream>
using namespace std;

int main()
{
    // Print "Hello World" 5 times
    for (int i = 1; i <= 5; i++)
    {
        cout << "Hello World\n";
    }

    // Print numbers from 1 to n and calculate the sum
    int n, sum = 0;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
        sum += i;
    }
    cout << "\nSum of numbers from 1 to " << n << " is: " << sum << endl;

    return 0;
}

/*
    For Loop:
    - For loop is used to iterate a statement or a block of statements repeatedly for a fixed number of times.
    - It is used when the number of iterations is known.
    - The initialization is done only once at the beginning of the loop.
    - The condition is checked at the beginning of each iteration.
    - Loop runs until the condition is true.
    - The increment/decrement is done at the end of each iteration.
    - Infinite loop: If the condition is always true, then the loop will run infinitely.
    - Some terminologies:
        - Iterate: To repeat a process multiple times.
        - Iteration: Each repetition of the process.
        - Iterator: A variable that is used to iterate.
    - The syntax of the for loop is:
        for (initialization; condition; increment/decrement)
        {
            // code to be executed
        }
    - Example:
        for (int i = 0; i < 5; i++)
        {
            cout << i << endl;
        }
        - The above code will print the numbers from 0 to 4.

*/