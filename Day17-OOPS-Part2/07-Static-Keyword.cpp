#include <iostream>
using namespace std;

void staticDemoFunc()
{
    static int count = 0; // Static Variable
    count++;
    cout << "Count: " << count << endl;
}

class StaticDemoCls
{
    static int staticVar; // Static Variable

public:
    StaticDemoCls()
    {
        staticVar++;
        cout << "StaticVar: " << staticVar << endl;
    }
    ~StaticDemoCls()
    {
        cout << "Destructor Called" << endl;
    }
};
int StaticDemoCls::staticVar = 0; // Static Variable Initialization using Scope Resolution Operator

int main()
{
    staticDemoFunc(); // Count: 1
    staticDemoFunc(); // Count: 2
    staticDemoFunc(); // Count: 3

    StaticDemoCls s1; // StaticVar: 1
    StaticDemoCls s2; // StaticVar: 2
    StaticDemoCls s3; // StaticVar: 3

    if (true)
    {
        static StaticDemoCls s4; // Static Object - Created only once and destroyed only when the program ends not when the scope ends
    }

    cout << "End of Main" << endl;
    return 0;
}
/*
    Static Keyword:
    - Static Variable:
        Variables declared as static in function are initialized only once and retain their value even after the function ends.
        Static variabales in a class are created and initialized only once. They are shared by all objects of the class.

    - Static Object:
        Static objects are created only once and they are destroyed only when the program ends.
        Static objects are created in the order they are defined in the program.
        Static objects are destroyed in the reverse order they are defined in the program.
*/