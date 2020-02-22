#include<iostream>
#include<fstream>

using namespace std;

const char skFailas[] = "Autobusai.txt";
ifstream fd(skFailas);
const char raFailas[] = "Rezultatai.txt";
ofstream fdd(raFailas);

const int m = 100;
unsigned int A[m];

int masIved();
int masSpausd(int n);
int vidurkis(unsigned int suma, int kiekis);

int main() {
	unsigned int n = masIved();
	unsigned int suma = masSpausd(n);
	unsigned int vid = vidurkis(suma, n);
	cout << "Vidurkis: " << vid << endl;
	
	int t;
	cin >> t;
	return t;
	//return 0;
}

int masIved() {
	int n = 0;
	int t;
	while (!fd.eof()) {
		fd >> t;
		A[n] = t;
		n++;
	}
	n--;
	return n;
}

int masSpausd(int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". " << A[i] << endl;
		fdd << i + 1 << ". " << A[i] << endl;
		suma += A[i];
	}
	return suma;
}

int vidurkis(unsigned int suma, int kiekis) {
	return suma / kiekis;
}