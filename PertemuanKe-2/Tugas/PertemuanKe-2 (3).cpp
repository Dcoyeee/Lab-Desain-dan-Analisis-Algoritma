#include <iostream>
using namespace std;

void swap(int ass[], int posdani, int posfahdlu){ //menukarkan nilai yang ada pada array
	int temp;
	temp = ass[posdani];
	ass[posdani] = ass[posfahdlu];
	ass[posfahdlu] = temp;	
}

int partition(int ass[], int lowrohman, int high, int pivot){ //untuk membagi dan mengecek value
	int i = lowrohman;
	int j = lowrohman;
	while(i <= high){ //mengecek value array per index, apakah lebih besar atau lebih kecil dari pivot
		if(ass[i] > pivot){
			i++;
		}else{
			swap(ass, i, j); //memanggil fungsi tukar jika lebih besar dari pivot
			i++;
			j++;
		}
	}
	return j-1; //mengurangi index j
}

void quicksort(int ass[], int lowrohman, int high){
	if(lowrohman < high){ //mengecek ukuran index awal dengan panjang array
		int pivot = ass[high]; //mendeklarasi pivot dengan array index paling akhir
		int pos = partition(ass, lowrohman, high, pivot); //mendeklarasi pos dengan fungsi partisi
		
		quicksort(ass, lowrohman, pos-1);
		quicksort(ass, pos+1, high);
	}
}

int main(){
	int n;
	cout<<"tentukan panjang array : ";
	cin>>n;
	int ass[n];
	for(int i = 0; i < n; i++){
		cin>>ass[i];
	}
	quicksort(ass, 0, n-1);
	cout<<"Berikut adalah array yang telah di sortir : ";
	for(int i = 0; i < n; i++){
		cout<<ass[i]<<"\t";
	}
	return 0;
}
