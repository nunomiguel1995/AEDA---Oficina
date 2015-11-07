#include <iostream>
#include "Veiculo.h"
#include "Funcionario.h"
#include "Oficina.h"
#include "Cliente.h"
#include "Excepcoes.h"

using namespace std;

int main(){
	Oficina oficina("Oficina");

	Veiculo *v1 = new Motorizada("Honda","11-22-AA",2009);
	Veiculo *v2 = new Camiao("Mercedes","11-22-AA",2008);
	Veiculo *v3 = new Autocarro("Opel","11-22-BB",2009);
	Veiculo *v4 = new Automovel("Ford","11-22-CC",2007);
	Veiculo *v5 = new Camiao("Fiat","11-22-DD",2006);
	Funcionario f1("Joao Pires");
	Funcionario f2("Joao Silva");
	Funcionario f3("Joao Silva");
	Funcionario f4("Rey Mysterio");
	Cliente c1("Jorge Sousa");
	Cliente c2("Jorge Silva");
	Cliente c3("Jorge Silva");
	Cliente c4("João Pedro");

	/**
	 *
	 */
	oficina.addVeiculo(v1);
	oficina.addVeiculo(v3);
	oficina.addVeiculo(v4);
	try{
		oficina.addVeiculo(v2);
	}catch(VeiculoExistente &e){
		cout << "Veiculo com a matricula " << e.getMatricula() << " já existe.\n";
	}
	oficina.guardaVeiculos();

	/**
	 *
	 */
	oficina.addFuncionario(f1);
	oficina.addFuncionario(f2);
	try{
		oficina.addFuncionario(f3);
	}catch(FuncionarioExistente &e){
		cout << "Funcionario com o nome " << e.getNome() << " já existe.\n";
	}

	oficina.addCliente(c1);
	oficina.addCliente(c2);
	try{
		oficina.addCliente(c3);
	}catch(ClienteExistente &e){
		cout << "Cliente com o nome " << e.getNome() << " já existe.\n";
	}
	oficina.guardaClientes();


	vector<Funcionario> func = oficina.getFuncionarios();
	func[0].addVeiculo(v1); //joão pires
	func[0].addVeiculo(v3); //joão pires
	func[1].addVeiculo(v4); //o outro
	try{
		func[0].addVeiculo(v3);
	}catch(VeiculoExistente &e){
		cout << "Veiculo com a matricula " << e.getMatricula() << " já existe na lista de veiculos do funcionário.\n";
	}
	oficina.setFuncionarios(func);
	oficina.guardaFuncionarios();

	vector<Cliente> client = oficina.getClientes();
	client[0].addVeiculo(v1);
	client[0].addVeiculo(v3);
	client[1].addVeiculo(v4);
	oficina.setClientes(client);
	oficina.guardaClientes();

	return 0;
}

