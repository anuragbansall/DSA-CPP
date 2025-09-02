#include <iostream>
#include <stack>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode *head);

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