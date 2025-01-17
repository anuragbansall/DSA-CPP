#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[] = "Hello";
    char str2[] = "World";

    // strlen() function
    cout << "Length of str1: " << strlen(str1) << endl; // Output: 5
    cout << "Length of str2: " << strlen(str2) << endl; // Output: 5

    cout << endl;

    // strcpy() function
    char str3[10];
    strcpy(str3, str1);
    cout << "Copied str1 to str3: " << str3 << endl; // Output: Hello

    cout << endl;

    // strcat() function
    char str4[20];
    strcpy(str4, str1);
    strcat(str4, " ");
    strcat(str4, str2);
    cout << "Concatenated str1 and str2: " << str4 << endl; // Output: Hello World

    cout << endl;

    // strcmp() function
    cout << "Comparing str1 and str2: " << strcmp(str1, str2) << endl; // Output: -1
    cout << "Comparing str2 and str1: " << strcmp(str2, str1) << endl; // Output: 1
    cout << "Comparing str1 and str1: " << strcmp(str1, str1) << endl; // Output: 0

    return 0;
}

/*
    C-String:
    - A C-string is a character array that ends with a null character ('\0').
    - C-strings are used to store a string of characters in a fixed-size array.
    - C-strings are declared using double quotes ("") and are terminated by a null character.
    - Include the cstring header file to use C-string functions.
    Example:
        char name[] = "Anurag";

    C-String Functions:
    - strlen(str) function: Returns the length of a C-string.
    - strcpy(dest, src) function: Copies the contents of one C-string to another.
    - strcat(dest, src) function: Concatenates the contents of two C-strings.
    - strcmp(str1, str2) function: Compares two C-strings lexicographically. Returns 0 if the strings are equal.
*/