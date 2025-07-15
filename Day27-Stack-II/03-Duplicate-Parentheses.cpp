#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool duplicateParentheses(string &s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == ')')
        {
            bool hasContent = false;

            while (!st.empty() && st.top() != '(')
            {
                hasContent = true; // Found some content inside the parentheses
                st.pop();          // Pop the top element from the stack
            }

            if (!st.empty() && st.top() == '(')
            {
                st.pop(); // pop the opening parenthesis
            }

            if (!hasContent)
            {
                return true;
            }
        }
        else
        {
            st.push(c); // Push the current character onto the stack
        }
    }

    return false; // No duplicate parentheses found
}

int main(void)
{
    string s = "(a + b) * (c + d)";

    if (duplicateParentheses(s))
    {
        cout << "Duplicate parentheses found." << endl;
    }
    else
    {
        cout << "No duplicate parentheses found." << endl;
    }

    return 0;
}