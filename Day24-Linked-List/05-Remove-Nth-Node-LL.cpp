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
        next = NULL; // set next to NULL
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

    // Method to remove the nth node from the end of the list
    void removeNthFromEnd(int n)
    {
        if (head == NULL || n <= 0 || n > size)
        {
            cout << "Invalid input" << endl; // invalid input
            return;
        }

        if (n == size)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node *current = head;
        for (int i = 0; i < size - n - 1; i++)
        {
            current = current->next; // move to the node before the one to be deleted
        }

        Node *temp = current->next; // node to be deleted
        current->next = current->next->next;
        delete temp;

        size--;
        return;
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

    int n = 2; // remove the 2nd node from the end
    list.removeNthFromEnd(n);
    cout << "List after removing " << n << "th node from end: ";
    list.printList();

    return 0;
}
