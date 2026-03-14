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

    void dfsHelper(int node, unordered_map<int, bool> &visited)
    {
        cout << node << " ";
        visited[node] = true;

        for (auto nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
    }

    void dfs(int start)
    {
        unordered_map<int, bool> visited; // element, isVisited
        dfsHelper(start, visited);
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
    g.dfs(0); // Output Should be: 0 1 3 2

    return 0;
}

/*
    Graph DFS (Depth First Search):
    1. DFS is a graph traversal algorithm that explores the graph depth by depth.
    2. It uses a stack data structure to keep track of the nodes to be explored next.
    3. DFS starts from a given source node and explores as far as possible along each branch before backtracking.
    4. DFS is useful for finding a path between two nodes and for traversing all the nodes in a graph.

    Example of DFS:
    Consider the following graph:
        0 --- 1
        |     |
        2 --- 3
    If we start DFS from node 0, the order of traversal will be:
    0 -> 1 -> 3 -> 2
*/