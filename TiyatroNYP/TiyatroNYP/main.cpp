#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "salon.h"
#include "oyun.h"


using namespace std;

ofstream yaz;
ifstream oku;



class theatre {
public:
	string ad, soyad;
	int durak, okuyucu = 0, okuyucu1 = 0;
	int bakiye;
	int ID = 1;
	int fakeid;


	theatre();
	void kullanýcýekle();
	void kullanýcýlistele();
	void bakiyeguncelle(int);
	int kullanýcýgetir(int);
	void paraiade(int);
	void biletucretal(int);
	void bakiyekontrol(int);
};

int main() {

	int secim = 0;
	theatre t;
	salon s;
	oyun o;

	o.oyungoster();
	do {

		cout << endl << "----------------------------------------------------" << endl;
		cout << "1=> Kayit ol" << endl;
		cout << "2=> Bilet al" << endl;
		cout << "3=> Salon gor" << endl;
		cout << "4=>Bilet iade" << endl;
		cout << "5=>Hesaba para ekle" << endl;
		cout << "6=>Kullanici getir" << endl;
		cout << "7=>Oyun Listesi" << endl;
		cout << "8=>Tum kullanicilari goster" << endl;
		cout << "0=>Cikis yap" << endl;
		cout << endl;
		cout << "Islem numarasi giriniz : "; cin >> secim;

		switch (secim)
		{
		case 1: t.kullanýcýekle(); break;

		case 2: {

			cout << "-----BILET ALMA PLATFORMU-----" << endl << endl;

			int id;  cout << "ID giriniz : "; cin >> id; cout << endl;

			if (!t.kullanýcýgetir(id)) { cout << " KULLANICI KAYITLI DEGIL.." << endl;  break; }

			t.bakiyekontrol(id);

			int salonno; cout << "Salon no giriniz : "; cin >> salonno; cout << endl;
			int seansno; cout << "Seans kodunu giriniz : "; cin >> seansno; cout << endl;

			s.salongetir(seansno);

			cout << endl;

			s.koltuklal(seansno);

			s.salongetir(seansno);

			o.biletkes(id, seansno, salonno);

			t.biletucretal(id);

			cout << "Satis Basarili !!!" << endl;

			break;
		}

		case 3: {
			int a;
			cout << "Seans kodunu giriniz : "; cin >> a;
			s.salongetir(a);
			break;
		}

		case 4: {
			int id; cout << "ID giriniz : "; cin >> id;
			t.paraiade(id);
			s.koltukiade();
			o.biletiptal(id);
			break;

		}

		case 5: {
			int id; cout << "ID giriniz : "; cin >> id;
			t.bakiyeguncelle(id);
			break;
		}

		case 6: {
			int id; cout << "ID giriniz : "; cin >> id;
			t.kullanýcýgetir(id);
			break;
		}

		case 7: {
			o.oyungoster(); break;
		}

		case 8: {
			t.kullanýcýlistele(); break;
		}

		case 0: break;


		default: break;
		}
	} while (secim != 0);

}

theatre::theatre() {
	yaz.open("musteri.txt", ios::out);

	yaz << "ID\t\t\tAD\t\t\tSOYAD\t\t\tBakiye" << endl;
	yaz << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	durak = yaz.tellp();

	bakiye = 0;

	yaz.close();

}

void theatre::kullanýcýekle() {

	yaz.setf(ios::left);
	yaz.open("musteri.txt", ios::out | ios::app);

	cout << "---KULLANICI EKLEME PLATFORMU---" << endl;
	cout << "----------------------------------" << endl;
	cout << "AD : ";
	cin >> ad;

	cout << "SOYAD : ";
	cin >> soyad;

	yaz << setw(24) << ID << setw(24) << ad << setw(24) << soyad << setw(24) << bakiye << endl;
	cout << endl;

	cout << "ID : " << ID << endl;
	cout << "AD : " << ad << endl;
	cout << "SOYAD : " << soyad << endl;
	cout << "BAKIYE : " << bakiye << endl << endl;
	cout << "Kullanici ekleme basarili.." << endl << endl;

	yaz.close();
	ID++;
}

void theatre::kullanýcýlistele() {
	oku.open("musteri.txt", ios::in | ios::app);
	oku.seekg(durak);

	cout << "------------------------" << endl;
	cout << "      KULLANICILAR      " << endl;
	cout << "------------------------" << endl;

	while (oku >> fakeid >> ad >> soyad >> bakiye) {
		cout << "KULLANICI " << fakeid << endl;
		cout << "---------------" << endl;
		cout << "ID : " << fakeid << endl;
		cout << "AD : " << ad << endl;
		cout << "SOYAD : " << soyad << endl;
		cout << "BAKIYE : " << bakiye << endl;
		cout << "---------------" << endl;
		cout << endl;
	}
	oku.close();
}

int theatre::kullanýcýgetir(int a) {
	int v;
	oku.close();
	oku.open("musteri.txt", ios::in);
	oku.seekg(durak);

	while (oku >> v >> ad >> soyad >> bakiye) {

		cout << "---------------" << endl;
		cout << "ID : " << v << endl;
		cout << "AD : " << ad << endl;
		cout << "SOYAD : " << soyad << endl;
		cout << "BAKIYE : " << bakiye << endl;
		cout << "---------------" << endl;
		cout << endl;
		oku.close();
		return 1;

	}
	cout << "Kullanici bulunamadý..";
	oku.close();
	return 0;

}

void theatre::bakiyeguncelle(int a) {


	oku.close();
	int miktar;
	cout << "----BAKIYE GUNCELLEME PLATFORMU----" << endl << endl;
	cout << "Eklemek istediginiz miktari giriniz : ";
	cin >> miktar;

	yaz.open("musteri1.txt", ios::out);
	oku.open("musteri.txt", ios::in);

	oku.seekg(durak);

	yaz << "ID\t\t\tAD\t\t\tSOYAD\t\t\tBakiye" << endl;
	yaz << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	while (oku >> ID >> ad >> soyad >> bakiye)
	{
		if (ID == a)
		{
			bakiye += miktar;
			yaz << setw(24) << ID << setw(24) << ad << setw(24) << soyad << setw(24) << bakiye << endl;

			cout << "Bakiyeniz basariyla guncellendi.." << endl << endl;
		}
		else
			yaz << setw(24) << ID << setw(24) << ad << setw(24) << soyad << setw(24) << bakiye << endl;
	}



	yaz.close();
	oku.close();

	remove("musteri.txt");
	rename("musteri1.txt", "musteri.txt");

	kullanýcýgetir(a);

}

void theatre::paraiade(int x) {

	yaz.open("musteri1.txt", ios::out);
	oku.open("musteri.txt", ios::in);
	oku.seekg(durak);

	yaz << "ID\t\t\tAD\t\t\tSOYAD\t\t\tBakiye" << endl;
	yaz << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	while (oku >> ID >> ad >> soyad >> bakiye)
	{
		if (ID == x)
		{
			bakiye += 10;
			yaz << setw(24) << ID << setw(24) << ad << setw(24) << soyad << setw(24) << bakiye << endl;
		}
		else
			yaz << setw(24) << ID << setw(24) << ad << setw(24) << soyad << setw(24) << bakiye << endl;
	}

	yaz.close();
	oku.close();

	remove("musteri.txt");
	rename("musteri1.txt", "musteri.txt");
}

void theatre::biletucretal(int y) {

	yaz.open("musteri1.txt", ios::out);
	oku.open("musteri.txt", ios::in);
	oku.seekg(durak);

	yaz << "ID\t\t\tAD\t\t\tSOYAD\t\t\tBakiye" << endl;
	yaz << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	while (oku >> ID >> ad >> soyad >> bakiye)
	{
		if (ID == y)
		{
			bakiye -= 10;
			yaz << setw(24) << ID << setw(24) << ad << setw(24) << soyad << setw(24) << bakiye << endl;
			cout << endl;
			cout << "Bilet ucreti alindi" << endl;
		}
		else {
			yaz << setw(24) << ID << setw(24) << ad << setw(24) << soyad << setw(24) << bakiye << endl;
		}
	}

	yaz.close();
	oku.close();

	remove("musteri.txt");
	rename("musteri1.txt", "musteri.txt");

}

void theatre::bakiyekontrol(int z) {
	bool h = false;
	oku.open("musteri.txt", ios::in);
	cout << "Bakiye kontrol ediliyor.." << endl;
	oku.seekg(durak);
	while (oku >> okuyucu1 >> ad >> soyad >> bakiye) {

		if (okuyucu1 == z) {

			if (bakiye < 10) {
				cout << "Bakiye yetersiz" << endl << "Bakiye guncellemeye yonlendiriliyorsunuz..." << endl << endl;
				bakiyeguncelle(z);
				h = true;
			}
			else if (h) {
				biletucretal(z);
			}
		}
	}

	oku.close();
}

