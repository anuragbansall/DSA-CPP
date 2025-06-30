#include <iostream>
#include <vector>
using namespace std;

// Stack implementation in C++ using vectors
class Stack
{
private:
    vector<int> stack;

public:
    bool isEmpty()
    {
        return stack.empty();
    }

    void push(int value)
    {
        stack.push_back(value);
        cout << "Pushed " << value << " onto stack\n";
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return -1; // Indicating stack is empty
        }

        int poppedValue = stack.back();
        stack.pop_back();
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

        return stack.back();
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements: ";
        for (int i = stack.size() - 1; i >= 0; --i)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.display();

    cout << "Top element after pop is: " << s.peek() << endl;

    return 0;
}