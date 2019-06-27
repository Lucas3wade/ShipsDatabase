#pragma once

#include "Statek.h"
/// klasa opisujaca Statek wodny
class StatekWodny:public Statek
{
public:
	///konstruktor domyslny
	StatekWodny();

	///Metoda pozwalajaca na wprowadzenie danych Statku Wodnego.
	/**
	Umozliwia ustawienie danych obiektu na podane, za pomoca standardowego wejscia .*/
	void wprowadzDaneStatkuRecznie(istream &c);

	///Metoda pozwalajaca na wprowadzenie danych Statku Wodnego.
	/**
	Umozliwia wprowadzanie danych obiektu z pliku.
	\param c strumien wejscia*/
	void wprowadzDaneStatkuZPliku(istream &c);

	///Metoda pozwalajaca uzyskac dane na temat Statku Wodnego.
	/**
	Umozliwia wyprowadzenie danych obiektu na dowolny strumien wyjscia.
	\param c dowolny strumien wyjscia*/
	void wypisDanychStatku(ostream &c);

	friend ostream& operator<<(ostream &c, StatekWodny &sw);
	friend istream& operator >> (istream &c, StatekWodny &sw);
protected:
	string rodzaj_silnikow; ///<rodzaj silnikow np. spalinowe, elektryczne
	int liczba_kotwic; ///< liczba kotwic umieszczonych na statku
};
///Przeciazony operator wyjscia.
/**Przeciazony operator pozwala na uzyskanie danych na dowlny strumien wyjscia. W tym programie wykorzystywany do wypisu danych na standardowe wyjscie lub do pliku.*/
ostream& operator<<(ostream &c, StatekWodny &sw);
///Przeciazony operator wejscia.
/**Przeciazony operator pozwala na pobranie danych z dowolnego strumienia wejscia. W tym programie wykorzystywany do odczytu danych z pliku.*/
istream& operator>>(istream &c, StatekWodny &sw);