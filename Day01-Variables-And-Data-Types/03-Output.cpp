#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;                     // Output: Hello World!
    cout << "Welcome to" << " C++ Programming" << endl; // Output: Welcome to C++ Programming

    return 0;
}

/*
    Output:
    - The output statement is used to display information on the screen.
    - The output statement in C++ is implemented using the cout object.
    - The cout object is defined in the iostream header file.
    - The insertion operator << is used to insert data into the cout object.
    - The endl manipulator is used to insert a newline character.
    - The output statement is terminated by a semicolon.
*/

/*
    How to Run CPP Code in Terminal?
    - Open your terminal or command prompt.
    - Navigate to the directory where your C++ code file is located.
    - Compile the code using the following command:
        g++ filename.cpp
            or
        g++ filename.cpp -o output_filename
    - Run the compiled executable:
        ./output_filename
    - You should see the output of your C++ program in the terminal.
*/