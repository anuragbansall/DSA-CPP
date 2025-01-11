#include <iostream>
using namespace std;

int main()
{
    /*
        Question 1: What will be the output of the following code:
        int x;
        int *ptr;
        x = 7;
        ptr = &x;
        cout << * ptr;

        Output: 7
    */

    /*
        Question 2: What will be the output of the following code:
        void multipleBy2(int &a, int&b, int &c){
            a *= 2;
            b *= 2;
            c *= 2;
        }

        int main(){
            int x = 1, y = 2, z = 3;
            multipleBy2(x, y, z);
            cout << x << " " << y << " " << z;
            return 0;
        }

        Output: 2 4 6
    */

    /*
        Question 3: What will be the output of the following code:
        int a = 32;
        int *ptr = &a;

        int ch = 'A';
        char &cho = ch;

        cho += a;
        *ptr += ch;
        cout << a << " " << ch;

        Output: 129 'a'
    */

    return 0;
}