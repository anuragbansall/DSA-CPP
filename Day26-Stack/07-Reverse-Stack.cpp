#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> &st)
{
    stack<int> tempStack = st;

    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
}

void insertAtBottom(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }

    int topVal = st.top();
    st.pop();

    insertAtBottom(st, val);

    st.push(topVal); // backtracking
}

// Reverse a stack
void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int topVal = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, topVal); // backtracking
}

int main(void)
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Original Stack: ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed Stack: ";
    printStack(st);

    return 0;
}