#include <iostream>
using namespace std;

// WAF to find the product of two numbers
int product(int a, int b);

// WAF to find if a number is odd or even
bool isEven(int num);

int main()
{
    int x = 5, y = 3;

    cout << "Product: " << product(x, y) << endl; // Output: Product: 15

    cout << isEven(5) << endl; // Output: 0 (false)
    cout << isEven(10) << endl; // Output: 1 (true)

    return 0;
}

int product(int a, int b)
{
    return a * b;
}

bool isEven(int num)
{
    if (num % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}