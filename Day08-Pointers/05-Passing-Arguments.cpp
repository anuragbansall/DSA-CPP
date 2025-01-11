#include <iostream>
using namespace std;

void changeValueByValue(int a)
{
    a = a + 10;
    cout << "Inside changeValueByValue function: a = " << a << endl;
}

void changeValueByReference(int &a)
{
    a += 10;
    cout << "Inside changeValueByReference function: a = " << a << endl;
}

void changeValueByPointer(int *a)
{
    *a += 10;
    cout << "Inside changeValueByPointer function: a = " << *a << endl;
}

int main()
{
    int num = 10;
    cout << "Before calling the function changeValueByValue(): num = " << num << endl;
    changeValueByValue(num);
    cout << "After calling the function changeValueByValue(): num = " << num << endl;

    cout << endl;

    cout << "Before calling the function changeValueByReference(): num = " << num << endl;
    changeValueByReference(num);
    cout << "After calling the function changeValueByReference(): num = " << num << endl;

    cout << endl;

    cout << "Before calling the function changeValueByPointer(): num = " << num << endl;
    changeValueByPointer(&num);
    cout << "After calling the function changeValueByPointer(): num = " << num << endl;

    return 0;
}

/*
    Passing Arguments to Functions:
        Passing by Value:
        - In C++, when we pass arguments to a function, the default behavior is to pass by value.
        - When a function receives an argument by value, a copy of the argument is created in the function's stack frame.
        - Changes made to the copy inside the function will not affect the original argument.
        - Example:
            int add(int a, int b) {
                a = a + 10;
                return a + b;
            }
        // Here, a and b are passed by value. Any changes made to a and b inside the function will not affect the original arguments.

        Passing by Reference:
        - To modify the original arguments inside a function, we can pass the arguments by reference.
        - When a function receives an argument by reference, it can directly access and modify the original argument.
        - To pass an argument by reference, we use the reference operator (&) in the function definition.
        - We can also pass pointers to functions to achieve the same effect.
        - Example:
            void add(int &a, int &b) {
                a = a + 10;
                b = b + 20;
            }
            // Here, a and b are passed by reference. Any changes made to a and b inside the function will affect the original arguments.
*/