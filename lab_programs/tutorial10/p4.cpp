// Prim's
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
public:
    int V; // Number of vertices
    vector<vector<pair<int, int>> > adj; // Adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // Assuming an undirected graph
    }

    void primMST() {
        vector<int> key(V, INF); // Key values used to pick the minimum weight edge
        vector<int> parent(V, -1); // Parent array to store the MST
        vector<bool> inMST(V, false); // To keep track of vertices included in MST

        key[0] = 0; // Start with the first vertex

        set<pair<int, int>> s;
        s.insert(make_pair(0, 0));

        while (!s.empty()) {
            int u = s.begin()->second;
            s.erase(s.begin());
            inMST[u] = true;

            for (const auto &edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!inMST[v] && weight < key[v]) {
                    s.erase(make_pair(key[v], v));
                    key[v] = weight;
                    s.insert(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        // Print the Minimum Spanning Tree
        for (int i = 1; i < V; i++) {
            cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << endl;
        }
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

    g.primMST();

    return 0;
}
