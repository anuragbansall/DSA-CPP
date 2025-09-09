#include <iostream>
using namespace std;

// Queue using Linked List
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int val)
    {
        Node *newNode = new Node(val);

        if (!front)
        {
            front = newNode;
            rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue operation
    int dequeue()
    {
        if (!front)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int val = front->data;
        Node *temp = front;
        front = front->next;

        if (!front)
            rear = nullptr;

        delete temp;
        return val;
    }

    // Peek operation
    int peek()
    {
        if (!front)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return front->data;
    }
};

int main(void)
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element is: " << q.peek() << endl;

    cout << "Dequeued element is: " << q.dequeue() << endl;
    cout << "Front element is: " << q.peek() << endl;

    return 0;
}