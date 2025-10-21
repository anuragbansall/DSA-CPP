#include <iostream>
#include <queue> // For priority_queue
using namespace std;

int main(void)
{
    // When we include <queue>, we get access to the priority_queue class which is used to implement heaps.

    priority_queue<int> maxHeap;                            // Max-Heap (default)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-Heap

    // Example usage
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);

    while (!maxHeap.empty())
    {
        cout << "Max-Heap Top: " << maxHeap.top() << endl; // Should print the largest element
        maxHeap.pop();
    }

    while (!minHeap.empty())
    {
        cout << "Min-Heap Top: " << minHeap.top() << endl; // Should print the smallest element
        minHeap.pop();
    }

    return 0;
}

/*
    Heaps/Priority Queues:
    - Priority Queue is a part of STL in C++. It is built on the heap data structure.
    - Priority Queue always maintains the maximum (or minimum) element at the top. Remaining elements are unordered.
    - A priority queue is a special type of queue in which each element is associated with a priority and is served according to its priority.
    - If elements have the same priority, they are served according to their order in the queue.
    - In C++, the priority_queue class is used to implement priority queues.
    - For Example:
        A college can use a priority queue to manage student registrations, where students with higher academic performance get priority in course enrollment. Will use max-heap to implement this because higher performance means higher priority.
        We can also use sorted array to get the same result but sorting takes O(n log n) time complexity while priority queue operations take O(n + k log n) time complexity.

    - Heap is a specialized tree-based data structure that satisfies the heap property.
    - In a max heap, for any given node C, if P is a parent node of C, then the key (the value) of P is greater than or equal to the key of C.
    - In a min heap, the key of P is less than or equal to the key of C.
    - The heap is used to implement priority queues, and it provides efficient access to the highest (or lowest) priority element.
    - It is visualized as a complete binary tree. But it is usually implemented using arrays / vectors for efficiency.

    - Common operations on heaps include insertion, deletion of the root element, and heapification.
    - The time complexity for these operations is O(log n), where n is the number of elements in the heap.

    - Heaps can be implemented using arrays or linked lists, but array-based implementations are more common due to their cache efficiency.

    priority_queue<int>: This creates a max-heap where the largest element is always at the top.

        priority_queue<int, vector<int>, greater<int>>: This creates a min-heap where the smallest element is always at the top.

    Methods:
    - push(element): Inserts an element into the heap. Time Complexity: O(log n)
    - pop(): Removes the top element from the heap. Time Complexity: O(log n)
    - top(): Returns the top element of the heap without removing it. Time Complexity: O(1)

    Complete Binary Tree:
    - A complete binary tree is a binary tree in which all the levels are completely filled except possibly the last level, which is filled from left to right.

    Example:
            10
          /    \
         15     30
        / \    /
      40  50  100
    - This is a complete binary tree.

    Example:
            30
          /
         15
        / \
      5   3
    - This is not a complete binary tree.
*/