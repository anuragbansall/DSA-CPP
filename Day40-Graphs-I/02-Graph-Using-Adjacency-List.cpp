#include <iostream>
#include <list> // List is a double linked list in C++. We can use it to store the adjacent nodes of each node in the graph.
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
};

int main(void)
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    /*
    The graph looks like this:
        0 --- 1
        |     |
        2 --- 3
    */

    g.printAdjList();

    return 0;
}

/*
    Graph using Adjacency List:
    - An adjacency list is a way to represent a graph using a list of lists. Each node has a list of its adjacent nodes. This is an efficient way to represent sparse graphs, where the number of edges is much less than the square of the number of nodes.
    - For example, consider the following graph:
        A --- B
        |     |
        C --- D
    - The adjacency list representation of this graph would be:
        A: B, C
        B: A, D
        C: A, D
        D: B, C
    - In this representation, each node has a list of its adjacent nodes. For example, node A has two adjacent nodes, B and C. Node B has two adjacent nodes, A and D, and so on.
*/