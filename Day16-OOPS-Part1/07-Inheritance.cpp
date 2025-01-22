#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    string name;
    string color;

    void eat()
    {
        cout << name << " is eating" << endl;
    }
};

class Dog : public Animal // Dog class inheriting from Animal class
{
public:
    void bark()
    {
        cout << name << " is barking" << endl;
    }
};

int main()
{
    Dog d1;
    d1.name = "Tommy";
    d1.color = "Brown";
    d1.eat();
    d1.bark();

    return 0;
}

/*
    Inheritance:
    - Inheritance is a mechanism in which one class acquires the properties and behavior of another class.
    - The class that inherits the properties and behavior is known as the derived class.
    - The class that inherits from another class is known as the base class or superclass.
    - It helps in code reusability.
    - Syntax:
    class BaseClass // Superclass
    {
        // BaseClass members
    };
    class DerivedClass : public BaseClass // DerivedClass inheriting from BaseClass
    {
        // DerivedClass members
    };

    - Types of Inheritance:
    1. Single Inheritance: A class inherits from only one class.
    2. Multiple Inheritance: A class inherits from more than one class.
    3. Multilevel Inheritance: A class inherits from another derived class.
    4. Multiple Inheritance: A class inherits from more than one class.
    6. Hierarchical: More than one derived class inherits from a single base class.
    7. Hybrid Inheritance: Combination of two or more types of inheritance.

    Mode of Inheritance:

    Base class      |       Type of Inheritance        |
    member access   |----------------------------------|
    specifier       | Public    | Protected | Private  |
    ----------------|-----------|-----------|----------|
    Public          | Public    | Protected | Private  |
    Protected       | Protected | Protected | Private  |
    Private         |           Not Inherited          |
*/