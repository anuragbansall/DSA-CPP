#include <iostream>
#include <deque>
using namespace std;

class Queue
{
    deque<int> d;

public:
    void enqueue(int value)
    {
        d.push_back(value);
    }

    void dequeue()
    {
        if (!d.empty())
        {
            d.pop_front();
        }
    }

    int front()
    {
        if (!d.empty())
        {
            return d.front();
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
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.dequeue();
    }

    return 0;
}