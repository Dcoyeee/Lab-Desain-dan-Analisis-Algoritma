#include <iostream>
using namespace std;

void merge (int arr[], int l, int m, int r){ //untuk membagi dan menggabungkan value
	int x, y, z;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1], R[n2]; //membagi array menjadi 2
	for (x = 0; x < n1; x++) 
        L[x] = arr[l + x]; //memasukan value array  arr ke array l 
	for (y = 0; y < n2; y++) 
	    R[y] = arr[m + 1 + y]; //memasukan value array  arr ke array r
	
	x = 0;
	y = 0;
	z = l;
	
	while(x < n1 && y < n2) {
		if (L[x] <= R[y]) { //mengecek array l apakah lebih kecil atau tidak dari pada array r
			arr[z] = L[x]; //menukar value array sesuai syarat array
			x++;
		}else {
			arr[z] = R[y]; //menukar value array sesuai syarat array
			y++;
		}
		z++;
	}
	while (x < n1) {
		arr[z] = L[x]; //merubah value array
		x++;
		z++;
	}
	
	while (y < n2) 	{
		arr[z] = R[y]; //merubah value array
		y++;
		z++;
	}
}

void mergesort(int arr[], int l, int r){ //untuk menggabungkan urutan
	if (l < r) 	{
		int m = l + (r - l) / 2;
		
		mergesort (arr, l, m);
		mergesort (arr, m + 1, r);
		
		merge(arr, l, m, r);
	}
}

void show(int A[], int size){ //untuk menampilkan value array
	int i;
	for (i = 0; i < size; i++) 
		cout << A[i] << " ";
}

int main() {
    int size;
    cout << "Masukan banyak data : ";
    cin >> size;

    int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "\nMasukkan Data Array ke - " << i << " = ";
		cin >> arr[i];
	}

    mergesort(arr, 0, size - 1);

    cout << "Hasil : ";
    show(arr, size);


    return 0;
}
