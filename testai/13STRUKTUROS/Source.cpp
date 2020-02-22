#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const char skFailas[] = "Klase.txt";
const char raFailas[] = "KlaseRez.txt";

struct ivertinimai {
	string pavarde;
	string vardas;
	double paz[8];
};

ivertinimai A[100];

void skaityti(const char sk[], ivertinimai mas[], int &n);
void rasyti(const char ra[], ivertinimai mas[], int n);
double vidurkis(double sar[]);
double klaVidurkis(ivertinimai mas[], int &n);

int main() {
	int n;
	skaityti(skFailas, A, n);
	rasyti(raFailas, A, n);

	return 0;
}

void skaityti(const char sk[], ivertinimai mas[], int &n) {
	ifstream fd(sk);
	fd >> n;
	for (int i = 0; i < n; i++) {
		fd >> mas[i].pavarde >> mas[i].vardas;
		for (int j = 0; j < 8; j++) {
			fd >> mas[i].paz[j];
		}
	}
	fd.close();
}
void rasyti(const char ra[], ivertinimai mas[], int n) {
	ofstream fr(ra);
	fr << "Pradiniai duomenys: " << endl;
	fr << "    " << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(10) << "Pazymiai" << endl;
	for (int i = 0; i < n; i++) {
		fr << "  * " << setw(15) << mas[i].pavarde << setw(15) << mas[i].vardas << setw(2);
		for (int j = 0; j < 8; j++) {
			fr << mas[i].paz[j] << " ";
		}
		fr << endl;
	}
	fr << endl;

	fr << "Vidurkiai:" << endl;
	fr << "    " << setw(20) << "Pavarde" << setw(15) << "Vardas" << setw(9) << "Vidurkis" << endl;
	for (int i = 0; i < n; i++) {
		fr << "  * " << setw(20) << mas[i].pavarde << setw(15) << mas[i].vardas << setw(9) << setprecision(3) << vidurkis(mas[i].paz) << endl;
	}
	fr << endl;

	fr << "Bendras klases vidurkis: " << setprecision(3) << klaVidurkis(mas, n) << endl;
}
double vidurkis(double sar[]) {
	double su = 0;
	for (int i = 0; i < 8; i++) {
		su += sar[i];
	}
	su /= 8;
	return su;
}
double klaVidurkis(ivertinimai mas[], int &n) {
	double su = 0;
	for (int i = 0; i < n; i++) {
		su += vidurkis(mas[i].paz);
	}
	su /= n;
	return su;
}