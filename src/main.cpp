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
	Funcionario f1("Joao Pires");
	Funcionario f2("Joao Silva");
	Funcionario f3("Joao Silva");
	Cliente c1("Jorge Sousa");
	Cliente c2("Jorge Silva");
	Cliente c3("Jorge Silva");
	Cliente c4("João Pedro");

	oficina.addVeiculo(v1);
	oficina.addVeiculo(v3);
	oficina.addVeiculo(v4);
	try{
		oficina.addVeiculo(v2);
	}catch(VeiculoExistente &e){
		cout << "Veiculo com a matricula " << e.getMatricula() << " já existe.\n";
	}
	oficina.guardaVeiculos();

	//f1.addVeiculo(v1);
	//f1.addVeiculo(v3);
	//f2.addVeiculo(v4);
	//try{
	//	oficina.addFuncionario(f1);
	//	oficina.addFuncionario(f2);
	//	oficina.addFuncionario(f3);
	//}catch(FuncionarioExistente &e){
	//	cout << e.getNome() << " já existe" << endl;
	//}

	//oficina.guardaFuncionarios();

	oficina.leClientes();
	vector<Cliente> func = oficina.getClientes();
	for(unsigned int i = 0; i < func.size(); i++){

	}

	return 0;
}

