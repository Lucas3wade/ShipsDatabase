#pragma once

#include <string>

using namespace std;

/// Klasa przechowujaca podstawowe dane statku
class OpisStatku
{
public:
	///Konstruktor domyslny
	OpisStatku();
	
	//metody

	///Metoda pozwalajaca na ustawienie danych opisu statku
	/**Metoda umozliwia na ustawienie danych obiektu na podane jako parametry.
	\param nowa_nazwa_statku nazwa statku
	\param nowa_dlugosc_statku dlugosc statku w metrach
	\param nowa_wysokosc_statku wysokosc statku w metrach 
	\param nowa_szerokosc_statku szerekosc statku w metrach
	\param nowy_rok_produkcji  rok produkcji statku */
	void wprowadzOpisStatku(string nowa_nazwa_statku, float nowa_dlugosc_statku, float nowa_wysokosc_statku, float nowa_szerokosc_statku, int nowy_rok_produkcji);

	///Metoda pozwalajaca uzyskac podstawowe dane na temat statku.
	/**
	Umozliwia wyprowadzenie danych obiektu na dowolny strumien wyjscia.
	\param c dowolny strumien wyjscia
	*/
	void wypisOpisStatku(ostream &c);

	//operatory
	friend ostream& operator<<(ostream &c, OpisStatku &ops);
	friend istream& operator>>(istream &c, OpisStatku &ops);

private:
	string nazwa_statku; ///< nazwa_statku nazwa statku
	float dlugosc_statku; ///<dlugosc_statku dlugosc statku w metrach
	float wysokosc_statku;///<wysokosc_statku wysokosc statku w metrach 
	float szerokosc_statku;///<szerokosc_statku szerekosc statku w metrach
	int rok_produkcji;///< rok_produkcji rok produkcji statku 

};

///Przeciazony operator wyjscia.
/**Przeciazony operator pozwala na uzyskanie danych na dowlny strumien wyjscia. W tym programie wykorzystywany do wypisu danych na standardowe wyjscie lub do pliku.*/
ostream& operator<<(ostream &c, OpisStatku &ops);
///Przeciazony operator wejscia.
/**Przeciazony operator pozwala na pobranie danych z dowolnego strumienia wejscia. W tym programie wykorzystywany do odczytu danych z pliku.*/
istream& operator>>(istream &c, OpisStatku &ops);