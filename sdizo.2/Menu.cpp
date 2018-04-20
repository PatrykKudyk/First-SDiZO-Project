#include "Menu.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>


using namespace std;

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::menu(Menu menu)
{
	bool running = true;
	do {
		int i = 0, number;
		do {
			if (i > 0) cout << "Podana przez ciebie liczba wykracza poza dopuszczalny zakres." << endl
				<< "Podaj nowa, ktora jest poprawna" << endl;
			cout << "Wybierz rodzaj danych, na ktorym chcesz przeprowadzic testy:" << endl
				<< "[1] - Tablica" << endl
				<< "[2] - Lista" << endl
				<< "[3] - Kopiec" << endl
				<< "[4] - Zakonczyc dzialanie programu" << endl;
			cin >> number;
			if (cin.fail())
			{
				do {
					cout << "Niepoprawny format wprowadzonej danej. Wprowadz nowa." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> number;
				} while (cin.fail());
			}
			i++;
			system("cls");
		} while (number < 1 || number > 4);

		switch (number)
		{
		case 1:
			menu.arr.menu();
			break;
		case 2:
			menu.list.menu();
			break;
		case 3:
			menu.heap.menu();
			break;
		case 4:
			running = false;
		default:
			break;
		}
	} while (running);

}