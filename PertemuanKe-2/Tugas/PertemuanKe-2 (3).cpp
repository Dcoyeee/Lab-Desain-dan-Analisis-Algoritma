#include <iostream>
using namespace std;

void swap(int arr[], int pos1, int pos2){ //menukarkan nilai yang ada pada array
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;	
}

int partition(int arr[], int low, int high, int pivot){ //untuk membagi dan mengecek value
	int i = low;
	int j = low;
	while(i <= high){ //mengecek value array per index, apakah lebih besar atau lebih kecil dari pivot
		if(arr[i] > pivot){
			i++;
		}else{
			swap(arr, i, j); //memanggil fungsi tukar jika lebih besar dari pivot
			i++;
			j++;
		}
	}
	return j-1; //mengurangi index j
}

void quicksort(int arr[], int low, int high){
	if(low < high){ //mengecek ukuran index awal dengan panjang array
		int pivot = arr[high]; //mendeklarasi pivot dengan array index paling akhir
		int pos = partition(arr, low, high, pivot); //mendeklarasi pos dengan fungsi partisi
		
		quicksort(arr, low, pos-1);
		quicksort(arr, pos+1, high);
	}
}

int main(){
	int n;
	cout<<"tentukan panjang array : ";
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	quicksort(arr, 0, n-1);
	cout<<"Berikut adalah array yang telah di sortir : ";
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<"\t";
	}
}
