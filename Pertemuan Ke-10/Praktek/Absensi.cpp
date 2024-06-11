#include <iostream>
#include <vector>
using namespace std;

class graf {
private:
    int jumlahSimpul;
    vector<vector<int>> matriksKetetanggan;

public:
    graf(int simpul) : jumlahSimpul(simpul) {
        for (int i = 0; i < simpul; i++) {
            vector<int> baris(simpul, 0);
            matriksKetetanggan.push_back(baris);
        }
    }

    void tambahSisi(int u, int v) {
        if (u >= 0 && u < jumlahSimpul && v >= 0 && v < jumlahSimpul) {
            matriksKetetanggan[u][v] = 1;
            matriksKetetanggan[v][u] = 1;
        } else {
            cout << "Sisi titik tidak valid! " << endl;
        }
    }

    void hapusSisi(int u, int v) {
        if (u >= 0 && u < jumlahSimpul && v >= 0 && v < jumlahSimpul) {
            matriksKetetanggan[u][v] = 0;
            matriksKetetanggan[v][u] = 0;
        } else {
            cout << "Sisi titik tidak valid! " << endl;
        }
    }

    void tampilan() {
        for (int i = 0; i < jumlahSimpul; i++) {
            for (int j = 0; j < jumlahSimpul; j++) {
                cout << matriksKetetanggan[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int simpul = 5; 
    graf g(simpul);

    g.tambahSisi(0, 1);
    g.tambahSisi(0, 4);
    g.tambahSisi(1, 2);
    g.tambahSisi(1, 4);
    g.tambahSisi(2, 3);
    g.tambahSisi(3, 4);

    cout << "Matriks Ketetanggan:" << endl;
    g.tampilan();

    g.hapusSisi(1, 2);
    cout << "Matriks Ketetanggan setelah menghapus sisi antara 1 dan 2:" << endl;
    g.tampilan();

    return 0;
}