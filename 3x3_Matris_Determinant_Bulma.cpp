#include <iostream>

using namespace std;

int matris [3][3];
int sarruskurali [3][5]; // Sarrus Kuralini uygulayabilmek icin olusturulmus bir matris. 
int determinant ,carpimlarintoplami1,carpimlarintoplami2;


void SarrusKuraliMatrisi() {

	// Kullanicinin girdigi matrisin ilk uc sutununu aldigimiz ve hesaplama yapacagimiz matrisin ilk uc sutununa yerlestirdigimiz kisim.
	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			sarruskurali[i][j] = matris[i][j] ;

		}

	}

	// Kullanicinin girdigi matrisin ilk iki sutununu aldigimiz ve hesaplama yapacagimiz matrisin son iki sutununa yerlestirdigimiz kisim.
	for (int i = 0; i < 3; i++) {

		for (int j = 3; j <=4; j++) {

			sarruskurali[i][j] = matris[i][j-3];

		}

	}

}

// Matrisimizin determinant degerini hesaplama.
void MatrisHesaplama() {

	carpimlarintoplami1 = (sarruskurali[0][0] * sarruskurali[1][1] * sarruskurali[2][2]) +
						  (sarruskurali[0][1] * sarruskurali[1][2] * sarruskurali[2][3]) +
		                  (sarruskurali[0][2] * sarruskurali[1][3] * sarruskurali[2][4]) ;

	carpimlarintoplami2 = (sarruskurali[0][2] * sarruskurali[1][1] * sarruskurali[2][0]) +
		                  (sarruskurali[0][3] * sarruskurali[1][2] * sarruskurali[2][1]) +
		                  (sarruskurali[0][4] * sarruskurali[1][3] * sarruskurali[2][2]) ;


	determinant = carpimlarintoplami1 - carpimlarintoplami2;
}

// Kullanicinin girdigi matrisin ekrana yazdirilmasi.
void MatrisiYazdir() {

	cout << "\tGirdiginiz Matris: \n" << endl;

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			cout <<"\t" << matris[i][j] << "\t";
		}
		cout << endl;
	}

}

int main()
{
	char EveyaH; 

	do {

		cout << "\t\t\t************************************************************" << endl;
		cout << "\t\t\t* 3x3'luk Bir Matrisin Determinantini Hesaplamayan Program *" << endl;
		cout << "\t\t\t************************************************************" << endl;

		cout << endl;

		// Kullanýcýdan matris elemanlarini alma.
		for (int i = 1; i <= 3; i++) {

			for (int j = 1; j <= 3; j++) {

				cout << "\t" << i << ". Sira" << " " << j << ". Sutun Degerini Giriniz: ";
				cin >> matris[i - 1][j - 1];
			}
			cout << endl;
		}

		cout << endl;
		MatrisiYazdir();

		cout << endl;
		SarrusKuraliMatrisi();

		MatrisHesaplama();

		cout << endl;
		cout << "Girdiginiz Matrisin Determinanti: ";
		cout << determinant << endl;

		// Kullanici hesap yapmaya devam etmek istiyor mu? (evet veya hayir)
		cout << endl;
		cout << "Baska bir matrisin determinantini hesaplamak ister misiniz? (E/H): ";
		cin >> EveyaH;

		system("cls");


	} while (EveyaH=='E' || EveyaH=='e');

	cout << "\t\t\tProgrami Kullandiginiz Icin Tesekkurler"<<endl;

  return 0;

}

