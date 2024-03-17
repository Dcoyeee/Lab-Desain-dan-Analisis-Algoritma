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


// #include <iostream>
// using namespace std;

// int main(){
// 	int a[105], c;
	
// 	cout<<"x : ";
// 	for(int i = 0; i < 4; i++){
// 		cin>>a[i];
// 	}
	
// 	for(int j = 0; j < 4; j++){
// 		cout<<"Tahap "<< j+1 << " : ";
// 			for(int k = 0; k < 4-1; k++){
// 				if(a[k] > a[k+1]){
// 					c = a[k];
// 					a[k] = a[k+1];
// 					a[k+1] = c;
// 				}
// 			}
// 			for(int l = 0; l < 4; l++){
// 				cout<<a[l]<<" ";
// 			}
// 		cout<<endl;
// 	}
	
// 	cout<<"Hasil : ";
// 		for(int k = 0; k < 4; k++){
// 			if(a[k] > a[k+1]){
// 				c = a[k];
// 				a[k] = a[k+1];
// 				a[k+1] = c;
// 			}
// 			cout<<a[k]<<" ";
// 		}
// }
