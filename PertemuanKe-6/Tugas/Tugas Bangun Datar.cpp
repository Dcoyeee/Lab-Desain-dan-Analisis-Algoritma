#include <iostream>
using namespace std;

class BangunDatar {
	private:
		int lebar;
		int tinggi;
		
	public:
        void setLebarTinggi(int y, int z) {
        	lebar = y;
        	tinggi = z;
		}	
		int getLuas() const {
		return lebar * tinggi;
		}
};

class PersegiPanjang : public BangunDatar {
	public:
		BangunDatar::BangunDatar;
};

class Segitiga : public BangunDatar {
	public: 
	    BangunDatar::BangunDatar;
};

class persegi : public BangunDatar {
	public:
		BangunDatar::BangunDatar;
};

int main() {
	PersegiPanjang persegiPanjang;
	Segitiga segitiga;
	persegi persegi;
	
	int pPanjang, pLebar, sAlas, sTinggi, prPanjang, prLebar;
	
	std::cout << "Masukan panjang persegi panjang: ";
	std::cin >> pPanjang;
	std::cout << "Masukan lebar persegi panjang: ";
	std::cin >> pLebar;
	std::cout << "Masukan alas segitiga: ";
	std::cin >> sAlas;
	std::cout << "Masukan tinggi segitiga: ";
	std::cin >> sTinggi;
	std::cout << "Masukan panjang persegi: ";
	std::cin >> prPanjang;
	std::cout << "Masukan lebar persegi: ";
	std::cin >> prLebar;
	
	persegiPanjang.setLebarTinggi(pPanjang, pLebar);
	segitiga.setLebarTinggi(sAlas, sTinggi);
	persegi.setLebarTinggi(prPanjang, prLebar);
	
	std::cout << "\nLuas Persegi Panjang: " << persegiPanjang.getLuas() << std::endl;
	std::cout << "Luas segitiga: " << segitiga.getLuas() << std::endl;
	std::cout << "Luas persegi: " << persegi.getLuas() << std::endl;
	
	return 0;
}

