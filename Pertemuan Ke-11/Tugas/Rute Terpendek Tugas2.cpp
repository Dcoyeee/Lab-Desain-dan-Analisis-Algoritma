#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define V 6

int jarakMinimum(vector<int>& jarak, vector<bool>& setJPT) {
    int min = INT_MAX, indeks_min;
    for (int v = 0; v < V; v++)
        if (!setJPT[v] && jarak[v] <= min)
            min = jarak[v], indeks_min = v;
    return indeks_min;
}

void graph(vector<vector<int>>& graf, int sumber) {
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

    cout << "Simpul \t Jarak dari Sumber" << endl;
    for (int i = 0; i < V; i++)
        cout << i + 1 << " \t\t" << jarak[i] << endl;
}

int main() {
    vector<vector<int>> graf = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14, 0, 2, 0, 9, 0}
    };

    int sumber = 0;
    graph(graf, sumber);

    return 0;
}