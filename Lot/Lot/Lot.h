#pragma once
#include <iostream>
#include <string>

using namespace std;

size_t generujLiczbeLosowa(size_t poczatek, size_t koniec);


class Lot
{
	int id_lotu;
	string m_startowe;
	string m_docelowe;
	int godzina;
	int minuta;
	string klasa_lotnicza;
	int cena;
	string status;

	class Bilet
	{
		friend class Lot;
		int id;
		//const int id_lotu;
		const size_t pesel{};
		string imie;
		string nazwisko;
		int wiek;
		int liczba_pasazerow;
		size_t liczba_bagazu;
		string bagaz[20] = {};
	public:
		Bilet();
		~Bilet();
		size_t get_pesel() const { return pesel; };
		size_t get_id();
		void set_id(int i);
		string get_imie();
		void set_imie(string imie);
		string get_nazwisko();
		void set_nazwisko(string nazwisko);
		size_t get_wiek();
		void set_wiek(int wiek);
		size_t get_liczba_pasazerow();
		void set_liczba_pasazerow(int liczba_pasazerow);
		size_t get_liczba_bagazu();
		void set_liczba_bagazu(size_t liczba_bagazu);
		string get_bagaz(int i);
		void set_bagaz(int f, string bag);

	};

	Bilet* bilety;

public:
	Lot();
	~Lot();
	Lot(const Lot&);
	size_t get_id_lotu();
	void set_id_lotu(int id_lotu);
	string get_m_startowe();
	void set_m_startowe(string m_startowe);
	string get_m_docelowe();
	void set_m_docelowe(string m_docelowe);
	size_t get_godzina();
	void set_godzina(int godzina);
	size_t get_minuta();
	void set_minuta(int minuta);
	string get_klasa_lotnicza();
	void set_klasa_lotnicza(string klasa_lotnicza);
	size_t get_cena();
	void set_cena(int cena);
	string get_status();
	void set_status(string status);


	void print(Lot* loty, size_t rozmiar, size_t nr);
	void kupBilet(Lot* loty, size_t rozmiar);
	void sprawdz_bagaz(size_t rozmiar_bagazu, size_t d);
	//void stworz(Bilet*& bilety, const size_t rozmiar);
	void usun(Bilet* bilety, size_t rozmiar, size_t index);
	void stworz(size_t rozmiar);
	void usun();
};

void usun(Lot*& loty);
void stworz(Lot*& loty, const size_t rozmiar);
void wygenerujLoty(Lot*& loty, size_t rozmiar);
void wybierzLot(Lot* loty, size_t rozmiar, string action);
void aktualnyCzas(int& Hour, int& Min, int& Sec);
void printLoty(Lot*& loty, size_t rozmiar);


