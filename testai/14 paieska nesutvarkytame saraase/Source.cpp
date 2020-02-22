#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const char skFailas[] = "Pirkiniai.txt";
const char raFailas[] = "Rezultatai.txt";

struct pirkinys {
	string pavadinimas;
	int kiekis;
	double kaina;
};

pirkinys pirkiniai[100];
pirkinys rez[100];

void skaityti(const char sk[], pirkinys sar[], int &n) {
	ifstream fd(sk);
	fd >> n;
	for (int i = 0; i < n; i++) {
		fd >> sar[i].pavadinimas >> sar[i].kiekis >> sar[i].kaina;
	}
	fd.close();
}
void rasyti(const char ra[], pirkinys sar[], pirkinys rez[], int n, int n2) {
	ofstream fr(ra);
	fr << "Pradiniai duomenys: " << endl;
	fr << "    " << setw(30) << "Pavadinimas" << setw(7) << "Kiekis" << setw(6) << "Kaina" << endl;
	for (int i = 0; i < n; i++) {
		fr << "  * " << setw(30) << sar[i].pavadinimas << setw(7) << sar[i].kiekis << setw(6) << sar[i].kaina;
		
		fr << endl;
	}
	fr << "Rezultatai:" << endl;
	int pilna_kaina = 0;
	for (int i = 0; i < n2; i++) {
		cout << rez[i].pavadinimas << " " << rez[i].kiekis << endl;
		fr << rez[i].pavadinimas << " " << rez[i].kiekis << endl;
		pilna_kaina += rez[i].kiekis;
	}
	cout << "Is viso: " << pilna_kaina << endl;
	fr << "Is viso: " << pilna_kaina << endl;
	fr << endl;
}
int paieska(pirkinys sar[], int n, string pav) {
	for (int i = 0; i < n; i++) {
		if (!pav.compare(sar[i].pavadinimas)) {
			return i;
		}
	}
	return -1;
}

int main() {
	int n;
	skaityti(skFailas, pirkiniai, n);

	int t;
	cout << "Kiek prekiu norite ieskoti: ";
	cin >> t;
	cin.ignore();
	
	double pilna_kaina = 0.0;
	string preke;
	int id;
	for (int i = 0; i < t; i++)
	{
		cout << "Iveskite pilna prekes pavadinima: ";
		getline(cin, preke);
		rez[i].pavadinimas = preke;
		rez[i].kiekis = paieska(pirkiniai, n, preke);
	}
	
	rasyti(raFailas, pirkiniai, rez, n, t);

	return 0;
}