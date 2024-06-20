#include <iostream>
#include <vector>
#include <limits.h>
#include <map>

using namespace std;

#define V 6

map<char, int> charToIndex = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}};
map<int, char> indexToChar = {{0, 'A'}, {1, 'B'}, {2, 'C'}, {3, 'D'}, {4, 'E'}, {5, 'F'}};

int jarakMinimum(vector<int>& jarak, vector<bool>& setJPT) {
    int min = INT_MAX, indeks_min;
    for (int v = 0; v < V; v++)
        if (!setJPT[v] && jarak[v] <= min)
            min = jarak[v], indeks_min = v;
    return indeks_min;
}

void dijkstra(vector<vector<int>>& graf, int sumber, int tujuan) {
    vector<int> jarak(V, INT_MAX);
    vector<bool> setJPT(V, false);

    jarak[sumber] = 0;

    for (int hitung = 0; hitung < V - 1; hitung++) {
        int u = jarakMinimum(jarak, setJPT);
        setJPT[u] = true;

        for (int v = 0; v < V; v++)
            if (!setJPT[v] && graf[u][v] && jarak[u] != INT_MAX && jarak[u] + graf[u][v] < jarak[v])
                jarak[v] = jarak[u] + graf[u][v];
    }

    cout << "Jarak dari simpul " << indexToChar[sumber] << " ke simpul " << indexToChar[tujuan] << " adalah " << jarak[tujuan] << endl;
}

void printGraph(const vector<vector<int>>& graf) {
    cout << "Representasi Matriks:" << endl;
    cout << "  A -1- B\n  |     |  \\\n 2|     5   1\n  |     |    \\\n  C -2- D -2- E\n        |    /\n        2   1\n        |  /\n        F\n";
}

int main() {
    vector<vector<int>> graf = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 0, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 0, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };

    printGraph(graf);

    char simpulAsal, simpulTujuan;
    cout << "Masukkan simpul asal (A-F): ";
    cin >> simpulAsal;
    cout << "Masukkan simpul tujuan (A-F): ";
    cin >> simpulTujuan;

    int sumber = charToIndex[simpulAsal];
    int tujuan = charToIndex[simpulTujuan];

    dijkstra(graf, sumber, tujuan);

    return 0;
}