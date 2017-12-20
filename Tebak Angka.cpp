#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Fungsi mendapatkan nilai random dari 0 - 100
int random() {
	srand((unsigned)time(NULL));
	
	int r = rand() % 100;
	return r;
}

main() {
	//Deklarasi variable
	int nyawa = 7;
	int jawabanUser;
	int jawabanKomputer;
	bool gameSelesai = false; //Variabel menentukan game itu selesai atau belum
	
	//Mendapatkan nilai random dari fungsi
	jawabanKomputer = random();
	
	//Munculkan teks
	cout<<"=== PERMAINAN Tebak Angka dari 0 - 100 ==="<<endl;
	cout<<"Permainan ini adalah permainan dimana pemain menebak angka dari 0 - 100 dari angka yang diacak dengan 7 kali kesempatan."<<endl;
	
	//Looping selama nyawa lebih dari > 0 atau game belum selesai
	while(nyawa > 0 && !gameSelesai) {
		cout<<"\nMasukkan angka tebakan: ";
		cin>>jawabanUser;
		
		//Jika jawaban user kurang dari 0 atau lebih dari 100
		if(jawabanUser < 0 || jawabanUser > 100) {
			cout<<"Jawaban anda harus diantar 0 sampai 100"<<endl;
		}
		
		//Jika jawaban user terlalu rendah dari jawaban sebenearnya
		else if(jawabanUser < jawabanKomputer) {
			nyawa--; //Kurangi nyawa
			cout<<"Jawaban anda terlalu rendah, coba angka lebih tinggi lagi"<<endl;
			cout<<"Sisa nyawa anda adalah "<<nyawa<<endl;
		}
		
		//Jika jawaban user terlalu tinggi dari jawaban sebenearnya
		else if(jawabanUser > jawabanKomputer) {
			nyawa--; //Kurangi nyawa
			cout<<"Jawaban anda terlalu tinggi, coba angka lebih rendah lagi"<<endl;
			cout<<"Sisa nyawa anda adalah "<<nyawa<<endl;
		}
		
		//Jika jawabannya benar
		else {
			gameSelesai = true; //Ubah agar game menjadi selesai
			cout<<"Selamat jawaban anda benar"<<endl;
		}
		
		
		//Mengecek jika nyawa user < 1 maka kalah
		if(nyawa < 1) {
			cout<<"Maaf anda kalah, jawaban sebenarnya yaitu "<<jawabanKomputer<<endl;
		}
	}
}
