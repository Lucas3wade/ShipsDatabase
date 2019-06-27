#pragma once

#include "Maszynownia.h"
#include "OpisStatku.h"
#include "Pracownik.h"
#include <vector>
///Klasa glowna abstrakcyjna podstawowa Statek
class Statek
{
public:
	/// konstruktor zwiekszajacy liczbe stworzonych statkow.
	Statek();
	

	//metody

	///Wirtualna metoda pozwalajaca na wprowadzenie danych Statku.
	/**
	Umozliwia ustawienie danych obiektu, za pomoca standardowego wejscia .*/
	virtual void wprowadzDaneStatkuRecznie(istream &c);

	///Metoda pozwalajaca na wprowadzenie danych Statku Kosmicznego.
	/**
	Umozliwia wprowadzanie danych obiektu z pliku.
	\param c strumien wejscia*/
	virtual void wprowadzDaneStatkuZPliku(istream &c);

	///Metoda abstrakcyjna pozwalajaca uzyskac dane klas pochodnych.
	/**
	Umozliwia wyprowadzenie danych obiektu na dowolny strumien wyjscia.
	\param c dowolny strumien wyjscia*/
	virtual void wypisDanychStatku(ostream &c)=0;

	///Metoda  pozwalajaca uzyskac podstawoe dane klasy podstawowej.
	/**
	Umozliwia wyprowadzenie danych obiektu na dowolny strumien wyjscia.
	\param c dowolny strumien wyjscia*/
	void wypisGlownychDanychStatku(ostream &c);

	///Metoda pozwalajaca dodac Pracownika do listy pasazerow.
	/**Metoda pozwala na dodanie Pracownika o podanym nazwisku.
	\param nazwisko nazwisko Pracownika ktorego chcemy dodac na liste*/
	void dodajPracownika(string nazwisko_pracownika);

	///Metoda pozwalajaca usunac dowolnego Pracownika z listy pasazerow
	/**Metoda pozwala na usuniecie Pracownika o podanym indeksie.
	\param indeks indeks Pracownika na liscie*/
	void usunPracownika(unsigned int indeks);
	
	/// Statyczna metoda zwracajaca liczbe istniejacych statkow
	/**Metoda pozwala ustalic ile statkow zostalo stworzonych
	\return liczba_istniejacych_statkow liczba istniejacych statkow  */
	static int liczbaIstniejacychStatkow()
	{
		return liczba_istniejacych_statkow;
	}

	friend ostream& operator<<(ostream &c, Statek &s);
	friend istream& operator>>(istream &c, Statek &s);
	
protected:
	Maszynownia maszynownia; ///<maszynownia klasa opisujaca maszynownie statku
	vector<Pracownik> pracownicy; ///<pracownicy kontener przechowujacy pracownikow statku
	OpisStatku opis_statku; ///< opis_statku klasa pozwalajaca przechowywac ogolne dane statku
	static int liczba_istniejacych_statkow; ///< liczba_istniejacych_statkow statyczna zmienna przechowujaca liczbe stworzonych statkow
};

///Przeciazony operator wyjscia.
/**Przeciazony operator pozwala na uzyskanie danych na dowlny strumien wyjscia. W tym programie wykorzystywany do wypisu danych na standardowe wyjscie lub do pliku.*/
ostream& operator<<(ostream &c, Statek &s);
///Przeciazony operator wejscia.
/**Przeciazony operator pozwala na pobranie danych z dowolnego strumienia wejscia. W tym programie wykorzystywany do odczytu danych z pliku.*/
istream& operator >> (istream &c, Statek &s);