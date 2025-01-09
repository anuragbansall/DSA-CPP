#include <iostream>
using namespace std;

// Function Overloading Example

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    cout << add(10, 20) << endl;     // Output: 30
    cout << add(10.5, 20.7) << endl; // Output: 31.2
    cout << add(10, 20, 30) << endl; // Output: 60
    // The add function is overloaded with different parameter types. When calling the add function, we can pass different data types to achieve different behavior.

    return 0;
}

/*
    Function Overloading:
    When multiple functions have the same name but different parameters,
    they are considered function overloading.
    - The functions must have different parameter lists.
    - The return type can be different or the same.
    - Function overloading enables us to define multiple functions with the same name but different behavior based on the input parameters.
    Example:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
    // The add function is overloaded with different parameter types.
    // When calling the add function, we can pass different data types to achieve different behavior.
    // For example:
    // cout << add(10, 20) << endl; // Output: 30
    // cout << add(10.5, 20.7) << endl; // Output: 31.2
*/