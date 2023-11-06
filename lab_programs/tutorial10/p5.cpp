// Kruskal's algoritm
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;

    // Comparator for sorting edges
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

class Graph {
public:
    int V; // Number of vertices
    vector<Edge> edges; // List of edges

    Graph(int V) {
        this->V = V;
    }

    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    vector<Edge> kruskalMST() {
        vector<Edge> result; // To store the edges of the MST
        vector<int> parent(V, -1);

        // Sort edges in non-decreasing order of their weights
        sort(edges.begin(), edges.end());

        for (const Edge &edge : edges) {
            int srcParent = find(parent, edge.src);
            int destParent = find(parent, edge.dest);

            if (srcParent != destParent) {
                result.push_back(edge);
                Union(parent, srcParent, destParent);
            }
        }

        return result;
    }

    int find(vector<int> &parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void Union(vector<int> &parent, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);
        parent[xRoot] = yRoot;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    vector<Edge> result = g.kruskalMST();

    for (const Edge &edge : result) {
        cout << "Edge: " << edge.src << " - " << edge.dest << " Weight: " << edge.weight << endl;
    }

    return 0;
}
