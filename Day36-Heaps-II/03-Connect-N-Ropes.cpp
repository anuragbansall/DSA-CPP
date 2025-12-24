#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    /*
        If cost to connect two ropes = sum of their lengths,
        For example, if we have two ropes of lengths 2 and 3,
        then the cost to connect these two ropes is 2 + 3 = 5.
        Find the minimum cost to connect N ropes.

        rope Lengths = {4, 3, 2, 6}
        Output: 29
        Explanation:
        1. First connect ropes of lengths 2 and 3.
           Cost = 2 + 3 = 5
        2. Now we have three ropes of lengths 4, 5 and 6.
           Connect ropes of lengths 4 and 5.
              Cost = 4 + 5 = 9
        3. Finally connect the two ropes of lengths 6 and 9.
           Cost = 6 + 9 = 15
        Total cost = 5 + 9 + 15 = 29

        Approach:
        1. Use a min-heap to store the lengths of the ropes.
        2. While there is more than one rope in the heap:
           a. Extract the two ropes of the smallest lengths.
           b. Connect them (sum their lengths) and add the cost to the total cost.
           c. Insert the new rope back into the min-heap.
    */
    vector<int> ropes = {4, 3, 2, 6};
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Step 1: Insert all rope lengths into the min-heap
    for (int length : ropes)
    {
        minHeap.push(length);
    }

    int totalCost = 0;

    while (minHeap.size() > 1)
    {
        // Step 2: Extract the two smallest lengths
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        // Step 3: Connect the ropes and update the total cost
        int cost = first + second;
        totalCost += cost;
        minHeap.push(cost);
    }

    cout << "Minimum cost to connect ropes: " << totalCost << endl;

    return 0;
}