#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    vector<int> heap;

    void heapifyUp(int index)
    {
        if (index == 0)
            return; // Reached the root

        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex]) // Max-Heap property
        {
            swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index)
    {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int largestIndex = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[largestIndex])
        {
            largestIndex = leftChildIndex;
        }
        if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[largestIndex])
        {
            largestIndex = rightChildIndex;
        }

        if (largestIndex != index)
        {
            swap(heap[index], heap[largestIndex]);
            heapifyDown(largestIndex);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);      // Step 1: Add the new element at the end
        heapifyUp(heap.size() - 1); // Step 2: Heapify Up
    }

    int pop()
    {
        if (heap.empty())
            throw runtime_error("Heap is empty");

        int rootValue = heap[0];
        heap[0] = heap.back(); // Step 1: Replace root with last element
        heap.pop_back();       // Step 2: Remove last element
        heapifyDown(0);        // Step 3: Heapify Down

        return rootValue;
    }

    int top()
    {
        if (!heap.empty())
            return heap[0];
        throw runtime_error("Heap is empty");
    }
};

int main(void)
{
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);

    cout << "Top element in the heap: " << h.top() << endl; // Should print 50 for Max-Heap

    return 0;
}

/*
    Heap as an array / vector:
    Example:
        Complete Binary Tree:
                  10
                /    \
              20      30
             /  \    /  \
           40   50  60   70

        Array Representation: [10, 20, 30, 40, 50, 60, 70]

    Properties:
    1. For any node at index i:
        - Left Child is at index 2*i + 1
        - Right Child is at index 2*i + 2
        - Parent is at index (i - 1) / 2

    Operations:
    1. Insertion:
        Step 1: Add the new element at the end of the array.
            heap.push_back(newElement);
        Step 2: "Heapify Up" to maintain heap property.
            compare the added element with its parent and swap if necessary, repeat until the heap property is restored.

    2. Deletion:
        Step 1: Replace the root with the last element in the array.
        Step 2: Remove the last element.
        Step 3: "Heapify Down" to maintain heap property.
            compare the new root with its children and swap with the larger child if necessary, repeat until the heap property is restored.
*/