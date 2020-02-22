#include<iostream>
#include<fstream>

using namespace std;

const char skFailas[] = "Duomenys.txt";
const char raFailas[] = "Rezultatai.txt";

int Kiek(char sim);

int main() {
	ofstream fr(raFailas);
	fr << 'a' << " " << Kiek('a') << endl;
	fr.close();

	return 0;
}

int Kiek(char sim) {
	char s;
	int k = 0;
	ifstream fd(skFailas);
	while (!fd.eof()) {
		fd.get(s);
		if (!fd.eof() && (s == sim)) k++;
	}
	fd.close();
	return k;
}