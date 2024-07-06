#include <iostream>
#include <vector>
using namespace std;

int hash1(int key, int size) {
    return key % size;
}

int hash2(int key) {
    return 1 + (key % 6);
}

void insertDoubleHashing(vector<int>& hash_table, int size, int key) {
    int index = hash1(key, size);
    if (hash_table[index] == -1) {
        hash_table[index] = key;
    } else {
        int i = 1;
        while (true) {
            int new_index = (index + i * hash2(key)) % size;
            if (hash_table[new_index] == -1) {
                hash_table[new_index] = key;
                break;
            }
            i++;
        }
    }
}

void displayHashTable(const vector<int>& hash_table) {
    cout << "Isi Tabel Hash:" << endl;
    for (int i = 0; i < hash_table.size(); i++) {
        if (hash_table[i] == -1) {
            cout << i << " --> Kosong" << endl;
        } else {
            cout << i << " --> " << hash_table[i] << endl;
        }
    }
}

void searchHashTable(const vector<int>& hash_table, int size, int key) {
    int index = hash1(key, size);
    int i = 0;
    while (true) {
        int new_index = (index + i * hash2(key)) % size;
        if (hash_table[new_index] == key) {
            cout << key << " ditemukan dalam tabel hash." << endl;
            return;
        }
        if (hash_table[new_index] == -1) {
            cout << key << " tidak ditemukan dalam tabel hash." << endl;
            return;
        }
        i++;
    }
}

int main() {
    int size, n;

    cout << "Masukkan ukuran tabel hash: ";
    cin >> size;
    cout << "Masukkan jumlah elemen yang akan disisipkan: ";
    cin >> n;

    vector<int> hash_table(size, -1);

    cout << "Masukkan " << n << " elemen:" << endl;
    vector<int> elements(n);
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    for (int elem : elements) {
        insertDoubleHashing(hash_table, size, elem);
    }

    displayHashTable(hash_table);

    int key;
    cout << "Masukkan elemen yang ingin dicari dalam tabel hash: ";
    cin >> key;
    searchHashTable(hash_table, size, key);

    return 0;
}