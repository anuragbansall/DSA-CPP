#include <iostream>
#include <string>
using namespace std;

void removeDuplicate(string str, string ans, bool map[26]);

int main(void)
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    bool map[26] = {false};

    removeDuplicate(str, "", map);

    return 0;
}

void removeDuplicate(string str, string ans, bool map[26])
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = str[0];
    string ros = str.substr(1);
    int index = tolower(ch) - 'a';

    if (map[index])
    {
        removeDuplicate(ros, ans, map);
    }
    else
    {
        map[index] = true;
        removeDuplicate(ros, ans + ch, map);
    }
}