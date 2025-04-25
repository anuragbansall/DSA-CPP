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

    // Method to print the list
    void printList()
    {
        Node *current = head; // start from the head

        while (current != NULL)
        {
            cout << current->data << " -> "; // print the data of the current node
            current = current->next;         // move to the next node
        }

        cout << "NULL" << endl; // print NULL at the end of the list
    }

    void reverse()
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;
        tail = head;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
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

    cout << "Original List: ";
    list.printList();

    list.reverse(); // Reverse the linked list

    cout << "Reversed List: ";
    list.printList();

    return 0;
}
