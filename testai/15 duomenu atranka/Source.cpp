#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const char skFailas[] = "Valstybe1.txt";
const char sk2Failas[] = "Valstybe2.txt";
const char raFailas[] = "Rezultatai.txt";
const char didzKiekis = 100;

struct valstybe {
	string pavadinimas;
	double plotas;
	double gyventojai;
};
struct apdorota {
	string pavadinimas;
	double tankis;
	string vv;
};

valstybe V1[didzKiekis];
valstybe V2[didzKiekis];
apdorota Va[didzKiekis];

ofstream fr(raFailas);

void skaityti(const char sk[], const char sk2[], valstybe sar[], valstybe sar2[], string &vardas, string &vardas2, int &n, int &m);
void rasytiDuomenis(valstybe sar[], int n);
void rasytiRezultatus(apdorota sar[], int n);
void rikiuoti(apdorota sar[], int n);
int atrinkimas(valstybe sar[], int n, double x, string vv, int k);

int main() {
	int n, m;
	string vardas, vardas2;
	skaityti(skFailas, sk2Failas, V1, V2, vardas, vardas2, n, m);

	double x;
	cout << "Iveskite plota: ";
	cin >> x;

	int k=atrinkimas(V1, n, x, vardas, 0);
	k=atrinkimas(V2, m, x, vardas2, k);

	rikiuoti(Va, k);

	rasytiDuomenis(V1, n);
	rasytiDuomenis(V2, m);
	rasytiRezultatus(Va, k);

	return 0;
}

void skaityti(const char sk[], const char sk2[], valstybe sar[], valstybe sar2[], string & vardas, string & vardas2, int & n, int & m) {
	ifstream fd(sk);
	getline(fd, vardas);
	fd >> n;
	for (int i = 0; i < n; i++) {
		fd >> sar[i].pavadinimas >> sar[i].plotas >> sar[i].gyventojai;
	}
	fd.close();
	ifstream fdd(sk2);
	getline(fdd, vardas2);
	fdd >> m;
	for (int i = 0; i < m; i++) {
		fdd >> sar2[i].pavadinimas >> sar2[i].plotas >> sar2[i].gyventojai;
	}
	fdd.close();
}
void rasytiDuomenis(valstybe sar[], int n) {
	fr << setw(19) << "Miesto pavadinimas " << setw(17) << "Plotas(km2.) " << setw(24) << "Gyventoju skc.(tukst). " << endl;
	for (int i = 0; i < n; i++) {
		fr << setw(19) << sar[i].pavadinimas << setw(17) << sar[i].plotas << setw(24) << sar[i].gyventojai << endl;
	}

}
void rasytiRezultatus(apdorota sar[], int n) {
	fr << "Rezultatai:" << endl;
	fr << setw(19) << "Miesto pavadinimas " << setw(17) << "Gyventoju tankis " << setw(20) << "Valstybe" << endl;
	for (int i = 0; i < n; i++) {
		fr << setw(19) << sar[i].pavadinimas << setw(17) << sar[i].tankis << setw(20) << sar[i].vv << endl;
	}
	fr.close();
}
void rikiuoti(apdorota sar[], int n) {
	int mini;
	apdorota b;
	for (int i = 0; i < n - 1; i++) {
		mini = i;
		for (int j = 0; j < n; j++) {
			if (sar[j].tankis < sar[mini].tankis) {
				mini = j;
				b = sar[i];
				sar[i] = sar[mini];
				sar[mini] = b;
			}
		}
	}
}
int atrinkimas(valstybe sar[], int n, double x, string vv, int k) {
	for (int i = 0; i < n; i++) {
		if (sar[i].plotas > x) {
			Va[k].pavadinimas = sar[i].pavadinimas;
			Va[k].tankis = sar[i].gyventojai * 1000 / sar[i].plotas;
			Va[k].vv = vv;
			k++;
		}
	}
	return k;
}