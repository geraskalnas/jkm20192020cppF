#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;


class Taskas {
private:
	int  x, y;
public:
	Taskas();
	Taskas(int xx, int yy);
	~Taskas();
	void Deti(int xx, int yy);
	void Imti(int & xx, int & yy);
	int ImtiX();
	int ImtiY();
	int Padetis();
};


double Atstumas(Taskas & a, Taskas & b);
double AtstumasN(Taskas & a, Taskas & b);

int main() {
	setlocale(LC_ALL, "Lithuanian");
	cout << "Programa darbà pradëjo" << endl;
	int x(0);
	Taskas a(0, 0),
		b(0, 4),
		c(3, 0);

	double ab = AtstumasN(a, b);
	double bc = AtstumasN(b, c);
	double ac = AtstumasN(a, c);
	cout << "Atstumas tarp a ir b: " << ab << endl;
	cout << "Atstumas tarp b ir c: " << bc << endl;
	cout << "Atstumas tarp a ir c: " << bc << endl;

	Taskas t;
	int xt, yt;
	cout << "Uþraðykite taðko koordinates (x, y): ";
	cin >> xt >> yt;
	t.Deti(xt, yt);
	cout << "Atstumas tarp a ir t: " << AtstumasN(a, t) << endl;
	cout << "Taðko t padetis: ";
	
	switch (t.Padetis()) {
	case -2:
		cout << "Y asis";
		break;
	case -1:
		cout << "X asis";
		break;
	case 0:
		cout << "Centras";
		break;
	case 1:
		cout << "I ketvirtis";
		break;
	case 2:
		cout << "II ketvirtis";
		break;
	case 3:
		cout << "III ketvirtis";
		break;
	case 4:
		cout << "IV ketvirtis";
		break;
	}
	cout << endl;
	cout << "Programa darbà baigë" << endl;

	return 0;
}


Taskas::Taskas() : x(0), y(0) {}
Taskas::Taskas(int xx, int yy) : x(xx), y(yy) {
	//x=xx
	//y=yy
}
Taskas::~Taskas(){

}
void Taskas::Deti(int xx, int yy) {
	x = xx;
	y = yy;
}
void Taskas::Imti(int & xx, int & yy) {
	xx = x;
	yy = y;
}
int Taskas::ImtiX() {
	return x;
}
int Taskas::ImtiY() {
	return y;
}
int Taskas::Padetis() {
	if (x == 0 && y == 0) {//centras
		return 0;
	}
	else if (x != 0 && y == 0) {//x asis
		return -1;
	}
	else if (x == 0 && y != 0) {//y asis
		return -2;
	}
	else{
		return x < 0 ? 1 : 0 + y > 0 ? 1 : 3;

	}
}


double Atstumas(Taskas & a, Taskas & b) {
	int xa, ya, xb, yb;
	a.Imti(xa, ya);
	b.Imti(xb, yb);
	return pow(pow(xa - xb, 2.0) + pow(ya - yb, 2.0), 0.5);
}
double AtstumasN(Taskas & a, Taskas & b) {
	return pow(pow(a.ImtiX() - b.ImtiX(), 2.0) + pow(a.ImtiY() - b.ImtiY(), 2.0), 0.5);
}