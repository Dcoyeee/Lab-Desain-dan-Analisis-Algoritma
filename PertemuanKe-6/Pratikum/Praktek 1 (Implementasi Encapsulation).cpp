#include <iostream>
using namespace std;

class Karyawan{
	private:
		int gaji;
	
	public: 
		void set_gaji(int s){
			gaji = s;
		}
		
		int getgaji(){
			return gaji;
		}
};

int main(){
	Karyawan myobj;
	
	myobj.set_gaji(50000);
	cout<<myobj.getgaji()<<endl;
}
