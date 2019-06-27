#include "StatekKosmiczny.h"
#include <iostream>
StatekKosmiczny::StatekKosmiczny()
{
#ifdef _DEBUG
	cout << "Utworzono StatekKosmiczny - konstruktor domyslny" << endl << endl;
#endif
}

/*void StatekKosmiczny::dodajDaneStatku(string nowa_nazwa_statku, int nowa_liczba_silnikow, int nowa_liczba_osob_obslugujacych, float nowa_dlugosc_statku, float nowa_wysokosc_statku, float nowa_szerokosc_statku, int nowy_rok_produkcji, string nowe_miejsce_wylotu, string nowe_miejsce_ladowania)
{
	wprowadzDaneStatku(nowa_nazwa_statku, nowa_liczba_silnikow, nowa_liczba_osob_obslugujacych, nowa_dlugosc_statku, nowa_wysokosc_statku, nowa_szerokosc_statku, nowy_rok_produkcji);
	miejsce_ladowania = nowe_miejsce_ladowania;
	miejsce_wylotu = nowe_miejsce_wylotu;
}*/

void StatekKosmiczny::wprowadzDaneStatkuRecznie(istream &c)
{
	string nowe_miejsce_wylotu, nowe_miejsce_ladowania;
	Statek::wprowadzDaneStatkuRecznie(c);
	cout << "Wprowadz miejsce wylotu: " << endl;
	c >> nowe_miejsce_wylotu;
	miejsce_wylotu = nowe_miejsce_wylotu;
	cout << "Wprowadz miejsce ladowania: " << endl;
	c >> nowe_miejsce_ladowania;
	miejsce_ladowania = nowe_miejsce_ladowania;
	
}
void StatekKosmiczny::wprowadzDaneStatkuZPliku(istream &c)
{
	Statek::wprowadzDaneStatkuZPliku(c);
	c >> *this;
}
void StatekKosmiczny::wypisDanychStatku(ostream &c)
{
	c << "Statek Kosmiczny" << endl;
	wypisGlownychDanychStatku(c);
	c << *this;
}

ostream& operator<<(ostream &c, StatekKosmiczny &sk)
{
	c << "Miejsce wylotu:" << endl;
	c << sk.miejsce_wylotu << endl; 
	c<<"Miejsce ladowania:" << endl;
	c<< sk.miejsce_ladowania << endl;
	return c;
}

istream& operator >> (istream &c, StatekKosmiczny &sk)
{
	string zmienna_pomocnicza;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza;
	c >> sk.miejsce_wylotu;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza;
	c >> sk.miejsce_ladowania;
	return c;
}