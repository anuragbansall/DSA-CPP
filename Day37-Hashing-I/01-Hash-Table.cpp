#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string key;
    int value;
    Node *next;

    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }

    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
};

// Hash Table Class
class HashTable
{
private:
    int totalSize;   // Total size of the hash table
    int currentSize; // Current number of elements in the hash table
    Node **table;    // Array of pointers to Node

    void rehash()
    {
        cout << "Rehashing called!" << endl;

        Node **oldTable = table;
        int oldSize = totalSize;

        totalSize *= 2; // Double the size
        currentSize = 0;

        table = new Node *[totalSize]; // Create new table

        // Initialize new table
        for (int i = 0; i < totalSize; i++)
        {
            table[i] = nullptr;
        }

        // Reinsert old elements into new table
        for (int i = 0; i < oldSize; i++)
        {
            Node *current = oldTable[i];

            while (current != nullptr)
            {
                insert(current->key, current->value);
                current = current->next;
            }

            // Free old linked list
            if (oldTable[i] != nullptr)
            {
                delete oldTable[i];
            }
        }
    }

public:
    // Constructor
    HashTable(int size)
    {
        totalSize = size;
        currentSize = 0;

        table = new Node *[totalSize];

        for (int i = 0; i < totalSize; i++)
        {
            table[i] = nullptr;
        }
    }

    // Hash Function
    int hashFunction(string key)
    {
        int hashValue = 0;

        for (char ch : key)
        {
            hashValue += int(ch); // Simple sum of ASCII values
        }

        return hashValue % totalSize; // Ensure the hash value fits within the table size
    }

    // Insert Operation
    void insert(string key, int value)
    {
        int index = hashFunction(key);

        Node *newNode = new Node(key, value);

        // Insert at the beginning of the linked list for collision handling
        newNode->next = table[index];
        table[index] = newNode;

        currentSize++;

        // Load Factor Calculation
        double lamda = currentSize / (double)totalSize;
        double threshold = 0.7;

        // if lamda exceeds threshold, rehashing can be implemented here
        if (lamda > threshold)
        {
            rehash(); // Rehash the table for better performance
        }
    }

    // Delete Operation
    void remove(string key)
    {
        int index = hashFunction(key);

        Node *current = table[index];
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (current->key == key)
            {
                // Item found at start of linked list
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }

                currentSize--;
                return;
            }

            prev = current;
            current = current->next;
        }
    }

    // Search Operation
    int search(string key)
    {
        int index = hashFunction(key);
        Node *current = table[index];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }

        return -1; // Key not found
    }

    void print()
    {
        cout << "-------------------------" << endl;
        for (int i = 0; i < totalSize; i++)
        {
            cout << "Bucket " << i << ": ";
            Node *current = table[i];

            while (current != nullptr)
            {
                cout << "[" << current->key << ": " << current->value << "] -> ";
                current = current->next;
            }

            cout << "nullptr" << endl;
        }
        cout << "-------------------------" << endl;
    }
};

int main(void)
{
    HashTable ht(10);

    ht.insert("apple", 100);
    ht.insert("banana", 200);
    ht.insert("orange", 300);

    cout << "Hash Table Contents:" << endl;
    ht.print();

    cout << "Value for 'apple': " << ht.search("apple") << endl;   // Output: 100
    cout << "Value for 'banana': " << ht.search("banana") << endl; // Output: 200
    cout << "Value for 'grape': " << ht.search("grape") << endl;   // Output: -1 (not found)

    ht.remove("banana");
    cout << "Value for 'banana' after deletion: " << ht.search("banana") << endl; // Output: -1 (not found)

    return 0;
}

/*
    Hashing:
    A technique used to uniquely identify a specific object from a group of similar objects.
    It uses a mathematical function called a hash function to convert input data of arbitrary size into a fixed-size value, known as a hash code or hash value.

    Hash Function:
    A hash function takes an input (or 'key') and returns a fixed-size string of bytes. The output, typically a hash code, is used to index into an array of buckets or slots, from which the desired value can be found.

    Hash Table:
    Unordered data structures that store key-value pairs.
    Operations:
    - Insert Operation // O(1) on average
    - Delete Operation // O(1) on average
    - Search Operation // O(1) on average
*/