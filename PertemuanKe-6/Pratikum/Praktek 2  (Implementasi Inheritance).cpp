#include <iostream>
using namespace std;

class BangunDatar {
	protected:
		int lebar, tinggi;
	
	public:
		void set_value(int a, int b){
			lebar = a;
			tinggi = b;
		}
};

class PersegiPanjang: public BangunDatar{
	public:
		int get_value(){
			return (lebar * tinggi);
		}
};

class Segitiga: public BangunDatar{
	public:
		int get_value(){
			return (lebar * tinggi / 2);
		}
};

int main(){
	PersegiPanjang persegi_panjang;
	Segitiga segitiga;
	
	persegi_panjang.set_value(4,5);
	segitiga.set_value(10,5);
	
	cout<<persegi_panjang.get_value()<<endl;
	cout<<segitiga.get_value();
}
