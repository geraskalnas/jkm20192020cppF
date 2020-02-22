#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;


const char skFailas[] = "Duomenys.txt";
const char raFailas[] = "Rezultatai.txt";
const int pMax = 50;


void skaityti(const char skFailas[], int A[], int & n);
void spaudinti(const char raFailas[], int A[], int & n);
int ilgiausiaiZydi(int A[], int n);
void spausdintiIlgZydi(const char raFailas[], int A[], int n, int sk);


int main() {
	int P[pMax]; int n;
	int max;
	ofstream fr;

	skaityti(skFailas, P, n);
	spaudinti(raFailas, P, n);
	fr.open(raFailas, ios::app);
	max = ilgiausiaiZydi(P, n);
	fr << "Visos geles nuvys po " << max << " d." << endl;
	fr.close();
	spausdintiIlgZydi(raFailas, P, n, max);

	return 0;
}

void skaityti(const char skFailas[], int A[], int & n) {
	ifstream fd(skFailas);
	fd >> n;
	for (int i = 0; i < n; i++) {
		fd >> A[i];
	}
	fd.close();

}

void spaudinti(const char raFailas[], int A[], int & n) {
	ofstream fr(raFailas);
	fr << " Puokstes geles   " << endl;
	fr << "------------------" << endl;
	fr << " G. Nr.  Z. laikas" << endl;
	fr << "------------------" << endl;
	for (int i = 0; i < n; i++) {
		fr << setw(4) << i + 1 << "      " << setw(2) << A[i] << endl;
	}
	fr.close();
}
int ilgiausiaiZydi(int A[], int n) {
	int max = A[0];
	for (int i = 1; i < n; i++)
		if (A[i] > max)
			max = A[i];
	return max;
}
void spausdintiIlgZydi(const char raFailas[], int A[], int n, int sk) {
	ofstream fr(raFailas, ios::app);
	fr << "Geliu, kurias reiktu deti i puokste, numeriai:" << endl;
	for (int i = 0; i < n; i++)
		if (A[i] == sk)
			fr << "  " << i + 1;
	fr << endl;
	fr.close();
}