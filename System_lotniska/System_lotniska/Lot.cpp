#include "Osoba.h"
#include "Klient.h"
#include "Pilot.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>

string miejsca_docelowe[] = { "LONDYN", "PARYZ", "BERLIN", "MADRYT", "OSLO", "STOCKHOLM", "PRAGA", "WIEDEN", "RZYM", "AMSTERDAM", "MOSKWA", "MINSK", "KIJOW" };
int rozmiar_md = *(&miejsca_docelowe + 1) - miejsca_docelowe;

string klasa_l[] = { "ekonomiczna", "biznesowa", "pierwsza" };

string loty[10][3];

int Hour, Min, Sec;
size_t rozmiar = 10;
size_t rozmiar_pasazerow = 20;



Lot::Lot() : id_lotu{ 0 }, m_startowe{ "brak" }, m_docelowe{ "brak" }, godzina{ 0 },
minuta{ 0 }, klasa_lotnicza{ "brak" }, cena{ 0 }, status{ "brak" }
{
	os(osoby);
}

Lot::~Lot()
{
	osUsun(osoby);
}


void aktualnyCzas(int& Hour, int& Min, int& Sec)
{
	// _CRT_SECURE_NO_WARNINGS
	time_t currentTime;
	struct tm* localTime;
	time(&currentTime);                   // Wez aktualny czas
	localTime = localtime(&currentTime);  // Skonwertuj aktualny czas na lokalny
	Hour = localTime->tm_hour;
	Min = localTime->tm_min;
	Sec = localTime->tm_sec;
}

void wygenerujLoty(Lot*& loty, size_t rozmiar)
{
	int rand_md, rand_klasa, czasGodz_o, czasMin_o;
	int wylosowane_loty[10] = {};
	bool isGood = true;
	system("CLS");
	srand(time(NULL));
	aktualnyCzas(Hour, Min, Sec);
	string m_start = "WARSZAWA";
	for (int i = 0; i < rozmiar; i++)
	{
		rand_md = rand() % rozmiar_md;
		rand_klasa = rand() % 3;
		czasGodz_o = rand() % 6;
		czasMin_o = rand() % (60 - Sec);
		for (int s = 0; s < 10; s++)
		{
			if (wylosowane_loty[s] == rand_md)
			{
				isGood = false;
				i = i - 1;
				break;
			}
			else
			{
				isGood = true;
			}
		}
		if (isGood)
		{
			wylosowane_loty[i] = rand_md;
			loty[i].set_id_lotu(i + 1);
			loty[i].set_m_startowe(m_start);
			loty[i].set_m_docelowe(miejsca_docelowe[rand_md]);
			loty[i].set_godzina(Hour + czasGodz_o);
			loty[i].set_minuta(Min + czasMin_o);
			loty[i].set_klasa_lotnicza(klasa_l[rand_klasa]);
			if (klasa_l[rand_klasa] == "ekonomiczna")
			{
				loty[i].set_cena(150);
			}
			if (klasa_l[rand_klasa] == "biznesowa")
			{
				loty[i].set_cena(400);
			}
			if (klasa_l[rand_klasa] == "pierwsza")
			{
				loty[i].set_cena(999);
			}
			if (loty[i].get_m_docelowe() == "MOSKWA" || loty[i].get_m_docelowe() == "KIJOW" || loty[i].get_m_docelowe() == "MINSK")
			{
				loty[i].set_status("ODWOLANY");
			}
			else
			{
				loty[i].set_status("DOSTEPNY");
			}
		}
	}
}

void printLoty(Lot*& loty, size_t rozmiar)
{
	size_t strLength, strLength2;
	string emptyLines, emptyLines2;
	system("CLS");
	aktualnyCzas(Hour, Min, Sec);
	cout << "Aktualny czas to : " << Hour << ":" << Min << "\n\n";
	cout << "Dostepne loty: " << endl;
	for (int i = 0; i < rozmiar; i++)
	{
		emptyLines = "         "; // 9 
		emptyLines2 = "          "; // 12
		strLength = loty[i].get_m_docelowe().length();
		strLength2 = loty[i].get_klasa_lotnicza().length();
		emptyLines.resize(9 - strLength);
		emptyLines2.resize(12 - strLength2);
		if (i == 9)
		{
			cout << "  Lot nr. " << loty[i].get_id_lotu() << "  | " << loty[i].get_m_startowe() << " - " << loty[i].get_m_docelowe() << emptyLines << " | "
				<< "Klasa: " << loty[i].get_klasa_lotnicza() << emptyLines2 << "-  "
				<< "Cena: " << loty[i].get_cena() << " | "
				<< "Odlot: " << loty[i].get_godzina()
				<< ":" << loty[i].get_minuta()
				<< " | "
				<< "Status: " << loty[i].get_status() << endl;
		}
		else
		{
			cout << "  Lot nr.  " << loty[i].get_id_lotu() << "  | " << loty[i].get_m_startowe() << " - " << loty[i].get_m_docelowe() << emptyLines << " | "
				<< "Klasa: " << loty[i].get_klasa_lotnicza() << emptyLines2 << "-  "
				<< "Cena: " << loty[i].get_cena() << " | "
				<< "Odlot: " << loty[i].get_godzina()
				<< ":" << loty[i].get_minuta()
				<< " | "
				<< "Status: " << loty[i].get_status() << endl;
		}
	}
	cout << "\n";
}



void wybierzLot(Lot* loty, size_t rozmiar, string action)
{
	size_t opcja, nr, index;
	system("CLS");
	printLoty(loty, rozmiar);
	cout << "Wybierz lot: " << endl;
	cin >> nr;
	nr--;
	if (loty[nr].get_status() == "ODWOLANY")
	{
		cout << "Ten lot jest odwolany!!!" << endl;
	}
	else
	{
		if (action == "rejestruj_k")
		{
			system("CLS");
			loty[nr].rejestrujKlienta();
		}
		if (action == "wyswietl_k")
		{
			system("CLS");
			loty[nr].wyswietlKlientow();
		}
		if (action == "rejestruj_p")
		{
			system("CLS");
			loty[nr].rejestrujPilota();
		}
		if (action == "wyswietl_p")
		{
			system("CLS");
			loty[nr].wyswietlPilotow();
		}
		if (action == "usunIndex_k")
		{
			system("CLS");
			loty[nr].wyswietlKlientow();
			cout << "Ktory index chcesz usunac? " << endl;
			cin >> index;
			loty[nr].anulujBilet(index);
		}
		if (action == "usunIndex_p")
		{
			system("CLS");
			loty[nr].wyswietlPilotow();
			cout << "Ktory index chcesz usunac? " << endl;
			cin >> index;
			loty[nr].usunPilota(index);
		}
		if (action == "usun_k")
		{
			system("CLS");
			loty[nr].anulujBilety();
		}
		if (action == "usun_p")
		{
			system("CLS");
			loty[nr].usunPilotow();
		}
	}
}