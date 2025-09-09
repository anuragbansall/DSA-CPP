#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    while (!q.empty())
    {
        cout << "Front element is: " << q.front() << endl;
        q.pop();
    }

    return 0;
}