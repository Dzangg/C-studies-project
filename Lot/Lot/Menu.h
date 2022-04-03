#pragma once

#include <iostream>
#include <string>
#include "Lot.h"
using namespace std;

void menu()
{

	size_t opcja, index, rozmiar = 10;
	
	Lot* loty;
	stworz(loty, rozmiar);
	wygenerujLoty(loty, rozmiar);



	cout << "Witaj na Lotnisku\n" << endl;

	while (true)
	{
		cout << "Wybierz opcje: " << endl << "(1) Wyswietl dostepne loty\n(2) Kup bilet\n(3) Wyswietl\n(4) Usun cale\n(5) Usun index\n(6) Zarzadzanie lotniskiem\n(7) Usun Loty\n" << endl;
		cin >> opcja;
		switch (opcja)
		{
		case 1:
			printLoty(loty, rozmiar);
			break;
		case 2:
			wybierzLot(loty, rozmiar, "kup");
			break;
		case 3:
			wybierzLot(loty, rozmiar, "print");
			break;
		case 4:
			//usun(bilety);
			break;
		case 5:
			system("CLS");
			//print(bilety, rozmiar);
			cout << "Ktory index chcesz usunac? " << endl;
			cin >> index;
			//usun(bilety, rozmiar, index);
			break;
		case 6:
			//
			break;
		case 7:

		default:
			cout << "Zla opcja" << endl;
			break;
		}
	}
}