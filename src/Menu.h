#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include <iostream>
#include "Oficina.h"

using namespace std;

class Menu{
public:
	void addMenu(Oficina &oficina);
	void removeMenu(Oficina &oficina);
	void displayMenu(Oficina &oficina);
	void modifyMenu(Oficina &oficina);
	void menu(Oficina &oficina);
};

#endif
