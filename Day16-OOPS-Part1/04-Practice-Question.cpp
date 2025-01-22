#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    int id;
    string password;

public:
    string username;

    // Parameterized Constructor
    User(int id)
    {
        this->id = id;
    }

    // Getter and Setter for password
    string getPassword()
    {
        return password;
    }

    void setPassword(string password)
    {
        this->password = password;
    }

    void printInfo()
    {
        cout << "ID: " << id << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
    }
};

int main()
{
    /*
        Create a User class with properties: id(private), username(public), password(private).
        Its id should be initialized in parameterized constructor.
        It should have a getter and setter for password.
    */
    User u1(101);
    u1.username = "john";
    u1.setPassword("john@123");
    u1.printInfo();

    return 0;
}