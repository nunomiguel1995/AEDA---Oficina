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
	Date(int a, int m, int d, int h, int min);
	Date();
	void print();
	bool operator < (const Date &d1);
	int getAno() const {return ano;};
	int getMes() const{return mes;};
	int getDia() const{return dia;};
	int getHora() const{return hora;};
	int getMinutos() const{return minutos;};
	void setAno(int a) {this->ano = a;};
	void setMes(int m){this->mes = m;};
	void setDia(int d){this->dia = d;};
	void setHora(int h){this->hora = h;};
	void setMinutos(int m){this->minutos = m;};
	bool operator ==(const Date &d);
};

#endif
