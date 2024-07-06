#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class HashTable {
public:
    vector<int> table;
    int capacity;
    int size;
    int hashIndex;

    int hash1(int key) {
        return key % capacity;
    }

    int hash2(int key) {
        return 1 + (key % (capacity - 1));
    }

public:
    int getIndex(int indx) {
        return indx;
    }

    HashTable(int cap) {
        capacity = cap;
        size = 0;
        table.resize(capacity, -1);
    }

    bool isFull() {
        return size == capacity;
    }

    void insert(int key) {
        if (isFull()) {
            cout << "Hash table is full" << endl;
            return;
        }

        int index = hash1(key);
        int stepSize = hash2(key);
        
        while (table[index] != -1) {
            index = (index + stepSize) % capacity;
        }
        
        table[index] = key;
        size++;
    }

    bool search(int key) {
        int index = hash1(key);
        int stepSize = hash2(key);
        int originalIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                hashIndex = index;
                return true;
            }

            index = (index + stepSize) % capacity;

            if (index == originalIndex)
                return false;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i] != -1)
                cout << i << " --> " << table[i] << endl;
            else
                cout << i << " --> " << "empty" << endl;
        }
    }
};

int main() {
    HashTable ht(7);
    int input;

    cout << "Masukkan angka kedalam hash table (Max 7)" << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Masukkan angka ke-" << i + 1 << ": "; cin >> input;
        ht.insert(input);
    }

    cout << "Masukkan angka yang ingin dicari dari hash table: "; cin >> input;

    ht.display();

    int key = input;
    if (ht.search(key))
        cout << key << " ditemukan di hash table pada index ke-" << ht.hashIndex << endl;
    else
        cout << key << " tidak ditemukan di hash table" << endl;

    return 0;
}