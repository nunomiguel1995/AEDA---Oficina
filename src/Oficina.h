#ifndef SRC_OFICINA_H_
#define SRC_OFICINA_H_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Excepcoes.h"
#include "Funcionario.h"
#include "Veiculo.h"
#include "Cliente.h"
#include "insertionSort.h"
#include "Servico.h"
#include "BST.h"
#include <stdlib.h>
#include <time.h>
#include <typeinfo>
#include <tr1/unordered_set>
#include <queue>
#include <math.h>

#include "Date.h"

using namespace std;

typedef tr1::unordered_set<Cliente> tabHInativos;
typedef priority_queue<Cliente> FilaPrioridade;

struct eq {
	bool operator() (const Cliente &c1, const Cliente &c2) const {
		return (c1.getId() == c2.getId());
	}
};

struct h {
	int operator() (const Cliente &c1) const {
		string s1 = c1.getNome();
		int v = 0;
		for ( unsigned int i = 0; i < s1.size(); i++){
			v = 37*v + s1[i];
		}
		return v;
	}
};

class Oficina{
	string nome;
	vector<Funcionario> funcionarios;
	vector<Veiculo *> veiculos;
	vector<Cliente> clientes;
	vector <Standard *> servicosStandard;
	FilaPrioridade maisPontos;
	tabHInativos inativos;
public:
	Oficina(string nome);
	~Oficina();

	string getNome() const;
	vector<Funcionario> getFuncionarios() const;
	Funcionario getFuncionarioNome(string nome) const;
	Cliente getClienteNome(string nome) const;
	tabHInativos getInativos() const {return inativos;};

	void setFuncionarios(vector<Funcionario> func);
	void setClientes(vector<Cliente> clnts);
	void setVeiculos(vector <Veiculo *> veic);
	void setServicosStandard(vector <Standard *> stand);

	vector<Veiculo *> getVeiculos() const;
	Veiculo * getVeiculoMatricula(string mt) const;
	vector<Funcionario> getFuncionariosVeiculo(Veiculo *v) const;
	vector<Cliente> getClientes() const;
	vector <Standard *> getServicosStandard() const;

	void addFuncionario(Funcionario & f);
	void addCliente(Cliente & c);
	void addVeiculo(Veiculo *&v);
	void addVeiculoCliente(Veiculo *&v,string nome);
	void addVeiculoFuncionario(Veiculo *&v, string nome);
	void addServicoStandard(Standard *s);
	void addClienteInativo(Cliente & c1, Date &d1);
	void addServico(Cliente &c, Veiculo *v, Servico*s, Date &d);

	void removeFuncionario(Funcionario &f);
	void removeCliente(Cliente &c);
	void removeVeiculo(Veiculo *&v);
	void removeVeiculoFuncionario(Veiculo *&v, string nome);
	void removeVeiculoCliente(Veiculo *&v, string nome);
	void removeServicoStandard(Standard *s);
	void removeClienteInativo(Cliente &c);

	void displayFuncionarios() const;
	void displayVeiculos() const;
	void displayClientes() const;
	void displayServicosStandard();
	void displayClientesInativos();

	Servico* createServico(string tipo, string nome, float preco, int duracao, Date date);
	Veiculo* createVeiculo(string tipo, string marca, string matricula, int ano);

	void criaServicoVeiculo();
	void criaVeiculoCliente();
	void criaVeiculoFuncionario();
	void criaFuncionario();
	void criaCliente();

	bool guardaFuncionarios();
	bool guardaVeiculos();
	bool guardaClientes();
	bool guardaServicos();
	bool leFuncionarios();
	bool leVeiculos();
	bool leClientes();
	bool leServicos();
	int getNumInativos();

	void ordenaFuncionarios();
	void ordenaVeiculos();
	void ordenaClientes();

	int posVeiculo(string mt);
	int isStandard(string nome);

	void HappyHour();
	void AtualizaPontos(Date d);
};


#endif /* SRC_OFICINA_H_ */
