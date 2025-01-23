#include <iostream>
using namespace std;

class Parent
{
public:
    // Virtual function (overriding the base class function)
    virtual void display()
    {
        cout << "Parent Display" << endl;
    }
};

class Child : public Parent
{
public:
    // Overriding the display() function
    void display()
    {
        cout << "Child Display" << endl;
    }
};

int main()
{
    Child c;
    Parent *ptr = &c; // Pointer of Parent class pointing to Child object

    ptr->display(); // Child Display (Virtual function is called based on the object type)

    return 0;
}

/*
    Virtual Function is a function that is declared in the base class using the virtual keyword and is overridden in the derived class. When a virtual function is called using a pointer or reference to the base class, the function call is resolved at runtime based on the actual object type rather than the pointer or reference type. In the above example, we have a Parent class with a virtual display function and a Child class that overrides the display function. When we create a Child object and a pointer of the Parent class pointing to the Child object, and call the display function using the pointer, the display function of the Child class is called. This is because the display function is declared as virtual in the base class, and the function call is resolved at runtime based on the actual object type.
*/