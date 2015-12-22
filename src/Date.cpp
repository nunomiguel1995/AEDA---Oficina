#include "Date.h"

Date::Date(int a, int m, int d, int h, int min) : ano(a),mes(m),dia(d),hora(h),minutos(min){}

<<<<<<< HEAD
}
void Date::print(){
	cout << ano << "/" << mes << "/" << dia << " - " << hora << ":" << minutos << endl;

=======
Date::Date(){}

void Date::print(){
	cout << ano << " / " << mes << " / " << dia << " - " << hora << " : " << minutos << endl;
>>>>>>> 43f711f759709609df12b97f64e2fb90762f02a6
}

bool Date::operator <(const Date &d1){
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

bool operator==(const Date d1, const Date d2){
	return (d1.getAno() == d2.getAno()) && (d1.getMes() == d2.getMes()) && (d1.getDia() == d2.getDia()) && (d1.getHora() == d2.getHora()) && (d1.getMinutos() == d2.getMinutos());
}
