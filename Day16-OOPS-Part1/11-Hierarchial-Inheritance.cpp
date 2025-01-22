#include <iostream>
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

class Bird : public Animal
{
public:
    void fly()
    {
        cout << name << " is flying" << endl;
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        cout << name << " is barking" << endl;
    }
};

int main()
{
    Bird b1;
    b1.name = "Sparrow";
    b1.color = "Brown";
    b1.eat();
    b1.fly();

    Dog d1;
    d1.name = "Tommy";
    d1.color = "Brown";
    d1.eat();
    d1.bark();

    return 0;
}

/*
    Hierarchical Inheritance
    In hierarchical inheritance, more than one derived class inherits from a single base class. In the above example, the Bird and Dog classes inherit from the Animal class. The Bird and Dog classes are the derived classes, and the Animal class is the base class.

            -------------------
            |     Animal      |
            -------------------
                |           |
                V           V
    -------------------    -------------------
    |      Bird       |    |      Dog        |
    -------------------    -------------------

    Hybrid Inheritance
    Hybrid inheritance is a combination of multiple, multilevel, and hierarchical inheritance. 
*/