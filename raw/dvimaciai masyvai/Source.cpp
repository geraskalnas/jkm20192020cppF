#include <iostream>

using namespace std;

void ivesti(int a[][100], int &r, int &c);
void spausdinti(int a[][100], int &r, int &c);


int main() {
	int r, c, a[100][100], sum[100][100];
	
	cout << "Ivesti eiluciu skaiciu:";
	cin >> r; cout << "Ivesti stulpeliu skaiciu: ";
	cin >> c; cout << endl;
	
	ivesti(a, r, c);

	spausdinti(a, r, c);


	int t;
	cin >> t;
	return t;
}
void ivesti(int a[][100], int &r, int &c) {
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) {
			cout << "Iveskite" << i + 1 << "." << j + 1 << " : ";
			cin >> a[i][j];
		}
}
void spausdinti(int a[][100], int &r, int &c) {
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cout << i + 1 << "." << j + 1 << " : " << a[i][j] << endl;

}