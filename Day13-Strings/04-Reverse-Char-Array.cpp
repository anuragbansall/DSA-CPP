#include <iostream>
#include <cstring>
using namespace std;

void reverse(char str[]);

int main()
{
    char sentence[] = "This is a Test Sentence";
    cout << "Original Sentence: " << sentence << endl;

    reverse(sentence);
    cout << "Reversed Sentence: " << sentence << endl;

    return 0;
}

void reverse(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end)
    {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}