// Memuat library iostream untuk input/output
#include <iostream>

using namespace std;

// Fungsi untuk menggabungkan dua sub-array yang sudah terurut menjadi satu array terurut
void merge(int auu[], int lq, int mw, int rf) { 
    int xi, yi, zi;
    int n1 = mw - lq + 1; // Ukuran sub-array kiri
    int n2 = rf - mw; // Ukuran sub-array kanan
    int L[n1], R[n2]; // Array sementara untuk menyimpan sub-array kiri dan kanan

    // Menyalin elemen sub-array kiri ke array sementara L
    for (xi = 0; xi < n1; xi++)
        L[xi] = auu[lq + xi];

    // Menyalin elemen sub-array kanan ke array sementara R
    for (yi = 0; yi < n2; yi++)
        R[yi] = auu[mw + 1 + yi];

    xi = 0; // Indeks awal untuk array L
    yi = 0; // Indeks awal untuk array R
    zi = lq; // Indeks awal untuk array auu

    // Menggabungkan dua sub-array terurut ke dalam array auu
    while (xi < n1 && yi < n2) {
        if (L[xi] <= R[yi]) {
            auu[zi] = L[xi]; // Memasukkan elemen dari sub-array kiri ke array auu
            xi++;
        } else {
            auu[zi] = R[yi]; // Memasukkan elemen dari sub-array kanan ke array auu
            yi++;
        }
        zi++;
    }

    // Menangani sisa elemen dari sub-array kiri
    while (xi < n1) {
        auu[zi] = L[xi];
        xi++;
        zi++;
    }

    // Menangani sisa elemen dari sub-array kanan
    while (yi < n2) {
        auu[zi] = R[yi];
        yi++;
        zi++;
    }
}

// Fungsi rekursif untuk melakukan pengurutan dengan algoritma Merge Sort
void mergesort(int auu[], int lq, int rf) {
    if (lq < rf) {
        int mw = lq + (rf - lq) / 2; // Mencari indeks tengah untuk membagi array

        mergesort(auu, lq, mw); // Mengurut sub-array kiri secara rekursif
        mergesort(auu, mw + 1, rf); // Mengurut sub-array kanan secara rekursif

        merge(auu, lq, mw, rf); // Menggabungkan dua sub-array terurut
    }
}

// Fungsi untuk menampilkan elemen-elemen dalam array
void show(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main() {
    int size;
    cout << "Masukan banyak data : ";
    cin >> size;

    // Mengalokasikan memori dinamis untuk array auu
    int* auu = new int[size];

    // Meminta pengguna memasukkan nilai-nilai ke dalam array
    for (int i = 0; i < size; i++) {
        cout << "\nMasukkan Data Array ke - " << i << " = ";
        cin >> auu[i];
    }

    // Mengurut array menggunakan algoritma Merge Sort
    mergesort(auu, 0, size - 1);

    cout << "Hasil : ";
    show(auu, size); // Menampilkan array yang sudah terurut

    // Membebaskan memori yang dialokasikan untuk array auu
    delete[] auu;

    return 0;
}
