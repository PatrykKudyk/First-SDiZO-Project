#pragma once

class Array
{
	int *arr;
	int size;
public:
	void menu();
	void readFile();
	void display();
	void push(int data);
	void addEnd(int val);
	void add();
	void addBeg(int val);
	void addGiv(int val, int index);
	void subbBeg();
	void subbEnd();
	void subbGiv(int index);
	void subb();
	void find(int val);
	void clearArr();
	Array();
	~Array();
};
