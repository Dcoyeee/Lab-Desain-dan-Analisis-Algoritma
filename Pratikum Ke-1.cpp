#include <iostream>
using namespace std;

void buble(int arr[], int n){
	int i, j, tmp;
	for(i = 0; i < n; i++){
		for(j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

int main(){
	int x[100], y, z;
	
	cout<<"Masukan banyak elemen : ";
	cin>>y;
	cout<<"Masukan nilai : \n";
	for(int i = 0; i < y; i++){
		cin>>x[i];
	}
	
	buble(x, y);
	
	cout<<"Hasil pengurutan dengan algoritma bubble sort :\n";
	for(int i = 0; i < y; i++){
		cout<<x[i]<<" ";
	}
	
	cout<<endl;
	return 0;
}
