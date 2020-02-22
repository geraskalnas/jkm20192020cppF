#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const char skFailas[] = "LeidiniaiS.txt";
const char sk2Failas[] = "LeidiniaiN.txt";
const char raFailas[] = "Rezultatai.txt";
const char didzKiekis = 100;

struct leidinys {
	string pavadinimas;
	int perMen;
	double egzKaina;
};
struct apdorotas {
	string pavadinimas;
	double men3Kaina, men6Kaina, men12Kaina;
};

leidinys A[didzKiekis * 2], B[didzKiekis];
apdorotas C[didzKiekis * 2];

ofstream fr(raFailas);

void Skaityti(const char sk[], const char sk2[], leidinys sar[], leidinys sar2[], int & n, int & m);
void RasytiDuomenis(leidinys sar[], int n);
void RasytiRezultatus(apdorotas sar[], int n, int pig);
bool Tikrinti(string a, string b, int j = 0);//ar a Turi buti pirmesnis uz b
void RikiuotiPagalVarda(apdorotas sar[], int n);
void SudarytiA(leidinys sar[], leidinys sar2[], int &n, int m);
void SudarytiC(leidinys sar[], apdorotas sar2[], int n, int &k);
void Salinti(leidinys sar[], int &n, int tr);
void TrintiDublikatus(leidinys sar[], int &n);
int Pigiausias(apdorotas sar[], int n);

int main() {
	int n, m;
	string vardas, vardas2;
	Skaityti(skFailas, sk2Failas, A, B, n, m);

	RasytiDuomenis(A, n);
	RasytiDuomenis(B, m);

	SudarytiA(A, B, n, m);
	TrintiDublikatus(A, n);

	int k = 0;
	SudarytiC(A, C, n, k);
	RikiuotiPagalVarda(C, k);

	int pig = Pigiausias(C, k);

	RasytiRezultatus(C, k, pig);

	return 0;
}

void Skaityti(const char sk[], const char sk2[], leidinys sar[], leidinys sar2[], int & n, int & m) {
	ifstream fd(sk);
	fd >> n;
	for (int i = 0; i < n; i++) {
		fd >> sar[i].pavadinimas >> sar[i].perMen >> sar[i].egzKaina;
	}
	fd.close();
	ifstream fdd(sk2);
	fdd >> m;
	for (int i = 0; i < m; i++) {
		fdd >> sar2[i].pavadinimas >> sar2[i].perMen >> sar2[i].egzKaina;
	}
	fdd.close();
}
void RasytiDuomenis(leidinys sar[], int n) {
	fr << left << setw(30) << "Leidinio pavadinimas " << setw(22) << "Egzemplioriu per men. " << setw(5) << "Kaina" << endl;
	for (int i = 0; i < n; i++) {
		fr << left << setw(30) << sar[i].pavadinimas << setw(22) << sar[i].perMen << setw(5) << fixed << setprecision(2) << sar[i].egzKaina << endl;
	}
	fr << endl;
}
void RasytiRezultatus(apdorotas sar[], int n, int pig) {
	fr << "Rezultatai:" << endl;
	fr << left << setw(40) << "Leidinio pavadinimas " << setw(13) << "3 men. kaina " << setw(13) << "6 men. kaina " << setw(14) << "12 men. kaina " << endl;
	for (int i = 0; i < n; i++) {
		fr << left << setw(40) << sar[i].pavadinimas;
		fr << setw(13) << fixed << setprecision(2) << sar[i].men3Kaina;
		fr << setw(13) << fixed << setprecision(2) << sar[i].men6Kaina;
		fr << setw(14) << fixed << setprecision(2) << sar[i].men12Kaina << endl;
	}
	fr << "Pigiausias zurnalas metams: " << sar[pig].pavadinimas << " " << sar[pig].men12Kaina << endl;
	fr.close();
}
bool Tikrinti(string a, string b, int j) {//grzina true jei a pirmesnis uz b
	char ch, ch2;
	for (int i = j; i < a.length(); i++) {
		ch = a.at(i);
		ch2 = b.at(i);
		if ((int)ch == (int)ch2) {
			return Tikrinti(a, b, i + 1);
		}
		else if ((int)ch < (int)ch2) {
			return true;
		}
		else {
			return false;
		}
	}
	return true;
}
void RikiuotiPagalVarda(apdorotas sar[], int n) {
	apdorotas c;
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (Tikrinti(sar[j].pavadinimas, sar[j - 1].pavadinimas, 0)) {
				c = sar[j];
				sar[j] = sar[j - 1];
				sar[j - 1] = c;
			}
		}
	}
}
double SudarytiKaina(int perMen, double egzKaina, int men) {
	return perMen * egzKaina * men;
}
void SudarytiA(leidinys sar[], leidinys sar2[], int &n, int m) {
	int o = n;
	n += m;
	for (int i = o; i < n; i++) {
		sar[i] = sar2[i - o];
	}
}
void SudarytiC(leidinys sar[], apdorotas sar2[], int n, int &k) {
	for (int i = 0; i < n; i++) {
		sar2[k] = { sar[i].pavadinimas, SudarytiKaina(sar[i].perMen, sar[i].egzKaina, 3), SudarytiKaina(sar[i].perMen, sar[i].egzKaina, 6), SudarytiKaina(sar[i].perMen, sar[i].egzKaina, 12) };
		k++;
	}
}
void Salinti(leidinys sar[], int &n, int tr) {
	for (int i = tr; i < n - 1; i++) {
		sar[i] = sar[i + 1];
	}
	n--;
}
void TrintiDublikatus(leidinys sar[], int &n) {
	apdorotas c;
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (sar[i].pavadinimas == sar[j].pavadinimas) {
				Salinti(sar, n, j);
			}
		}
	}
}
int Pigiausias(apdorotas sar[], int n) {
	double didz = 99999999999;
	int id = -1;
	for (int i = 0; i < n; i++) {
		if (sar[i].men12Kaina < didz) {
			id = i;
			didz = sar[i].men12Kaina;
		}
	}
	return id;
}