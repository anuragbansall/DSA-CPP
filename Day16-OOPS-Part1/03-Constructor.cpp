#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    float cgpa;

public:
    // Non-Parameterized Constructor (Default Constructor)
    Student() // Constructor
    {
        cout << "Non-Parameterized Constructor called" << endl;
    }

    // Parameterized Constructor
    Student(string name, float cgpa)
    {
        this->name = name;
        this->cgpa = cgpa;
        cout << "Parameterized Constructor called" << endl;
    }

    // Getters
    string getName()
    {
        return name;
    }

    float getCGPA()
    {
        return cgpa;
    }
};

int main()
{
    Student s1;              // Non-Parameterized Constructor called
    Student s2("John", 8.5); // Parameterized Constructor called
    cout << "Name: " << s2.getName() << endl;
    cout << "CGPA: " << s2.getCGPA() << endl;

    return 0;
}

/*
    Constructors:
    - A constructor is a special member function that initializes an object of a class.
    - It is called automatically when the object is created.
    - It has the same name as the class.
    - It does not have a return type.
    - It can have parameters.
    - It can be overloaded.
    - It can be defined inside or outside the class.
    - Syntax:
    class MyClass
    {
        public:
            MyClass() // Constructor
            {
                // Constructor code
            }
    };
    - Example:
    class Student
    {
        public:
            Student() // Constructor
            {
                cout << "Constructor called" << endl;
            }
    };

    - Types of Constructors:
        1. Default Constructor (No-Arg Constructor)
        2. Parameterized Constructor (Arg Constructor)
        3. Copy Constructor (Special Constructor)
        4. Constructor Overloading (Multiple Constructors)

    this Pointer:
    - It is a pointer that points to the object itself.
    - It is used to refer to the current object.
    - Syntax:
    class MyClass
    {
        public:
            MyClass() // Constructor
            {
                this->member = value;
            }
    };
    - Example:
    class Student
    {
        public:
            Student(string name, float cgpa)
            {
                this->name = name;
                this->cgpa = cgpa;
            }
    };
*/