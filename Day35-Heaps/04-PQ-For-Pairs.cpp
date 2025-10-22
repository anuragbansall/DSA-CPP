#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct ComparePairs
{
    // Overload the () operator to compare pairs based on the second element (marks)
    bool operator()(const pair<string, int> &p1, const pair<string, int> &p2)
    {
        return p1.second < p2.second; // Max-Heap based on marks
    }
};

int main(void)
{
    // Priority queue to store pairs of (name, marks)
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePairs> pq; // Max-Heap based on marks

    // Insert pairs into the priority queue
    pq.push(make_pair("Alice", 85));
    pq.push(make_pair("Bob", 90));
    pq.push(make_pair("Charlie", 78));

    // Pop and display students in order of their marks
    while (!pq.empty())
    {
        pair<string, int> p = pq.top();
        cout << "Name: " << p.first << ", Marks: " << p.second << endl;
        pq.pop();
    }

    return 0;
}