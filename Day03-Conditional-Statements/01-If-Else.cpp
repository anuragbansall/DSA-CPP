#include <iostream>
using namespace std;

int main()
{
    // Print the largest of 2 Numbers:
    cout << "Print the largest of 2 Numbers:" << endl;
    int a, b;
    cout << "Enter 1st Number: ";
    cin >> a;
    cout << "Enter 2nd Number: ";
    cin >> b;

    if (a > b)
    {
        cout << a << " is greater than " << b << endl;
    }
    else
    {
        cout << b << " is greater than " << a << endl;
    }

    // Print if a number is even or odd:
    cout << "Print if a number is even or odd:" << endl;
    int num;
    cout << "Enter a Number: ";
    cin >> num;

    if (num % 2 == 0)
    {
        cout << num << " is an even number." << endl;
    }
    else
    {
        cout << num << " is an odd number." << endl;
    }

    return 0;
}

/*
    If-Else Statement:
    - If-Else statement is used to execute a block of code when the condition is true.
    - If the condition is false, then the code inside the else block will be executed.
    - The else block is optional.
    - The condition is any expression that returns a boolean value.
    - Syntax:
        if (condition)
        {
            // code to be executed if the condition is true
        }
        else
        {
            // code to be executed if the condition is false
        }
    - Example:
        int age = 20;
        if (age >= 18)
        {
            cout << "You are an adult." << endl;
        }
        else
        {
            cout << "You are a child." << endl;
        }
        - The above code will print "You are an adult." because the age is greater than or equal to 18.
*/