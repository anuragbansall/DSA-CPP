#include <iostream>
using namespace std;

// Function declaration and definition
void sayHello()
{
    cout << "Hello, World!" << endl;
}

// Forward declaration/Function prototype
void sayGoodbye();

int main()
{
    sayHello();   // Call the sayHello function
    sayGoodbye(); // Call the sayGoodbye function

    return 0;
}

// Function definition
void sayGoodbye()
{
    cout << "Goodbye, World!" << endl;
}

/*
    Functions:
    - A function is a block of code that performs a specific task.
    - It is used to break down a program into smaller, more manageable parts.
    - Functions have a name, parameters, and a return type.
    - Functions can be defined inside or outside the main function.
    - Syntax:
        return_type function_name(parameters)
        {
            // code
        }
    - Example:
        int add(int a, int b)
        {
            return a + b;
        }
        // It returns the sum of two numbers.

    Function Call:
    - A function call is the execution of a function by passing arguments to it.
    - Function call uses stack memory to store the return address and local variables.
    - Stack memory is a temporary memory that is used to store function call information.
    - Stack frames are created for each function call.
    - Syntax:
        function_name(arguments);
    - Example:
        int sum = add(5, 3);
        // It calls the add function with the arguments 5 and 3 and stores the result in the sum variable.
        cout << "Sum: " << sum << endl; // Output: Sum: 8

    Forward Declaration:
    - A forward declaration is a declaration that specifies the name of a function but does not provide its implementation.
    - It is used to inform the compiler about the existence of a function before it is used.
    - Syntax:
        return_type function_name(parameters);
    - Example:
        int add(int a, int b); // Forward declaration/Function prototype
        // It declares the add function with the specified parameters and return type.

        // The implementation of the add function can be provided later in the code.
        int add(int a, int b) // Function definition
        {
            return a + b;
        }

*/