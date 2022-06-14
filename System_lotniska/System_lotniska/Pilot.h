#pragma once
#include <iostream>
#include <string>
#include "Osoba.h"

using namespace std;


class Pilot : public Lot::Osoba
{
	string stopien;

public:
	Pilot();
	~Pilot();
	void naliczenieZnizki()
	{

	}
	virtual void rejestruj(int i)
	{
		string temp;
		int temp2;
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
		cout << "Wprowadz stopien: " << endl;
		cin >> temp;
		set_stopien(temp);
	}
	virtual void wyswietl()
	{
		cout << "Imie: " << get_imie() << endl;
		cout << "Nazwisko: " << get_nazwisko() << endl;
		cout << "Wiek: " << get_wiek() << endl;
		cout << "Stopien: " << get_stopien() << endl;
		cout << "\n\n";
	}

	void set_stopien(string stopien) { this->stopien = stopien; }
	string get_stopien() { return stopien; }

};