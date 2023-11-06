#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Graph {
private:
    map<int, list<int>> adj;
    map<int, bool> visited;
    bool iscyclic;
    bool bipart;

public:
    Graph() {
        iscyclic = false;
        bipart = true;
    }

    void addedge(int src, int dest) {
        adj[src].push_back(dest);
        adj[dest].push_back(src);
    }

    void Display() {
        for (auto x = adj.begin(); x != adj.end(); ++x) {
            cout << x->first;
            for (auto it = x->second.begin(); it != x->second.end(); ++it) {
                cout << "->" << *it;
            }
            cout << endl;
        }
    }

    bool cyclicity() {
        return iscyclic;
    }

    bool connectedness() {
        return visited.size() == adj.size();
    }

    bool tree() {
        return connectedness() && !iscyclic;
    }

    bool particity() {
        return bipart;
    }
};

int main(void) {
    Graph g1;
    int n;
    cout << "Enter the number of edges: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int src, dest;
        cout << "Enter source and destination for edge " << i + 1 << ": ";
        cin >> src >> dest;
        g1.addedge(src, dest);
    }

    cout << "Graph structure:" << endl;
    g1.Display();

    if (g1.connectedness()) {
        cout << "Graph is connected." << endl;
    } else {
        cout << "Graph is not connected." << endl;
    }

    if (g1.tree()) {
        cout << "The graph is a tree." << endl;
    } else {
        cout << "The graph is not a tree." << endl;
    }

    if (g1.particity()) {
        cout << "Graph is Bipartite." << endl;
    } else {
        cout << "Graph is not Bipartite." << endl;
    }

    if (g1.cyclicity()) {
        cout << "Graph is Cyclic." << endl;
    } else {
        cout << "Graph is Acyclic." << endl;
    }
}
