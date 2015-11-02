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
	Funcionario f4("Rey Mysterio");

	oficina.addFuncionario(f1);
	oficina.addFuncionario(f2);

	try{
		oficina.addFuncionario(f3);
	}catch(FuncionarioExistente &e){
		cout << "Funcionario com o nome " << e.getNome() << " já existe.\n";
	}

	oficina.removeFuncionario(f1);

	try{
		oficina.removeFuncionario(f4);
	}catch(FuncionarioInexistente &e){
		cout << "Funcionario com o nome " << e.getNome() << " não existe.\n";
	}

	vector<Funcionario> funcionarios = oficina.getFuncionarios();

	for(unsigned int i = 0; i < funcionarios.size(); i++){
		cout << "Nome do funcionario: " << funcionarios[i].getNome() << endl;
	}

	Cliente c1("Jorge Sousa");
	Cliente c2("Jorge Silva");
	Cliente c3("Jorge Silva");
	Cliente c4("João Pedro");

	oficina.addCliente(c1);
	oficina.addCliente(c2);

	try{
		oficina.addCliente(c3);
	}catch(ClienteExistente &e){
		cout << "Cliente com o nome " << e.getNome() << " já existe.\n";
	}

	oficina.removeCliente(c1);

	try{
		oficina.removeCliente(c4);
	}catch(ClienteInexistente &e){
		cout << "Cliente com o nome " << e.getNome() << " não existe.\n";
	}

	vector<Cliente> clientes = oficina.getClientes();

	for(unsigned int i = 0; i < clientes.size(); i++){
		cout << "Nome do cliente: " << clientes[i].getNome() << endl;
	}

	vector<Veiculo *> vecF1 = f1.getVeiculos();

	for(unsigned int i=0; i<vecF1.size();i++){
		cout << "Veiculo: " << f1.getVeiculos()[i]->getMarca() << " ; " << f1.getVeiculos()[i]->getMatricula() << endl;
	}

	f1.addVeiculo(v1);
	f1.addVeiculo(v3);

	try{
		f1.addVeiculo(v2);
	}catch(VeiculoExistente &e){
		cout << "Veiculo com a matricula " << e.getMatricula() << " já existe na lista de veiculos do funcionário.\n";
	}

	cout << "Veiculo(s) do funcionário " << f1.getNome() << ": \n";
	for(unsigned int i = 0; i < f1.getVeiculos().size(); i++){
		cout << f1.getVeiculos()[i]->getMarca() << " ; " << f1.getVeiculos()[i]->getMatricula() << endl;
	}

	f1.removeVeiculo(v1);

	try{
		f1.removeVeiculo(v1);
	}catch(VeiculoInexistente &e){
		cout << "Veiculo com a matricula " << e.getMatricula() << " não existe na lista de veiculos do funcionário.\n";
	}

	cout << "Veiculo(s) do funcionário " << f1.getNome() << ": \n";
	for(unsigned int i = 0; i < f1.getVeiculos().size(); i++){
		cout << f1.getVeiculos()[i]->getMarca() << " ; " << f1.getVeiculos()[i]->getMatricula() << endl;
	}

	return 0;
}

