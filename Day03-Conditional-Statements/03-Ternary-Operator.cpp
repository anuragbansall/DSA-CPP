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
    int largest = (a > b) ? a : b;
    cout << "The largest number is: " << largest << endl;

    return 0;
}

/*
    Ternary Operator:
    - Ternary operator is a conditional operator that returns a value based on a condition.
    - It is a shorthand for the if-else statement.
    - Syntax:
        variable = (condition) ? expression1 : expression2;
    - If the condition is true, then expression1 is evaluated and assigned to the variable else expression2 is evaluated and assigned to the variable.
    - Example:
        int age = 20;
        string result = (age >= 18) ? "You are an adult." : "You are a minor.";
        cout << result << endl; // Output: You are an adult.

*/