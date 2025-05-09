#include <iostream>
using namespace std;

// Linked List Implementation
class Node
{
public:
    // Data members
    int data;
    Node *next;

    // Constructor
    Node(int value)
    {
        data = value;
        next = NULL;
    }

    // Destructor
    ~Node()
    {
        // Destructor to free memory
        if (next != NULL)
        {
            delete next; // delete the next node
            next = NULL; // set next to NULL
        }
    }

    // Method to get the data of the node in the List
    friend class List;
};
// collection of nodes is called a linked list so we create a class for it

class List
{
public:
    // Data members
    Node *head; // pointer to the first node
    Node *tail; // pointer to the last node
    int size;   // size of the linked list

    // Constructor
    List()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // Destructor
    ~List()
    {
        // Destructor to free memory
        if (head != NULL)
        {
            delete head; // delete the head node
            head = NULL; // set head to NULL
        }

        size = 0; // set size to 0
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

    int searchIterative(int value)
    {
        Node *current = head;
        int index = 0;

        while (current != NULL)
        {
            if (current->data == value)
            {
                return index;
            }
            current = current->next;
            index++;
        }

        return -1;
    }
};

int main(void)
{
    List list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    cout << list.searchIterative(30) << endl; // Output: 2
    cout << list.searchIterative(60) << endl; // Output: -1
    cout << list.searchIterative(10) << endl; // Output: 0

    return 0;
}