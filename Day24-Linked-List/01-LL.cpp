#include <iostream>
using namespace std;

// Linked List Implementation
class Node
{
    // Data members
    int data;
    Node *next;

public:
    // Constructor
    Node(int value)
    {
        data = value;
        next = NULL;
    }

    // Method to get the data of the node in the List
    friend class List;
};
// collection of nodes is called a linked list so we create a class for it

class List
{
    // Data members
    Node *head; // pointer to the first node
    Node *tail; // pointer to the last node
    int size;   // size of the linked list

public:
    // Constructor
    List()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // Method to add a node to the start of the list
    void push_front(int value)
    {
        Node *newNode = new Node(value); // create a new node

        if (head == NULL) // if the list is empty
        {
            head = newNode; // set the head to the new node
            tail = newNode; // set the tail to the new node
        }
        else
        {
            newNode->next = head; // set the next of the new node to the current head
            head = newNode;       // set the head to the new node
        }
        size++; // increment the size of the list
    }

    // Method to add a node to the end of the list
    void push_back(int value)
    {
        Node *newNode = new Node(value); // create a new node

        if (head == NULL) // if the list is empty
        {
            head = newNode; // set the head to the new node
            tail = newNode; // set the tail to the new node
        }
        else
        {
            tail->next = newNode; // set the next of the current tail to the new node
            tail = newNode;       // set the tail to the new node
        }
        size++; // increment the size of the list
    }
};

int main(void)
{
    List ll; // create a new linked list

    ll.push_front(10); // add 10 to the front of the list
    ll.push_front(20); // add 20 to the front of the list

    ll.push_back(30); // add 30 to the end of the list
    ll.push_back(40); // add 40 to the end of the list

    return 0;
}

/*
    Linked List:
    - A data structure that consists of a sequence of elements, each containing a reference (link) to the next element in the sequence.
    - Each element is called a node, and the first node is called the head.
    - The last node points to null, indicating the end of the list.
    - Linked lists can be singly linked (each node points to the next) or doubly linked (each node points to both the next and previous nodes).
    - Linked lists are dynamic in size, allowing for efficient insertion and deletion of elements.

    In C++ there are two ways to implement a linked list:
    1. Using STL (Standard Template Library) which provides a built-in linked list class.
    2. Using a custom implementation where you define a node structure and manage the links manually.
*/