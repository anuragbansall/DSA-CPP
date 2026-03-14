#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    };

    void addEdge(int i, int j, bool undir = true) // i -- j
    {
        l[i].push_back(j);

        if (undir)
        {
            l[j].push_back(i);
        }
    };

    void printAdjList()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "->";
            for (auto node : l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    };

    void bfs(int start)
    {
        queue<int> q;
        unordered_map<int, bool> visited; // element, isVisited

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }

        cout << endl;
    }
};

int main(void)
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.printAdjList();
    cout << endl;
    g.bfs(0); // Output Should be: 0 1 2 3

    return 0;
}

/*
    Graph BFS (Breadth First Search):
    1. BFS is a graph traversal algorithm that explores the graph level by level.
    2. It uses a queue data structure to keep track of the nodes to be explored next.
    3. BFS starts from a given source node and explores all its neighbors before moving to the next level of neighbors.
    4. BFS is useful for finding the shortest path in an unweighted graph and for traversing all the nodes in a graph.

    Example of BFS:
    Consider the following graph:
        0 --- 1
        |     |
        2 --- 3
    If we start BFS from node 0, the order of traversal will be:
    0 -> 1 -> 2 -> 3
*/