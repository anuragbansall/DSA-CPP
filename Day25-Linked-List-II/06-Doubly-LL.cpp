#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void printList()
    {
        Node *current = head;

        while (current)
        {
            cout << current->data << " <-> ";
            current = current->next;
        }

        cout << "nullptr" << endl;
    }

    void push_front(int value)
    {
        Node *newNode = new Node(value);

        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int value)
    {
        Node *newNode = new Node(value);

        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (!head)
        {
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }

        temp->next = nullptr;
        delete temp;
    }

    void pop_back()
    {
        if (!tail)
        {
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }

        temp->prev = nullptr;
        delete temp;
    }
};

int main(void)
{
    DoublyLinkedList dll;
    dll.push_front(10);
    dll.push_front(20);
    dll.push_front(30);
    dll.push_front(40);

    dll.push_back(50);
    dll.push_back(60);
    dll.push_back(70);
    dll.push_back(80);

    dll.printList();

    dll.pop_front();
    dll.pop_back();

    dll.printList();

    return 0;
}