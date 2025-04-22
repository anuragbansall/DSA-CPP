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

    // Method to get the size of the list
    int getSize()
    {
        return size; // return the size of the list
    }

    // Method to insert a node at a specific position in the list
    void insertAt(int position, int value)
    {
        Node *newNode = new Node(value); // create a new node

        if (position < 0 || position > size) // check if the position is valid
        {
            cout << "Invalid position" << endl; // print error message
            return;                             // exit the method
        }

        if (position == 0) // if the position is 0, add to the front
        {
            push_front(value); // call push_front method
        }
        else if (position == size) // if the position is equal to size, add to the end
        {
            push_back(value); // call push_back method
        }
        else
        {
            Node *current = head; // start from the head

            for (int i = 0; i < position - 1; i++) // move to the node before the position
            {
                current = current->next;
            }

            newNode->next = current->next; // set the next of the new node to the next of the current node
            current->next = newNode;       // set the next of the current node to the new node
            size++;                        // increment the size of the list
        }
    }

    // Mehod to remove a first node from the list
    void pop_front()
    {
        if (head == NULL) // check if the list is empty
        {
            cout << "List is empty" << endl; // print error message
            return;                          // exit the method
        }

        Node *temp = head; // store the head node in a temporary variable
        head = head->next; // set the head to the next node
        temp->next = NULL; // set the next of the temporary node to NULL

        delete temp; // delete the temporary node
        size--;      // decrement the size of the list
    }

    // Method to remove a last node from the list
    void pop_back()
    {
        if (head == NULL) // check if the list is empty
        {
            cout << "List is empty" << endl; // print error message
            return;                          // exit the method
        }

        if (head->next == NULL) // if there is only one node in the list
        {
            delete head; // delete the head node
            head = NULL; // set head to NULL
            tail = NULL; // set tail to NULL
        }
        else
        {
            Node *current = head; // start from the head

            while (current->next->next != NULL) // move to the second last node
            {
                current = current->next;
            }

            delete current->next; // delete the last node
            current->next = NULL; // set the next of the second last node to NULL
            tail = current;       // set the tail to the second last node
        }

        size--; // decrement the size of the list
    }
};

int main(void)
{
    List ll; // create a new linked list

    ll.push_front(10); // add 10 to the front of the list
    ll.push_front(20); // add 20 to the front of the list

    ll.push_back(30); // add 30 to the end of the list
    ll.push_back(40); // add 40 to the end of the list

    ll.insertAt(2, 25); // insert 25 at position 2
    ll.insertAt(10, 5); // insert 5 at position 10 (invalid position)

    ll.pop_front(); // remove the first node from the list
    ll.pop_back();  // remove the last node from the list

    ll.printList(); // print the list

    cout << "Size of the list: " << ll.getSize() << endl; // print the size of the list

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