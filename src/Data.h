#ifndef SRC_DATA_H_
#define SRC_DATA_H_

#include <iostream>

using namespace std;

class Date{
	int ano;
	int mes;
	int dia;
	int hora;
	int minutos;
public:
	Date(int dia, int mes, int ano);
	bool &operator < (Date d1);
};

#endif
