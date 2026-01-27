#include <iostream>
#include <unordered_set>
using namespace std;

int main(void)
{
    // Example usage of unordered_set
    unordered_set<string> mySet;

    // Inserting elements
    mySet.insert("Apple");
    mySet.insert("Banana");
    mySet.insert("Cherry");
    mySet.insert("Apple"); // Duplicate, will not be added

    // Accessing elements
    cout << "Elements in the unordered_set:" << endl;
    for (const auto &element : mySet)
    {
        cout << element << endl;
    }

    // Checking existence using count
    if (mySet.count("Banana")) // count returns 1 if element exists, else 0
    {
        cout << "Banana exists in the set" << endl;
    }
    else
    {
        cout << "Banana does not exist in the set" << endl;
    }

    // Checking existence using find
    if (mySet.find("Cherry") != mySet.end()) // mySet.end() returns an iterator to the end
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