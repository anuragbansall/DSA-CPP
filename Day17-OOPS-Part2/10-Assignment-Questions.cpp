#include <iostream>
#include <string>
using namespace std;

class Complex
{
    int real;
    int imag;

public:
    Complex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }

    Complex operator-(Complex &obj)
    {
        Complex temp(0, 0);
        temp.real = this->real - obj.real;
        temp.imag = this->imag - obj.imag;
        return temp;
    }

    void display()
    {
        cout << "Real: " << real << " Imaginary: " << imag << endl;
    }
};

class BankAccount
{
    string accountNumber;
    int balance;

public:
    BankAccount(string accountNumber, int balance)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposit(int amount)
    {
        balance += amount;
    }

    void withdraw(int amount)
    {
        balance -= amount;
    }

    int getBalance()
    {
        return balance;
    }
};

class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person
{
    string studentID;

public:
    Student(string name, int age, string studentID) : Person(name, age)
    {
        this->studentID = studentID;
    }

    void displayStudentInfo()
    {
        cout << "Name: " << name << " Age: " << age << " Student ID: " << studentID << endl;
    }
};

int main()
{
    /*
        Question 1:
        Create a class to store Complex numbers. Using operator overloading, create the logic to subtract one complex number from another.
        Note - In Complex numbers, the real part of 1st gets subtracted from the real part of 2nd number. Same goes for the imaginary part.
    */
    Complex c1(5, 3);
    Complex c2(2, 1);
    Complex c3 = c1 - c2;
    c3.display();

    /*
        Question 2:
        Create a class BankAccount with private attributes accountNumber and balance. Implement public methods deposit(), withdraw(), and getBalance() to manage the account.
    */
    BankAccount b1("SBI12345", 1000);
    b1.deposit(500);
    b1.withdraw(200);
    cout << "Balance: " << b1.getBalance() << endl;

    /*
        Question 3:
        Create a base class Person with attributes name and age. Derive a class Student from Person and add an additional attribute studentID. Implement a method displayStudentInfo() in the Student class to display all details.
        In main function, Student class object will be created in this format: Student student("Alice", 20, "S12345");
        Note - When we initialize an object of a derived class, the base class part has to be constructed first. If we don't initialize it ourselves in the derived class' constructor by calling one of its constructors, the compiler will attempt to use the default constructor of the base class. To invoke the parent’s parameterized constructor in Child’s constructor, syntax is: Child(int x) : Parent(x) { ...... }
    */
    Student s1("Alice", 20, "S12345");
    s1.displayStudentInfo();

    return 0;
}