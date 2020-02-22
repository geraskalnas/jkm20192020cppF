#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

const char skFailas[] = "Duomenys.txt";
const char raFailas[] = "Rezultatai.txt";
const int pMax = 50;

struct kods {
	int lytis;//ir amzius
	int gimMetai;
	int gimMen;
	int gimDien;
	int regNum;
};

void skaityti(const char skFailas[], vector <kods> & kod, int & n);
void spaudinti(const char raFailas[], int A[], int & n);
int gautiLyti(long long kodas);
int gautiMetus(long long kodas);
int gautiMenesi(long long kodas);
int gautiDiena(long long kodas);
int gautiNumeri(long long kodas);

int main() {
	vector <kods> kod;
	int n;
	skaityti(skFailas, kod, n);

	int rekLytis=0, rekMetai=100, rekMen=13, rekDien=32, rekNum=0;
	for (int i = 0; i < n; i++) {
		if (kod[i].lytis % 2 == 0) {
			if (kod[i].lytis > rekLytis) {
				rekLytis = kod[i].lytis;
				rekMetai = kod[i].gimMetai;
				rekMen = kod[i].gimMen;
				rekDien = kod[i].gimDien;
				rekNum = kod[i].regNum;
				//continue;
				if (kod[i].gimMetai < rekMetai) {
					rekMetai = kod[i].gimMetai;
					rekMen = kod[i].gimMen;
					rekDien = kod[i].gimDien;
					rekNum = kod[i].regNum;
					//continue;
					if (kod[i].gimMen < rekMen) {
						rekMen = kod[i].gimMen;
						rekDien = kod[i].gimDien;
						rekNum = kod[i].regNum;
						//continue;
						if (kod[i].gimDien < rekDien) {
							rekDien = kod[i].gimDien;
							rekNum = kod[i].regNum;
							if(kod[i].regNum < rekNum){
								rekNum = kod[i].regNum;
							}
						}
					}
				}
			}
		}
	}


	
	cout << rekLytis << " " << rekMetai << " " << rekMen << " " << rekDien << " " << rekNum;








	int t;
	cin >> t;
	return t;
}
void skaityti(const char skFailas[], vector <kods> & kod, int & n) {
	ifstream fd(skFailas);
	fd >> n;
	for (int i = 0; i < n; i++) {
		long long kodas;
		fd >> kodas;
		int lytis = gautiLyti(kodas);
		int metai = gautiMetus(kodas);
		int men = gautiMenesi(kodas);
		int dien = gautiDiena(kodas);
		int num = gautiNumeri(kodas);
		kod.push_back({ lytis, metai, men, dien, num });
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
int gautiLyti(long long kodas) {
	return kodas / pow(10, 10);
}
int gautiMetus(long long kodas) {
	int t = kodas / pow(10, 8);
	t -= (t/100)*100;
	return t;
}
int gautiMenesi(long long kodas) {
	int t = kodas / pow(10, 6);
	t -= (t / 100) * 100;
	return t;
}
int gautiDiena(long long kodas) {
	int t = kodas / pow(10, 4);
	t -= (t / 100) * 100;
	return t;
}
int gautiNumeri(long long kodas) {
	int t = kodas;
	t -= (t / 10000) * 10000;
	return t;
}