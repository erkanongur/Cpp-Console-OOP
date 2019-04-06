#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ofstream yazma;
ifstream okuma;

class oyun {
public:
	int sayac;
	string oyunadi[4];
	string oyunsaat, oyunadi1;
	int oyunsure, iD, salonn;
	oyun();
	void oyungoster();
	void biletkes(int, int, int);
	void biletiptal(int);
};
oyun::oyun() {
	oyunadi[0] = "Bir Demet Tiyatro"; oyunadi[1] = "BKM Mutfak"; oyunadi[2] = "Guldur Guldur"; oyunadi[3] = "Vatan Yahut Silistre";

	yazma.setf(ios::left);
	yazma.open("bilet.txt", ios::out);

	yazma << setw(20) << "ID" << setw(20) << "Oyun Adý" << setw(20) << "Salon" << setw(20) << "Saat" << setw(20) << "Sure" << endl;
	yazma << "------------------------------------------------------------------------------------" << endl;

	sayac = yazma.tellp();
	yazma.close();
}

void oyun::oyungoster() {

	cout << "-------------------------------" << endl;
	cout << "-----------SALON 1-------------" << endl;
	cout << "       BIR DEMET TIYATRO       "; cout << "|    Demet AKBAG , Yilmaz Erdogan ve daha" << endl;
	cout << "-------------------------------"; cout << "| nice meshur oyuncularýmýzýn rol aldigi " << endl;
	cout << "          SEANSLAR             "; cout << "| 'Bir Demet Tiyatro'  her hafta yepyeni" << endl;
	cout << "   1-)12:00        2-)15:00    "; cout << "| skecleri ile karsinizda..." << endl;
	cout << "          Sure : 45 dk         " << endl;
	cout << "-------------------------------" << endl;
	cout << endl << endl;
	cout << "-------------------------------" << endl;
	cout << "-----------SALON 2-------------" << endl;
	cout << "          BKM MUTFAK           "; cout << "|    Eser Yenenler , Oguzhan Koc ve daha" << endl;
	cout << "-------------------------------"; cout << "| bircok genc yetenekli oyuncular  yeni" << endl;
	cout << "          SEANSLAR             "; cout << "| hafta yeni skecleri ile karsinizda..." << endl;
	cout << "   3-)13:00        4-)16:00    " << endl;
	cout << "          Sure : 45 dk         " << endl;
	cout << "-------------------------------" << endl;
	cout << endl << endl;
	cout << "-------------------------------" << endl;
	cout << "-----------SALON 3-------------" << endl;
	cout << "         GULDUR GULDUR         "; cout << "|    Ali Sunal ve muthis kadrosunun" << endl;
	cout << "-------------------------------"; cout << "| skeclerini kacirmayin!!!        " << endl;
	cout << "          SEANSLAR             " << endl;
	cout << "   5-)19:00        6-)20:00    " << endl;
	cout << "          Sure : 45 dk         " << endl;
	cout << "-------------------------------" << endl;
	cout << endl << endl;
	cout << "-------------------------------" << endl;
	cout << "-----------SALON 4-------------" << endl;
	cout << "     VATAN YAHUT SILISTRE      "; cout << "|    NAMIK KEMAL'in  ilk tiyatro  eseri olan" << endl;
	cout << "-------------------------------"; cout << "| 'VATAN YAHUT SILISTRE' oyunu tiyatromuzda" << endl;
	cout << "          SEANSLAR             "; cout << "| bu aksam gosterimdedir...                " << endl;
	cout << "   7-)20:00        8-)21:00    " << endl;
	cout << "          Sure : 45 dk         " << endl;
	cout << "-------------------------------" << endl;
	cout << endl << endl;
}

void oyun::biletkes(int id, int oyunno, int salonno) {
	yazma.setf(ios::left);
	yazma.open("bilet.txt", ios::out | ios::app);

	yazma << setw(20) << id;

	if (oyunno == 1) { yazma << setw(20) << oyunadi[oyunno - 1] << setw(20) << setw(20) << salonno << setw(20) << "12:00" << setw(20) << "45 dk" << endl;; }
	else if (oyunno == 2) { yazma << setw(20) << oyunadi[oyunno - 2] << setw(20) << salonno << setw(20) << "15:00" << setw(20) << "45 dk" << endl; }

	else if (oyunno == 3) { yazma << setw(20) << oyunadi[oyunno - 2] << setw(20) << salonno << setw(20) << "13:00" << setw(20) << "45 dk" << endl;; }
	else if (oyunno == 4) { yazma << setw(20) << oyunadi[oyunno - 3] << setw(20) << salonno << setw(20) << "16:00" << setw(20) << "45 dk" << endl;; }

	else if (oyunno == 5) { yazma << setw(20) << oyunadi[oyunno - 3] << setw(20) << salonno << setw(20) << "19:00" << setw(20) << "45 dk" << endl;; }
	else if (oyunno == 6) { yazma << setw(20) << oyunadi[oyunno - 4] << setw(20) << salonno << setw(20) << "20:00" << setw(20) << "45 dk" << endl;; }

	else if (oyunno == 7) { yazma << setw(20) << oyunadi[oyunno - 4] << setw(20) << salonno << setw(20) << "20:00" << setw(20) << "45 dk" << endl;; }
	else if (oyunno == 8) { yazma << setw(20) << oyunadi[oyunno - 5] << setw(20) << salonno << setw(20) << "21:00" << setw(20) << "45 dk" << endl;; }

	else { cout << "Yanlis seans kodu!!" << endl; }

	yazma.close();


}

void oyun::biletiptal(int id) {
	okuma.close();
	yazma.open("bilet1.txt", ios::out);
	okuma.open("bilet.txt", ios::in);
	okuma.seekg(sayac);

	yazma << setw(20) << "ID" << setw(20) << "Oyun Adý" << setw(20) << "Salon" << setw(20) << "Saat" << setw(20) << "Sure" << endl;
	yazma << "------------------------------------------------------------------------------------" << endl;

	while (okuma >> iD >> oyunadi1 >> salonn >> oyunsaat >> oyunsure)
	{
		if (iD == id) { cout << "Bilet Silindi..." << endl; }
		else {
			yazma << setw(20) << iD << setw(20) << oyunadi << setw(20) << salonn << setw(20) << oyunsaat << setw(20) << oyunsure << endl;
		}
	}
	yazma.close();
	okuma.close();

	remove("bilet.txt");
	rename("bilet1.txt", "bilet.txt");
}
