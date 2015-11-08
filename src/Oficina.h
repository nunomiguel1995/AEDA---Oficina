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
	vector <Standard> servicosStandard;

public:
	Oficina(string nome);
	~Oficina();

	string getNome() const;
	vector<Funcionario> getFuncionarios() const;
	Funcionario getFuncionarioNome(string nome) const;
	Cliente getClienteNome(string nome) const;

	void setFuncionarios(vector<Funcionario> func);
	void setClientes(vector<Cliente> clnts);
	void setVeiculos(vector <Veiculo *> veic);
	//void setServicosStandard(vector <Standard> stand);

	vector<Veiculo *> getVeiculos() const;
	Veiculo * getVeiculoMatricula(string mt) const;
	vector<Funcionario> getFuncionariosVeiculo(Veiculo *v) const;
	vector<Cliente> getClientes() const;
	vector<Servico *> getServicos() const;
	//vector <Standard> getServicosStandard() const;

	void addFuncionario(Funcionario & f);
	void addCliente(Cliente & c);
	void addVeiculo(Veiculo *&v);
	void addVeiculoCliente(Veiculo *&v,string nome);
	void addVeiculoFuncionario(Veiculo *&v, string nome);
	//void addServicoStandard(Standard *s);

	void removeFuncionario(Funcionario &f);
	void removeCliente(Cliente &c);
	void removeVeiculo(Veiculo *&v);
	void removeVeiculoFuncionario(Veiculo *&v, string nome);
	void removeVeiculoCliente(Veiculo *&v, string nome);
	//void removeServicoStandard(Standard *s);

	void displayFuncionarios() const;
	void displayVeiculos() const;
	void displayClientes() const;
	//void displayServicosStandard() const;

	bool guardaFuncionarios();
	bool guardaVeiculos();
	bool guardaClientes();
	bool guardaServicos();
	bool leFuncionarios();
	bool leVeiculos();
	bool leClientes();
	bool leServicos();

	void ordenaFuncionarios();
	void ordenaVeiculos();
	void ordenaClientes();

	int posVeiculo(string mt);
};


#endif /* SRC_OFICINA_H_ */
