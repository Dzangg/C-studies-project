#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include "Lot.h"

string zakazane_przedmioty[] = { "PISTOLET", "NOZ", "BRON", "KARABIN", "KOKTAJL MOLOTOVA", "GRANAT", "BOMBA" };
int rozmiar_zp = *(&zakazane_przedmioty + 1) - zakazane_przedmioty;

string miejsca_docelowe[] = { "LONDYN", "PARYZ", "BERLIN", "MADRYT", "OSLO", "STOCKHOLM", "PRAGA", "WIEDEN", "RZYM", "AMSTERDAM", "MOSKWA", "MINSK", "KIJOW" };
int rozmiar_md = *(&miejsca_docelowe + 1) - miejsca_docelowe;

string klasa_l[] = { "ekonomiczna", "biznesowa", "pierwsza" };

string loty[10][3];

int Hour, Min, Sec;

int rozmiar = 10;

size_t generujLiczbeLosowa(size_t begin, size_t end) {
	random_device seed;     // ziarno poczatkowe
	mt19937 engine(seed()); // generator
	uniform_int_distribution<size_t> uniformDist(begin, end);
	return uniformDist(engine);
}

// ****************** BILET ******************
size_t Lot::Bilet::get_id() { return id; }
string Lot::Bilet::get_imie() { return imie; }
string Lot::Bilet::get_nazwisko() { return nazwisko; }
size_t Lot::Bilet::get_wiek() { return wiek; }
size_t Lot::Bilet::get_liczba_pasazerow() { return liczba_pasazerow; }
size_t Lot::Bilet::get_liczba_bagazu() { return liczba_bagazu; }
string Lot::Bilet::get_bagaz(int i) { return bagaz[i]; }

void Lot::Bilet::set_id(int id) { this->id = id; };
void Lot::Bilet::set_imie(string imie) { this->imie = imie; };
void Lot::Bilet::set_nazwisko(string nazwisko) { this->nazwisko = nazwisko; };
void Lot::Bilet::set_wiek(int wiek) { this->wiek = wiek; };
void Lot::Bilet::set_liczba_pasazerow(int liczba_pasazerow) { this->liczba_pasazerow = liczba_pasazerow; };
void Lot::Bilet::set_liczba_bagazu(size_t liczba_bagazu) { this->liczba_bagazu = liczba_bagazu; };
void Lot::Bilet::set_bagaz(int f, string bag) { this->bagaz[f] = bag; };


// ****************** LOT ******************
size_t Lot::get_id_lotu() { return id_lotu; }
string Lot::get_m_startowe() { return m_startowe; }
string Lot::get_m_docelowe() { return m_docelowe; }
size_t Lot::get_godzina() { return godzina; }
size_t Lot::get_minuta() { return minuta; }
string Lot::get_klasa_lotnicza() { return klasa_lotnicza; }
size_t Lot::get_cena() { return cena; }
string Lot::get_status() { return status; }

void Lot::set_id_lotu(int id_lotu) { this->id_lotu = id_lotu; };
void Lot::set_m_startowe(string m_startowe) { this->m_startowe = m_startowe; };
void Lot::set_m_docelowe(string m_docelowe) { this->m_docelowe = m_docelowe; };
void Lot::set_godzina(int godzina) { this->godzina = godzina; };
void Lot::set_minuta(int minuta) { this->minuta = minuta; };
void Lot::set_klasa_lotnicza(string klasa_lotnicza) { this->klasa_lotnicza = klasa_lotnicza; };
void Lot::set_cena(int cena) { this->cena = cena; };
void Lot::set_status(string status) { this->status = status; };




// ------------------ Konstruktor ------------------
Lot::Lot()
{
	id_lotu = 0;
	m_startowe = "brak";
	m_docelowe = "brak";
	godzina = 0;
	minuta = 0;
	klasa_lotnicza = "brak";
	cena = 0;
	status = "brak";

	stworz(rozmiar);
	
}

Lot::Bilet::Bilet() : pesel{ generujLiczbeLosowa(10000000000, 20000000000) }
{
	id = 0;
	imie = "brak";
	nazwisko = "brak";
	wiek = 0;
	liczba_pasazerow = 0;
	liczba_bagazu = 0;
};

// ------------------ Konstruktor kopiujacy ------------------
Lot::Lot(const Lot& l)
{
	id_lotu = l.id_lotu;
	m_startowe = l.m_startowe;
	m_docelowe = l.m_docelowe;
	godzina = l.godzina;
	minuta = l.minuta;
	klasa_lotnicza = l.klasa_lotnicza;
	cena = l.cena;
	status = l.status;
}


// ------------------ Destruktor ------------------
Lot::~Lot()
{
	usun();
}
Lot::Bilet::~Bilet()
{


}


// ------------------ Stworz ------------------
void stworz(Lot*& loty, const size_t rozmiar) 
{
	loty = new Lot[rozmiar];
}
void Lot::stworz(size_t rozmiar) 
{
	bilety = new Bilet[rozmiar];
}

// ------------------ Usun ------------------
void usun(Lot*& loty) // fn
{
	delete[] loty;
	loty = nullptr;
	cout << "Tablica loty zostala usunieta. " << endl;
}
void Lot::usun() // fn
{
	delete[] bilety;
	bilety = nullptr;
	cout << "Tablica  bilty zostala usunieta. " << endl;
}


// ------------------ Usun Index ------------------
void Lot::usun(Bilet* bilety, size_t rozmiar, size_t index)
{
	size_t rozmiar_bagazu, licznik = 0;
	bilety[index - 1].set_id(0);
	bilety[index - 1].set_imie("brak");
	bilety[index - 1].set_nazwisko("brak");
	bilety[index - 1].set_wiek(0);
	bilety[index - 1].set_liczba_pasazerow(0);
	rozmiar_bagazu = bilety[index - 1].get_liczba_bagazu();
	for (int i = 0; i < rozmiar_bagazu; i++)
	{
		bilety[index - 1].set_bagaz(i, "");
	}

	for (int j = 0; j < rozmiar; j++)
	{
		if (bilety[j].get_id() != NULL)
		{
			licznik++;
			bilety[j].set_id(licznik);
		}
	}
	system("CLS");
}



// ------------------ Kup Bilet ------------------
void Lot::kupBilet(Lot* loty, size_t rozmiar) {
	string bag, temp;
	int opcja;
	int licznik_bagazu = 0;
	int temp2;
	for (int i = 0; i < rozmiar; i++)
	{
		system("CLS");
		licznik_bagazu = 0;
		if (bilety[i].get_id() == 0)
		{
			cout << "----------Kasa biletowa----------" << endl;
			bilety[i].set_id(i + 1);
			cout << "Wprowadz imie: " << endl;
			cin >> temp;
			bilety[i].set_imie(temp);
			cout << "Wprowadz nazwisko: " << endl;
			cin >> temp;
			bilety[i].set_nazwisko(temp);
			cout << "Wprowadz wiek: " << endl;
			cin >> temp2;
			bilety[i].set_wiek(temp2);
			cout << "Wprowadz liczbe pasazerow: " << endl;
			cin >> temp2;
			bilety[i].set_liczba_pasazerow(temp2);
			cout << "Wprowadz zawartosc bagazu: " << endl;
			while (true)
			{
				cout << "Wprowadz rzecz lub wprowadz q aby przejsc dalej: " << endl;
				cin >> bag;
				if (bag == "q")
				{
					bilety[i].set_liczba_bagazu(licznik_bagazu);
					sprawdz_bagaz(licznik_bagazu, i);
					break;
				}
				else
				{
					bilety[i].set_bagaz(licznik_bagazu, bag);
					licznik_bagazu++;
					continue;
				}
			}

			cout << "Chcesz kupic kolejny bilet? (1)Tak (2)Nie " << endl;
			cin >> opcja;
			if (opcja == 1)
			{
				continue;
			}
			if (opcja == 2)
			{
				system("CLS");
				break;
			}
		}
		else
		{
			continue;
		}
	}
}

// ------------------ Sprawdz bagaz ------------------
void Lot::sprawdz_bagaz(size_t rozmiar_bagazu, size_t d)
{
	string rzecz;
	int nielegalny_przedmiot = 0;
	cout << "\n";
	for (size_t i = 0; i < rozmiar_bagazu; i++)
	{
		rzecz = bilety[d].get_bagaz(i);
		transform(rzecz.begin(), rzecz.end(), rzecz.begin(), ::toupper); // konwertowanie string na duze litery
		for (size_t k = 0; k < rozmiar_zp; k++)
		{
			if (rzecz == zakazane_przedmioty[k])
			{
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

// ------------------ Print ------------------
void Lot::print(Lot* loty, size_t rozmiar, size_t nr)
{
	int licznik_bagazu;
	string temp, temp2;
	system("CLS");
	licznik_bagazu = 0;
	cout << "Lot nr. " << loty[nr].get_id_lotu() << " | "  << loty[nr].get_m_startowe()
		<< " - " << loty[nr].get_m_docelowe() << " | " << "\n\n";
	for (int i = 0; i < rozmiar; i++)
	{
		if (bilety[i].get_id() == 0)
		{
			continue;
		}
		else
		{
			cout << "Bilet: " << bilety[i].get_id() << endl;
			cout << "Imie: " << bilety[i].get_imie() << endl;
			cout << "Nazwisko: " << bilety[i].get_nazwisko() << endl;
			cout << "Wiek: " << bilety[i].get_wiek() << endl;
			cout << "Pesel: " << bilety[i].get_pesel() << endl;
			cout << "Liczba pasazerow: " << bilety[i].get_liczba_pasazerow() << endl;
			cout << "Zawartosc bagazu: " << endl;
			for (size_t j = 0; j < bilety[i].get_liczba_bagazu(); j++)
			{
				cout << bilety[i].get_bagaz(j) << " ";
			}
			cout << "\n";
		}
	}
	cout << "\n";
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


// ------------------ Print ------------------
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
	size_t opcja;
	size_t nr;
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
		if (action == "kup")
		{
			loty[nr].kupBilet(loty, rozmiar);
		}
		if (action == "print")
		{
			loty[nr].print(loty, rozmiar, nr);
		}
	}
}