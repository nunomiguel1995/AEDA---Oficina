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
	oficina.displayVeiculos();

	/**
	 *
	 */
	oficina.removeVeiculo(v4);
	try{
		oficina.removeVeiculo(v5);
	}catch(VeiculoInexistente &e){
		cout << "Veiculo com a matricula " << e.getMatricula() << " não existe.\n";
	}
	oficina.displayVeiculos();

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
	oficina.displayFuncionarios();

	/**
	 *
	 */
	oficina.addCliente(c1);
	oficina.addCliente(c2);
	try{
		oficina.addCliente(c3);
	}catch(ClienteExistente &e){
		cout << "Cliente com o nome " << e.getNome() << " já existe.\n";
	}
	oficina.displayClientes();

	/**
	 *
	 */
	oficina.removeCliente(c1);
	try{
		oficina.removeCliente(c4);
	}catch(ClienteInexistente &e){
		cout << "Cliente com o nome " << e.getNome() << " não existe.\n";
	}
	oficina.displayClientes();

	/**
	 *
	 */
	f1.addVeiculo(v1);
	f1.addVeiculo(v3);
	try{
		f1.addVeiculo(v2);
	}catch(VeiculoExistente &e){
		cout << "Veiculo com a matricula " << e.getMatricula() << " já existe na lista de veiculos do funcionário.\n";
	}
	f1.displayVeiculos();

	/**
	 *
	 */
	f1.removeVeiculo(v1);
	try{
		f1.removeVeiculo(v1);
	}catch(VeiculoInexistente &e){
		cout << "Veiculo com a matricula " << e.getMatricula() << " não existe na lista de veiculos do funcionário.\n";
	}
	f1.displayVeiculos();

	oficina.guardaFuncionarios();

	return 0;
}

