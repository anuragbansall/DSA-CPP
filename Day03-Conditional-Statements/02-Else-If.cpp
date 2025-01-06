#include <iostream>
using namespace std;

int main()
{
    // Income Tax Calculation:
    cout << "Income Tax Calculation:" << endl;
    float income, tax;
    cout << "Enter your income(in lakhs): ";
    cin >> income;

    if (income < 5)
    {
        tax = income * 0;
        cout << "Your tax is: 0%" << endl;
    }
    else if (income >= 5 && income < 10)
    {
        tax = income * 0.2;
        cout << "Your tax is: 20%" << endl;
    }
    else if (income >= 10)
    {
        tax = income * 0.3;
        cout << "Your tax is: 30%" << endl;
    }
    else
    {
        cout << "Invalid income range." << endl;
    }

    cout << "Your tax amount is: " << tax << " lakhs." << endl;

    // Print the largest of 3 Numbers:
    cout << "Print the largest of 3 Numbers:" << endl;
    int a, b, c;
    cout << "Enter 1st Number: ";
    cin >> a;
    cout << "Enter 2nd Number: ";
    cin >> b;
    cout << "Enter 3rd Number: ";
    cin >> c;

    if (a > b && a > c)
    {
        cout << "The largest number is: " << a << endl;
    }
    else if (b > c)
    {
        cout << "The largest number is: " << b << endl;
    }
    else
    {
        cout << "The largest number is: " << c << endl;
    }

    return 0;
}

/*
    Else-If Statement:
    - Else-If statement is used to execute a block of code when the condition is true.
    - If the first condition is false, then the code inside the else-if block will be executed.
    - The else-if block is optional.
    - Syntax:
        if (condition1)
        {
            // code to be executed if condition1 is true
        }
        else if (condition2)
        {
            // code to be executed if condition2 is true
        }
        else if (condition3)
        {
            // code to be executed if condition3 is true
        }
        .
        .
        .
        else
        {
            // code to be executed if all conditions are false
        }
    - Example:
        int age = 20;
        if (age < 18)
        {
            cout << "You are a minor." << endl;
        }
        else if (age >= 18 && age < 60)
        {
            cout << "You are an adult." << endl;
        }
        else
        {
            cout << "You are a senior citizen." << endl;
        }
*/