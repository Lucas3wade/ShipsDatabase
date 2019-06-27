#include "Interfejs.h"


#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void zapiszDoPliku(vector<Statek*> wektor,ostream &c)
{
	for(unsigned int i=0;i<wektor.size();i++)
	{
		wektor[i]->wypisDanychStatku(c);
	}
}

void wypiszNaEkran(vector<Statek*> wektor, ostream &c)
{
	for (unsigned int i = 0; i < wektor.size(); i++)
	{
		wektor[i]->wypisDanychStatku(c);
		c << endl;
	}
}
void wczytajDaneZPliku(vector<Statek*> &wektor,istream &c)
{
	StatekKosmiczny *sk;
	StatekWodnyPasazerski *swp;
	int i = 0;
	string rodzaj_statku;
	while(c >> rodzaj_statku >> rodzaj_statku)
	{
		if (rodzaj_statku == "Kosmiczny")
		{
			sk = new StatekKosmiczny();
			sk->wprowadzDaneStatkuZPliku(c);
			wektor.push_back(sk);
		}
		else
		{
			c >> rodzaj_statku;
			swp = new StatekWodnyPasazerski();
			swp->wprowadzDaneStatkuZPliku(c);
			wektor.push_back(swp);
		}
	}
}
void menu()
{
	vector <Statek*> obiekty;
	ifstream plik_wejsciowy;
	ofstream plik_wyjsciowy;
	int koniec_menu = 1;
	StatekKosmiczny *sk;
	StatekWodnyPasazerski *swp;

	while (koniec_menu)
	{
		char opcja_menu = 'x';
		cout << "Menu:" << endl;
		cout << "[1] Dodaj obiekt." << endl;
		cout << "[2] Wprowadz dane z pliku." << endl;
		cout << "[3] Zapisz do pliku." << endl;
		cout << "[4] Wypisz na ekran." << endl;
		cout << "[q] Wyjdz." << endl;
		cin >> opcja_menu;
		if (opcja_menu == '1')
		{
			int koniec_wprowadzania_obiektow = 1;
			while (koniec_wprowadzania_obiektow)
			{
				char opcja_menu_wprowadzania_obiektow = 'x';
				cout << "[1] Dodaj Statek Kosmiczny." << endl;
				cout << "[2] Dodaj Statek Wodny Pasazerski" << endl;
				cout << "[q] Wyjdz." << endl;
				cin >> opcja_menu_wprowadzania_obiektow;
				if (opcja_menu_wprowadzania_obiektow == '1')
				{
					sk = new StatekKosmiczny();
					sk->wprowadzDaneStatkuRecznie(cin);
					

					int koniec_wprowadzania_pracownikow = 1;
					while (koniec_wprowadzania_pracownikow)
					{
						string podane_nazwisko;
						int indeks;
						char opcja_menu_wprowadzania_pracownikow = 'x';
						cout << "[1] Dodaj pracownika." << endl;
						cout << "[2] Usun pracownika." << endl;
						cout << "[q] Wyjdz." << endl;
						cin >> opcja_menu_wprowadzania_pracownikow;
						switch (opcja_menu_wprowadzania_pracownikow)
						{
						case '1':
							cout << "Wprowadz nazwisko:" << endl;
							cin >> podane_nazwisko;
							sk->dodajPracownika(podane_nazwisko);
							break;
						case '2':
							cout << "Wprowadz indeks pracownika do usuniecia:" << endl;
							cin >> indeks;
							sk->usunPracownika(indeks);
							break;
						case 'q':
							koniec_wprowadzania_pracownikow = 0;
							break;
						default:
							cout << "Wprowadziles bledny znak, wprowadz jeszcze raz!" << endl;
							break;
						}	
					}
					obiekty.push_back(sk);
				}
				else if (opcja_menu_wprowadzania_obiektow == '2')
				{
					swp = new StatekWodnyPasazerski();
					swp->wprowadzDaneStatkuRecznie(cin);

					int koniec_wprowadzania_pracownikow = 1, koniec_wprowadzania_pasazerow=1;
					while (koniec_wprowadzania_pracownikow)
					{
						string podane_nazwisko;
						int indeks;
						char opcja_menu_wprowadzania_pracownikow = 'x';
						cout << "[1] Dodaj pracownika." << endl;
						cout << "[2] Usun pracownika." << endl;
						cout << "[q] Wyjdz." << endl;
						cin >> opcja_menu_wprowadzania_pracownikow;
						switch (opcja_menu_wprowadzania_pracownikow)
						{
						case '1':
							cout << "Wprowadz nazwisko pracownika:" << endl;
							cin >> podane_nazwisko;
							swp->dodajPracownika(podane_nazwisko);
							break;
						case '2':
							cout << "Wprowadz indeks pracownika do usuniecia:" << endl;
							cin >> indeks;
							swp->usunPracownika(indeks);
							break;
						case 'q':
							koniec_wprowadzania_pracownikow = 0;
							break;
						default:
							cout << "Wprowadziles bledny znak, wprowadz jeszcze raz!" << endl;
							break;
						}
					}
					while (koniec_wprowadzania_pasazerow)
					{
						string podane_nazwisko;
						int indeks;
						char opcja_menu_wprowadzania_pasazera = 'x';
						cout << "[1] Dodaj pasazera." << endl;
						cout << "[2] Usun pasazera." << endl;
						cout << "[q] Wyjdz." << endl;
						cin >> opcja_menu_wprowadzania_pasazera;
						switch (opcja_menu_wprowadzania_pasazera)
						{
						case '1':
							cout << "Wprowadz nazwisko pasazera:" << endl;
							cin >> podane_nazwisko;
							swp->dodajPasazera(podane_nazwisko);
							break;
						case '2':
							cout << "Wprowadz indeks pracownika do usuniecia:" << endl;
							cin >> indeks;
							swp->usunPasazera(indeks);
							break;
						case 'q':
							koniec_wprowadzania_pasazerow = 0;
							break;
						default:
							cout << "Wprowadziles bledny znak, wprowadz jeszcze raz!" << endl;
							break;
						}
					}

					obiekty.push_back(swp);
				}
				else if (opcja_menu_wprowadzania_obiektow == 'q')
				{
					koniec_wprowadzania_obiektow = 0;
				}
				else
				{
					cout << "Wprowadziles bledny znak, wprowadz jeszcze raz!" << endl;
				}
				
			}
		}
		else if (opcja_menu == '2')
		{
			string podana_nazwa_pliku;
			cout << "Podaj nazwe pliku do odczytu.(z dopiskiem "".txt"")" << endl;
			cin >> podana_nazwa_pliku;
			plik_wejsciowy.open(podana_nazwa_pliku);
			if (plik_wejsciowy.good())
			{
			wczytajDaneZPliku(obiekty, plik_wejsciowy);
				
			}
			else
				cout << "Nieudane otwarcie pliku." << endl;
			plik_wejsciowy.close();

		}
		else if (opcja_menu == '3')
		{
			string podana_nazwa_pliku;
			cout << "Podaj nazwe pliku do zapisu.(z dopiskiem "".txt"")" << endl;
			cin >> podana_nazwa_pliku;
			plik_wyjsciowy.open(podana_nazwa_pliku);
			if (plik_wyjsciowy.good())
			{
				zapiszDoPliku(obiekty, plik_wyjsciowy);
				
			}
			else
				cout << "Blad otwarcia pliku" << endl;
			plik_wyjsciowy.close();
				
		}
		else if (opcja_menu == '4')
		{
			wypiszNaEkran(obiekty,cout);

		}
		else if (opcja_menu == 'q')
		{
			koniec_menu = 0;
		}
		else
		{
			cout << "Wprowadziles bledny znak, wprowadz jeszcze raz!" << endl;
		}
	
	}
	obiekty.erase(obiekty.begin(),obiekty.end());
}