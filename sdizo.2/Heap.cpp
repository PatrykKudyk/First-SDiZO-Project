#include "Heap.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

void Heap::menu()
{
	int counter = 0;
	this->readFile();
	bool running = true;
	do {
		int i = 0, number;
		do {
			system("cls");
			if (i > 0) cout << "Podana przez ciebie liczba wykracza poza dopuszczalny zakres." << endl
				<< "Podaj nowa, ktora jest poprawna" << endl;
			cout << "Co chcialbys teraz zrobic?:" << endl
				<< "[1] - Dodac element do badanego obiektu" << endl
				<< "[2] - Usunac element z badanego obiektu" << endl
				<< "[3] - Wyszukac element w badanym obiekcie" << endl
				<< "[4] - Wypisac elementy badanego obiektu" << endl
				<< "[5] - Zakonczyc dzialania na kopcach" << endl;
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
		} while (number < 1 || number > 5);

		switch (number)
		{
		case 1:
			int data;
			do {
				system("cls");
				cout << "Podaj liczbe do wpisania: " << endl;
				cin >> data;
				if (cin.fail())
				{
					do {
						cout << "Niepoprawny format wprowadzonej danej. Wprowadz nowa." << endl;
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> data;
					} while (cin.fail());
				}
			} while (cin.fail());
			this->push(data);
			cout << "Zrobione";
			cin.get();
			cin.get();
			break;
		case 2:
			if (this->size != 0)
				this->pop();
			else
			{
				cout << "Kopiec jest pusty. Nie mozna usunac elementu!" << endl;
				cin.get();
				cin.get();
			}
			break;
		case 3:
			if (this->size != 0) {
				counter = 0;
				do {
					if (counter > 0) cout << "Podano liczbe z poza zakresu!" << endl
						<< "Prosze o podanie poprawnej." << endl;
					cout << "Podaj liczbe, ktora chcialbys wyszukac w tablicy:" << endl;
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
					counter++;
					system("cls");
				} while (cin.fail());
				this->find(number);
			}
			else
			{
				cout << "Kopiec jest pusty. Nie ma czego wyszukiwac." << endl;
				cin.get();
				cin.get();
			}
			break;
		case 4:
			if (this->size != 0)
			{
				this->display("", "", 0);
				cout << endl;
				cin.get();
				cin.get();
			}
			else
			{
				cout << "Kopiec jest pusty. Nie ma co wypisywac!" << endl;
				cin.get();
				cin.get();
			}
			break;
		case 5:
			running = false;
			break;
		default:
			break;
		}
	} while (running);
	cin.get();
	system("cls");

	delete[] this->arr;
	this->arr = nullptr;
	this->size = NULL;
}

void Heap::readFile()
{
	string bufor;
	fstream file;
	int temp;

	file.open("data.txt", ios::in);
	if (file.good() == true)
		cout << "Odczyt poprawny!" << endl;
	else
	{
		cout << "Nieudane wczytywanie pliku!" << endl;
		cin.get();
		cin.get();
	}

	this->arr = new int;
	while (file.eof() == NULL)
	{
		getline(file, bufor);
		istringstream iss(bufor);
		iss >> temp;
		this->push(temp);
	}
}

void Heap::push(int val)
{
	int *pom = new int[this->size + 1];
	for (int i = 0; i < this->size; i++)
		pom[i] = this->arr[i];

	if (this->size == 0)
		delete this->arr;
	else
		delete[] this->arr;
	this->arr = pom;

	int i = this->size;
	int j = (i - 1) / 2;
	while (i > 0 && this->arr[j] < val)
	{
		this->arr[i] = this->arr[j];
		i = j;
		j = (i - 1) / 2;
	}
	this->arr[i] = val;
	this->size++;
}

void Heap::pop()
{
	if (this->size == 1)
	{
		int *pom = new int;
		delete[] this->arr;
		this->arr = pom;
		this->size = 0;
	}
	else
	{
		this->arr[0] = this->arr[this->size - 1]; // ustawiam wartosc pierwszego elementu na wartosc ostatniego
		int *pom = new int[this->size - 1];
		for (int i = 0; i < this->size - 1; i++)
			pom[i] = this->arr[i];
		delete[] this->arr;
		this->arr = pom;
		this->size--;
	}

	if (this->size - 1)
	{
		int v = this->arr[0];
		int i = 0, j = 1;
		while (j < this->size)
		{
			if (j + 1 < this->size && this->arr[j + 1] > this->arr[j])
				j++;
			if (v >= this->arr[j])
				break;
			this->arr[i] = this->arr[j];
			i = j;
			j = 2 * j + 1;
		}
		this->arr[i] = v;
	}
		cout << "Zrobione!" << endl;
		cin.get();
		cin.get();
		system("cls");
}

void Heap::display(string sp, string sn, int v)
{
	string s;

	if (v < this->size)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		display(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << this->arr[v] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		display(s + cp, cl, 2 * v + 1);
	}
}

void Heap::find(int val)
{
	int index;
	bool found = false;

	for (int i = 0; i < this->size; i++)
		if (this->arr[i] == val)
		{
			found = true;
			index = i;
			break;
		}
		if (found)
			cout << "Znalazlem zadana liczbe! (" << val << ")" << endl
				<< "Znajduje sie ona pod indeksem : " << index << " z zakresu <0," << this->size - 1 << ">" << endl;
		else
			cout << "Niestety, ale nie udalo sie znalezc zadanej przez Ciebie liczby. (" << val << ")" << endl;
		
		cin.get();
		cin.get();
		system("cls");
}

void Heap::clearHeap()
{
	if (this->size > 0)
	{
		delete[] this->arr;
		this->arr = nullptr;
		this->size = 0;
	}
	else
		return;
}

Heap::Heap()
{
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
}

Heap::~Heap()
{
	clearHeap();
}
