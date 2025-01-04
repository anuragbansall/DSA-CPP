#include <iostream>  // Preprocessor directive to include input output stream header file
using namespace std; // Using standard namespace

#define PI 3.14159                   // Macro definition for PI
#define PRINT cout << "Hello World!" // Macro definition for printing Hello World!

int main() // Main function where program execution begins
{
    cout << PI << endl; // Output: 3.14159
    PRINT << endl;      // Output: Hello World!

    return 0;
}

/*
    Preprocessor Directives:
    - They are written in the form # followed by a directive keyword.
    - They are not terminated by a semicolon.
    - They are used to include header files, define macros, and conditional compilation.
    - They are processed by the preprocessor before the actual compilation of the code.
*/

/*
    Namespace:
    - A namespace is a scope that provides a way to group related names together.
    - It is useful when dealing with multiple libraries or when you want to avoid name conflicts.
    - The keyword namespace is used to declare a new namespace.
*/

/*
    Macro:
    - A macro is a fragment of code that has been given a name.
    - Whenever the name is used, it is replaced by the contents of the macro.
    - Macros are defined using the #define directive.
    - Macros are used to make the code more readable and maintainable.
    - Macros are processed by the preprocessor before the actual compilation of the code.
*/

/*
    Main Function:
    - The main function is the entry point of a C++ program.
    - It is declared with the keyword "int main()" and returns an integer value.
    - The main function is called by the operating system to start the program execution.
    - The return value of the main function is used to indicate the status of the program execution.
    - The main function can have parameters and return a value.
    - The main function is mandatory in every C++ program.
*/