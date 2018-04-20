#pragma once
#include "Array.h"
#include "List.h"
#include "Heap.h"

class Menu
{
	Array arr;
	List list;
	Heap heap;
public:
	Menu();
	~Menu();
	void menu(Menu menu);
};
