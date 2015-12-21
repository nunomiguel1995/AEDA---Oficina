#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include <string>
#include <iostream>
#include <vector>
#include "Veiculo.h"
#include "Excepcoes.h"
#include "Date.h"

using namespace std;

class Cliente{
	string nome;
	int id;
	vector<Veiculo *> veiculos;
	string email;
	int telef;
	string morada;

public:
	Cliente(string nome);
	string getNome() const;
	int getId() const;
	string getEmail() const {return email;};
	int getTelef() const {return telef;};
	string getMorada() const {return morada;};
	void setId(unsigned int id);
	void setVeiculos(vector<Veiculo*> veiculos);
	void setNome(string nome);
	Veiculo * getVeiculoMatricula(string mt) const;
	vector <Veiculo*> getVeiculos() const;
	void addVeiculo(Veiculo *v1);
	void removeVeiculo (Veiculo *v1);
	friend bool operator <(const Cliente c1, const Cliente c2);
	void displayCliente() const;
	bool isInativo(Date &d1);
};

#endif /* SRC_CLIENTE_H_ */
