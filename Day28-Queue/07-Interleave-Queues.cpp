#include <iostream>
#include <queue>
using namespace std;

// Interleave two queues
void interleaveQueues(queue<int> &q);

int main(void)
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);

    interleaveQueues(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

void interleaveQueues(queue<int> &q)
{
    int n = q.size();

    if (n % 2 != 0)
    {
        cout << "Queue has odd number of elements, cannot interleave" << endl;
        return;
    }

    queue<int> firstHalf;

    for (int i = 0; i < n / 2; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty())
    {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }

    return;
}