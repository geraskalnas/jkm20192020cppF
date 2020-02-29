#pragma once
#include <string>
#include <ctime>

using namespace std;

struct automobilis {
	string automobilio_numeris;
	time_t pradzios_laikas, pabaigos_laikas;
};

public class Automobilis {
public:
	int n;
	automobilis automobiliai[1000];
public:
	Automobilis();
	//Automobilis(string numeris, time_t pradzia, time_t pabaiga);
	~Automobilis();
	/*void Deti(string numeris, time_t pradzia, time_t pabaiga);
	void Imti(string & numeris, time_t & pradzia, time_t & pabaiga);*/
	void AtidarytiDuomenis();
	void SaugotiDuomenis();
};