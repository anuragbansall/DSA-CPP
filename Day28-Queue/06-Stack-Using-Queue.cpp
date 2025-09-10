#include <iostream>
#include <queue>
using namespace std;

// Stack using Queue

class Stack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int val)
    {
        q1.push(val);
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();

        // Swap the queues
        swap(q1, q2);
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();
        q2.push(topElement);
        q1.pop();

        // Swap the queues
        swap(q1, q2);

        return topElement;
    }

    bool isEmpty()
    {
        return q1.empty();
    }
};

;

int main(void)
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
