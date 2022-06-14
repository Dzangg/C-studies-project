#include "Osoba.h"
#include "Klient.h"
#include "Pilot.h"
#include <random>

size_t generujLiczbeLosowa(size_t begin, size_t end) {
	random_device seed;     // ziarno poczatkowe
	mt19937 engine(seed()); // generator
	uniform_int_distribution<size_t> uniformDist(begin, end);
	return uniformDist(engine);
}

Lot::Osoba::Osoba() : id{ 0 }, pesel{ generujLiczbeLosowa(10000000000, 20000000000) },
imie{ "brak" }, nazwisko{ "brak" }, wiek{ 0 }, znizka{ 0 }
{

}

Lot::Osoba::~Osoba()
{

}


void Lot::rejestrujKlienta()
{
	cout << "Rejestracja klienta.\n" << endl;
	for (int i = 0; i < 10; i++)
	{

		if (osoby[i]->get_imie() == "brak")
		{
			osoby[i]->rejestruj(i);
			break;
		}
	}
}
void Lot::wyswietlKlientow()
{
	system("CLS");
	cout << "Zarejestrowani klienci: \n" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (osoby[i]->get_imie() != "brak")
		{
			cout << "Bilet nr: " << osoby[i]->get_id() + 1 << endl;
			osoby[i]->wyswietl();
		}

	}
}

void Lot::anulujBilet(size_t ind)
{
	osoby[ind - 1]->set_imie("brak");
	osoby[ind - 1]->set_nazwisko("brak");
	osoby[ind - 1]->set_wiek(0);

	int licznik = 0;
	for (int i = 0; i < 10; i++)
	{
		if (osoby[i]->get_imie() != "brak")
		{
			osoby[i]->set_id(licznik);
			licznik++;
		}
	}
}

void Lot::anulujBilety()
{
	for (int i = 0; i < 10; i++)
	{
		osoby[i]->set_imie("brak");
		osoby[i]->set_nazwisko("brak");
		osoby[i]->set_wiek(0);
	}
}

void Lot::rejestrujPilota()
{
	cout << "Rejestracja pilota.\n" << endl;
	for (int i = 10; i < 20; i++)
	{
		if (osoby[i]->get_imie() == "brak")
		{
			osoby[i]->rejestruj(i - 10);
			break;
		}
	}
}

void Lot::wyswietlPilotow()
{
	cout << "Zarejestrowani piloci: \n" << endl;
	for (int i = 10; i < 20; i++)
	{
		if (osoby[i]->get_imie() != "brak")
		{
			cout << "Pilot nr: " << osoby[i]->get_id() + 1 << endl;
			osoby[i]->wyswietl();
		}

	}
}

void Lot::usunPilota(size_t ind)
{
	osoby[ind + 10]->set_imie("brak");
	osoby[ind + 10]->set_nazwisko("brak");
	osoby[ind + 10]->set_wiek(0);

	int licznik = 0;
	for (int i = 10; i < 20; i++)
	{
		if (osoby[i]->get_imie() != "brak")
		{
			osoby[i]->set_id(licznik);
			licznik++;
		}
	}
}

void Lot::usunPilotow()
{
	for (int i = 10; i < 20; i++)
	{
		osoby[i]->set_imie("brak");
		osoby[i]->set_nazwisko("brak");
		osoby[i]->set_wiek(0);
	}
}