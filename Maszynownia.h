#pragma once
#include <string>

using namespace std;
/// Klasa pozwalajaca przechowywac dane na temat maszynownii.
class Maszynownia
{
	
public:
	///Konstruktor domyslny
	Maszynownia();
	
	//metody

	///Metoda pozwalajaca na wprowadzenie danych maszynownii.
	/**
	Umozliwia ustawienie danych obiektu na podane.
	\param nowa_liczba_silnikow jest to liczba silnikow statku
	\param nowa_liczba_osob_obslugujacych jest to liczba osob obslugujacych silniki na statku*/
	void wprowadzDaneMaszynownia(int nowa_liczba_silnikow, int nowa_liczba_osob_obslugujacych);

	///Metoda pozwalajaca uzyskac dane na temat maszynownii.
	/**
	Umozliwia wyprowadzenie danych obiektu na dowolny strumien wyjscia.
	\param c dowolny strumien wyjscia
	*/
	void wypisMaszynownia(ostream &c);

	//operatory

	friend ostream& operator<<(ostream &c, Maszynownia &maszynownia);
	friend istream& operator>>(istream &c, Maszynownia &maszynownia);

private:
	int liczba_silnikow; ///<  liczba silnikow zamontowanych na statku
	int liczba_osob_obslugujacych; ///< liczba osob potrzebnych do obslugi silnikow na statku
};

///Przeciazony operator wejscia.
/**Przeciazony operator pozwala na pobranie danych z dowolnego strumienia wejscia. W tym programie wykorzystywany do odczytu danych z pliku.*/
istream& operator >> (istream &c, Maszynownia &maszynownia);
///Przeciazony operator wyjscia.
/**Przeciazony operator pozwala na uzyskanie danych na dowlny strumien wyjscia. W tym programie wykorzystywany do wypisu danych na standardowe wyjscie lub do pliku.*/
ostream& operator<<(ostream &c, Maszynownia &maszynownia);


