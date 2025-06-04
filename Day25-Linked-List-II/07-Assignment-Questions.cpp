#include <iostream>
#include <vector>
#include <algorithm>
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

void deleteNodes(LinkedList &list, int M, int N)
{
    Node *current = list.head;

    while (current)
    {
        // skip M nodes
        for (int i = 1; current && i < M; i++)
        {
            current = current->next;
        }

        if (!current)
        {
            break;
        }

        Node *temp = current->next;

        for (int i = 0; current && i < N; i++)
        {
            Node *nodeToDelete = temp;
            temp = temp->next;
            delete nodeToDelete; // delete the node
        }

        current->next = temp;

        current = temp;
    }
}

void swapNodes(LinkedList &list, int x, int y)
{
    if (x == y)
    {
        return;
    }

    Node *prevX = nullptr;
    Node *currX = list.head;

    for (int i = 1; currX && i < x; i++)
    {
        prevX = currX;
        currX = currX->next;
    }

    Node *prevY = nullptr;
    Node *currY = list.head;

    for (int i = 1; currY && i < y; i++)
    {
        prevY = currY;
        currY = currY->next;
    }

    if (!currX || !currY)
    {
        return;
    }

    if (prevX)
    {
        prevX->next = currY;
    }
    else
    {
        list.head = currY;
    }

    if (prevY)
    {
        prevY->next = currX;
    }
    else
    {
        list.head = currX;
    }

    Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void rearrangeEvenOdd(LinkedList &list)
{
    if (!list.head || !list.head->next)
    {
        return;
    }

    Node *evenHead = nullptr;
    Node *evenTail = nullptr;
    Node *oddHead = nullptr;
    Node *oddTail = nullptr;

    Node *current = list.head;

    while (current)
    {
        if (current->data % 2 == 0) // even
        {
            if (!evenHead)
            {
                evenHead = current;
                evenTail = current;
            }
            else
            {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }
        else // odd
        {
            if (!oddHead)
            {
                oddHead = current;
                oddTail = current;
            }
            else
            {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }

        current = current->next;
    }

    if (evenTail)
    {
        evenTail->next = oddHead;
        if (oddTail)
        {
            oddTail->next = nullptr;
        }
        list.head = evenHead;
    }
    else
    {
        list.head = oddHead;
    }
}

LinkedList *merge(LinkedList *list1, LinkedList *list2)
{
    LinkedList *mergedList = new LinkedList();
    Node *ptr1 = list1->head;
    Node *ptr2 = list2->head;

    while (ptr1 && ptr2)
    {
        if (ptr1->data < ptr2->data)
        {
            mergedList->push_back(ptr1->data);
            ptr1 = ptr1->next;
        }
        else
        {
            mergedList->push_back(ptr2->data);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1)
    {
        mergedList->push_back(ptr1->data);
        ptr1 = ptr1->next;
    }
    while (ptr2)
    {
        mergedList->push_back(ptr2->data);
        ptr2 = ptr2->next;
    }

    return mergedList;
}

LinkedList *mergeKSortedLists(vector<LinkedList *> &lists)
{
    if (lists.empty())
    {
        return nullptr;
    }

    LinkedList *mergedList = lists[0];

    for (size_t i = 1; i < lists.size(); i++)
    {
        mergedList = merge(mergedList, lists[i]);
    }

    return mergedList;
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

    /*
        Question 2: Delete N Nodes After M Nodes of a Linked List
        Given a linked list and two integers M and N, traverse the linked list such that you retain M nodes, then delete the next N nodes, and continue the same till the end of the linked list.

        Example 1:
        M = 2, N = 2
        LL: 1->2->3->4->5->6->7->8
        Output: 1->2->5->6

        Example 2:
        M = 3, N = 2
        LL: 1->2->3->4->5->6->7->8->9->10
        Output: 1->2->3->6->7->8
    */

    LinkedList list3;
    list3.push_back(1);
    list3.push_back(2);
    list3.push_back(3);
    list3.push_back(4);
    list3.push_back(5);
    list3.push_back(6);
    list3.push_back(7);
    list3.push_back(8);

    cout << "Original List: ";
    list3.printList();

    deleteNodes(list3, 2, 2);
    cout << "After deleting nodes: ";
    list3.printList();

    /*
        Question 3: Swapping Nodes in a Linked List
        Given a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links, not by swapping data.
        Assume all keys in the linked list are distinct.

        Sample Input 1: 1->2->3->4,  x = 2, y = 4
        Sample Output 1: 1->4->3->2
    */

    LinkedList list4;
    list4.push_back(1);
    list4.push_back(2);
    list4.push_back(3);
    list4.push_back(4);

    cout << "Original List: ";
    list4.printList();

    swapNodes(list4, 2, 4);
    cout << "After swapping nodes 2 and 4: ";
    list4.printList();

    /*
        Question 4: Odd Even Linked List
        We have a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list.
        Also, keep the order of even and odd numbers same.

        Sample Input 1: 8->12->10->5->4->1->6->NULL
        Sample Output 1: 8->12->10->4->6->5->1->NULL

        Sample Input 2: 1->3->5->7->NULL
        Sample Output 2: 1->3->5->7->NULL
    */

    LinkedList list5;
    list5.push_back(8);
    list5.push_back(12);
    list5.push_back(10);
    list5.push_back(5);
    list5.push_back(4);
    list5.push_back(1);
    list5.push_back(6);

    cout << "Original List: ";
    list5.printList();

    rearrangeEvenOdd(list5);
    cout << "After rearranging even and odd: ";
    list5.printList();

    /*
        Question 5: Merge k Sorted Linked Lists
        Given k sorted linked lists, each of size n, merge them into a single sorted linked list and print the result.

        Sample Input 1:
        k = 3, n = 2
        l1 = 1->3->NULL
        l2 = 6->8->NULL
        l3 = 9->10->NULL

        Sample Output 1:
        1->3->6->8->9->10->NULL
    */

    vector<LinkedList *> lists;
    LinkedList *list6 = new LinkedList();
    list6->push_back(1);
    list6->push_back(3);

    LinkedList *list7 = new LinkedList();
    list7->push_back(6);
    list7->push_back(8);

    LinkedList *list8 = new LinkedList();
    list8->push_back(9);
    list8->push_back(10);

    lists.push_back(list6);
    lists.push_back(list7);
    lists.push_back(list8);

    LinkedList *mergedList = mergeKSortedLists(lists);
    cout << "Merged List: ";
    mergedList->printList();

    return 0;
}