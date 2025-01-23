#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    Complex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }

    // Operator Overloading
    Complex operator+(Complex &c2)
    {
        Complex temp(0, 0);
        temp.real = this->real + c2.real;
        temp.imag = this->imag + c2.imag;
        return temp;
    }
};

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;
    c3.display();

    return 0;
}

/*
    Operator Overloading is a feature that allows us to redefine the behavior of an operator when it is used with user-defined data types. In the above example, we have overloaded the + operator for the Complex class. When we use the + operator with two Complex objects, the overloaded operator+ function is called, which adds the real and imaginary parts of the two Complex objects and returns a new Complex object with the sum of the real and imaginary parts. In the main function, we have created two Complex objects c1 and c2 and added them using the + operator. The result is stored in the c3 object, which is then displayed using the display function.
*/