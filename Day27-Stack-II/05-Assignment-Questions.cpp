#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode *head);
string decodeString(const string &s);
string simplifyPath(string &path);
int trapRainWater(const vector<int> &height);

int main(void)
{

    /*
        Question 1: Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
        Examples:
        Input: head = [1, 2, 2, 1]   Output: true
        Input: head = [1, 2, 3]      Output: false
        Note: Use a stack to solve this problem.
    */

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    cout << (isPalindrome(head) ? "true" : "false") << endl;

    /*
        Question 2: Given an encoded string, return its decoded string.
        The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is repeated exactly k times.
        Note that k is a positive integer. You may assume the input string is always valid: no extra whitespaces, square brackets are well-formed, etc.
        Also, the original data does not contain any digits; digits are only used for repeat counts k.
        For example, there will not be inputs like 3a or 2[4].

        Examples:
        Input: s = "3[a]2[bc]"      Output: "aaabcbc"
        Input: s = "2[abc]3[cd]ef"  Output: "abcabccdcdcdef"
    */
    string s = "3[a]2[bc]";
    cout << decodeString(s) << endl;

    /*
        Question 3: Given an absolute path for a file (Unix-style), simplify it.
        Note:
        - An absolute path always begins with '/' (the root directory).
        - A single dot '.' means the current directory.
        - A double dot '..' means the parent directory.
        - Multiple consecutive slashes should be treated as a single slash.

        Examples:
        Input: path = "/home//foo/"
        Output: "/home/foo"
        Explanation: Multiple consecutive slashes are replaced by a single one.

        Input: path = "/home/user/Documents/../Pictures"
        Output: "/home/user/Pictures"
        Explanation: ".." moves up one directory level.
    */
    string path = "/home//foo/";

    cout << simplifyPath(path) << endl;

    /*
        Question 4: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
        Examples:
        Input: height = [7, 0, 4, 2, 5, 0, 6, 4, 0, 5]
        Output: 25
        Explanation: The elevation map [7, 0, 4, 2, 5, 0, 6, 4, 0, 5] can trap 25 units of rainwater.
    */

    vector<int> height = {7, 0, 4, 2, 5, 0, 6, 4, 0, 5};
    cout << trapRainWater(height) << endl;

    return 0;
}

bool isPalindrome(ListNode *head)
{
    stack<int> st;
    ListNode *temp = head;

    while (temp)
    {
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;

    while (temp)
    {
        if (temp->val != st.top())
        {
            return false;
        }

        st.pop();
        temp = temp->next;
    }

    return true;
}

string decodeString(const string &s)
{
    stack<int> countStack;
    stack<string> stringStack;
    string currentString;
    int n = 0;

    for (char c : s)
    {
        if (isdigit(c))
        {
            n = n * 10 + (c - '0'); // This builds the repeat count
        }
        else if (c == '[')
        {
            countStack.push(n);
            n = 0;
            stringStack.push(currentString);
            currentString.clear();
        }
        else if (c == ']')
        {
            int count = countStack.top();
            countStack.pop();

            string decodedString;
            for (int i = 0; i < count; ++i)
            {
                decodedString += currentString;
            }

            currentString = stringStack.top() + decodedString;
            stringStack.pop();
        }
        else
        {
            currentString += c;
        }
    }

    return currentString;
}

string simplifyPath(string &path)
{
    stack<string> st;
    string current;

    path.push_back('/'); // Append a '/' to handle the last segment

    for (char ch : path)
    {
        if (ch == '/')
        {
            if (current == "..")
                st.pop();
            else if (!current.empty() && current != ".")
                st.push(current);

            current.clear();
        }
        else
        {
            current += ch;
        }
    }

    while (!st.empty())
    {
        current = "/" + st.top() + current;
        st.pop();
    }

    return current.empty() ? "/" : current;
}

int trapRainWater(const vector<int> &height)
{
    stack<int> st;
    int waterTrapped = 0;
    int n = height.size();

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && height[i] > height[st.top()])
        {
            int top = st.top();
            st.pop();

            if (st.empty())
                break;

            int distance = i - st.top() - 1;
            int boundedHeight = min(height[i], height[st.top()]) - height[top];
            waterTrapped += distance * boundedHeight;
        }
        st.push(i);
    }

    return waterTrapped;
}