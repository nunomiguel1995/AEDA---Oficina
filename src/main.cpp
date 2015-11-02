#include <iostream>
#include "Veiculo.h"
#include "Funcionario.h"
#include "Oficina.h"
#include "Cliente.h"
#include "Excepcoes.h"

using namespace std;

int main(){
	Oficina oficina("Oficina");

	Veiculo *v1 = new Motorizada("Honda","11-22-AA");
	Veiculo *v2 = new Camiao("Mercedes","11-22-AA");
	Veiculo *v3 = new Autocarro("Opel","11-22-BB");
	Veiculo *v4 = new Automovel("Ford","11-22-CC");
	Veiculo *v5 = new Camiao("Fiat","11-22-DD");

	oficina.addVeiculo(v1);
	oficina.addVeiculo(v3);
	oficina.addVeiculo(v4);

	try{
		oficina.addVeiculo(v2);
	}catch(VeiculoExistente &e){
		cout << "Veiculo com a matricula " << e.getMatricula() << " já existe.\n";
	}

	oficina.removeVeiculo(v4);

	try{
		oficina.removeVeiculo(v5);
	}catch(VeiculoInexistente &e){
		cout << "Veiculo com a matricula " << e.getMatricula() << " não existe.\n";
	}

	vector<Veiculo *> veiculos = oficina.getVeiculos();

	for(unsigned int i = 0; i < veiculos.size(); i++){
		cout << "Veiculo: " << veiculos[i]->getMarca() << " ; " << veiculos[i]->getMatricula() << endl;
	}

	Funcionario f1("Joao Pires");
	Funcionario f2("Joao Silva");
	Funcionario f3("Joao Silva");

	oficina.addFuncionario(f1);
	oficina.addFuncionario(f2);

	try{
		oficina.addFuncionario(f3);
	}catch(FuncionarioExistente &e){
		cout << "Funcionario com o nome " << e.getNome() << " já existe.\n";
	}

	vector<Funcionario> funcionarios = oficina.getFuncionarios();

	for(unsigned int i = 0; i < funcionarios.size(); i++){
		cout << "Nome do funcionario: " << funcionarios[i].getNome() << endl;
	}

	Cliente c1("Jorge Sousa");
	Cliente c2("Jorge Silva");
	Cliente c3("Jorge Silva");

	oficina.addCliente(c1);
	oficina.addCliente(c2);

	try{
		oficina.addCliente(c3);
	}catch(ClienteExistente &e){
		cout << "Cliente com o nome " << e.getNome() << " já existe.\n";
	}

	vector<Cliente> clientes = oficina.getClientes();

	for(unsigned int i = 0; i < clientes.size(); i++){
		cout << "Nome do cliente: " << clientes[i].getNome() << endl;
	}

	return 0;
}

