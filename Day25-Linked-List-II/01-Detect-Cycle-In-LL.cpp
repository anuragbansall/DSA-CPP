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
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void createCycle()
    {
        if (head == NULL || head->next == NULL)
            return;

        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head->next;
    }

    bool detectCycle()
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true; // Cycle detected
            }
        }

        return false; // No cycle detected
    }
};

int main(void)
{
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);

    cout << ll.detectCycle() << endl; // Should print 0 (false)

    ll.createCycle(); // Create a cycle for testing

    cout << ll.detectCycle() << endl; // Should print 1 (true)

    return 0;
}