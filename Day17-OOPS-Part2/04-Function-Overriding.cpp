#include <iostream>
using namespace std;

class Parent
{
public:
    void display()
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
    Parent p;
    Child c;

    p.display(); // Parent Display
    c.display(); // Child Display

    return 0;
}

/*
    Function Overriding is a feature that allows us to have a function in the derived class with the same name and signature as a function in the base class. In the above example, we have a Parent class with a display function and a Child class that inherits from the Parent class and overrides the display function. When we create objects of the Parent and Child classes and call the display function, the display function of the respective class is called. In the main function, we have created objects of the Parent and Child classes and called the display function on them. The display function of the Parent class is called for the Parent object, and the display function of the Child class is called for the Child object.
*/