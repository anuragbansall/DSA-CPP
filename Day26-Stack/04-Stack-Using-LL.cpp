#include <iostream>
using namespace std;

// Stack implementation using a linked list
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class Stack
{
private:
    Node<T> *top;
    int size;

public:
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return T(); // Return default-constructed T
        }

        return top->data;
    }

    int getSize()
    {
        return size;
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        size++;

        cout << value << " pushed onto stack\n";
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return T(); // Return default-constructed T
        }

        Node<T> *temp = top;
        T poppedValue = top->data;
        top = top->next;
        delete temp;
        size--;

        return poppedValue;
    }
};

int main(void)
{
    Stack<int> s; // Now we have to specify the type of data we want to store in the stack
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peek() << endl;

    cout << "Popped element is: " << s.pop() << endl;
    cout << "Top element after pop is: " << s.peek() << endl;

    cout << "Stack Size is: " << s.getSize() << endl;

    return 0;
}