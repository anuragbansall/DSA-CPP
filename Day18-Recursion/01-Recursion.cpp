#include <iostream>
using namespace std;

// Recursive function to print numbers from n to 1
void printN(int n)
{
    if (n == 0)
    {
        cout << endl;
        return;
    } // Base case

    cout << n << " ";

    printN(n - 1); // Recursive call
}

int main(void)
{
    int n = 5;
    printN(n);

    return 0;
}

/*
    Recursion:
    - A function that calls itself is called a recursive function.
    - Recursion is a programming technique where a function calls itself in certain conditions.
    - It is used to solve problems that can be broken down into smaller, repetitive problems.
    - Example:
    int factorial(int n)
    {
        if (n == 0)
            return 1;
        return n * factorial(n - 1);
    }
        // The above function calculates the factorial of a number using recursion. It calls itself for n-1 times until n becomes 0.

    Stack Overflow:
    - A stack overflow occurs when a program runs out of memory in the call stack.
    - It happens when a function calls itself infinitely.
*/