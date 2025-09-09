#include <iostream>
using namespace std;

// Circular Queue using Array
class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    CircularQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Enqueue operation
    void enqueue(int val)
    {
        if (size == capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }

    // Dequeue operation
    int dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        front = (front + 1) % capacity;
        int val = arr[front];
        size--;

        return val;
    }
};

int main(void)
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // This should show "Queue is full"

    cout << q.dequeue() << endl; // 10
    cout << q.dequeue() << endl; // 20

    q.enqueue(70);
    q.enqueue(80);

    while (true)
    {
        int val = q.dequeue();
        if (val == -1)
            break;
        cout << val << endl;
    }

    return 0;
}