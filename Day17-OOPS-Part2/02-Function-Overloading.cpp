#include <iostream>
using namespace std;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{
    Calculator calc;
    cout << "Sum of 10 and 20 is: " << calc.add(10, 20) << endl;
    cout << "Sum of 10.5 and 20.5 is: " << calc.add(10.5, 20.5) << endl;
    cout << "Sum of 10, 20, and 30 is: " << calc.add(10, 20, 30) << endl;

    return 0;
}

/*
    Function Overloading is a feature that allows us to have more than one function with the same name but with different parameters. And it is also known as Compile Time Polymorphism. In the above class, we have three add functions with different parameters. The first add function takes two integer parameters, the second add function takes two double parameters, and the third add function takes three integer parameters. When we call the add function with different parameters, the compiler will decide which function to call based on the number and type of parameters passed to the function. In the main function, we have called the add function with different parameters and the compiler will call the appropriate add function based on the parameters passed to the function.
*/