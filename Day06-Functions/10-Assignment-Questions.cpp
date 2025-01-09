#include <iostream>
using namespace std;

int reverse(int num);
bool isPalindrome(int num);
int digitSum(int num);
int abSquare(int a, int b);
int largestOfThree(int a, int b, int c);
char nextCharacter(char ch);

int main()
{
    /*
    Question 1:
        Write a function to check if a number is a palindrome in C++.
        A number is called a palindrome if the number is equal to the reverse of a number.
        Eg: 121 is a palindrome because the reverse of 121 is 121 itself.
        On the other hand, 321 is not a palindrome because the reverse of 321 is 123, which is not equal to 321.
    */
    cout << isPalindrome(121) << endl; // Output: 1 (true)
    cout << isPalindrome(321) << endl; // Output: 0 (false)

    /*
    Question 2:
        Write a function to calculate the sum of digits of a number.
    */
    cout << digitSum(123) << endl; // Output: 6

    /*
    Question 3:
        Write a function which takes 2 numbers as parameters (a & b) and outputs: a^2 + b^2 + 2*ab.
    */
    cout << abSquare(3, 4) << endl; // Output: 49

    /*
    Question 4:
        Write a function that prints the largest of 3 numbers.
    */
    cout << largestOfThree(10, 5, 8) << endl; // Output: 10

    /*
    Question 5:
        Write a function that accepts a character (ch) as a parameter & returns the character that occurs after ch in the English alphabet.
        Eg: input = 'c', return value = 'd'
        Note: for ch = 'z', return 'a'.
    */
    cout << nextCharacter('c') << endl; // Output: 'd'
    cout << nextCharacter('z') << endl; // Output: 'a'

    return 0;
}

int reverse(int num)
{
    int reverseNum = 0;
    while (num > 0)
    {
        reverseNum = reverseNum * 10 + num % 10;
        num = num / 10;
    }
    return reverseNum;
}

bool isPalindrome(int num)
{
    return reverse(num) == num;
}

int digitSum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int abSquare(int a, int b)
{
    return a * a + b * b + (2 * a * b);
}

int largestOfThree(int a, int b, int c)
{
    int largest = a;
    if (b > largest)
    {
        largest = b;
    }
    else if (c > largest)
    {
        largest = c;
    }

    return largest;
}

char nextCharacter(char ch)
{
    if (ch == 'z')
    {
        return 'a';
    }

    return ++ch; // Increment the character by 1 and return it
}