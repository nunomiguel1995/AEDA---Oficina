/*
 * Oficina.h
 *
 *  Created on: 27/10/2015
 *      Author: Inês
 */

#ifndef SRC_OFICINA_H_
#define SRC_OFICINA_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//oi kridos
class Cliente{
	string nome;
	int id;
	vector <Veiculo *> veiculos;

public:
	Cliente(string nome, int id);
	string getNome() const;
	int getId() const;
	vector <Veiculo*> getVeiculos() const;
	bool addVeiculo(Veiculo v1);
	bool removeVeiculo (Veiculo v1);

};

class Servico{
	string nome;
};

class Standard: public Servico{

};



class Veiculo{

	string marca;
	string matricula;

public:
	Veiculo (string marca, string matricula);
	string getMarca();
	string getMatricula;

};

class Automoveis: public Veiculo{
	vector <Servico> servicos;

public:
	Automoveis(string marca, string matricula);
	vector <Servico> getServicos();
	bool addServico(Servico s1);
	bool removeServico(Servico s1);

};

class Motorizadas: public Veiculo{
	vector <Servico> servicos;

public:
	Motorizadas(string marca, string matricula);
	vector <Servico> getServicos();
	bool addServico(Servico s1);
	bool removeServico(Servico s1);
};

class Camiao: public Veiculo{
	vector <Servico> servicos;

public:
	Camiao(string marca, string matricula);
	vector <Servico> getServicos();
	bool addServico(Servico s1);
	bool removeServico(Servico s1);
};

class Autocarro: public Veiculo{
	vector <Servico> servicos;

public:
	Autocarro(string marca, string matricula);
	vector <Servico> getServicos();
	bool addServico(Servico s1);
	bool removeServico(Servico s1);
};



class Funcionario {

};


class Oficina{};





#endif /* SRC_OFICINA_H_ */
