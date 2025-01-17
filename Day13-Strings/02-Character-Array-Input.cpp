#include <iostream>
using namespace std;

int main()
{
    // char word[10];
    // cout << "Enter a word: ";
    // cin >> word; // cin reads a word until a space, tab, or newline character is encountered
    // cout << "You entered: " << word << endl;

    char sentence[100];
    cout << "Enter a sentence: ";
    cin.getline(sentence, sizeof(sentence)); // cin.getline() reads a line until a newline character or delimiter is encountered
    cout << "You entered: " << sentence << endl;

    return 0;
}

/*
    cin.getline() Function:
    - The cin.getline() function reads a line from the input stream and stores it in a character array.
    - Syntax:
        cin.getline(array_name, size, delimiter);
    - The getline() function reads a line from the input stream and stores it in the character array until the size-1 characters or a newline character is encountered.
    - Delimiter is an optional parameter. By default, it is '\n'.
*/