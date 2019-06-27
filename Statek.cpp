#include "Statek.h"
#include <iostream>
#include<string>

using namespace std;

int Statek::liczba_istniejacych_statkow = 0;

//konstruktor
Statek::Statek()
{
#ifdef _DEBUG
	cout << "Utworzono Statek - konstruktor domyslny" << endl<<endl;
#endif
	liczba_istniejacych_statkow++;
}


// wprowadzanie danych
void Statek::wprowadzDaneStatkuRecznie(istream &c)
{
	string nowa_nazwa_statku;
	int nowa_liczba_silnikow, nowa_liczba_osob_obslugujacych, nowy_rok_produkcji;
	float nowa_dlugosc_statku, nowa_wysokosc_statku, nowa_szerokosc_statku ;

	cout << "Wprowadz nazwe statku: " << endl;
	c >> nowa_nazwa_statku;
	cout << "Wprowadz dlugosc statku: " << endl;
	c >> nowa_dlugosc_statku;
	cout << "Wprowadz wysokosc statku: " << endl;
	c >> nowa_wysokosc_statku;
	cout << "Wprowadz szerokosc statku: " << endl;
	c >> nowa_szerokosc_statku;
	cout << "Wprowadz rok produkcji statku: " << endl;
	c >> nowy_rok_produkcji;
	cout << "Wprowadz liczbe silnikow: " << endl;
	c >> nowa_liczba_silnikow;
	cout << "Wprowadz liczbe osob obslugujacych silniki: " << endl;
	c >> nowa_liczba_osob_obslugujacych;
	maszynownia.wprowadzDaneMaszynownia(nowa_liczba_silnikow, nowa_liczba_osob_obslugujacych);
	opis_statku.wprowadzOpisStatku(nowa_nazwa_statku, nowa_dlugosc_statku, nowa_wysokosc_statku, nowa_szerokosc_statku, nowy_rok_produkcji);
}

void Statek::wprowadzDaneStatkuZPliku(istream &c)
{
	c >> *this;
}



//dodawanie pracownika
void Statek::dodajPracownika(string nazwisko_pracownika)
{
	Pracownik nowy_pracownik(nazwisko_pracownika);
	pracownicy.push_back(nowy_pracownik);
	//cout << "Dodalem pracownika! " << endl;
}

//usuwanie pracownika o podanym numerze
void Statek::usunPracownika(unsigned int indeks)
{
	if (indeks < pracownicy.size())
	{
		pracownicy.erase(pracownicy.begin() + indeks, pracownicy.begin() + indeks + 1);
		cout << "Usunalem " << indeks << " pracownika! " << endl;
	}
	else
		cout << "Brak pracownika o podanym indeksie" << endl;
	
}

//wypis danych o statku
void Statek::wypisGlownychDanychStatku(ostream &c)
{
	c << *this;
}

//operator strumieniowy
ostream& operator<<(ostream &c, Statek &s)
{
	c << s.opis_statku;
	c << s.maszynownia;
	c << "Liczba pracownikow: " <<endl<< s.pracownicy.size() << endl;
	if (s.pracownicy.size() > 0)
	{
		for (unsigned int i = 0; i < s.pracownicy.size(); i++)
		{
			c << "Pracownik[" << i << "]: "<<endl;
			c << s.pracownicy[i] << endl;
		}
	}
	else
		c << "Brak pracownikow" << endl;
	return c;
}

istream& operator >> (istream &c, Statek &s)
{
	string zmienna_pomocnicza, nazwisko;
	unsigned int liczba_pracownikow;
	c >> s.opis_statku;
	c >> s.maszynownia;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza;
	c >> liczba_pracownikow;
	if (liczba_pracownikow > 0)
	{
		for (unsigned int i = 0; i < liczba_pracownikow; i++)
		{
			c >> zmienna_pomocnicza;
			c >> nazwisko;
			s.dodajPracownika(nazwisko);
		}
	}
	else
		c >> zmienna_pomocnicza >> zmienna_pomocnicza;
	return c;
}