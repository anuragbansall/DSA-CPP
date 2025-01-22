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
        // age = obj.age; // Shallow Copy
        age = new int; // Deep Copy
        *age = *(obj.age);
        cout << "Copy Constructor called" << endl;
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

    // *s1.age = 19;
    // s1.printInfo();
    // s2.printInfo(); // Age of s2 is also changed because of Shallow Copy

    *s1.age = 19;
    s1.printInfo();
    s2.printInfo(); // Age of s2 is not changed because of Deep Copy

    return 0;
}

/*
    Copy Constructor:
    - A copy constructor is a member function that initializes an object using another object of the same class.
    - It is called when a new object is created from an existing object.
    - Syntax:
    class MyClass
    {
        public:
            MyClass(const MyClass &obj) // Copy Constructor
            {
                // Copy data members from obj to this object
            }
    };
    - Example:
    class Student
    {
        string name;
        float cgpa;

        public:
            Student(const Student &obj) // Copy Constructor
            {
                name = obj.name;
                cgpa = obj.cgpa;
            }
    };

    Shallow Copy vs Deep Copy:
    - Shallow Copy: It copies the memory address of the object to another object. Both objects point to the same memory location.
    - Deep Copy: It creates a new memory location and copies the values of the object to another object.
    - Advantages of Deep Copy:
        - It prevents data corruption.
        - It prevents memory leaks.
        - It is more efficient.
        - It is used when we want to modify the original object while keeping a copy intact.
*/