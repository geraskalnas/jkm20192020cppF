#include "Automobilis.h"
#include <fstream>

Automobilis::Automobilis()// : automobilio_numeris("AAA000"), pradzios_laikas(0), pabaigos_laikas(0)
{
	AtidarytiDuomenis();
}
/*
Automobilis::Automobilis(string numeris, time_t pradzia, time_t pabaiga) : automobilio_numeris(numeris), pradzios_laikas(pradzia), pabaigos_laikas(pabaiga)
{
}
*/
Automobilis::~Automobilis()
{
}
/*
void Automobilis::Deti(string numeris, time_t pradzia, time_t pabaiga)
{
	automobilio_numeris = numeris;
	pradzios_laikas = pradzia;
	pabaigos_laikas = pabaiga;
}

void Automobilis::Imti(string & numeris, time_t & pradzia, time_t & pabaiga)
{
	numeris = automobilio_numeris;
	pradzia = pradzios_laikas;
	pradzia = pabaigos_laikas;
}
*/
void Automobilis::AtidarytiDuomenis()
{
	std::ofstream fr("automobiliai.txt");
	for (int i = 0; i < n; i++)
	{
		fr << automobiliai[i].automobilio_numeris << "#" << automobiliai[i].pradzios_laikas << ":" << automobiliai[i].pabaigos_laikas << '\n';

	}
	fr.close();
}
void Automobilis::SaugotiDuomenis()
{
	ifstream fd("automobiliai.txt");
	n = 0;
	std::string eilute;
	while (!fd.eof())
	{
		getline(fd, automobiliai[n].automobilio_numeris, '#');
		//getline(fd, automobiliai[n].pradzios_laikas, ':');
		//getline(fd, automobiliai[n].pabaigos_laikas, '@');
		fd >> automobiliai[n].pradzios_laikas;
		fd >> automobiliai[n].pabaigos_laikas;
		fd.ignore(80, '\n');
		n++;
	}
	n--;
	fd.close();
}