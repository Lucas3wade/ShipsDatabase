#include "StatekWodny.h"
#include <iostream>

StatekWodny::StatekWodny()
{
#ifdef _DEBUG
	cout << "Utworzono StatekWodny - konstruktor domyslny" << endl << endl;
#endif
}

void StatekWodny::wprowadzDaneStatkuRecznie(istream &c)
{
	Statek::wprowadzDaneStatkuRecznie(c);
	string nowy_rodzaj_silnikow;
	int nowa_liczba_kotwic;
	cout << "Wprowadz liczbe kotwic: " << endl;
	c >> nowa_liczba_kotwic;
	liczba_kotwic = nowa_liczba_kotwic;
	cout << "Wprowadz nowy rodzaj silnikow: " << endl;
	c>>nowy_rodzaj_silnikow;
	rodzaj_silnikow = nowy_rodzaj_silnikow;
}

void StatekWodny::wprowadzDaneStatkuZPliku(istream &c)
{
	Statek::wprowadzDaneStatkuZPliku(c);
	c >> *this;
}
void StatekWodny::wypisDanychStatku(ostream &c)
{
	wypisGlownychDanychStatku(c);
	c << *this;
}

ostream& operator<<(ostream &c, StatekWodny &sw)
{
	c << "Liczbba kotwic: " <<endl<< sw.liczba_kotwic << endl;
	c << "Rodzaj silnikow: " <<endl<< sw.rodzaj_silnikow << endl;
	return c;
}
istream& operator >> (istream &c, StatekWodny &sw)
{
	string zmienna_pomocnicza;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza;
	c >>sw.liczba_kotwic;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza;
	c >>  sw.rodzaj_silnikow;
	return c;
}
