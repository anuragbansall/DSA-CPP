#include <iostream>
#include <string>
using namespace std;

class A
{
    string secret = "I am a secret";
    friend void showSecret(A obj); // Friend Function Declaration
};

void showSecret(A obj) // Friend Function Definition
{
    cout << obj.secret << endl; // Allowed to access private member
}

int main()
{
    A a;

    showSecret(a); // Output: I am a secret

    return 0;
}

/*
    Friend Function:
    - A friend function can access private and protected members of a class in which it is declared as friend.
    - It is used to allow a particular function to access the private and protected members of a class.
    - Syntax:
        class Class1
        {
            private:
                int a;
            protected:
                int b;
            public:
                int c;
            friend void func(Class1 obj);
        };

        void func(Class1 obj)
        {
            cout << obj.a << endl; // Allowed to access private member
            cout << obj.b << endl; // Allowed to access protected member
            cout << obj.c << endl; // Allowed to access public member
        }
*/