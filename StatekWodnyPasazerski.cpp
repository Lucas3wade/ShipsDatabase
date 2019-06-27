#include "StatekWodnyPasazerski.h"
#include <iostream>
#include <vector>

StatekWodnyPasazerski::StatekWodnyPasazerski(int podana_liczba_pokoi):liczba_pokoi(podana_liczba_pokoi)
{
#ifdef _DEBUG
	cout << "Utworzono StatekPasazerski - konstruktor domyslny" << endl << endl;
#endif
}

void StatekWodnyPasazerski::dodajPasazera(string imie_nazwisko)
{
	pasazerowie_imie_nazwisko.push_back(imie_nazwisko);
	//cout << "Dodalem pasazera! " << endl;
}

void StatekWodnyPasazerski::usunPasazera(unsigned int indeks)
{
	if (indeks < pasazerowie_imie_nazwisko.size())
	{
		pasazerowie_imie_nazwisko.erase(pasazerowie_imie_nazwisko.begin() + indeks, pasazerowie_imie_nazwisko.begin() + indeks + 1);
		cout << "Usunalem "<<indeks<<" pasazera! " << endl;
	}
}

int StatekWodnyPasazerski::liczbaPokoi()
{
	return liczba_pokoi;
}

void StatekWodnyPasazerski::wprowadzDaneStatkuRecznie(istream &c)
{
	int nowa_liczba_pokoi;
	StatekWodny::wprowadzDaneStatkuRecznie(c);
	cout << "Wprowadz liczbe pokoi:" << endl;
	cin >> nowa_liczba_pokoi;
	liczba_pokoi = nowa_liczba_pokoi;
}

void StatekWodnyPasazerski::wprowadzDaneStatkuZPliku(istream &c)
{
	StatekWodny::wprowadzDaneStatkuZPliku(c);
	c >> *this;
}


void StatekWodnyPasazerski::wypisDanychStatku(ostream &c)
{
	c << "Statek Wodny Pasazerski" << endl;
	StatekWodny::wypisDanychStatku(c);
	c << *this;
}

ostream& operator<<(ostream &c, StatekWodnyPasazerski &swp)
{
	c << "Liczba pokoi: " <<endl<< swp.liczba_pokoi << endl;
	c << "Liczba pasazerow: " <<endl<< swp.pasazerowie_imie_nazwisko.size() << endl;
	if (swp.pasazerowie_imie_nazwisko.size() > 0)
	{
		for (unsigned int i = 0; i < swp.pasazerowie_imie_nazwisko.size(); i++)
		{
			c << "Pasazer[" << i << "]: "<<endl;
			c << swp.pasazerowie_imie_nazwisko[i] << endl;
		}
	}
	else
		c << "Brak pasazerow" << endl;
	return c;
}

istream& operator >> (istream &c, StatekWodnyPasazerski &swp)
{
	string zmienna_pomocnicza, nazwisko;
	unsigned int liczba_pasazerow;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza;
	c>> swp.liczba_pokoi;
	c >> zmienna_pomocnicza >> zmienna_pomocnicza;
	c>>liczba_pasazerow;
	if (liczba_pasazerow > 0)
	{
		for (unsigned int i = 0; i < liczba_pasazerow; i++)
		{
			c >> zmienna_pomocnicza;
			c >> nazwisko;
			swp.dodajPasazera(nazwisko);
		}
	}
	else
		c >> zmienna_pomocnicza >> zmienna_pomocnicza;
	return c;
}