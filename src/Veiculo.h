#ifndef SRC_VEICULO_H_
#define SRC_VEICULO_H_

#include <string>
#include <iostream>
#include <vector>
#include "Servico.h"

using namespace std;

class Veiculo{
	string marca;
	string matricula;
	int ano;
public:
	Veiculo (string marca, string matricula, int ano);
	~Veiculo();
	string getMarca() const;
	string getMatricula() const;
	int getAno() const;
<<<<<<< HEAD
=======
	friend bool operator <(const Veiculo v1, const Veiculo v2);
<<<<<<< HEAD
	void displayVeiculo() const;
=======
>>>>>>> 3ce1fbd9676c55264a36a4eeb11577adc8e4de51
>>>>>>> 2d389e19e7452db7db8dac5548cd0afb1db4c896
};

class Motorizada: public Veiculo{
	vector<Servico> servicos;
public:
	Motorizada(string marca, string matricula, int ano);
	~Motorizada();
	vector<Servico> getServicos() const;
	void addServico(const Servico & s);
};

class Camiao: public Veiculo{
	vector<Servico> servicos;
public:
	Camiao(string marca, string matricula, int ano);
	~Camiao();
	vector<Servico> getServicos() const;
	void addServico(const Servico & s);
};

class Autocarro: public Veiculo{
	vector<Servico> servicos;
public:
	Autocarro(string marca, string matricula, int ano);
	~Autocarro();
	vector<Servico> getServicos() const;
	void addServico(const Servico & s);
};

class Automovel: public Veiculo{
	vector<Servico> servicos;
public:
	Automovel(string marca, string matricula, int anoS);
	~Automovel();
	vector<Servico> getServicos() const;
	void addServico(const Servico & s);
};

#endif /* SRC_VEICULO_H_ */
