#include <iostream>
#include <iomanip>
#include "Trikampis.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Lithuanian");
	double a, b, c;
	a = 3;
	b = 4;
	c = 5;

	Trikampis trk(a, b, c);
	double aa, bb, cc;
	trk.Imti(aa, bb, cc);
	cout << "Atkarp� ilgiai: " << aa << " " << bb << " " << cc << endl;

	if (trk.ArTrikampis()) {
		cout << "Atkarpos sudaro trikamp�: " << endl;
		if (trk.ArStatus()) {
			cout << " - statuj� trikamp�" << endl;
		}
		else if (trk.ArLygiakrastis()) {
			cout << " - lygiakra�t� trikamp�" << endl;
		}
		else if (trk.ArLygiasonis()) {
			cout << " - lygia�on� trikamp�" << endl;
		}
		cout << "Trikampi� plotas: " << trk.Plotas() << endl;
	}
	else {
		cout << "Atkarpos nesudaro trikampio" << endl;
	}
	return 0;
}