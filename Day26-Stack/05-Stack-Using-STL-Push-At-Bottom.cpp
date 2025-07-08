#include <iostream>
#include <stack>
using namespace std;

// Stack using STL (Push at bottom)

void pushAtBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int temp = s.top();

    s.pop();
    pushAtBottom(s, x);
    s.push(temp); // backtracking
}

int main(void)
{
    stack<int> s;
    s.push(1);
    s.push(2);
    
    pushAtBottom(s, 3);
    pushAtBottom(s, 4);

    // Final stack will be: 4, 3, 1, 2

    return 0;
}