#pragma once

#include "Statek.h"
/// Klasa przechowujaca dane Statku kosmicznego
class StatekKosmiczny:public Statek
{
public:
	StatekKosmiczny();

	///Metoda pozwalajaca na wprowadzenie danych Statku Kosmicznego.
	/**
	Umozliwia ustawienie danych obiektu, za pomoca standardowego wejscia .*/
	void wprowadzDaneStatkuRecznie(istream &c);

	///Metoda pozwalajaca na wprowadzenie danych Statku Kosmicznego.
	/**
	Umozliwia wprowadzanie danych obiektu z pliku.
	\param c strumien wejscia*/
	void wprowadzDaneStatkuZPliku(istream &c);

	///Metoda pozwalajaca uzyskac dane na temat Statku Kosmicznego.
	/**
	Umozliwia wyprowadzenie danych obiektu na dowolny strumien wyjscia.
	\param c dowolny strumien wyjscia*/
	void wypisDanychStatku(ostream &c);

	friend ostream& operator<<(ostream &c, StatekKosmiczny &sk);
	friend istream& operator >> (istream &c, StatekKosmiczny &sk);
protected:
	string miejsce_wylotu; ///<miejsce_wylotu miejsce wylotu statku
	string miejsce_ladowania; ///<miejsce_ladowania miejsce ladowania statku
};
///Przeciazony operator wyjscia.
/**Przeciazony operator pozwala na uzyskanie danych na dowlny strumien wyjscia. W tym programie wykorzystywany do wypisu danych na standardowe wyjscie lub do pliku.*/
ostream& operator<<(ostream &c, StatekKosmiczny &sk);
///Przeciazony operator wejscia.
/**Przeciazony operator pozwala na pobranie danych z dowolnego strumienia wejscia. W tym programie wykorzystywany do odczytu danych z pliku.*/
istream& operator>>(istream &c, StatekKosmiczny &sk);