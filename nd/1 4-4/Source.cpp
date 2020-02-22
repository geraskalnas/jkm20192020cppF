#include<iostream>

using namespace std;

int atstumas(int x1, int y1, int x2, int y2);

int main() {
	int n;
	cout << "Kiek tasku: ";
	cin >> n; cin.ignore();

	int x, y;
	int X[100], Y[100];
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". x y: ";
		cin >> x >> y;
	}

	cout << "Taskai, kuriuos sujungdami gausime staciuosiu trikampius:" << endl;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			for (int c = 0; c < n; c++) {
				int A = atstumas(X[a], Y[a], X[b], Y[b]);
				int B = atstumas(X[b], Y[b], X[c], Y[c]);
				int C = atstumas(X[c], Y[c], X[a], Y[a]);
				if ((A*A) + (B*B) == C * C && a != b && b != c && c != a) {
					cout << a + 1 << "-asis " << b + 1 << "-asis " << c + 1 << "-asis" << endl;
				}
			}
		}
	}

	int t;
	cin >> t;
	return t;
}

int atstumas(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}