#include "Date.h"

Date::Date(int dia, int mes, int ano, int hora, int minutos){
	this->dia=dia;
	this->mes=mes;
	this->ano=ano;
	this->hora=hora;
	this->minutos=minutos;

}

void printDate(){
	cout << endl;
}

bool Date:: operator < (Date &d1){

	if (ano < d1.ano) return true;
	if (ano > d1.ano) return false;
	else{
		if (mes < d1.mes) return true;
		if (mes > d1.mes) return false;
		else {
			if (dia < d1.dia) return true;
			if (dia > d1.dia) return false;
			else{
				if (hora < d1.hora) return true;
				if (hora > d1.hora) return false;
				else {
					if (minutos < d1.minutos) return true;
					if (minutos > d1.minutos) return false;
				}
			}
		}
	}
}
