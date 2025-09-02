#include <iostream>
#include <stack>
#include <string>
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