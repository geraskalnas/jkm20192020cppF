#include "Trikampis.h"
#include <cmath>

const double CEps = 0.0001;

Trikampis::Trikampis(): a(0), b(0), c(0)
{
}

Trikampis::Trikampis(double aa, double bb, double cc): a(aa), b(bb), c(cc)
{
}

Trikampis::~Trikampis()
{
}

void Trikampis::Deti(double aa, double bb, double cc)
{
	a = aa;
	b = bb;
	c = cc;
}

void Trikampis::Imti(double & aa, double & bb, double & cc)
{
	aa = a;
	bb = b;
	cc = c;
}
bool Trikampis::ArTrikampis() {
	return (a < b + c) && (b < a + c) && (c < a + b);
}
bool Trikampis::ArStatus(){
	return  fabs(a*a - (b * b + c * c)) < CEps ||
		fabs(b*b - (a * a + c * c)) < CEps ||
		fabs(c*c - (a * a + b * b)) < CEps;
}
bool Trikampis::ArLygiakrastis() {
	return fabs(a - b) < CEps &&
		fabs(b - c) < CEps &&
		fabs(c - a) < CEps;
}
bool Trikampis::ArLygiasonis() {
	return fabs(a - b) < CEps ||
		fabs(b - c) < CEps ||
		fabs(c - a) < CEps;
}
double Trikampis::Perimetras() {
	return a + b + c;
}
double Trikampis::Plotas() {
	double pp = Perimetras() / 2;
	return pow(pp*(pp - a)*(pp - b)*(pp - c), 0.5);
}
