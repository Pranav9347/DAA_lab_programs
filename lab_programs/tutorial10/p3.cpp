//Dijkstra's algoritm
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Graph class to represent the weighted graph
class Graph {
public:
    int V; // Number of vertices
    vector<vector<pair<int, int>> > adj; // Adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // Assuming an undirected graph
    }

    // Dijkstra's algorithm to find the shortest path
    void dijkstra(int src) {
        int INF = 1000000; // Replace with a sufficiently large integer value
        vector<int> dist(V, INF);
        set<pair<int, int>> s; // Set to store vertices and their distances

        dist[src] = 0;
        s.insert(make_pair(0, src));

        while (!s.empty()) {
            pair<int, int> tmp = *(s.begin());
            s.erase(s.begin());

            int u = tmp.second;

            for (const auto &edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[v] > dist[u] + weight) {
                    if (dist[v] != INF) {
                        s.erase(s.find(make_pair(dist[v], v));
                    }

                    dist[v] = dist[u] + weight;
                    s.insert(make_pair(dist[v], v));
                }
            }
        }

        // Print the shortest distances from the source to all other vertices
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": Distance = " << dist[i] << endl;
        }
    }
};

int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 6);
    g.addEdge(3, 5, 4);
    g.addEdge(4, 5, 2);

    int src = 0;
    g.dijkstra(src);

    return 0;
}
