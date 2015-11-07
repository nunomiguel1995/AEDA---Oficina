#ifndef SRC_FUNCIONARIO_H_
#define SRC_FUNCIONARIO_H_

#include <string>
#include <iostream>
#include <vector>
#include "Veiculo.h"
#include "Excepcoes.h"

using namespace std;

class Funcionario {
	string nome;
	vector<Veiculo *> veiculos;
public:
	Funcionario(string n);
	vector <Veiculo *> getVeiculos() const;
	void addVeiculo(Veiculo * v1);
	void removeVeiculo(Veiculo *v1);
	string getNome() const;
	void displayVeiculos() const;
	friend bool operator<(const Funcionario f1, const Funcionario f2);
	void displayFuncionario() const;
};



#endif /* SRC_FUNCIONARIO_H_ */
