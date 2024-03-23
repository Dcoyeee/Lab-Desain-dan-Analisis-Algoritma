#include <iostream>
using namespace std;

void hasilData(int Data[], int Jumlah) {
    cout << "Data sebelum sorting: "; 
    for (int i = 0; i < Jumlah; i++) {
        cout << Data[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int Data[], int Jumlah) {
    int temp, pos;
    for (int a = 0; a < Jumlah; a++) {
        temp = Data[a];
        pos = a;
        for (int b = a + 1; b < Jumlah; b++) {
            if (Data[b] > temp) {
                temp = Data[b];
                pos = b;
            }
        }
        Data[pos] = Data[a];
        Data[a] = temp;

        
        cout << "Iterasi ke-" << a + 1 << " : ";
        for (int c = 0; c < Jumlah; c++) {
            cout << Data[c] << " ";
        }
        cout << endl;
    }
}

int main() {
    int Jumlah;
    cout << "Masukkan jumlah elemen: ";
    cin >> Jumlah;

    int Data[Jumlah];

    // Memasukkan elemen array
    for (int i = 0; i < Jumlah; i++) {
        cout << "Masukkan nilai elemen ke-" << i + 1 << " : ";
        cin >> Data[i];
    }
    cout << endl;

    // Menampilkan data sebelum sorting
    hasilData(Data, Jumlah);
    cout << endl;

    // Melakukan sorting
    bubbleSort(Data, Jumlah);

    // Menampilkan data setelah sorting
    cout << "Data setelah sorting : ";
    for (int d = 0; d < Jumlah; d++) {
        cout << Data[d] << " ";
    }
    cout << endl;

    return 0;
}
