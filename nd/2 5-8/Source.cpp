#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

const char* skFailas = "Duomenys.txt";
const char* raFailas = "Rezultatai.txt";
const int cMax = 100;

int countDigit(long long n)//https://www.geeksforgeeks.org/program-count-digits-integer-3-different-methods/
{
	int count = 0;
	while (n != 0) {
		n = n / 10;
		++count;
	}
	return count;
}
int eiluteMinMakKvadr(int mas[cMax][cMax], int l, int nk) {
	int min = 999999;
	int max = 0;
	for (int k = 0; k < nk; k++) {
		if (mas[k][l] < min) {
			min = mas[k][l];
		}
		if (mas[k][l] > max) {
			max = mas[k][l];
		}
	}
	return (max*max) - (min*min);
}
void skaityti(int mas[cMax][cMax], int &nk, int &nl) {
	ifstream fd(skFailas);
	fd >> nk;
	fd >> nl;
	for (int l = 0; l < nl; l++) {
		for (int k = 0; k < nk; k++) {
			fd >> mas[k][l];
		}
	}
	fd.close();
}
void rasyti(int mas[cMax], int &n) {
	ofstream fr(raFailas);
	fr << "|------------|" << endl;
	fr << "|--Skaicius--|" << endl;
	fr << "|------------|" << endl;
	for (int i = 0; i < n; i++) {
		int sk = countDigit(mas[i]);
		fr << fixed << "|--" << setw(8) << mas[i] << "--|" << endl;
	}
	fr << "|------------|" << endl;
	fr.close();
}
void spausdinti(int mas[cMax], int &n) {
	cout << "|------------|" << endl;
	cout << "|--Skaicius--|" << endl;
	cout << "|------------|" << endl;
	for (int i = 0; i < n; i++) {
		int sk = countDigit(mas[i]);
		cout << fixed << "|--" << setw(8) << mas[i] << "--|" << endl;
	}
	cout << "|------------|" << endl;
}

int main() {
	int F[cMax][cMax];
	int A[cMax];
	int nk, nl;

	skaityti(F, nk, nl);
	for (int l = 0; l < nl; l++) {
		A[l]=eiluteMinMakKvadr(F, l, nk);
	}
	rasyti(A, nl);
	spausdinti(A, nl);

	int t;
	cin >> t;
	return t;
}