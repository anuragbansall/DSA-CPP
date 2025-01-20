#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 3;
    
    int and_result = a & b;
    cout << "AND: " << and_result << endl; // 1

    int or_result = a | b;
    cout << "OR: " << or_result << endl; // 7

    int xor_result = a ^ b;
    cout << "XOR: " << xor_result << endl; // 6

    int not_result = ~a;
    cout << "NOT: " << not_result << endl; // -6

    int left_shift = a << 1;
    cout << "Left Shift: " << left_shift << endl; // 10

    int right_shift = a >> 1;
    cout << "Right Shift: " << right_shift << endl; // 2

    return 0;
}

/*
    Bitwise Operators:
        - Bitwise operators manipulate individual bits of a number.
        - Operations are performed on the binary representation of numbers.
        - Primarily used with integers.

    Types of Bitwise Operators:
    ----------------------------------

    1. AND (&): Operates on two bit patterns. The result is 1 only if both bits are 1.
       Rules: 1 & 1 = 1, 1 & 0 = 0, 0 & 1 = 0, 0 & 0 = 0
       Example: 5 & 3 = 1
        5 in binary: 101
        3 in binary: 011
                  101
        AND       011
        ------------
                  001  = 1

    2. OR (|): Operates on two bit patterns. The result is 1 if either of the bits is 1.
       Rules: 1 | 1 = 1, 1 | 0 = 1, 0 | 1 = 1, 0 | 0 = 0
       Example: 5 | 3 = 7
        5 in binary: 101
        3 in binary: 011
                  101
         OR       011
        ------------
                  111  = 7

    3. XOR (^): Operates on two bit patterns. The result is 1 if the bits are different.
       Rules: 1 ^ 1 = 0, 1 ^ 0 = 1, 0 ^ 1 = 1, 0 ^ 0 = 0
       Example: 5 ^ 3 = 6
        5 in binary: 101
        3 in binary: 011
                  101
        XOR       011
        ------------
                  110  = 6

    4. NOT (~): Unary operator that flips all the bits of a number (including the sign bit).
       Rules: ~1 = 0, ~0 = 1
       Example: ~5 = -6 (in two's complement representation)
        5 in binary:  0000 0101
        ~5 in binary: 1111 1010 (two's complement gives -6)

    5. Left Shift (<<): Shifts the bits to the left. Vacated bits are filled with 0.
       Rules: Multiply by 2^n (where n is the number of shifts).
       Example: 5 << 1 = 10
        5 in binary:  0000 0101
        << 1 shift:   0000 1010  = 10

    6. Right Shift (>>): Shifts the bits to the right. Vacated bits depend on the type:
         - Logical right shift (unsigned): Vacated bits are filled with 0.
         - Arithmetic right shift (signed): Vacated bits depend on the sign.
       Rules: Divide by 2^n (for unsigned integers).
       Example: 5 >> 1 = 2
        5 in binary:  0000 0101
        >> 1 shift:   0000 0010  = 2
*/
