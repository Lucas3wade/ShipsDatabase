#pragma once

#include <string>

using namespace std;

///Klasa pozwala na przechowywanie danych na temat pracownika.
class Pracownik
{
public:
	///Konstruktor z parametrem
	/**Pozwala na stworzenie pracownika od podanego nazwiska
	\param podane_nazwisko nazwisko pracownika ktorego chcemy dodac*/
	Pracownik(string podane_nazwisko="-");

	//zaprzyjazniony operator strumieniowy
	friend ostream& operator<<(ostream &c, Pracownik &p);

private:
	string nazwisko; ///<nazwisko pracownika
};

///Przeciazony operator wyjscia.
/**Przeciazony operator pozwala na uzyskanie danych na dowolny strumien wyjscia. W tym programie wykorzystywany do wypisu danych na standardowe wyjscie lub do pliku.*/
ostream& operator<<(ostream &c, Pracownik &p);
