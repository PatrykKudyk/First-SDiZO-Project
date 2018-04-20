#pragma once
class List
{
	int data;
	int size;
	List *next, *prev;
	List *head, *tail;
public:
	void push(int data);
	void readFile();
	void add();
	void addBeg(int val);
	void addEnd(int val);
	void addGiv(int val, int index);
	void subbBeg();
	void subbEnd();
	void subbGiv(int index);
	void subb();
	void find(int val);
	void display(List* head, List* tail);
	void menu();
	void clearList();
	List();
	~List();
};