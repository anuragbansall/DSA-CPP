#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char name[] = {'a', 'n', 'u', 'r', 'a', 'g', '\0'};
    cout << "Name: " << name << endl;                   // Output: Name: anurag
    cout << "Size of Name: " << sizeof(name) << endl;   // Output: Size of Name: 7
    cout << "Length of Name: " << strlen(name) << endl; // Output: Length of Name: 6 (strlen() is a function in cstring library)
    cout << "name[0]: " << name[0] << endl;             // Output: name[0]: a

    cout << endl;

    char fullName[] = "Anurag Bansal";
    cout << "Full Name: " << fullName << endl;                   // Output: Full Name: Anurag Bansal
    cout << "Size of Full Name: " << sizeof(fullName) << endl;   // Output: Size of Full Name: 14
    cout << "Length of Full Name: " << strlen(fullName) << endl; // Output: Length of Full Name: 13 (strlen() is a function in cstring library)
    cout << "fullName[0]: " << fullName[0] << endl;              // Output: fullName[0]: A

    return 0;
}

/*
    Characters Array:
    - An array of characters is an array of individual characters.
    - The array of characters is also known as a string.
    - Syntax:
        char name[] = {'a', 'b', 'c', 'd', 'e'};
        char name[] = "abcde";
    - The second syntax is more common and easy to use.
    - In memory, the array of characters is stored as a sequence of characters terminated by a null character '\0'. So the size of the array should be one more than the number of characters in the string.
*/