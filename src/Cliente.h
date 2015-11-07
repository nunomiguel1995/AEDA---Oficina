#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include <string>
#include <iostream>
#include <vector>
#include "Veiculo.h"
#include "Excepcoes.h"

using namespace std;

class Cliente{
	string nome;
	int id;
	vector<Veiculo *> veiculos;
public:
	Cliente(string nome);
	string getNome() const;
	int getId() const;
	void setId(unsigned int id);
	vector <Veiculo*> getVeiculos() const;
	void addVeiculo(Veiculo *v1);
	void removeVeiculo (Veiculo *v1);
};

#endif /* SRC_CLIENTE_H_ */
