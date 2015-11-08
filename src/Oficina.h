#ifndef SRC_OFICINA_H_
#define SRC_OFICINA_H_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Excepcoes.h"
#include "Funcionario.h"
#include "Veiculo.h"
#include "Cliente.h"
#include "insertionSort.h"
#include <typeinfo>


using namespace std;

class Oficina{
	string nome;
	vector<Funcionario> funcionarios;
	vector<Veiculo *> veiculos;
	vector<Cliente> clientes;

public:
	Oficina(string nome);
	~Oficina();
	string getNome() const;
	vector<Funcionario> getFuncionarios() const;
	Funcionario getFuncionarioNome(string nome) const;
	Cliente getClienteNome(string nome) const;
	void setFuncionarios(vector<Funcionario> func);
	void setClientes(vector<Cliente> clnts);
	vector<Veiculo *> getVeiculos() const;
	Veiculo * getVeiculoMatricula(string mt) const;
	vector<Cliente> getClientes() const;
	vector<Servico *> getServicos() const;
	void addFuncionario(Funcionario & f);
	void addCliente(Cliente c);
	void addVeiculo(Veiculo *v);
	void addVeiculoCliente(Veiculo *v,string nome);
	void addVeiculoFuncionario(Veiculo *v, string nome);
	void removeFuncionario(Funcionario f);
	void removeCliente(Cliente c);
	void removeVeiculo(Veiculo *v);
	void removeVeiculoFuncionario(Veiculo *v, string nome);
	void removeVeiculoCliente(Veiculo *v, string nome);
	void displayFuncionarios() const;
	void displayVeiculos() const;
	void displayClientes() const;

	bool guardaFuncionarios();
	bool guardaVeiculos();
	bool guardaClientes();
	bool leFuncionarios();
	bool leVeiculos();
	bool leClientes();

	void ordenaFuncionarios();
	void ordenaVeiculos();
	void ordenaClientes();
};


#endif /* SRC_OFICINA_H_ */
