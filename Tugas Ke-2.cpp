#include <iostream>
using namespace std;

void hasilData(int arrayData[], int jumlahElemen) {
    cout << "Data sebelum sorting: "; 
    for (int i = 0; i < jumlahElemen; i++) {
        cout << arrayData[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arrayData[], int jumlahElemen) {
    int temp, pos;
    for (int a = 0; a < jumlahElemen; a++) {
        temp = arrayData[a];
        pos = a;
        for (int b = a + 1; b < jumlahElemen; b++) {
            if (arrayData[b] < temp) {
                temp = arrayData[b];
                pos = b;
            }
        }
        arrayData[pos] = arrayData[a];
        arrayData[a] = temp;

        
        cout << "Iterasi ke-" << a + 1 << " : ";
        for (int c = 0; c < jumlahElemen; c++) {
            cout << arrayData[c] << " ";
        }
        cout << endl;
    }
}


int main() {
	
    int jumlahElemen;
    cout << "Masukkan jumlah elemen: ";
    cin >> jumlahElemen;

    int arrayData[jumlahElemen];

    // Memasukkan elemen array
    for (int i = 0; i < jumlahElemen; i++) {
        cout << "Masukkan nilai elemen ke-" << i + 1 << " : ";
        cin >> arrayData[i];
    }
cout << endl;
    // Menampilkan data sebelum sorting
    hasilData(arrayData, jumlahElemen);
cout << endl;
    // Melakukan sorting
    bubbleSort(arrayData, jumlahElemen);

    // Menampilkan data setelah sorting
    cout << "Data setelah sorting : ";
    for (int d = 0; d < jumlahElemen; d++) {
        cout << arrayData[d] << " ";
    }
    cout << endl;

    return 0;
}
