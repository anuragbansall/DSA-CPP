#include <iostream>
using namespace std;

int globalVariable = 10; // Global variable accessible throughout the program

void func(); // Function declaration

int main()
{
    int localVariable = 20; // Local variable only accessible within the main function

    cout << "Inside main function:" << endl;
    cout << "Local Variable: " << localVariable << endl;   // Output: 20
    cout << "Global Variable: " << globalVariable << endl; // Output: 10

    func(); // Calling the function to demonstrate scope
    return 0;
}

// Function to demonstrate scope
void func()
{
    cout << "\nInside func function:" << endl;
    cout << "Global Variable: " << globalVariable << endl; // Output: 10
    // cout << "Local Variable: " << localVariable << endl;
    // The above line will cause an error: 'localVariable' was not declared in this scope
}

/*
    Scope Explanation:
    1. Local Scope:
    - Variables declared inside a function, block, or loop have a local scope.
    - These variables are only accessible within the block in which they are declared.
    - They are created when the block is entered and destroyed when the block ends.

    Example:
    void exampleFunction() {
        int localVariable = 10; // Local to this function
        cout << localVariable << endl; // Output: 10
    }
    // localVariable is not accessible outside exampleFunction.

    2. Global Scope:
    - Variables declared outside any function, block, or loop have a global scope.
    - These variables can be accessed from anywhere in the program.
    - Global variables persist throughout the lifetime of the program.

    Example:
    int globalVariable = 10; // Global variable
    void anotherFunction() {
        cout << globalVariable << endl; // Output: 10
   }
*/
