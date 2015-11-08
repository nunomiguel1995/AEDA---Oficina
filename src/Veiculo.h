#ifndef SRC_VEICULO_H_
#define SRC_VEICULO_H_

#include <string>
#include <iostream>
#include <vector>
#include "Servico.h"

using namespace std;

/**
 * Classe Veiculo- classe base
 */
class Veiculo{
	string marca;
	string matricula;
	int ano;
public:
	Veiculo (string marca, string matricula, int ano);
	virtual ~Veiculo();
	string getMarca() const;
	string getMatricula() const;
	int getAno() const;
	friend bool operator <(const Veiculo v1, const Veiculo v2);
	void displayVeiculo() const;
	virtual vector<Servico *> getServicos() const;
	virtual string classname() const;
	virtual void addServico(Servico *&s, bool control);
};

/**
 * Classe Motorizada- classe derivada
 */
class Motorizada: public Veiculo{
	vector<Servico *> servicos;
	static const float taxa=0.1;
public:
	Motorizada(string marca, string matricula, int ano);
	~Motorizada();
	vector<Servico *> getServicos() const;
	void addServico(Servico * &s, bool control);
	string classname() const;
};

/**
 * Classe Camião- classe derivada
 */
class Camiao: public Veiculo{
	vector<Servico *> servicos;
	static const float taxa=0.5;
public:
	Camiao(string marca, string matricula, int ano);
	~Camiao();
	vector<Servico *> getServicos() const;
	void addServico(Servico * & s, bool control);
	string classname() const;
};

/**
 * Classe Autocarro- classe derivada
 */
class Autocarro: public Veiculo{
	vector<Servico *> servicos;
	static const float taxa=0.45;
public:
	Autocarro(string marca, string matricula, int ano);
	~Autocarro();
	vector<Servico *> getServicos() const;
	void addServico(Servico * & s, bool control);
	string classname() const;
};

/**
 * Classe Automovel- classe derivada
 */
class Automovel: public Veiculo{
	vector<Servico *> servicos;
	static const float taxa=0.3;
public:
	Automovel(string marca, string matricula, int anoS);
	~Automovel();
	vector<Servico *> getServicos() const;
	void addServico(Servico * & s, bool control);
	string classname() const;
};

#endif /* SRC_VEICULO_H_ */
