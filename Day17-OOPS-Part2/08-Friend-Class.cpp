#include <iostream>
#include <string>
using namespace std;

class A
{
    string secret = "I am a secret";
    friend class B; // Friend Class
};

class B // Friend Class
{
public:
    void showSecret(A obj)
    {
        cout << obj.secret << endl; // Allowed
    }
};

int main()
{
    A a;
    B b;

    b.showSecret(a);

    return 0;
}

/*
    Friend Class:
    - A friend class can access private and protected members of another class in which it is declared as friend.
    - It is used to allow a particular class to access the private and protected members of another class.
    - Syntax:
        class Class1
        {
            private:
                int a;
            protected:
                int b;
            public:
                int c;
                friend class Class2;
        };

        class Class2
        {
            public:
                void fun(Class1 obj)
                {
                    cout << obj.a << endl; // Allowed
                    cout << obj.b << endl; // Allowed
                    cout << obj.c << endl; // Allowed
                }
        };
*/