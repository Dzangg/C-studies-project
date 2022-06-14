#pragma once
#include <iostream>
#include <string>
#include "Osoba.h"
#include <algorithm>

using namespace std;

class Klient : public Lot::Osoba
{
	int liczba_pasazerow;
	int liczba_bagazu;
	string bagaz[20] = {};

public:
	Klient();
	~Klient();
	void naliczenieZnizki()
	{
		auto temp = sprawdzZnizka();
		set_znizka(temp);
	}

	virtual void rejestruj(int i)
	{
		string temp, bag;
		int temp2, licznik_bagazu = 0;
		for (int i = 0; i < get_liczba_bagazu(); i++)
		{
			bagaz[i] = " ";
		}

		set_id(i);
		cout << "Wprowadz imie: " << endl;
		cin >> temp;
		set_imie(temp);
		cout << "Wprowadz nazwisko: " << endl;
		cin >> temp;
		set_nazwisko(temp);
		cout << "Wprowadz wiek: " << endl;
		cin >> temp2;
		set_wiek(temp2);
		cout << "Wprowadz liczbe pasazerow: " << endl;
		cin >> temp2;
		set_liczba_pasazerow(temp2);
		cout << "Wprowadz zawartosc bagazu: " << endl;
		while (true)
		{
			cout << "Wprowadz rzecz lub wprowadz q aby przejsc dalej: " << endl;
			cin >> bag;
			if (bag == "q")
			{
				set_liczba_bagazu(licznik_bagazu);
				sprawdz_bagaz(licznik_bagazu);
				break;
			}
			else
			{
				set_bagaz(licznik_bagazu, bag);
				licznik_bagazu++;
				continue;
			}
		}
	}
	virtual void wyswietl()
	{
		cout << "Imie: " << get_imie() << endl;
		cout << "Nazwisko: " << get_nazwisko() << endl;
		cout << "Wiek: " << get_wiek() << endl;
		cout << "Liczba pasazerow: " << get_liczba_pasazerow() << endl;
		cout << "Bagaz: ";
		for (size_t k = 0; k < get_liczba_bagazu(); k++)
		{
			cout << get_bagaz(k) << " ";
		}
		cout << "\n\n";
	}

	void sprawdz_bagaz(size_t rozmiar_bagazu)
	{
		string zakazane_przedmioty[] = { "PISTOLET", "NOZ", "BRON", "KARABIN", "KOKTAJL MOLOTOVA", "GRANAT", "BOMBA" };
		string rzecz;
		int nielegalny_przedmiot = 0;
		cout << "\n";
		for (size_t i = 0; i < rozmiar_bagazu; i++)
		{
			rzecz = get_bagaz(i);
			transform(rzecz.begin(), rzecz.end(), rzecz.begin(), ::toupper); // konwertowanie string na duze litery
			for (size_t k = 0; k < 7; k++)
			{
				if (rzecz == zakazane_przedmioty[k])
				{
					//transform(rzecz.begin(), rzecz.end(), rzecz.begin(), ::tolower);
					cout << "Wykryto nielegalny przedmiot: " << rzecz << endl;
					nielegalny_przedmiot++;
				}
			}
		}
		if (nielegalny_przedmiot > 0)
		{
			cout << "Wezwana zostala policja...\n" << endl;
			exit(0);
		}
		else
		{
			cout << "Weryfikacja bagazu przebiegla pomyslnie...\n" << endl;
		}
	}



	void set_liczba_pasazerow(int liczba_pasazerow) { this->liczba_pasazerow = liczba_pasazerow; }
	int get_liczba_pasazerow() { return liczba_pasazerow; }
	void set_liczba_bagazu(int liczba_bagazu) { this->liczba_bagazu = liczba_bagazu; }
	int get_liczba_bagazu() { return liczba_bagazu; }
	void set_bagaz(int k, string bag) { this->bagaz[k] = bag; }
	string get_bagaz(int k) { return bagaz[k]; }


};
