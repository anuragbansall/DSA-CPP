#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    map<int, string> m; // Create a map that maps integers to strings

    m[1] = "One";   // Insert key-value pair (1, "One")
    m[2] = "Two";   // Insert key-value pair (2, "Two")
    m[3] = "Three"; // Insert key-value pair (3, "Three")

    // Access and print values using their keys
    cout << "Key: 1, Value: " << m[1] << endl;
    cout << "Key: 2, Value: " << m[2] << endl;
    cout << "Key: 3, Value: " << m[3] << endl;

    // Check if a key exists in the map
    int keyToCheck = 2;
    if (m.count(keyToCheck) > 0)
    {
        cout << "Key " << keyToCheck << " exists in the map." << endl;
    }
    else
    {
        cout << "Key " << keyToCheck << " does not exist in the map." << endl;
    }

    // Modify a value associated with a key
    m[2] = "Two (modified)";

    // Iterate through the map and print all key-value pairs
    cout << "All key-value pairs in the map:" << endl;
    for (const auto &pair : m)
    {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    return 0;
}

/*
    Map:
    1. Map is a container that stores elements in key-value pairs.
    2. Each key is unique, and it is used to access the corresponding value.
    3. Map is implemented as a balanced binary search tree (usually a Red-Black Tree).
    4. The elements in a map are always sorted by the key.
    5. Common operations on a map include insertion, deletion, and searching for elements by key.
    6. The time complexity for these operations is O(log n) on average.
*/