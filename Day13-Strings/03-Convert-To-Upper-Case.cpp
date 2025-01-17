#include <iostream>
#include <cstring>
using namespace std;

void toUpperCase(char str[]);
void toLowerCase(char str[]);

int main()
{
    char sentence[] = "This Is A Test Sentence";
    cout << "Original Sentence: " << sentence << endl;

    toUpperCase(sentence);
    cout << "Sentence in Upper Case: " << sentence << endl;

    toLowerCase(sentence);
    cout << "Sentence in Lower Case: " << sentence << endl;

    return 0;
}

void toUpperCase(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            int position = str[i] - 'a';
            str[i] = 'A' + position;
        }
    }
}

void toLowerCase(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            int position = str[i] - 'A';
            str[i] = 'a' + position;
        }
    }
}