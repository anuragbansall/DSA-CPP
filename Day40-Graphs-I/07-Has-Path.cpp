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

    bool hasPathHelper(int src, int dest, unordered_map<int, bool> &visited)
    {
        if (src == dest)
        {
            return true;
        }

        visited[src] = true;

        for (auto nbr : l[src])
        {
            if (!visited[nbr])
            {
                bool nbrHasPath = hasPathHelper(nbr, dest, visited);
                if (nbrHasPath)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPath(int src, int dest)
    {
        unordered_map<int, bool> visited;
        return hasPathHelper(src, dest, visited);
    }
};

int main(void)
{
    /*
        Has Path:
        Check if path exists between source and destination in graph or not.

        Example:

        0 -- 1
        |    |
        2 -- 3

        Source: 0
        Destination: 3
        Output: true

        Source: 0
        Destination: 4
        Output: false
    */

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << g.hasPath(0, 3) << endl; // true
    cout << g.hasPath(0, 4) << endl; // true
    cout << g.hasPath(1, 7) << endl; // false

    return 0;
}