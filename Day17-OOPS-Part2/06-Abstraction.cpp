#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0; // Pure Virtual Function
};

class Circle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing Rectangle" << endl;
    }
};

int main()
{
    // Shape s; // Error: Cannot instantiate abstract class

    Circle c;
    c.draw();

    Rectangle r;
    r.draw();

    return 0;
}

/*
    Abstraction:
    - Abstraction is the concept of hiding the internal details and showing only the necessary features of an object.
    - In C++, classes provide great level of abstraction.
    - Abstraction is achieved using access specifiers (public, private, protected).
    - It can be also achieved by using abstract classes and pure virtual functions.

    Abstract Class:
    - Abstract class is a class that has atleast one pure virtual function.
    - Abstract class cannot be instantiated.
    - Abstract class can have normal functions, constructors, destructors, data members etc.
    - It acts as a blueprint for derived classes.
    - Syntax:
        class AbstractClass
        {
            public:
                virtual void fun() = 0;
        };

    Pure Virtual Function:
    - A pure virtual function is a virtual function that does not have a definition in the base class.
    - It is declared using the "= 0" syntax.
    - Pure virtual functions are useful when a class has some methods that need to be implemented in derived classes but not yet provided.
    - Example:
        class Animal
        {
            public:
                virtual void makeSound() = 0; // Pure Virtual Function
        };
*/