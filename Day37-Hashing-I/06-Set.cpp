#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    // Example usage of set
    set<string> mySet;

    // Inserting elements
    mySet.insert("Apple");
    mySet.insert("Banana");
    mySet.insert("Cherry");
    mySet.insert("Apple"); // Duplicate, will not be added

    // Accessing elements
    cout << "Elements in the set:" << endl;
    for (const auto &element : mySet)
    {
        cout << element << endl;
    }

    // Checking existence using count
    if (mySet.count("Banana")) // count returns 1 if element exists,
    {
        cout << "Banana exists in the set" << endl;
    }
    else
    {
        cout << "Banana does not exist in the set" << endl;
    }

    // Checking existence using find
    if (mySet.find("Cherry") != mySet.end()) // mySet.end()
    {
        cout << "Cherry found in the set" << endl;
    }
    else
    {
        cout << "Cherry not found in the set" << endl;
    }

    // Removing an element
    mySet.erase("Apple"); // Removing element "Apple"
    cout << "After erasing Apple:" << endl;
    if (mySet.find("Apple") != mySet.end())
    {
        cout << "Apple found in the set" << endl;
    }
    else
    {
        cout << "Apple not found in the set" << endl;
    }

    return 0;
}

/*
    Unordered Set vs Set in C++:
    1. Ordering:
       - set: Stores elements in a sorted order.
       - unordered_set: Stores elements in an arbitrary order, not sorted.
    2. Underlying Data Structure:
       - set: Implemented as a balanced binary search tree (usually a Red-Black Tree), which allows for ordered traversal.
       - unordered_set: Implemented using hash tables, which allows for faster average time complexity for lookups.
    3. Time Complexity:
       - set: O(log n) for insertions, deletions, and lookups due to tree structure.
       - unordered_set: O(1) average time complexity for insertions, deletions, and lookups, but can degrade to O(n) in worst-case scenarios due to hash collisions.
    4. Use Cases:
       - set: Used when you need to maintain a collection of unique items in a sorted order and require ordered traversal.
       - unordered_set: Used when you need to store unique items and perform fast lookups, insertions, and deletions without concern for order.
*/