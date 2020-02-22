#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char* skFailas = "Tekstas.txt";
const char* raFailas = "Rezultatai.txt";

int ieskoti(int mas[100], char S);
int didzKiekis(int mas[100], int eiles);
void rasyti(int mas[100], int eiles);

int main() {
	int sRaides[100];
	char S;
	cout << "Iveskite simboli: ";
	cin >> S;
	
	int eiles = ieskoti(sRaides, S);
	int eile = didzKiekis(sRaides, eiles);
	rasyti(sRaides, eiles);

	cout << "Daugiausiai (" << sRaides[eile] << ") simboliu \"" << S << "\" yra " << eile + 1 << " eileje." << endl;


	cout << endl << "Spauskite 0 ir <enter> kad iseitumete. ";
	int t;
	cin >> t;
	return t;
}
int ieskoti(int mas[100], char S) {
	string E;
	int n, eile = 0;
	ifstream fd(skFailas);
	while (!fd.eof()) {
		getline(fd, E);
		n = E.length();
		int s = 0;
		for (int i = 0; i < n; i++) {
			if (E[i] == S) { s++; }
		}
		mas[eile] = s;
		eile++;
	}
	fd.close();
	return eile + 1;
}
int didzKiekis(int mas[100], int eiles){
	int rek = 0, rekI;
	for (int i = 0; i < eiles; i++) {
		if (mas[i] > rek) {
			rek = mas[i];
			rekI = i;
		}
	}
	return rekI;
}
void rasyti(int mas[100], int eiles) {
	ofstream fr(raFailas);
	for (int i = 0; i < eiles; i++) {
		fr << mas[i] << endl;
	}
	fr.close();
}