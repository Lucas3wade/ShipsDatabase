#pragma once
#include "StatekKosmiczny.h"
#include "StatekWodnyPasazerski.h"
#include "StatekWodny.h"
#include "Statek.h"

#include <vector>

///funckja uruchamiajaca interfejs
void menu();

/// Funkcja zapisajaca dane obiektow do pliku
/**Procedura pozwala zapisac stan wszystkich utrzorzonych obiektow, przetrzymywanych w kontenerze, do pliku.
\param wektor jest to kontener przechowujacy wskazniki na utworzone obiekty
\param c dowolny strumien wyjsciowy*/

void zapiszDoPliku(vector<Statek*> wektor,ostream &c);

/// Funkcja odczytujaca dane obiektow z pliku
/**Procedura pozwala odczytac stan wszystkich zapisanych obiektow, przetrzymywanych w pliku.
\param wektor jest to kontener w ktorym bedziemy przechowywac obiekty odczytane z pliku
\param c dowolny strumien wejsciowy*/

void wczytajDaneZPliku(vector<Statek*> &wektor,istream &c);

/// Funkcja wypisujaca dane obiektow na standardowe wyjscie
/**Procedura pozwala wypisac stan wszystkich, przechowywanych w kontenerze, obiektow.
\param wektor jest to kontener przechowujacy wskazniki na utworzone obiekty
\param c dowolny strumien wyjsciowy(w naszym przypadku bedzie to standardowe wyjscie)*/

void wypiszNaEkran(vector<Statek*> wektor, ostream &c);