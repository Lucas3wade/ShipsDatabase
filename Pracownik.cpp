#include "Pracownik.h"
#include <iostream>
#include <string>
using namespace std;

Pracownik::Pracownik(string podane_nazwisko)
{
	nazwisko = podane_nazwisko;
}

//operator strumieniowy
ostream& operator<<(ostream &c, Pracownik &p)
{
	c << p.nazwisko;
	return c;
}