#include <iostream>
#include <string>
using namespace std;

class OrangMahasiswa {
private:
    string nama;
    int npm;

public:
    void setNama(string z) {
        nama = z;
    }

    void setNPM(int y) {
        npm = y;
    }

    string getNama() {
        return nama;
    }

    int getNPM() {
        return npm;
    }
};


int main() {
    int jumlah_dataorang;
    cout << "Masukkan jumlah orang: ";
    cin >> jumlah_dataorang;

    OrangMahasiswa orang[jumlah_dataorang];
    string nama;
    int npm;

    for (int i = 0; i < jumlah_dataorang; ++i) {
        cout << "Masukkan Nama orang ke-" << i + 1 << " : ";
        cin>>nama;
        orang[i].setNama(nama);
        cout << "Masukkan NPM orang ke-" << i + 1 << " : ";
        cin >> npm;
        orang[i].setNPM(npm);
    }

    for (int i = 0; i < jumlah_dataorang; ++i) {
        cout << "Orang ke-" << i + 1 << ":" << endl;
        cout << "Nama: " << orang[i].getNama() << endl;
        cout << "NPM: " << orang[i].getNPM() << endl;
    }

    return 0;
}

