#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class salon {
private:
	int salonn[8];
	int slnno;
	char koltuk[9][9];

public:
	salon();
	void salongetir(int);
	void koltuklal(int);
	void koltukiade();
};

ofstream giris;
ifstream cikis;


salon::salon() {
	giris.open("salon.txt", ios::out);

	char h[8] = { 'A','B','C','D','E','F','G','H' };

	for (int i = 0; i < 8; i++) {

		giris << i + 1 << endl;

		salonn[i] = giris.tellp();

		giris << "12345678O" << endl;

		for (int j = 0; j < 8; j++) {

			for (int k = 0; k < 8; k++) {
				giris << "O";
			}
			giris << h[j] << endl;
		}
	}

	giris.close();
}

void salon::salongetir(int salonno) {
	bool x = true;
	char k[9][9];


	cikis.open("salon.txt", ios::in);

	switch (salonno)
	{
	case 1: {
		cikis.seekg(salonn[0]);

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cikis >> k[i][j];
			}
		}

		cikis.close();
		break;
	}
	case 2: {
		cikis.seekg(salonn[1]);

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cikis >> k[i][j];
			}
		}

		cikis.close();
		break;
	}
	case 3: {
		cikis.seekg(salonn[2]);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cikis >> k[i][j];
			}
		}

		cikis.close();
		break;
	}
	case 4: {
		cikis.seekg(salonn[3]);

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cikis >> k[i][j];
			}
		}

		cikis.close();
		break;
	}
	case 5: {
		cikis.seekg(salonn[4]);

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cikis >> k[i][j];
			}
		}

		cikis.close();
		break;
	}
	case 6: {

		cikis.seekg(salonn[5]);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cikis >> k[i][j];
			}
		}

		cikis.close();
		break;
	}
	case 7: {
		cikis.seekg(salonn[6]);

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cikis >> k[i][j];
			}
		}

		cikis.close();
		break;
	}
	case 8: {
		cikis.seekg(salonn[7]);

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cikis >> k[i][j];
			}
		}

		cikis.close();
		break;
	}
	default: cout << "Oyle bir salon yok !!" << endl;   cikis.close();   x = false;  break;
	}
	if (x) {
		if (salonno == 2) { salonno -= 1; }
		else if (salonno == 4) { salonno -= 1; }
		else if (salonno == 6) { salonno -= 1; }
		else if (salonno == 8) { salonno -= 1; }
		cout << "     SALON " << salonno << endl;
		cout << "-----------------" << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << k[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void salon::koltuklal(int salonno) {
	int sutun;
	char s�ra;
	char h[9] = { 'X','A','B','C','D','E','F','G','H' };

	cout << "Sira (Harf): "; cin >> s�ra;
	cout << "Sutun (Sayi): "; cin >> sutun;

	if (s�ra == 'a') { s�ra = 'A'; }
	else if (s�ra == 'b') { s�ra = 'B'; }
	else if (s�ra == 'c') { s�ra = 'C'; }
	else if (s�ra == 'd') { s�ra = 'D'; }
	else if (s�ra == 'e') { s�ra = 'E'; }
	else if (s�ra == 'f') { s�ra = 'F'; }
	else if (s�ra == 'g') { s�ra = 'G'; }
	else if (s�ra == 'h') { s�ra = 'H'; }

	giris.open("salon1.txt", ios::out);
	cikis.open("salon.txt", ios::in);


	while (cikis >> slnno) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cikis >> koltuk[i][j];
			}
		}
		giris << slnno << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (slnno == salonno && h[i] == s�ra && j + 1 == sutun) { giris << "X"; }
				else { giris << koltuk[i][j]; if (j == 8) { giris << endl; } }
			}
		}
	}


	cikis.close();
	giris.close();

	remove("salon.txt");
	rename("salon1.txt", "salon.txt");
}

void salon::koltukiade() {
	char s�ra; int sutun; int salonno;
	cout << "Salon no giriniz : "; cin >> salonno;
	cout << "Sira : "; cin >> s�ra;
	cout << "Sutun : "; cin >> sutun;

	char h[9] = { 'X','A','B','C','D','E','F','G','H' };

	giris.open("salon1.txt", ios::out);
	cikis.open("salon.txt", ios::in);

	while (cikis >> slnno) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cikis >> koltuk[i][j];
			}
		}
		giris << slnno << endl;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (slnno == salonno && h[i] == s�ra && j + 1 == sutun) { giris << "O"; }
				else { giris << koltuk[i][j]; if (j == 8) { giris << endl; } }
			}
		}
	}


	cikis.close();
	giris.close();

	remove("salon.txt");
	rename("salon1.txt", "salon.txt");

}
