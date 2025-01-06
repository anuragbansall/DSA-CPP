#include <iostream>
using namespace std;

int main()
{
    // Calculator
    int num1, num2, result;
    char operator_symbol;
    cout << "Enter 1st Number: ";
    cin >> num1;
    cout << "Enter Operator (+, -, *, /): ";
    cin >> operator_symbol;
    cout << "Enter 2nd Number: ";
    cin >> num2;

    switch (operator_symbol)
    {
    case '+':
        result = num1 + num2;
        cout << result << endl;
        break;
    case '-':
        result = num1 - num2;
        cout << result << endl;
        break;
    case '*':
        result = num1 * num2;
        cout << result << endl;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
            cout << result << endl;
        }
        else
        {
            cout << "Error: Division by zero" << endl;
        }
        break;
    default:
        cout << "Error: Invalid operator" << endl;
    }

    return 0;
}