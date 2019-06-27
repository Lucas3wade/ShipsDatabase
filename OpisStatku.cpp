#include "OpisStatku.h"
#include <iostream>
#include <string>
using namespace std;

OpisStatku::OpisStatku() 
{
#ifdef _DEBUG
	cout << "Utworzono Opis Statku - konstruktor domyslny" << endl;
#endif
}


void OpisStatku::wprowadzOpisStatku(string nowa_nazwa_statku, float nowa_dlugosc_statku, float nowa_wysokosc_statku, float nowa_szerokosc_statku, int nowy_rok_produkcji)
{
	nazwa_statku = nowa_nazwa_statku;
	dlugosc_statku = nowa_dlugosc_statku;
	wysokosc_statku = nowa_wysokosc_statku;
	szerokosc_statku = nowa_szerokosc_statku;
	rok_produkcji = nowy_rok_produkcji;
}

void OpisStatku::wypisOpisStatku(ostream &c)
{
	c << *this;
}

ostream& operator<<(ostream &c, OpisStatku &ops)
{
	c << "Nazawa statku: " <<  endl<< ops.nazwa_statku << endl;
	c << "Dlugosc statku: " << endl << ops.dlugosc_statku << endl;
	c << "Wysokosc statku: " << endl << ops.wysokosc_statku << endl;
	c << "Szerokosc statku: " << endl << ops.szerokosc_statku << endl;
	c << "Rok produkcji statku: " << endl << ops.rok_produkcji << endl;
	return c;
}

istream& operator >> (istream &c, OpisStatku &ops)
{
	string zmienna_pomocnicza;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza ;
	c >> ops.nazwa_statku;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza ;
	c >> ops.dlugosc_statku;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza ;
	c >> ops.wysokosc_statku;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza ;
	c >> ops.szerokosc_statku;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza >> zmienna_pomocnicza;
	c >> ops.rok_produkcji;
	return c;
}


