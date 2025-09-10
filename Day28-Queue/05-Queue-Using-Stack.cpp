#include <iostream>
#include <stack>
using namespace std;

// Queue using Stack

class Queue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int val)
    {
        s1.push(val);
    }

    void dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int front()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool isEmpty()
    {
        return s1.empty() && s2.empty();
    }
};

int main(void)
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    while (!q.isEmpty())
    {
        cout << q.front() << endl;
        q.dequeue();
    }

    return 0;
}
