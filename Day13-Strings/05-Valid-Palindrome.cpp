#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char str[]);

int main()
{
    char word[] = "madam";
    cout << word << ": " << isPalindrome(word) << endl; // Output: 1

    char word2[] = "hello";
    cout << word2 << ": " << isPalindrome(word2) << endl; // Output: 0

    return 0;
}

bool isPalindrome(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;

    while (start, end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}