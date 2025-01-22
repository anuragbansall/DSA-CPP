#include <iostream>
using namespace std;

class Student
{
    string name;
    float cgpa;

public:
    int *age; // Pointer variable
    // Parameterized Constructor
    Student(string name, float cgpa, int age)
    {
        this->name = name;
        this->cgpa = cgpa;
        this->age = new int; // Dynamic Memory Allocation
        *(this->age) = age;
        cout << "Parameterized Constructor called" << endl;
    }
    // Custom Copy Constructor
    Student(const Student &obj)
    {
        name = obj.name;
        cgpa = obj.cgpa;
        age = new int; // Deep Copy
        *age = *(obj.age);
        cout << "Copy Constructor called" << endl;
    }

    // Destructor
    ~Student()
    {
        cout << "Destructor called" << endl;
        if (age != NULL) // Check if the pointer is not null
        {
            delete age; // Deallocate memory
            age = NULL; // Nullify the pointer
        }
    }

    void printInfo()
    {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Age: " << *age << endl;
    }
};

int main()
{
    Student s1("John", 8.5, 18); // Parameterized Constructor called
    s1.printInfo();
    Student s2(s1); // Copy Constructor called
    s2.printInfo();

    return 0;
}

/*
    Destructor:
    - A destructor is a member function that is called automatically when an object is destroyed.
    - It is called when the object goes out of scope or when the delete operator is used.
    - It has the same name as the class preceded by a tilde(~).
    - It does not have parameters.
    - It does not have a return type.
    - The destructor is called in the reverse order of the constructors.
    - It is generally used to deallocate dynamic memory allocated by the object during its lifetime.
    - Syntax:
    class MyClass
    {
        public:
            ~MyClass() // Destructor
    };
    - Example:
    ~Student() // Destructor
    {
        cout << "Destructor called" << endl;
    }
*/