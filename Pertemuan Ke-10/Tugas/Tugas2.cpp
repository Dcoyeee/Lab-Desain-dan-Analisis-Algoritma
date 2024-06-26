#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void printAdjacencyList(vector<int> adj[], int V) {
    cout << "Daftar Ketetanggaan (Graf Berarah):" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Simpul " << i << ":";
        if (!adj[i].empty()) {
            for (int v : adj[i]) {
                cout << " -> " << v;
            }
        }
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printAdjacencyList(adj, V);

    return 0;
}