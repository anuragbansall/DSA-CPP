#include <iostream>
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

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
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

    int getSize()
    {
        int size = 0;
        Node *temp = head;

        while (temp)
        {
            size++;
            temp = temp->next;
        }

        return size;
    }
};

// Function to find the intersection point of two linked lists
Node *findIntersection(LinkedList &list1, LinkedList &list2)
{
    int list1Size = list1.getSize();
    int list2Size = list2.getSize();

    Node *ptr1 = list1.head;
    Node *ptr2 = list2.head;

    if (list1Size > list2Size)
    {
        int diff = list1Size - list2Size;
        for (int i = 0; i < diff; i++)
        {
            if (ptr1)
            {
                ptr1 = ptr1->next;
            }
        }
    }
    else
    {
        int diff = list2Size - list1Size;
        for (int i = 0; i < diff; i++)
        {
            if (ptr2)
            {
                ptr2 = ptr2->next;
            }
        }
    }

    while (ptr1 && ptr2)
    {
        if (ptr1 == ptr2)
        {
            return ptr1; // Intersection point found
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return nullptr; // No intersection point found
}

int main(void)
{
    /*
        Question 1: Intersection of Two Linked Lists
        In a system, there are two singly linked lists. Due to a programming error, the end node of one of the linked lists got linked to the second list, forming an inverted Y-shaped list.
        Write a program to find the point where the two linked lists merge.
    */

    LinkedList list1;
    LinkedList list2;

    list1.push_back(4);
    list1.push_back(5);

    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(6);
    list2.push_back(7);

    list1.head->next->next = list2.head->next->next->next;

    list1.printList();
    list2.printList();

    Node *intersectionPoint = findIntersection(list1, list2);
    if (intersectionPoint)
    {
        cout << "Intersection Point: " << intersectionPoint->data << endl;
    }
    else
    {
        cout << "No Intersection Point Found" << endl;
    }

    return 0;
}