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

class Mamal : public Animal
{
public:
    string type;
    float weight;

    void sleep()
    {
        cout << name << " is sleeping" << endl;
    }
};

class Dog : public Mamal
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
    d1.type = "Pet";
    d1.weight = 10.5;
    d1.eat();
    d1.sleep();
    d1.bark();

    return 0;
}

/*
    Multilevel Inheritance
    In multilevel inheritance, a class inherits from another derived class. In the above example, the Dog class inherits from the Mamal class, which in turn inherits from the Animal class. The Dog class is the derived class, the Mamal class is the intermediate class, and the Animal class is the base class.

    -------------------
    |     Animal      |
    -------------------
            |
            V
    -------------------
    |      Mamal      |
    -------------------
            |
            V
    -------------------
    |      Dog        |
    -------------------
*/