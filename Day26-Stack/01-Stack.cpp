#include <iostream>
using namespace std;

// Stack implementation in C++ using arrays
class Stack
{
private:
    int top;
    int capacity;
    int *array;

public:
    Stack(int size)
    {
        top = -1;
        capacity = size;
        array = new int[capacity];
    }

    ~Stack()
    {
        delete[] array;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int value)
    {
        if (top >= capacity - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }

        array[++top] = value;
        cout << "Pushed " << value << " onto stack\n";
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return -1; // Indicating stack is empty
        }

        int poppedValue = array[top--];
        cout << "Popped " << poppedValue << " from stack\n";
        return poppedValue;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1; // Indicating stack is empty
        }

        return array[top];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    Stack stack(5); // Create a stack of capacity 5
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.pop();
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.pop();

    stack.display();

    return 0;
}

/*
    Stack:
    - A stack is a linear data structure that follows the Last In First Out (LIFO) principle.
    - Elements can be added or removed from only one end, known as the top of the stack.
    - The last element added to the stack is the first one to be removed.
    - Common operations include push (to add an element), pop (to remove the top element), and peek (to view the top element without removing it).
    - Stacks can be implemented using arrays or linked lists.
    - Think of a stack like a stack of plates where you can only add or remove the top plate. The last plate you put on the stack is the first one you take off.
    - Stacks are used in various applications, such as function call management in programming languages, expression evaluation, and backtracking algorithms.
*/