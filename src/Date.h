#ifndef SRC_DATE_H_
#define SRC_DATE_H_

#include <iostream>


using namespace std;

class Date{
	int ano;
	int mes;
	int dia;
	int hora;
	int minutos;
public:
	Date(int dia, int mes, int ano, int hora, int minutos);
	bool operator < (Date &d1);
	int getAno() const {return ano;};
	int getMes() const{return mes;};
	int getDia() const{return dia;};
	int getHora() const{return hora;};
	int getMinutos() const{return minutos;};
};

#endif
