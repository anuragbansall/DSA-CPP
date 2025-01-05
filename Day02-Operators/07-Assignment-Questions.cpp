#include <iostream>
using namespace std;

int main()
{
    /*
        Question 1: What’ll be the output of the following programs:
        A.
        int main() {
            int x = 2, y = 5;
            int exp1 = (x * y / x); // 5
            int exp2 = (x * (y / x)); // 4
            cout << exp1 << ",";
            cout << exp2 << "\n";
        }
        Output: 5,4

        B.
        int main() {
            int x = 10, y = 5;
            int exp1 = (y * (x / y + x / y)); // 5 * (2 + 2) = 20
            int exp2 = (y * x / y + y * x / y); // 10 + 10 = 20
            cout << exp1 << ",";
            cout << exp2 << "\n";
        }
        Output: 20,20

        C.
        int main() {
            int x = 200, y = 50, z = 100;
            if (x > y && y > z) { // false
                cout << "Hello\n";
            }
            if (z > y && z < x) { // true
                cout << "C++\n";
            }
            if ((y + 200) < x && (y + 150) < z) { // false
                cout << "Hello C++\n";
            }
        }
        Output: C++
    */

    /*
        Question 2: Read up about Operator Precedence. When multiple operators are used in a single statement, it is operator precedence which decides which operation is performed first & so on. (Similar to the rule of BODMAS used in math)
        Note: Some of the operators mentioned in the table will be covered in later lectures.

        Operator Precedence:
        // Higher to Lower
        ( )      // Brackets
        ++, --   // Increment, Decrement
        ^        // Exponentiation
        *, /, % // Multiplication, Division, Modulus
        +, -     // Addition, Subtraction
        ==,!=, <, >, <=, >= // Comparison
        &&       // Logical AND
        ||       // Logical OR
        !        // Logical NOT
        =        // Assignment
    */

    return 0;
}