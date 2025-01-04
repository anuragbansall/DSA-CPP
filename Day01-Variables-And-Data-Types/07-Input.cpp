#include <iostream>
#include <string>
using namespace std;

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "You entered: " << number << endl;

    char character;
    cout << "Enter a character: ";
    cin.get(character);
    cout << "You entered: " << character << endl;

    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    cout << "You entered: " << sentence << endl;

    return 0;
}

/*
    Input:
    - cin: Standard input stream object
    - Extraction Operator (>>): Reads input from the standard input stream
    - Syntax: cin >> variable;
    - Example: cin >> number; // Reads an integer from the user and stores it in the variable 'number'

    - cin.get(): Reads a single character from the standard input stream
    - Syntax: cin.get();
    - Example: cin.get(); // Reads a single character from the user and stores it in the variable 'character'

    - getline(): Reads a line of text from the standard input stream
    - Syntax: getline(cin, variable);
    - Example: getline(cin, sentence); // Reads a line of text from the user and stores it in the variable 'sentence'
*/