#pragma once

#include "StatekWodny.h"
#include <string>
#include <vector>

using namespace std;
/// klasa opisujaca Statek wodny pasazerski
class StatekWodnyPasazerski:public StatekWodny
{
public:
	///konstruktor domyslny z parametrem 
	StatekWodnyPasazerski(int podana_liczba_pokoi=0);

	///Metoda pozwalajaca na wprowadzenie danych Statku Wodnego Pasazerskiego.
	/**
	Umozliwia ustawienie danych obiektu na podane, za pomoca standardowego wejscia .*/
	void wprowadzDaneStatkuRecznie(istream &c);

	///Metoda pozwalajaca na wprowadzenie danych Statku Wodnego Pasazerskiego.
	/**
	Umozliwia wprowadzanie danych obiektu z pliku.
	*/
	void wprowadzDaneStatkuZPliku(istream &c); 

	///Metoda pozwalajaca dodac pasazera do listy pasazerow.
	/**Metoda pozwala na dodanie pasazera o podanym nazwisku.
	\param nazwisko nazwisko pasazera ktorego chcemy dodac na liste*/
	void dodajPasazera(string imie_nazwisko);

	///Metoda pozwalajaca usunac dowolnego pasazera z listy pasazerow
	/**Metoda pozwala na usuniecie pasazera o podanym indeksie.
	\param indeks indeks pasazera na liscie*/
	void usunPasazera(unsigned int indeks);

	///Metoda pozwalajaca uzyskac dane na temat Statku Wodnego Pasazerskiego.
	/**
	Umozliwia wyprowadzenie danych obiektu na dowolny strumien wyjscia.
	\param c dowolny strumien wyjscia*/
	void wypisDanychStatku(ostream &c);

	///Metoda zwracajaca liczbe pokoi danego statku.
	/**Metoda zwraca liczbe calkowita oznaczajaca liczbe pokoi.
	\return liczba_pokoi liczba pokoi na statku*/
	int liczbaPokoi();

	friend ostream& operator<<(ostream &c, StatekWodnyPasazerski &swp);

	friend istream& operator >> (istream &c, StatekWodnyPasazerski &swp);

protected:
	vector<string> pasazerowie_imie_nazwisko;  ///<kontener wypelniony nazwiskami pasazerow
	int liczba_pokoi; ///< liczba pokoi na statku
};
///Przeciazony operator wyjscia.
/**Przeciazony operator pozwala na uzyskanie danych na dowolny strumien wyjscia. W tym programie wykorzystywany do wypisu danych na standardowe wyjscie lub do pliku.*/
ostream& operator<<(ostream &c, StatekWodnyPasazerski &swp);
///Przeciazony operator wejscia.
/**Przeciazony operator pozwala na pobranie danych z dowolnego strumienia wejscia. W tym programie wykorzystywany do odczytu danych z pliku.*/
istream& operator >> (istream &c, StatekWodnyPasazerski &swp);