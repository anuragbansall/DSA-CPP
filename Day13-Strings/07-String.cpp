#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Inputting String
    string name;
    cout << "Enter your full name: ";
    getline(cin, name); // getline() reads a line until a newline character is encountered

    // Outputting String
    cout << "Your full name is: " << name << endl;

    // String Member Functions
    int length = name.length();
    cout << "Length of the name: " << length << endl;

    name.append(" Bansal");
    cout << "Updated Name: " << name << endl;

    name.insert(6, " Sharma");
    cout << "Updated Name: " << name << endl;

    cout << "Character at position 7: " << name.at(7) << endl;

    name.clear();
    cout << "Cleared Name: " << name << endl; // Output: (empty string)

    return 0;
}

/*
    String:
    - C++ Strings are objects of pre-defined string class in STL (Standard Template Library).
    - The Strings have useful member functions that make string manipulation easier.
    - C++ Strings are dynamic (their size can change at runtime).
    - C++ Strings support operators like +, =, ==, !=, <, >, etc.
    - C++ Strings are stored contiguously in memory.
    - To use C++ Strings, include the string header file.
    - Example:
        string name = "Anurag";
        cout << "Name: " << name << endl;

    String Member Functions:
    - length() - Returns the length of the string.
    - append() - Adds a substring to the end of the string.
    - insert() - Inserts a substring at a specified position.
    - at() - Returns the character at a specified position.
    - clear() - Clears the string.
    - find() - Searches for a substring in the string.
    - substr() - Returns a substring from a specified position.
*/