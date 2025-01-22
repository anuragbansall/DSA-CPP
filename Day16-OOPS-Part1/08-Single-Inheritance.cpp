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
    Single Inheritance
    In single inheritance, a class inherits from only one class. In the above example, the Dog class inherits from the Animal class. The Dog class is the derived class, and the Animal class is the base class.

    -------------------
    |     Animal      |
    -------------------
            |
            V
    -------------------
    |      Dog        |
    -------------------
*/