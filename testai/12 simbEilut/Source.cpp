#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const char skFailas[] = "Duomenys.txt";
const char raFailas[] = "Rezultatai.txt";
const int didzKiekis = 100;

struct duomenys {
	string vardas, pavarde, asmKodas;
};

duomenys A[didzKiekis];
int n;
int B[didzKiekis];


void spausdinimas(const char ra[], int ii);
void skaityti(const char sk[]);
int atrinkti(string men);

int main() {
	skaityti(skFailas);
	
	string men;
	cout << "Iveskite menesi: " << endl;
	cin >> men;
	int ii=atrinkti(men);

	spausdinimas(raFailas, ii);

	int t;
	cin >> t;
	return t;
}


void spausdinimas(const char ra[], int ii) {
	ofstream fr(ra);
	for (int i = 0; i < ii; i++) {
		fr << A[B[ii]].pavarde << " ";
		for (int o = 1; o < 7;o++) {//data
			fr << A[B[ii]].asmKodas[o];
		}
		fr << endl;
	}
	fr.close();
}
void skaityti(const char sk[]) {
	ifstream fd(sk);
	fd >> n;
	for (int i = 0; i < n; i++) {
		fd >> A[i].vardas;
		fd >> A[i].pavarde;
		fd >> A[i].asmKodas;
	}
	fd.close();
}
int atrinkti(string men) {
	int ii = 0;
	for (int i = 0; i < n; i++) {
		string asmKodas = A[i].asmKodas;
		if (asmKodas[0] == '3') {//vyras
			if (asmKodas[3] == men[0] && asmKodas[4] == men[1]) {
				B[ii] = i;
				ii++;
			}
		}
	}
	return ii;//atrinktu vyru kiekis
}
