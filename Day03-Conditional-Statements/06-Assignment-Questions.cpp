#include <iostream>
using namespace std;

int main()
{
    // Question 1: Write a C++ program to get a number from the user and print whether it's positive, negative or zero.
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (number > 0)
    {
        cout << number << " is a positive number." << endl;
    }
    else if (number < 0)
    {
        cout << number << " is a negative number." << endl;
    }
    else
    {
        cout << number << " is zero." << endl;
    }

    // Question 2: Write a C++ program that takes a year from the user and print whether that year is a leap year or not.
    // Hint: A leap year is exactly divisible by 4 except for century years (years ending with 00). The century year is a leap year only if it is perfectly divisible by 400.
    // Eg: 1999 is not a leap year, 2000 is a leap year, 2004 is a leap year
    int year;
    cout << "Enter a year: ";
    cin >> year;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        cout << year << " is a leap year." << endl;
    }
    else
    {
        cout << year << " is not a leap year." << endl;
    }

    // Question 3: What will be the value of x & y in the following program:
    // int main() {
    //     int a = 63, b = 36;
    //     bool x = (a < b) ? true : false; // false
    //     int y = (a > b) ? a : b; // 63
    //     cout << x << "," << y << endl;
    //     return 0;
    // }
    // Output: 0(false),63

    // Question 4: What’ll be the output of the program:
    // int main() {
    //     int a = 5;
    //     if (++a * 5 <= 25) {
    //         cout << "Hello\n";
    //     } else {
    //         cout << "Bye\n";
    //     }
    //     return 0;
    // }
    // Output: Bye

    // Question 5: For any 3 digit number check whether it’s an Armstrong number or not.
    // Armstrong number is a number that is equal to the sum of cubes of its digits.
    // Eg: 371 is an armstrong number. 3*3*3 + 7*7*7 + 1*1*1 = 371
    int threeDigitNumber;
    cout << "Enter a 3-digit number: ";
    cin >> threeDigitNumber;

    int copyThreeDigitNumber = threeDigitNumber;
    int cubeSum = 0;

    int cube1 = copyThreeDigitNumber % 10;
    copyThreeDigitNumber /= 10;
    int cube2 = copyThreeDigitNumber % 10;
    copyThreeDigitNumber /= 10;
    int cube3 = copyThreeDigitNumber % 10;

    cubeSum = cube1 * cube1 * cube1 + cube2 * cube2 * cube2 + cube3 * cube3 * cube3;
    if (cubeSum == threeDigitNumber)
    {
        cout << threeDigitNumber << " is an Armstrong number." << endl;
    }
    else
    {
        cout << threeDigitNumber << " is not an Armstrong number." << endl;
    }

    // Bonus: Read up about the difference between typedef (keyword), macros & const (keyword) in C++.
    /* Answer:
        - `typedef` keyword in C++ is used for aliasing existing data types, user-defined data types, and pointers to a more meaningful name.
        Eg: typedef int myInt;
        This allows us to declare new integers using myInt, instead of int.

        - Macros can be of any type. Macros can even be any code block containing statements, loops, function calls, etc.
        They are expanded by the preprocessor before compilation takes place.

        - `const` keyword is used to define the constant value that cannot be changed during program execution.
     */

    return 0;
}