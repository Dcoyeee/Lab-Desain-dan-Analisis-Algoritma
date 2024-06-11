#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

using namespace std;

void printMatrix(vector<vector<int>>& costMatrix) {
    cout << "Cost List :" << endl;
    for (size_t i = 0; i < costMatrix.size(); ++i) {
        for (size_t j = 0; j < costMatrix[i].size(); ++j) {
            cout << "\t" << costMatrix[i][j];
        }
        cout << endl;
    }
}

void cariJalurTerdekat(vector<vector<int>>& costMatrix, int numKota) {
    vector<int> path(numKota);
    for (int i = 0; i < numKota; ++i)
        path[i] = i;

    int minCost = INT_MAX;
    vector<int> shortestPath;

    do {
        int currentCost = 0;
        for (int i = 0; i < numKota - 1; ++i)
            currentCost += costMatrix[path[i]][path[i + 1]];
        currentCost += costMatrix[path[numKota - 1]][path[0]];   

        if (currentCost < minCost) {
            minCost = currentCost;
            shortestPath = path;
        }

    } while (next_permutation(path.begin() + 1, path.end())); 

    cout << "\nJalur Terpendek : ";
    for (int i = 0; i < numKota; ++i) {
        cout << shortestPath[i] + 1;
        if (i != numKota - 1)
            cout << "--->";
    }
    cout << "--->" << shortestPath[0] + 1 << endl; 

    cout << "\nMinimum Cost : " << minCost << endl;
}

int main() {
    int numKota;
    cout << "Masukkan Jumlah Kota: ";
    cin >> numKota;

    vector<vector<int>> costMatrix(numKota, vector<int>(numKota));

    cout << "Nilai Cost Matrix" << endl;
    for (int i = 0; i < numKota; ++i) {
        cout << "Cost Element Baris ke-: " << i + 1 << endl;
        for (int j = 0; j < numKota; ++j) {
            cin >> costMatrix[i][j];
        }
        cout << endl;
    }

    printMatrix(costMatrix);
    cariJalurTerdekat(costMatrix, numKota);

    return 0;
}
