#include<iostream>
#include<fstream>

using namespace std;

const char* skFailas = "Duomenys.txt";
const char* raFailas = "Rezultatai.txt";

bool arIstrizaine(int x, int y, int &n) {
	if (n - y - 1 == x) return true;
	return false;
}
bool arPoIstrizaine(int x, int y, int &n) {
	if (n - x <= y) return true;
	return false;
}
void skaityti(int mas[10][10], int &n) {
	ifstream fr(skFailas);
	fr >> n;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (!arIstrizaine(b, a, n))
				fr >> mas[a][b];
		}
	}
	fr.close();
}
void rasyti(int mas[10][10], int &n, int neras) {
	ofstream fd(raFailas);
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (a == neras || arIstrizaine(b, a, n)) continue;//jei tai eilute kurios nerasyti arba tai istrizaine
			fd << mas[a][b] << " ";
		}
		if(a!=neras) fd << endl;
	}
	fd.close();
}
int aukscReiskme(int mas[10][10], int &n) {
	int rek=0, rekX, rekY;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			
			if (arPoIstrizaine(b, a, n)) {
				if (rek < mas[a][b]) {
					rek = mas[a][b];
					rekX = b;
					rekY = a;
				}
			}
		}
	}
	cout << "Ausciausia reiksme po istrizaine: x = " << rekX << " y = " << rekY << "; reiksme = " << rek << endl;
	return rekY;
}

int main() {
	int A[10][10];
	int n;

	skaityti(A, n);

	int rekY = aukscReiskme(A, n);

	rasyti(A, n, rekY);

	int t;
	cin >> t;
	return t;
}