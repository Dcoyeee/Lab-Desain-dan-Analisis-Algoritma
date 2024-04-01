#include <iostream>
using namespace std;

class contoh { //Membuat class namanya contoh
	private: // Membuat private
		int nilai;
	public: //Hak akses public
		contoh (int z){
			nilai = z;
		}
		
		int getNum(){ //Membuat fungsi namanya getNum untuk mengembalikan Nilai
			return nilai; //kembalikan nilai
		}
};

int main(){ //titik utama sebuah program, yang nantinya bisa memanggil class contoh
	contoh obj(10); //Maksimal class contoh yang bisa dimasukkan 10
	cout << "nilai yang diinput: "<<obj.getNum()<<endl; //pemanggilan output
	
	return 0;
}
