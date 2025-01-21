#include <iostream>
#include <string>
using namespace std;

class Student
{
public: // Access Specifier - Public (Accessible from outside the class)
    // Properties
    string name;
    float cgpa;

    // Methods
    void getPercentage()
    {
        cout << "Percentage: " << cgpa * 10 << endl;
    }
};

int main()
{
    Student s1; // Object of Student class
    cout << "Size of Student object: " << sizeof(s1) << endl;
    s1.name = "Anurag";
    s1.cgpa = 9.5;
    cout << "Name: " << s1.name << endl;
    cout << "CGPA: " << s1.cgpa << endl;
    s1.getPercentage();

    return 0;
}

/*
    OOPS - Object Oriented Programming System:
    - It is a programming paradigm that organizes code into objects.
    - It is a way of programming that uses objects to design applications and computer programs.
    - Objects are instances of classes, which are templates for creating objects.
    - Objects can be thought of as a data structure that has some attributes or properties and some methods or functions.

    Classes and Objects:
    - A class is a blueprint for creating objects.
    - An object is an instance of a class.
    - A class is a user-defined data type that has data members and member functions.
    - Data members are the data variables that represent the properties of an object.
    - Member functions are the functions that represent the behavior of an object.
    - Object-oriented programming promotes code reusability, modularity, and abstraction.
    - Syntax:
        class class_name
        {
            access_specifier:
                data_type data_member1;
                data_type data_member2;
                return_type member_function1(parameters);
                return_type member_function2(parameters);
        };
    - Example:
        class Employee
        {
            public:
                string name;
                int age;
                void printDetails()
                {
                    cout << "Name: " << name << endl;
                    cout << "Age: " << age << endl;
                }
        };

        int main()
        {
            Employee emp1;
            emp1.name = "John";
            emp1.age = 30;
            emp1.printDetails();
            return 0;
        }

    Access Specifiers/Modifiers:
    - Access specifiers are used to define the access control for the members of a class.
    - There are four access specifiers in C++: public, private, protected, and default.
    - public: The members declared as public are accessible from outside the class.
    - private: The members declared as private are not accessible from outside the class and can only be accessed within the class.
    - protected: The members declared as protected are accessible from the derived classes.
    - default: If no access specifier is specified, the default access specifier is private.
    - Syntax:
        class class_name
        {
            public:
                // public members
            private:
                // private members
            protected:
                // protected members
        };
*/