#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(void)
{
    // Example usage of unordered_map
    unordered_map<string, int> myMap;

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
    if (myMap.count("Cherry")) // count returns 1 if key exists, else 0
    {
        cout << "Cherry exists with value: " << myMap["Cherry"] << endl;
    }
    else
    {
        cout << "Cherry does not exist" << endl;
    }

    // Checking existence using find
    if (myMap.find("Banana") != myMap.end()) // myMap.end() returns an iterator to the end
    {
        cout << "Key Banana found with value: " << myMap["Banana"] << endl;
    }
    else
    {
        cout << "Key Banana not found" << endl;
    }

    // Removing an element
    myMap.erase("Apple"); // Removing element with key "Apple"
    cout << "After erasing Apple:" << endl;
    cout << "Apple after erase: " << myMap["Apple"] << endl; // Will print 0 as default value for non-existing key

    return 0;
}