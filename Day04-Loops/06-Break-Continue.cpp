#include <iostream>
using namespace std;

int main()
{
    // WAP where user can keep entering numbers till they enter multiple of 10. Hint: Use break statement.
    cout << "Enter a multiple of 10 to exit the loop." << endl;
    int num;
    do
    {
        cout << "Enter a number: ";
        cin >> num;
        if (num % 10 == 0)
        {
            cout << "You entered a multiple of 10. Exiting the loop." << endl;
            break;
        }
        cout << "You entered: " << num << endl;
    } while (true);

    // WAP to show numbers entered by the user except multiples of 10. Hint: Use continue statement
    cout << "Show numbers entered by the user except multiples of 10." << endl;
    int num2;
    do
    {
        cout << "Enter a number: ";
        cin >> num2;
        if (num2 % 10 == 0)
        {
            continue;
        }
        cout << "You entered: " << num2 << endl;
    } while (true);

    return 0;
}

/*
    Break:
    - The break statement is used to terminate the loop immediately.
    - It is used to exit the loop prematurely.
    - Syntax:
        break;
    - Example:
        for (int i = 0; i < 5; i++)
        {
            if (i == 3)
            {
                break;
            }
            cout << i << endl;
        }
        // The above code will print the numbers 0, 1, 2 and then exit the loop when i becomes 3.

    Continue:
    - The continue statement is used to skip the current iteration of the loop and move to the next iteration.
    - Syntax:
        continue;
    - Example:
        for (int i = 0; i < 5; i++)
        {
            if (i == 3)
            {
                continue;
            }
            cout << i << endl;
        }
        // The above code will print the numbers 0, 1, 2, 4 and skip 3.
*/