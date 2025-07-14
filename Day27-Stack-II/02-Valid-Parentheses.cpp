#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return st.empty();
}

int main(void)
{
    string input;
    cout << "Enter a string of parentheses: ";
    cin >> input;

    if (isValid(input))
    {
        cout << "The string is valid." << endl;
    }
    else
    {
        cout << "The string is invalid." << endl;
    }

    return 0;
}