#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

const char skFailas[] = "Duomenys.txt";
//const char raFailas[] = "Rezultatai.txt";
const int didzKiekis = 100;
const int pertrauka = 10;//min

struct sarasas {
	string miestas;
	double kaina;
	int isvykimas_h, isvykimas_m;
	int atvykimas_h, atvykimas_m;
};

sarasas miestas;

sarasas A[didzKiekis], B[didzKiekis];

void skaityti(const char sk[], int &n);
void spausdinti(sarasas sar, int formatas, int rod);
void rikiuotiKaina(int n);
void rikiuotiLaika(int n);
int brangiausias(string miesta, int n);
int antraPuse(string miesta, int n);

int main() {
	int n;
	
	skaityti(skFailas, n);
	cout << "PRADINIAI DUOMENYS: " << endl;
	for (int i = 0; i < n; i++){
		spausdinti(A[i], 0, (i>0?0:1));
	}
	cout << endl;
	
	string m;
	cout << "Iveskite miesta(raidziu Dydis SKIRIASI): ";
	cin >> m;
	cout << endl;
	
	int t=antraPuse(m, n);
	cout << "ISVYKSTANTYS ANTROJE PUSEJE: " << endl;
	for (int i = 0; i < t; i++){
		spausdinti(A[i], 1, (i>0?0:1));
	}
	cout << endl;
	
	
	t = brangiausias(m, n);
	cout << "Brangiausias marsrutas i " << m << ":" << endl;
	spausdinti(A[t], 0, 1);
	cout << endl;
	
	rikiuotiKaina(n);
	cout << "PAGAL KAINA: " << endl;
	for (int i = 0; i < n; i++){
		spausdinti(A[i], 0, (i>0?0:1));
	}
	cout << endl;
	
	rikiuotiLaika(n);
	cout << "PAGAL ISVYKIMO LAIKA: " << endl;
	for (int i = 0; i < n; i++){
		spausdinti(A[i], 0, (i>0?0:1));
	}
	cout << endl;
	
	
	return 0;
}

void skaityti(const char sk[], int &n) {
	ifstream fd(sk);
	fd >> n;
	for (int i = 0; i < n; i++) {
		fd >> miestas.miestas >> miestas.kaina >> miestas.isvykimas_h >> miestas.isvykimas_m >> miestas.atvykimas_h >> miestas.atvykimas_m;
		A[i] = miestas;
	}
	fd.close();
}
void spausdinti(sarasas sar, int formatas, int rod){//spausdina miesto lentele
	if(rod){
		if(formatas){
			cout << setw(18) << "Isvykimo laikas" << setw(18) << "Isvykimo laikas" << setw(6) << "Kaina" << endl;
		}else{
			cout << setw(15) << "Miestas" << setw(6) << "Kaina" << setw(18) << "Isvykimo laikas" << setw(18) << "Isvykimo laikas" << endl;
		}
}
	if(formatas){
		cout << setw(15) << sar.isvykimas_h << setw(1) << ":" << setw(2) << sar.isvykimas_m << setw(15) << sar.atvykimas_h << setw(1) << ":" << setw(2) << sar.atvykimas_m << " " << setw(6) << setprecision(2) << sar.kaina << endl;
	}else{
		cout << setw(15) << sar.miestas << setw(6) << sar.kaina << setw(15) << sar.isvykimas_h << setw(1) << ":" << setw(2) << sar.isvykimas_m << setw(15) << sar.atvykimas_h << setw(1) << ":" << setw(2) << sar.atvykimas_m << endl;
	}
}
void rikiuotiKaina(int n) {
	int mini;
	sarasas b;
	for (int i = 0; i < n - 1; i++) {
		mini = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j].kaina < A[i].kaina) {
				mini = j;
				b = A[i];
				A[i] = A[j];
				A[mini] = b;
			}
		}
	}
}
void rikiuotiLaika(int n) {
	int mini;
	sarasas b;
	for (int i = 0; i < n - 1; i++) {
		mini = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j].isvykimas_h < A[i].isvykimas_h || (A[j].isvykimas_h == A[i].isvykimas_h && A[j].isvykimas_m < A[i].isvykimas_m)) {
				mini = j;
				b = A[i];
				A[i] = A[j];
				A[mini] = b;
			}
		}
	}
}
int brangiausias(string miesta, int n) {
	int reki=0;
	for (int i = 0; i < n; i++) {
		if ((A[i].kaina > A[reki].kaina and miesta==A[i].miestas) || A[reki].miestas!=miesta) {
			reki = i;
		}
	}
	return reki;
}
int antraPuse(string miesta, int n){
	int coun=0;
	for (int i = 0; i < n; i++) {
		if (miesta==A[i].miestas && A[i].isvykimas_h>=12) {
			B[coun]=A[i];
			coun++;
		}
	}
	return coun;
}
