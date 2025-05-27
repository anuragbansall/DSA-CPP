#include <iostream>
#include <list>
#include <iterator>
using namespace std;

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

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node *split(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *right = slow->next;
    slow->next = nullptr; // Split the list into two halves
    return right;         // Return the head of the right half
}

Node *merge(Node *&left, Node *&right)
{
    if (!left)
    {
        return right; // If left is empty, return right
    }
    if (!right)
    {
        return left; // If right is empty, return left
    }

    Node *result = nullptr;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right); // Recursively merge the rest
    }
    else
    {
        result = right;
        result->next = merge(left, right->next); // Recursively merge the rest
    }

    return result; // Return the merged list
}

void mergeSort(Node *&head)
{
    if (!head || !head->next)
    {
        return; // Base case: if the list is empty or has one element
    }

    Node *right = split(head);

    mergeSort(head);
    mergeSort(right);

    head = merge(head, right); // Merge the sorted halves
}

int main(void)
{
    LinkedList ll;
    ll.push_back(10);
    ll.push_back(40);
    ll.push_back(50);
    ll.push_back(60);
    ll.push_back(20);
    ll.push_back(30);

    cout << "Original list: ";
    ll.printList();

    mergeSort(ll.head);
    cout << "Sorted list: ";
    ll.printList();

    return 0;
}