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
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node *splitList()
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *right = slow->next;
        slow->next = nullptr; // Split the list into two halves
        return right;
    }

    void reverseList(Node *&head)
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current)
        {
            next = current->next; // Store next node
            current->next = prev; // Reverse the link
            prev = current;       // Move prev to current
            current = next;       // Move to next node
        }

        head = prev; // Update head to the new front of the list
    }

    void alternateMerge(Node *left, Node *right)
    {
        Node *leftPtr = left;
        Node *rightPtr = right;

        Node *nextLeft = nullptr;
        Node *nextRight = nullptr;

        while (leftPtr && rightPtr)
        {
            nextLeft = leftPtr->next;
            nextRight = rightPtr->next;

            leftPtr->next = rightPtr;
            rightPtr->next = nextLeft;

            leftPtr = nextLeft;
            rightPtr = nextRight;
        }

        head = left;
    }

    void zigZag()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        Node *right = splitList();
        Node *left = head;

        reverseList(right);

        alternateMerge(left, right);
    }
};

int main(void)
{
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    list.zigZag();

    list.printList();

    return 0;
}