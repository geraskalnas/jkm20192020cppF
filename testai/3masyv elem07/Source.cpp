#include <iostream>
#include <fstream>

using namespace std;


int neig = 0;
const char skFailas[] = "Duomenys.txt";
const char raFailas[] = "Rezultatai.txt";

void ivesti(const char skFailas[], int a[], int &n);
void spausdinti(const char skFailas[], int a[], int &n);
void salinti(int a[], int &n, int k);
void dupSalinti(int a[], int &n);


int main() {
	int n, m, a[100];


	ivesti(skFailas, a, n);

	dupSalinti(a, n);

	spausdinti(raFailas, a, n);

	
	return 0;
}
void ivesti(const char skFailas[], int a[], int &n) {
	ifstream fd(skFailas);
	fd >> n;
	for (int i = 0; i < n; ++i)
		fd >> a[i];
}
void spausdinti(const char raFailas[], int a[], int &n) {
	ofstream fr(raFailas);
	for (int i = 0; i < n; ++i) {
		fr << i << ": " << a[i] << endl;
	}
}
void salinti(int a[], int &n, int k) {
	n-=1;
	for (int i = k; i < n; i++)
		a[i] = a[i + 1];
}
void dupSalinti(int a[], int &n) {
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] == a[j]) {
				salinti(a, n, j);
				i = 0;
				continue;
			}
}