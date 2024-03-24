#include <iostream>
#include <algorithm>
using namespace std;

int part(int ar[], int lowdani, int highfahdlu) {
    int pivot = ar[highfahdlu];
    int a = lowdani - 1;

    for (int j = lowdani; j < highfahdlu; j++) {
        if (ar[j] > pivot) {
            a++;
            swap(ar[a], ar[j]);
        }
    }
    swap(ar[a + 1], ar[highfahdlu]);
    return a + 1;
}

void qs(int rr[], int lowdani, int highfahdlu) {
    if (lowdani < highfahdlu) {
        int pi = part(rr, lowdani, highfahdlu);

        cout << "[ ";
        for (int a = 0; a < 10; a++) {
            cout << rr[a] << " ";
        }
        cout << " ]";
        cout << endl;

        qs(rr, lowdani, pi - 1);
        qs(rr, pi + 1, highfahdlu);
    }
}

int main() {
    int ar[100];
    
    cout << "masukkan 10 data: [ ";
    for (int a = 0; a < 10; a++) {
        cin >> ar[a];
    }
    cout << "]" << endl;
    
    system("cls");
    
    cout << "Data yang akan di sort : [ ";
    for (int a = 0; a < 10; a++) {
        cout << ar[a] << " ";
    }
    cout << "]" << endl << endl;

    cout << "Quick Sort: " << endl;
    qs(ar, 0, 10 - 1);

    return 0;
}

