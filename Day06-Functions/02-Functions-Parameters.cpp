#include <iostream>
using namespace std;

int sum(int a, int b = 5); // a and b are parameters; b has a default value of 5

int main()
{
    int x = 5, y = 3;
    int ans1 = sum(x, y); // x and y are arguments
    int ans2 = sum(x);    // x is an argument, y will be 5 by default (default parameter)
    cout << ans1 << endl; // Output: 8
    cout << ans2 << endl; // Output: 10

    return 0;
}

int sum(int a, int b) // Function definition
{
    int sum = a + b;

    return sum;
}

/*
    Function Parameters:
    - Parameters are variables that are used to pass values to a function.
    - They are declared inside the parentheses of the function definition.
    - Parameters are separated by commas.
    - Example:
        void printMessage(string message)
        {
            cout << message << endl;
        }
        // It takes a string parameter and prints it.

    Default Parameters:
    - Default parameters are used to provide a default value for a parameter.
    - If a value is not passed for a parameter, the default value is used.
    - Default parameters are specified in the function declaration.
    - Example:
        void printMessage(string message = "Hello, World!")
        {
            cout << message << endl;
        }
        // It takes a string parameter with a default value of "Hello, World!". If no value is passed, it will print "Hello, World!".
        printMessage(); // Output: Hello, World!
        printMessage("Goodbye!"); // Output: Goodbye!

    Function Arguments:
    - Function arguments are the actual values that are passed to a function when it is called.
    - They are specified inside the parentheses of the function call.
    - Example:
        printMessage("Hello, World!");
        // It calls the printMessage function with the argument "Hello, World!". The message parameter will be assigned this value.
*/