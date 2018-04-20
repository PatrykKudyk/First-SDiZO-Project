#include "Array.h"	
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

void Array::menu()
{
	int  counter;

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
				<< "[5] - Zakonczyc dzialania na tablicach" << endl;
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
			this->add();
			break;
		case 2:
			if (this->size == 0) 
			{
				cout << "Tablica jest pusta. Nie mozna usunac zadnego elementu." << endl;
				cin.get();
				cin.get();
			}
			else
				subb();
			break;
		case 3:
			counter = 0;
			if (this->size == 0) 
			{
				cout << "Tablica jest pusta. Nie mozna usunac zadnego elementu." << endl;
				cin.get();
				cin.get();
			}
			else {
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
				find(number);
			}
			break;
		case 4:
			if (this->size == 0) 
			{
				cout << "Tablica jest pusta." << endl;
				cin.get();
				cin.get();
			}
			else
				display();
			break;
		case 5:
			running = false;
			break;
		default:
			break;
		}
	} while (running);

	delete[] this->arr;
	this->arr = nullptr;
}

void Array::readFile()
{
	int temp;
	string bufor;
	fstream file;

	file.open("data.txt", ios::in);
	if (file.good() == true)
		cout << "Odczyt udany!" << endl;
	else
	{
		cout << "Nieudane wczytywanie pliku!" << endl;
		cin.get();
		cin.get();
	}

	this->arr = new int;
	this->size = 0;
	while(file.eof() == NULL) 
	{
		getline(file, bufor);
		istringstream iss(bufor);
		iss >> temp;
		push(temp);
		this->size++;
	}
	file.close();
}

void Array::display()
{
	for (int i = 0, k = 0; i < this->size; i++, k++)
	{
		if (k == 5)
		{
			cout << endl;
			k = 0;
		}
		cout << this->arr[i] << "\t";
	}
	cout << endl;
	cin.get();
	cin.get();
	system("cls");
}

void Array::push(int data)
{
	if (this->size == 0)
		this->arr[0] = data;

	int *pom = new int[this->size + 1];
	for (int i = 0; i < this->size + 1; i++)
	{
		if (i == this->size)
			pom[i] = data;
		else
			pom[i] = this->arr[i];
	}
	if (this->size == 0)
		delete this->arr;
	else
		delete[] this->arr;
	this->arr = pom;
}

void Array::add()
{
	int toAdd;
	int number, index;
	int counter = 0;
	cout << "W ktorym miejscu chcialbys dodac element?" << endl
		<< "[1] - na poczatku tablicy" << endl
		<< "[2] - na koncu tablicy" << endl
		<< "[3] - we wskazanym miejscu w tablicy" << endl;
	do {
		if (counter > 0) cout << "Podano liczbe z poza zakresu! Prosze o podanie poprawnej." << endl;
		cin >> number;
		if (cin.fail())
		{
			do {
				system("cls");
				cout << "Niepoprawny format wprowadzonej danej. Wprowadz nowa." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> number;
			} while (cin.fail());
		}
		counter++;
		system("cls");
	} while (number < 1 || number > 3);
	switch (number)
	{
	case 1:
		do {
			system("cls");
			cout << "Podaj liczbe do wpisania: " << endl;
			cin >> toAdd;
			if (cin.fail())
			{
				do {
					cout << "Niepoprawny format wprowadzonej danej. Wprowadz nowa." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> toAdd;
				} while (cin.fail());
			}
		} while (cin.fail());
		if (this->size == 0)
		{
			int *pom = new int[1];
			this->size = 1;
			pom[0] = toAdd;
			if (this->arr)
				delete this->arr;
			this->arr = pom;
			cout << "Zrobione!" << endl;
			cin.get();
			cin.get();
			system("cls");
		}
		else
			addBeg(toAdd);
		break;
	case 2:
		do {
			system("cls");
			cout << "Podaj liczbe do wpisania: " << endl;
			cin >> toAdd;
			if (cin.fail())
			{
				do {
					cout << "Niepoprawny format wprowadzonej danej. Wprowadz nowa." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> toAdd;
				} while (cin.fail());
			}
		} while (cin.fail());
		if (this->size == 0)
		{
			int *pom = new int[1];
			this->size = 1;
			pom[0] = toAdd;
			if (this->arr)
				delete this->arr;
			this->arr = pom;
			cout << "Zrobione!" << endl;
			cin.get();
			cin.get();
			system("cls");
		}
		else
			addEnd(toAdd);
		break;
	case 3:
		counter = 0;
		do {
			system("cls");
			cout << "Podaj liczbe do wpisania: " << endl;
			cin >> toAdd;
			if (cin.fail())
			{
				do {
					cout << "Niepoprawny format wprowadzonej danej. Wprowadz nowa." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> toAdd;
				} while (cin.fail());
			}
		} while (cin.fail());
		if (this->size == 0)
		{
			char litera;
			do {
				if (counter > 0) cout << "Wprowadzono niepoprawna litere, prosze wprowadzic poprawna!" << endl;
				cout << "Tablica jest pusta, a wiec mozesz dodac element tylko na poczatek tablicy." << endl
					<< "Czy chcesz to zrobic? t/n" << endl;
				cin >> litera;
				counter++;
				system("cls");
			} while (litera != 't' && litera != 'T' && litera != 'n' && litera != 'N');
			if (litera == 't' || litera == 'T') {
				int *pom = new int[1];
				this->size = 1;
				pom[0] = toAdd;
				if (this->arr)
					delete this->arr;
				this->arr = pom;
				cout << "Zrobione!" << endl;
			}
			cin.get();
			cin.get();
		}
		else {
			do {
				if (counter > 0) cout << "Podano liczbe z poza zakresu!" << endl
					<< "Prosze o podanie poprawnej." << endl;
				cout << "Podaj indeks z zakresu: <0," << this->size - 1 << ">, w ktory chcialbys wstawic wstawic swoja dana: " << endl;
				cin >> index;
				if (cin.fail())
				{
					do {
						cout << "Niepoprawny format wprowadzonej danej. Wprowadz nowa." << endl;
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> index;
					} while (cin.fail());
				}
				counter++;
				system("cls");
			} while (index < 0 || index > this->size - 1);
			addGiv(toAdd, index);
		}
		break;
	default:
		break;
	}
}

void Array::addBeg(int val)
{
	int size = this->size;
	int *pom = new int[size + 1];
	this->size++;
	for (int i = 0; i < this->size; i++)
	{
		if (i == 0)
			pom[i] = val;
		else
			pom[i] = this->arr[i - 1];
	}
	delete[] this->arr;
	this->arr = pom;
	cout << "Zrobione!" << endl;
	cin.get();
	cin.get();
	system("cls");
}

void Array::addEnd(int val)
{
	int *pom = new int[size + 1];
	this->size++;
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			pom[i] = val;
		else
			pom[i] = this->arr[i];
	}

	delete[] this->arr;
	this->arr = pom;
	cout << "Zrobione!" << endl;
	cin.get();
	cin.get();
	system("cls");
}

void Array::addGiv(int val, int index)
{
		int *pom = new int[size + 1];
		this->size++;
		for (int i = 0; i < this->size; i++)
		{
			if (i < index)
				pom[i] = this->arr[i];
			else if (i == index)
				pom[i] = val;
			else if (i > index)
				pom[i] = this->arr[i - 1];
		}
		delete[] this->arr;
		this->arr = pom;
		cout << "Zrobione!" << endl;
		cin.get();
		cin.get();
	system("cls");
}

void Array::subbBeg()
{
		int *pom = new int[this->size - 1];
		this->size--;
		for (int i = 0; i < this->size; i++)
			pom[i] = this->arr[i + 1];

		delete[] this->arr;
		this->arr = pom;

	cout << "Zrobione!" << endl;
	cin.get();
	cin.get();
	system("cls");
}

void Array::subbEnd()
{
	int *pom = new int[this->size - 1];
	this->size--;
	for (int i = 0; i < this->size; i++)
		pom[i] = this->arr[i];
	delete[] this->arr;
	this->arr = pom;
	cout << "Zrobione!" << endl;
	cin.get();
	cin.get();
	system("cls");
}

void Array::subbGiv(int index)
{
	int counter = 0;
	if (this->size == 1)
	{
		char litera;
		do {
			if (counter > 0) cout << "Wprowadzono niepoprawna litere, prosze wprowadzic poprawna!" << endl;
			cout << "Tablica ma jeden element, a wiec mozesz usunac tylko jego." << endl
				<< "Czy chcesz to zrobic? t/n" << endl;
			cin >> litera;
			counter++;
			system("cls");
		} while (litera != 't' && litera != 'T' && litera != 'n' && litera != 'N');
		if (litera == 't' || litera == 'T') {
			int *pom = new int;
			delete[] this->arr;
			this->arr = pom;
			this->size = 0;
			cout << "Zrobione!" << endl;
		}
		cin.get();
		cin.get();
	}
	else {
		int *pom = new int[this->size - 1];
		this->size--;
		for (int i = 0, j = 0; i < this->size; i++, j++) {
			if (i == index) j++;
			pom[i] = this->arr[j];
		}
		delete[] this->arr;
		this->arr = pom;
		cout << "Zrobione!" << endl;
		cin.get();
		cin.get();
	}
	system("cls");
}

void Array::subb()
{
	int index;
	int number;
	int counter = 0;
	cout << "Z ktorego miejsca chcialbys usunac element?" << endl
		<< "[1] - na poczatku tablicy" << endl
		<< "[2] - na koncu tablicy" << endl
		<< "[3] - we wskazanym miejscu w tablicy" << endl;
	do {
		if (counter > 0) cout << "Podano liczbe z poza zakresu! Prosze o podanie poprawnej." << endl;
		cin >> number;
		if (cin.fail())
		{
			do {
				system("cls");
				cout << "Niepoprawny format wprowadzonej danej. Wprowadz nowa." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> number;
			} while (cin.fail());
		}
		counter++;
		system("cls");
	} while (number < 1 || number > 3);
	switch (number)
	{
	case 1:
		if (this->size == 1)
		{
			int *pom = new int;
			delete[] this->arr;
			this->arr = pom;
			this->size = 0;
		}
		else
			subbBeg();
		break;
	case 2:
		if (this->size == 1)
		{
			int *pom = new int;
			delete[] this->arr;
			this->arr = pom;
			this->size = 0;
		}
		else
			subbEnd();
		break;
	case 3:
		counter = 0;
		do {
			if (counter > 0) cout << "Podano liczbe z poza zakresu!" << endl
				<< "Prosze o podanie poprawnej." << endl;
			cout << "Podaj indeks z zakresu: <0," << this->size - 1 << ">, z ktorego chcialbys usunac dane: " << endl;
			cin >> index;
			if (cin.fail())
			{
				do {
					cout << "Niepoprawny format wprowadzonej danej. Wprowadz nowa." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> index;
				} while (cin.fail());
			}
			counter++;
			system("cls");
		} while (index < 0 || index > this->size - 1);
		subbGiv(index);
		break;
	default:
		break;
	}
}

void Array::find(int val)
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

void Array::clearArr()
{
	if(this->size > 0)
	{
		delete[] this->arr;
		this->arr = nullptr;
		this->size = 0;
	}
	else
		return;
}

Array::Array()
{

}

Array::~Array()
{
	clearArr();
}
