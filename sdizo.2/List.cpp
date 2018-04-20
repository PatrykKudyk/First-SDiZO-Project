#include "List.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

void List::push(int data)
{
	List *p = new List;
	p->next = nullptr;
	p->data = data;

	if (tail) {
		p->prev = this->tail;
		p->prev->next = p;
	}
	else
	{
		this->head = p;
	}
	this->tail = p;
	this->size++;
}

void List::readFile()
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


	while (file.eof() == NULL)
	{
		getline(file, bufor);
		istringstream iss(bufor);
		iss >> temp;
		this->push(temp);
	}
}

void List::add()
{
	int toAdd, index;
	int number;
	int counter = 0;
	cout << "W ktorym miejscu chcialbys dodac element?" << endl
		<< "[1] - na poczatku listy" << endl
		<< "[2] - na koncu listy" << endl
		<< "[3] - we wskazanym miejscu w liscie" << endl;
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
		if (this->head == nullptr) {
			push(toAdd);
			cout << "Zrobione!" << endl;
			cin.get();
			cin.get();
		}
		else
			this->addBeg(toAdd);
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
		if (this->head == nullptr) {
			push(toAdd);
			cout << "Zrobione!" << endl;
			cin.get();
			cin.get();
		}
		else
			this->addEnd(toAdd);
		break;
	case 3:
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
		counter = 0;
		if (head == nullptr)
		{

			char litera;
			do {
				if (counter > 0) cout << "Wprowadzono niepoprawna litere, prosze wprowadzic poprawna!" << endl;
				cout << "Lista jest pusta, a wiec mozesz dodac element tylko na poczatek listy." << endl
					<< "Czy chcesz to zrobic? t/n" << endl;
				cin >> litera;
				counter++;
				system("cls");
			} while (litera != 't' && litera != 'T' && litera != 'n' && litera != 'N');
			if (litera == 't' || litera == 'T') {

				push(toAdd);
				cout << "Zrobione!" << endl;
				cin.get();
				cin.get();
			}
		}
		else
		{
			do {
				if (counter > 0) cout << "Podano liczbe z poza zakresu!" << endl
					<< "Prosze o podanie poprawnej." << endl;
				cout << "Podaj indeks z zakresu: <0," << this->size - 1 << ">, w ktory chcialbys wstawic swoja dana: " << endl;
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
			this->addGiv(toAdd, index);
		}
		break;
	default:
		break;
	}
}

void List::addBeg(int val)
{
	List *p = new List;
	p->next = this->head;
	p->data = val;
	p->prev = nullptr;
	this->head = p;
	p->next->prev = p;
	this->size = this->size + 1;

	cout << "Zrobione!" << endl;
	cin.get();
	cin.get();
	system("cls");
}

void List::addEnd(int val)
{
	List *p = new List;
	p->next = nullptr;
	p->data = val;
	p->prev = this->tail;
	p->prev->next = p;
	this->tail = p;
	this->size = this->size + 1;
	cout << "Zrobione!" << endl;
	cin.get();
	cin.get();
	system("cls");
}

void List::addGiv(int val, int index)
{
	if (index == 0) addBeg(val);
	else if (index == (this->size - 1)) addEnd(val);
	else if (index <= this->size / 2)
	{
		List *p;
		List *temp = new List;
		p = this->head;
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		p->next->prev = temp;
		temp->next = p->next;
		p->next = temp;
		temp->prev = p;
		temp->data = val;
		this->size++;
		cout << "Zrobione!" << endl;
	}
	else
	{
		List *p;
		List *temp = new List;
		p = this->tail;
		for (int i = (this->size - 1); i > index + 1; i--)
			p = p->prev;
		p->prev->next = temp;
		temp->prev = p->prev;
		p->prev = temp;
		temp->next = p;
		temp->data = val;
		this->size++;
		cout << "Zrobione!" << endl;
	}
	cin.get();
	cin.get();
	system("cls");
}

void List::subbBeg()
{
	if (this->head != NULL)
	{
		List *p;
		p = this->head;
		if (this->head != this->tail)
		{
			(this->head->next)->prev = NULL;
			p = this->head;
			this->head = this->head->next;
			delete p;
		}
		else
		{
			delete this->head;
			this->head = this->tail = NULL;
		}
		this->size = this->size - 1;
		cout << "Zrobione!" << endl;
	}
	else cout << "Lista jest pusta. Nie ma co usuwac." << endl;
	cin.get();
	cin.get();
	system("cls");
}

void List::subbEnd()
{
	if (this->tail != NULL)
	{
		List *p;
		p = this->tail;
		if (this->head != this->tail)
		{
			(this->tail->prev)->next = NULL;
			p = this->tail;
			this->tail = this->tail->prev;
			delete p;
		}
		else
		{
			delete this->tail;
			this->tail = this->head = NULL;
		}
		this->size = this->size - 1;
		cout << "Zrobione!" << endl;
	}
	else cout << "Lista jest pusta. Nie ma co usuwac." << endl;
	cin.get();
	cin.get();
	system("cls");
}

void List::subbGiv(int index)
{
	List *p;
	if (this->head == nullptr)
	{
		cout << "Lista jest pusta. Nie ma co usuwac." << endl;
		cin.get();
		cin.get();
	}
	else {
		if (index == 0) subbBeg();
		else if (index == (this->size - 1)) subbEnd();
		else if (index <= this->size / 2)
		{
			p = this->head;
			for (int i = 0; i < index; i++)
				p = p->next;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			this->size = this->size - 1;
			cout << "Zrobione!" << endl;
			cin.get();
			cin.get();
		}
		else
		{
			p = this->tail;
			for (int i = (this->size - 1); i > index; i--)
				p = p->prev;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
			this->size = this->size - 1;
			cout << "Zrobione!" << endl;
			cin.get();
			cin.get();
		}
	}
	system("cls");
}

void List::subb()
{
	int number, index;
	int counter = 0;
	cout << "Z ktorego miejsca chcialbys usunac element?" << endl
		<< "[1] - z poczatku listy" << endl
		<< "[2] - z konca listy" << endl
		<< "[3] - ze wskazanego miejsca w liscie" << endl;
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
		this->subbBeg();
		break;
	case 2:
		this->subbEnd();
		break;
	case 3:
		counter = 0;
		do {
			if (counter > 0) cout << "Podano liczbe z poza zakresu!" << endl
				<< "Prosze o podanie poprawnej." << endl;
			cout << "Podaj indeks z zakresu: <0," << this->size - 1 << ">, w ktory chcialbys wstawic swoja dana: " << endl;
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
		this->subbGiv(index);
		break;
	default:
		break;
	}
}

void List::find(int value)
{
	if (this->head == nullptr)
		cout << "Lista jest pusta. Na pewno nie ma tu szukanego przez Ciebie obiektu." << endl;
	else {
		List * h = this->head;
		List * t = this->tail;
		for (int i = 0; i <= this->size / 2; i++)
		{
			if (h->data == value) {
				cout << "Znalazlem zadana liczbe! (" << value << ")" << endl
					<< "Znajduje sie ona pod indeksem : " << i << " z zakresu <0," << this->size - 1 << ">" << endl;
				break;
			}
			if (t->data == value)
			{
				cout << "Znalazlem zadana liczbe! (" << value << ")" << endl
					<< "Znajduje sie ona pod indeksem : " << (this->size - 1 - i) << " z zakresu <0," << this->size - 1 << ">" << endl;
				break;
			}
			if (i == this->size / 2)
				cout << "Niestety, ale nie udalo sie znalezc zadanej przez Ciebie liczby. (" << value << ")" << endl;
			h = h->next;
			t = t->prev;
		}
	}
	cin.get();
	cin.get();
	system("cls");
}

void List::display(List* head, List* tail)
{
	int choise, i = 0, k = 0;
	List* p;
	do {
		if (i > 0) cout << "Podana przez ciebie liczba wykracza poza dopuszczalny zakres." << endl
			<< "Podaj nowa, ktora jest poprawna" << endl;
		cout << "Od ktorej strony chcialbys wyswietlic liste?" << endl
			<< "[1] - od poczatku (head)" << endl
			<< "[2] - od tylu (tail)" << endl;
		cin >> choise;
		if (cin.fail())
		{
			do {
				cout << "Niepoprawny format wprowadzonej danej. Wprowadz nowa." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> choise;
			} while (cin.fail());
		}
		i++;
		system("cls");
	} while (choise < 1 || choise > 2);
	switch (choise)
	{
	case 1:
		if (head != nullptr) {
			p = head;
			while (p != tail) {
				cout << p->data << "\t";
				p = p->next;
				k++;
				if (k == 5)
				{
					cout << endl;
					k = 0;
				}
			}
			cout << tail->data << endl;
			cout << endl;
		}
		else cout << "Lista jest pusta. Nie ma co wyswietlic" << endl;
		cin.get();
		cin.get();
		break;
	case 2:
		if (tail != nullptr) {
			p = tail;
			while (p != head) {
				cout << p->data << "\t";
				p = p->prev;
				k++;
				if (k == 5)
				{
					cout << endl;
					k = 0;
				}
			}
			cout << head->data << endl;
			cout << endl;
		}
		else cout << "Lista jest pusta. Nie ma co wyswietlic" << endl;
		cin.get();
		cin.get();
		break;
	default:
		break;
	}
}

void List::menu()
{
	int toAdd, counter = 0;
	int temp, size = 0;
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
				<< "[5] - Zakonczyc dzialania na listach" << endl;
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
				this->subb();
			break;
		case 3:
			counter = 0;
			if (this->size == 0) 
			{
				cout << "Tablica jest pusta. Nie mozna wyszukac zadnego elementu." << endl;
				cin.get();
				cin.get();
			}
			else
			{
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
			break;
		case 4:
			this->display(this->head, this->tail);
			break;
		case 5:
			running = false;
			break;
		default:
			break;
		}
	} while (running);

	this->clearList();
}

void List::clearList()
{
	List *p = head;

	while (p)
	{
		List *next = p->next;
		free(p);
		p = next;
	}
	size = 0;
	head = tail = NULL;
}

List::List()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

List::~List()
{
	clearList();
}
