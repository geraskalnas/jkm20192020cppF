#include<iostream>
#include<fstream>

using namespace std;

const char skFailas[] = "Duomenys.txt";
const char raFailas[] = "Rezultatai.txt";
const int didzKiekis = 100;

void spausdinimas(int mas[didzKiekis]);
int kiekis(char sim);
int maks(int mas[didzKiekis]);

int main() {
	int A[didzKiekis];

	for (int i = 48; i <=57; i++) {//skaicius 0 -> decimal 48 unicode
		A[i - 48] = kiekis((char)i);
	}

	int skaicius, kartai;
	skaicius = maks(A);
	kartai = A[skaicius];
	cout << "Skaicius " << skaicius << " pasikartojo " << kartai << " kartus." << endl;

	spausdinimas(A);


	int t;
	cin >> t;
	return t;
}


void spausdinimas(int mas[didzKiekis]) {
	ofstream fr(raFailas);
	for (int i = 0; i < 10; i++) {
		fr << i << " " << mas[i] << endl;
	}
	fr.close();
}
int kiekis(char sim) {
	char s;
	int k = 0;
	ifstream fd(skFailas);
	while (!fd.eof()) {
		fd.get(s);
		if (!fd.eof() && (s == sim)) k++;
	}
	fd.close();
	return k;
}
int maks(int mas[didzKiekis]) {
	int rek = 0, reki=0;
	for (int i = 0; i < 10; i++) {
		if (rek < mas[i]) {
			rek = mas[i];
			reki = i;
		}
	}
	return reki;
}