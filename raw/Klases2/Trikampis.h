#pragma once
class Trikampis
{
private:
	double a, b, c;
public:
	Trikampis();
	Trikampis(double aa, double bb, double cc);
	~Trikampis();
	void Deti(double aa, double bb, double cc);
	void Imti(double & aa, double & bb, double & cc);
	bool ArTrikampis();
	bool ArStatus();
	bool ArLygiakrastis();
	bool ArLygiasonis();
	double Perimetras();
	double Plotas();
};

