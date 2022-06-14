#pragma once
#include <iostream>
#include <string>

using namespace std;
class Lot
{
	friend class Klient;
	friend class Pilot;

	int id_lotu;
	string m_startowe;
	string m_docelowe;
	int godzina;
	int minuta;
	string klasa_lotnicza;
	int cena;
	string status;

	class Osoba
	{
		int id;
		const size_t pesel{};
		string imie;
		string nazwisko;
		int wiek;
		int znizka;
	public:
		virtual void rejestruj(int i) = 0;
		virtual void wyswietl() = 0;
		virtual void naliczenieZnizki() = 0;
		int sprawdzZnizka()
		{
			if (wiek < 16)
			{
				return 50;
			}
			else
			{
				return 0;
			}
		}
		Osoba();
		~Osoba();
		size_t get_pesel() const { return pesel; };
		size_t get_id() { return id; }
		void set_id(int id) { this->id = id; };
		string get_imie() { return imie; }
		void set_imie(string imie) { this->imie = imie; }
		string get_nazwisko() { return nazwisko; }
		void set_nazwisko(string nazwisko) { this->nazwisko = nazwisko; }
		int get_wiek() { return wiek; }
		void set_wiek(int wiek) { this->wiek = wiek; }

		int get_znizka() { return znizka; }
		void set_znizka(int i) { this->znizka = znizka; }
	};
	Osoba** osoby;
public:
	Lot();
	~Lot();
	void rejestrujKlienta();
	void wyswietlKlientow();
	void rejestrujPilota();
	void wyswietlPilotow();

	void anulujBilet(size_t ind);
	void anulujBilety();
	void usunPilota(size_t ind);
	void usunPilotow();


	size_t get_id_lotu() { return id_lotu; }
	void set_id_lotu(int id_lotu) { this->id_lotu = id_lotu; }
	string get_m_startowe() { return m_startowe; }
	void set_m_startowe(string m_startowe) { this->m_startowe = m_startowe; }
	string get_m_docelowe() { return m_docelowe; }
	void set_m_docelowe(string m_docelowe) { this->m_docelowe = m_docelowe; }
	size_t get_godzina() { return godzina; }
	void set_godzina(int godzina) { this->godzina = godzina; }
	size_t get_minuta() { return minuta; }
	void set_minuta(int minuta) { this->minuta = minuta; }
	string get_klasa_lotnicza() { return klasa_lotnicza; }
	void set_klasa_lotnicza(string klasa_lotnicza) { this->klasa_lotnicza = klasa_lotnicza; }
	size_t get_cena() { return cena; }
	void set_cena(int cena) { this->cena = cena; }
	string get_status() { return status; }
	void set_status(string status) { this->status = status; }
};


template <class T> void stworz(T*& t, size_t rozmiar)
{
	t = new T[rozmiar];
}

template <class T> void usun(T*& t)
{
	delete[] t;
	t = nullptr;
	cout << "Tablica loty zostala usunieta. " << endl;
}

template <class T> void os(T**& o)
{
	o = new T * [20];
	for (int i = 0; i < 10; i++)
	{
		o[i] = new Klient;
	}
	for (int i = 10; i < 20; i++)
	{
		o[i] = new Pilot;
	}
}

template <class T> void osUsun(T**& o)
{
	for (int i = 0; i < 20; i++)
	{
		delete o[i];
	}
	delete[] o;
	o = nullptr;
}

void wygenerujLoty(Lot*& loty, size_t rozmiar);
void wybierzLot(Lot* loty, size_t rozmiar, string action);
void aktualnyCzas(int& Hour, int& Min, int& Sec);
void printLoty(Lot*& loty, size_t rozmiar);