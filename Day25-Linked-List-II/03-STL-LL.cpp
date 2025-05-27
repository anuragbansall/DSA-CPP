#include <iostream>
#include <list>     // STL list
#include <iterator> // For iterators, if needed
using namespace std;

void printList(list<int> &ll)
{
    // Define an iterator for the list
    list<int>::iterator itr; // Declare an iterator for the list
    // or you can use auto itr = ll.begin(); to automatically deduce the type

    // Iterate through the list and print elements
    for (itr = ll.begin(); itr != ll.end(); ++itr)
    {
        cout << *itr << " -> "; // Dereference the iterator to get the value
    }

    cout << "NULL" << endl; // Indicate the end of the list
}

int main(void)
{
    // Create a list of integers
    list<int> ll;      // this syntax is similar to vector: vector<int> v;
    ll.push_back(10);  // Add 10 to the end of the list
    ll.push_front(20); // Add 20 to the front of the list
    ll.push_back(30);  // Add 30 to the end of the list

    printList(ll); // Print the list

    cout << "Size of the list: " << ll.size() << endl; // Print the size of the list

    cout << "Front element: " << ll.front() << endl; // Print the first element
    cout << "Back element: " << ll.back() << endl;   // Print the last element

    ll.pop_front(); // Remove the first element
    ll.pop_back();  // Remove the last element

    printList(ll); // Print the list after removals

    auto it = ll.begin(); // Get an iterator to the beginning of the list
    ll.insert(it, 40);    // Insert 40 at the beginning of the list

    printList(ll); // Print the list after insertions

    return 0;
}

/*
    Linked List in C++ STL:
    - C++ Standard Template Library (STL) provides a built-in linked list implementation.
    - The `list` class in STL is a doubly linked list.
    - It allows for efficient insertion and deletion of elements at both ends.
    - The `list` class provides various member functions for manipulating the list, such as `push_back`, `push_front`, `pop_back`, `pop_front`, and more.
    - It supports iterators, allowing for easy traversal and manipulation of the list elements.
*/

/*
    Iterators in C++ STL:
    - Iterators are objects that allow traversal of containers (like lists, vectors, etc.) in a uniform way.
    - They provide a way to access elements of a container without exposing the underlying structure.
    - C++ STL provides different types of iterators, such as input iterators, output iterators, forward iterators, bidirectional iterators, and random access iterators.

    Example of using iterators with a list:
    ```cpp
    #include <iostream>
    #include <list>
    using namespace std;

    int main() {
        list<int> ll = {10, 20, 30, 40, 50};

        // Using an iterator to traverse the list
        for (auto it = ll.begin(); it != ll.end(); ++it) {
            cout << *it << " ";
        }

        return 0;
    }
    ```
*/