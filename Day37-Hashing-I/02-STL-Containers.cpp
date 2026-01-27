#include <iostream>
using namespace std;

int main(void)
{

    return 0;
}

/*
    STL Containers in C++ for Hashing:
    1. unordered_set:
       - Description: An unordered_set is a collection of unique elements that are stored in no particular order.
       - Use Case: It is used when you need to store unique items and perform fast lookups, insertions, and deletions.
       - Example:
         ```cpp
         #include <unordered_set>
         unordered_set<int> mySet;
         mySet.insert(10);
         mySet.insert(20);
         if (mySet.find(10) != mySet.end()) {
             cout << "10 found in the set" << endl;
         }
         ```

    2. unordered_map:
       - Description: An unordered_map is a collection of key-value pairs, where each key is unique and maps to a specific value.
         - Use Case: It is used when you need to associate values with unique keys and require fast access to these values.
         - Example:
            ```cpp
            #include <unordered_map>
            unordered_map<int, string> myMap;
            myMap[1] = "One";
            myMap[2] = "Two";
            if (myMap.find(1) != myMap.end()) {
                cout << "Key 1 found with value: " << myMap[1] << endl;
            }
            ```
*/