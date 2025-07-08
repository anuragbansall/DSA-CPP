#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Reverse a string using stack
string reverseString(string str)
{
    stack<char> st;

    for (char ch : str)
    {
        st.push(ch);
    }

    string reversedStr = "";
    while (!st.empty())
    {
        reversedStr += st.top();
        st.pop();
    }

    return reversedStr;
}

int main(void)
{
    string str = "Hello, World!";
    string reversed = reverseString(str);
    cout << "Reversed String: " << reversed << endl;

    return 0;
}