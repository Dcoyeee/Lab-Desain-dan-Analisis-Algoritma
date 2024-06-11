#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    public:
        Graph(int V);
        void addEdge(int v, int w);
        void printAdjacencyList();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::printAdjacencyList() {
	 cout << "Daftar Ketetanggaan (Graf tidak Berarah):" << endl;
    for (int v = 0; v < V; ++v) {
        cout << "Simpul " << v << ":";
        for (auto x : adj[v])
            cout << " -> " << x;
        cout << endl;
    }
}

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printAdjacencyList();

    return 0;
}