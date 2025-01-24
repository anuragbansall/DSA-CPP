#include <iostream>
#include <string>
using namespace std;

class A
{
    string secret = "I am a secret";
    friend void showSecret(A obj); // Friend Function
};

void showSecret(A obj) // Friend Function
{
    cout << obj.secret << endl; // Allowed
}

int main()
{
    A a;

    showSecret(a);

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
            friend void fun(Class1 obj);
        };

        void fun(Class1 obj)
        {
            cout << obj.a << endl; // Allowed
            cout << obj.b << endl; // Allowed
            cout << obj.c << endl; // Allowed
        }
*/