#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    // Example usage of map
    map<string, int> myMap;

    // Inserting elements
    myMap["Apple"] = 10;
    myMap["Banana"] = 30;
    myMap["Cherry"] = 20;

    // Accessing elements
    for (const auto &pair : myMap)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    // Checking existence using count
    if (myMap.count("Banana")) // count returns 1 if key exists, else
    {
        cout << "Key Banana exists with value: " << myMap["Banana"] << endl;
    }
    else
    {
        cout << "Key Banana does not exist" << endl;
    }

    // Checking existence using find
    if (myMap.find("Cherry") != myMap.end()) // myMap.end() returns an iterator to the end
    {
        cout << "Key Cherry found with value: " << myMap["Cherry"] << endl;
    }
    else
    {
        cout << "Key Cherry not found" << endl;
    }

    // Removing an element
    myMap.erase("Apple"); // Removing element with key "Apple"
    cout << "After erasing key Apple:" << endl;
    cout << "Key Apple after erase: " << myMap["Apple"] << endl; // Will print 0 as default value for non-existing key

    return 0;
}

/*
    Unordered Map vs Map in C++:
    1. Ordering:
       - map: Stores elements in a sorted order based on the keys.
       - unordered_map: Stores elements in an arbitrary order, not sorted.
    2. Underlying Data Structure:
       - map: Implemented as a balanced binary search tree (usually a Red-Black Tree), which allows for ordered traversal.
       - unordered_map: Implemented using hash tables, which allows for faster average time complexity for lookups.
    3. Time Complexity:
       - map: O(log n) for insertions, deletions, and lookups due to tree structure.
       - unordered_map: O(1) average time complexity for insertions, deletions, and lookups, but can degrade to O(n) in worst-case scenarios due to hash collisions.
    4. Use Cases:
       - map: Preferred when ordered data is required or when range queries are needed.
       - unordered_map: Preferred for faster access when order does not matter.
*/