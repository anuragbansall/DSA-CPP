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

    void breakCycle()
    {
        Node *slow = head;
        Node *fast = head;

        // Detect cycle using Floyd's Tortoise and Hare algorithm
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break; // Cycle detected
            }
        }

        if (slow != fast || fast == NULL || fast->next == NULL)
        {
            return; // No cycle detected
        }

        // Find the start of the cycle
        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Find the node before the start of the cycle
        while (fast->next != slow)
        {
            fast = fast->next;
        }

        // Break the cycle
        fast->next = NULL;
    }
};

int main(void)
{
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);

    ll.createCycle(); // Create a cycle for testing

    ll.detectCycle() ? cout << "Cycle detected" << endl : cout << "No cycle detected" << endl;

    ll.breakCycle(); // Break the cycle

    ll.detectCycle() ? cout << "Cycle detected" << endl : cout << "No cycle detected" << endl;
    return 0;
}