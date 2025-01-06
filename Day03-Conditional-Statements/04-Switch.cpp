#include <iostream>
using namespace std;

int main()
{
    int day;
    cout << "Enter a day (1-7): ";
    cin >> day;

    switch (day)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;
    default:
        cout << "Invalid Day" << endl;
    }

    return 0;
}

/*
    Switch Statement:
    - Switch statement is used to select one of many code blocks to be executed based on a given condition.
    - The switch statement evaluates an expression and compares it with the values of the case labels.
    - If a match is found, the corresponding block of code is executed.
    - The break statement is used to exit the switch statement.
    - The default case is optional and is executed if no case matches the expression.
    - Syntax:
        switch (expression)
        {
            case value1:
                // code to be executed if expression is equal to value1
                break;
            case value2:
                // code to be executed if expression is equal to value2
                break;
            case value3:
                // code to be executed if expression is equal to value3
                break;
            .
            .
            .
            default:
                // code to be executed if no case matches the expression
        }
    - Example:
    int num = 5;
    switch (num)
    {
        case 1:
            cout << "One" << endl;
            break;
        case 2:
            cout << "Two" << endl;
            break;
        case 3:
            cout << "Three" << endl;
            break;
        case 4:
            cout << "Four" << endl;
            break;
        case 5:
            cout << "Five" << endl;
            break;
        default:
            cout << "Invalid Number" << endl;
    }
*/