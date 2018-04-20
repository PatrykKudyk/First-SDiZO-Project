#pragma once
#include <string>

class Heap
{
	int size;
	int *arr;
	std::string cr, cl, cp;
public:
	void menu();
	void readFile();
	void push(int val);
	void pop();
	void display(std::string sp, std::string sn, int v);
	void find(int val);
	void clearHeap();
	Heap();
	~Heap();
};

