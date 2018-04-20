#include <iostream>
#include "Menu.h"
#include "TimeMeasure.h"


using namespace std;

int main()
{
	
	Menu menu;
	menu.menu(menu);
	cin.get();
	cin.get();
	exit(EXIT_SUCCESS);
}