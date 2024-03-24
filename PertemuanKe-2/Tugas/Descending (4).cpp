#include<iostream>
using namespace std;

void swap(int aqq[], int posdani, int posfahdlu){
    int temp;
    temp = aqq[posdani];
    aqq[posdani] = aqq[posfahdlu];
    aqq[posfahdlu] = temp;
}

int partition(int aqq[], int lowrohman, int highalen, int pivot){
    int i = lowrohman - 1; 
    for (int j = lowrohman; j <= highalen - 1; j++){
        
        if (aqq[j] > pivot){
            i++; 
            swap(aqq, i, j);
        }
    }
    swap(aqq, i + 1, highalen);
    return (i + 1);
}

void quicksort(int aqq[], int lowrohman, int highalen){
    if (lowrohman < highalen){
        
        int pivot = aqq[highalen];
        int pi = partition(aqq, lowrohman, highalen, pivot);
        
        
        quicksort(aqq, lowrohman, pi - 1);
        quicksort(aqq, pi + 1, highalen);
    }
}

int main(){
    int n;
    cout << "Tentukan Panjang Array : ";
    cin >> n;
    int aqq[n];
    cout << "Masukkan Elemen Array: ";
    for (int i = 0; i < n; i++){
        cin >> aqq[i];
    }
    quicksort(aqq, 0, n - 1);
    cout << "Array setelah diurutkan secara descending: ";
    for (int i = 0; i < n; i++){ 
        cout << aqq[i] << " ";
    }
return 0;
}

