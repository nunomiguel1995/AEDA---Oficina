#ifndef SRC_OFICINA_H_
#define SRC_OFICINA_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Servico{
	string nome;
};

class Standard: public Servico{};

class Veiculo{
	string marca;
	string matricula;
public:
	Veiculo (string marca, string matricula);
	~Veiculo();
	string getMarca() const;
	string getMatricula() const;
};

class Motorizada: public Veiculo{
	vector<Servico> servicos;
public:
	Motorizada(string marca, string matricula);
	~Motorizada();
	vector<Servico> getServicos() const;
	void addServico(const Servico & s);
};

class Camiao: public Veiculo{
	vector<Servico> servicos;
public:
	Camiao(string marca, string matricula);
	~Camiao();
	vector<Servico> getServicos() const;
	void addServico(const Servico & s);
};

class Autocarro: public Veiculo{
	vector<Servico> servicos;
public:
	Autocarro(string marca, string matricula);
	~Autocarro();
	vector<Servico> getServicos() const;
	void addServico(const Servico & s);
};

class Automovel: public Veiculo{
	vector<Servico> servicos;
public:
	Automovel(string marca, string matricula);
	~Automovel();
	vector<Servico> getServicos() const;
	void addServico(const Servico & s);
};


class Cliente{
	string nome;
	int id;
	vector<Veiculo *> veiculos;
public:
	Cliente(string nome);
	string getNome() const;
	int getId() const;
	vector <Veiculo*> getVeiculos() const;
	void addVeiculo(Veiculo *v1);
	void removeVeiculo (Veiculo *v1);
};


class Funcionario {
	string nome;
	vector<Veiculo *> veiculos;

public:
	Funcionario(string n);
	vector <Veiculo *> getVeiculos() const;
	void addVeiculo(Veiculo *v1);
	void removeVeiculo(Veiculo *v1);
};

class Oficina{
	string nome;
	vector<Funcionario *> funcionarios;
	vector<Veiculo *> veiculos;
	vector<Cliente *> clientes;
	vector<Servico *> servicos;
public:
	Oficina(string nome);
	~Oficina();
	string getNome() const;
	vector<Funcionario *> getFuncionarios() const;
	vector<Veiculo *> getVeiculos() const;
	vector<Cliente *> getClientes() const;
	vector<Servico *> getServicos() const;
	void addFuncionario(const Funcionario & f);
	void addCliente(const Cliente & c);
	void addVeiculo(const Veiculo & v);
	void addServico(const Servico & s);
	void removeFuncionario(const Funcionario & f);
	void removeCliente(const Cliente & c);
	void removeVeiculo(const Veiculo & v);
	void removeServico(const Servico & s);
};

class VeiculoExistente{
			string matricula;
		public:
			VeiculoExistente(string mt){ matricula= mt;}
			string getMatricula() const{ return matricula;}
		};
		class VeiculoInexistente{
			string matricula;
		public:
			VeiculoInexistente(string mt){ matricula=mt;}
			string getMatricula() const{ return matricula;}
		};

#endif /* SRC_OFICINA_H_ */
