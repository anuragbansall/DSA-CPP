#include <iostream>
#include <vector>
using namespace std;

// Stack implementation in C++ using vectors with class template
template <typename T> // Template to allow any data type
class Stack
{
private:
    vector<T> stack;

public:
    bool isEmpty()
    {
        return stack.empty();
    }

    void push(T value)
    {
        stack.push_back(value);
        cout << "Pushed " << value << " onto stack\n";
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return T(); // Return default-constructed T
        }

        T poppedValue = stack.back();
        stack.pop_back();
        cout << "Popped " << poppedValue << " from stack\n";
        return poppedValue;
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return T(); // Return default-constructed T
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
    Stack<char> charStack; // Stack for characters
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    charStack.display();

    cout << "Top element is: " << charStack.peek() << endl;

    charStack.pop();
    charStack.display();

    cout << "Top element after pop is: " << charStack.peek() << endl;

    return 0;
}