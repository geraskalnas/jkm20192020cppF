#include <iostream>
#include <fstream>

using namespace std;


int neig = 0;
const char skFailas[] = "Dalykai.txt";
const char raFailas[] = "Rezultatai.txt";

void ivesti(const char skFailas[], int a[][100], int &n, int &m);
void spausdinti(const char skFailas[], int a[][100], int &n, int &m);
int kiekis(int a[][100], int nId, int &m);
int geriausias(int a[][100], int &n, int &m);


int main() {
	int n, m, a[100][100];


	ivesti(skFailas, a, n, m);

	spausdinti(raFailas, a, n, m);

	int id = geriausias(a, n, m);

	cout << "Geriausiai mokosi " << id + 1 << "-as mokinys." << endl;
	cout << neig << " mokiniai turi neigiamu ivertinimu." << endl;

	int t;
	cin >> t;
	return t;
}
void ivesti(const char skFailas[], int a[][100], int &n, int &m) {
	ifstream fd(skFailas);
	fd >> n;
	fd >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			fd >> a[i][j];
}
void spausdinti(const char raFailas[], int a[][100], int &n, int &m) {
	ofstream fr(raFailas);
	for (int i = 0; i < n; ++i) {
		fr << i + 1 << "-as mokinys gavo:" << endl;
		for (int j = 0; j < m; ++j) {
			fr << "    " << a[i][j] << endl;
		}
	}
}
int kiekis(int a[][100], int nId, int &m) {
	int suma = 0;
	for (int j = 0; j < m; ++j) {
		if (a[nId][j] < 4) {
			neig++;
		}
		suma += a[nId][j];
	}
	return suma;
}
int geriausias(int a[][100], int &n, int &m) {
	int rezId = 1000;
	int rez = 0;
	for (int i = 0; i < n; ++i) {
		int suma = kiekis(a, i, m);
		if (suma > rez) {
			rez = suma;
			rezId = i;
		}
	}
	return rezId;
}