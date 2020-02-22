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
	cout << "Atkarpø ilgiai: " << aa << " " << bb << " " << cc << endl;

	if (trk.ArTrikampis()) {
		cout << "Atkarpos sudaro trikampá: " << endl;
		if (trk.ArStatus()) {
			cout << " - statujá trikampá" << endl;
		}
		else if (trk.ArLygiakrastis()) {
			cout << " - lygiakraðtá trikampá" << endl;
		}
		else if (trk.ArLygiasonis()) {
			cout << " - lygiaðoná trikampá" << endl;
		}
		cout << "Trikampiø plotas: " << trk.Plotas() << endl;
	}
	else {
		cout << "Atkarpos nesudaro trikampio" << endl;
	}
	return 0;
}