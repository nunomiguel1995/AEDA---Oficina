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
<<<<<<< HEAD
	Date(int dia, int mes, int ano, int hora, int minutos);
	void print();
	bool operator < (Date &d1);
=======
	Date(int a, int m, int d, int h, int min);
	Date();
	void print();
	bool operator < (const Date &d1);
>>>>>>> 43f711f759709609df12b97f64e2fb90762f02a6
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
	friend bool operator ==(const Date d1, const Date d2);
};

#endif
