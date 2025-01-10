#include <iostream>
using namespace std;

int main()
{
    /*
        Question 1:
        Convert the following binary numbers into decimal forms:
        ● 111111
        - Answer: 32 + 16 + 8 + 4 + 2 + 1 = 63
        ● 10110
        - Answer: 16 + 0 + 4 + 2 + 0 = 22
        ● 10011
        - Answer: 16 + 0 + 0 + 2 + 1 = 19
        ● 110010
        - Answer: 32 + 16 + 0 + 0 + 2 + 0 = 50
    */

    /*
        Question 2:
        Convert the following decimal numbers into binary forms:
        ● 25
        - Answer: 11001
        ● 49
         - Answer: 110001
        ● 31
        - Answer: 11111
        ● 88
        - Answer: 1011000
    */

    /*
        Question 3:
        Following are the rules of adding 2 binary digits:
        0 + 0 = 0, carry = 0
        1 + 0 = 1, carry = 0
        0 + 1 = 1, carry = 0
        1 + 1 = 0, carry = 1

        So, in math if 2 + 3 = 5, in binary it looks like 10 + 11 = 101
        Using this method, try to add these 2 numbers (63 & 22) in their binary form
        and verify that the binary output is equal to the decimal value 85.

        Answer:
        (63)10 = (111111)2
        (22)10 = (10110)2

         111111
        +010110
        --------
         1010101 = 85
    */

    /*
        Bonus:
        Try to read up about 3 Bitwise Operators in C++: OR (|), AND (&) and NOT (~).
        [Refer Link] https://en.wikipedia.org/wiki/Bitwise_operation
    */

    return 0;
}