#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
    int salary;
    string subject;
};

class Student
{
public:
    int roll;
    float cgpa;
};

class TA : public Teacher, public Student
{
public:
    string name;
    int age;
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll: " << roll << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Salary: " << salary << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main()
{
    TA ta1;
    ta1.name = "John";
    ta1.age = 25;
    ta1.roll = 101;
    ta1.cgpa = 8.5;
    ta1.salary = 50000;
    ta1.subject = "Maths";
    ta1.display();

    return 0;
}

/*
    Multiple Inheritance
    In multiple inheritance, a class can inherit from more than one classes. In the above example, the TA class inherits from both the Teacher and Student classes. The TA class is the derived class, and the Teacher and Student classes are the base classes.

    -------------------     -------------------
    |      Teacher      |   |      Student      |
    -------------------     -------------------
                |                   |
                V                   V
                -------------------
                |        TA         |
                -------------------
*/