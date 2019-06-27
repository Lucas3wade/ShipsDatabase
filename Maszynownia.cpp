#include "Maszynownia.h"
#include <iostream>
#include <string>
using namespace std;
Maszynownia::Maszynownia() 
{
#ifdef _DEBUG
	cout << "Utworzono Maszynownia - konstruktor domyslny" << endl;
#endif
}


void Maszynownia::wprowadzDaneMaszynownia(int nowa_liczba_silnikow, int nowa_liczba_osob_obslugujacych)
{
	liczba_silnikow = nowa_liczba_silnikow;
	liczba_osob_obslugujacych = nowa_liczba_osob_obslugujacych;
}

void Maszynownia::wypisMaszynownia(ostream &c)
{
	c << *this;
}


ostream& operator<<(ostream &c, Maszynownia &maszynownia)
{
	c << "Liczba silnikow: " <<endl<< maszynownia.liczba_silnikow << endl;
	c << "Liczba osob obslugujacych silniki: " << endl << maszynownia.liczba_osob_obslugujacych << endl;
	return c;
}

istream& operator >> (istream &c, Maszynownia &maszynownia)
{
	string zmienna_pomocnicza;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza;
	c >> maszynownia.liczba_silnikow;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza >> zmienna_pomocnicza >> zmienna_pomocnicza;
	c >> maszynownia.liczba_osob_obslugujacych;
	return c;
}