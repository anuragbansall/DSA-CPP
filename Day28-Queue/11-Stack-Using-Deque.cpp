#include <iostream>
#include <deque>
using namespace std;

class Stack
{
    deque<int> d;

public:
    void push(int value)
    {
        d.push_back(value);
    }

    void pop()
    {
        if (!d.empty())
        {
            d.pop_back();
        }
    }

    int top()
    {
        if (!d.empty())
        {
            return d.back();
        }
        return -1;
    }

    bool empty()
    {
        return d.empty();
    }
};

int main(void)
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}