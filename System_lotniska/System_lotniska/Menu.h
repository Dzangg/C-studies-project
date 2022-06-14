#pragma once
#include <iostream>
#include <string>
#include "Osoba.h"
#include "Pilot.h"
#include "Klient.h"

using namespace std;

void menu()
{
	size_t rozmiar = 10;
	int opcja, opcja2, ind;
	Lot* loty;
	stworz(loty, rozmiar);
	wygenerujLoty(loty, rozmiar);

	while (true)
	{
		cout << "Witaj na lotnisku\n" << endl;
		cout << "Wybierz opcje: \n" <<
			"(1) Wyswietl loty\n"
			"-------------------------\n"
			"(2) Kup bilet\n"
			"(3) Wyswietl bilety\n"
			"(4) Anuluj bilet \n"
			"(5) Anuluj bilety \n"
			"-------------------------\n"
			"(6) Dodaj pilota\n"
			"(7) Wyswietl pilotow\n"
			"(8) Usun pilota\n"
			"(9) Usun pilotow\n"
			"-------------------------\n"
			"(10) Wyjscie\n\n";



		cin >> opcja;
		switch (opcja)
		{
		case 1:
			printLoty(loty, rozmiar);

			break;
		case 2:
			system("CLS");
			wybierzLot(loty, rozmiar, "rejestruj_k");
			system("CLS");
			break;
		case 3:
			system("CLS");
			wybierzLot(loty, rozmiar, "wyswietl_k");
			break;
		case 4:
			system("CLS");
			wybierzLot(loty, rozmiar, "usunIndex_k");
			break;
		case 5:
			wybierzLot(loty, rozmiar, "usun_k");
			system("CLS");
			break;
		case 6:
			system("CLS");
			wybierzLot(loty, rozmiar, "rejestruj_p");
			system("CLS");
			break;
		case 7:
			system("CLS");
			wybierzLot(loty, rozmiar, "wyswietl_p");
			break;
		case 8:
			system("CLS");
			wybierzLot(loty, rozmiar, "usunIndex_p");
			break;
		case 9:
			wybierzLot(loty, rozmiar, "usun_p");
			system("CLS");
			break;
		case 10:
			exit(1);
			break;
		case 11:
			usun(loty);
			break;
		default:
			cout << "Zla opcja" << endl;
		}
	}
}
