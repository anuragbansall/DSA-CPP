#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    string name;
    int age;
    float salary;

public:
    // Getters
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }

    float getSalary()
    {
        return salary;
    }

    // Setters
    void setName(string value)
    {
        name = value;
    }
    void setAge(int value)
    {
        age = value;
    }
    void setSalary(float value)
    {
        salary = value;
    }
};

int main()
{
    User u1;
    u1.setName("Anurag");
    u1.setAge(21);
    u1.setSalary(10000.0); // USD not INR :P

    cout << "Name: " << u1.getName() << endl;
    cout << "Age: " << u1.getAge() << endl;
    cout << "Salary: " << u1.getSalary() << endl;

    return 0;
}

/*
    Getters and Setters:
    - Getters and setters are used to access and modify the private data members of a class.
    - They provide a controlled and safe way to access and modify the data members.
    - Getters are used to access the data members.
    - Setters are used to modify the data members.
    - Getters and setters are also known as accessor and mutator methods.
    - Syntax:
        class class_name
        {
            private:
                data_type data_member;
            public:
                data_type get_data_member()
                {
                    return data_member;
                }
                void set_data_member(data_type value)
                {
                    data_member = value;
                }
        };
    - Example:
        class Employee
        {
            private:
                string name;
            public:
                string get_name()
                {
                    return name;
                }
                void set_name(string value)
                {
                    name = value;
                }
        };
*/