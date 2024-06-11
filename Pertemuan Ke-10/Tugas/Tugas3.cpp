#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int destination;
    int weight;
};

void addEdge(vector<Edge> adj[], int u, int v, int weight) {
    Edge edge;
    edge.destination = v;
    edge.weight = weight;
    adj[u].push_back(edge);
}

void printAdjacencyList(vector<Edge> adj[], int V) {
    cout << "Daftar Ketetanggaan (Graf Berbobot):" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Simpul " << i << ":";
        if (!adj[i].empty()) {
            for (Edge edge : adj[i]) {
                cout << " -> (" << edge.destination << ", " << edge.weight << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<Edge> adj[V];

    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);

    printAdjacencyList(adj, V);

    return 0;
}