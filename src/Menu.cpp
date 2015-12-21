#include "Oficina.h"

using namespace std;

void addMenu(Oficina &oficina){
	cout << "1 - Adicionar Funcionário" << endl; //
	cout <<	"2 - Adicionar Veiculo a Funcionário" << endl; //
	cout <<	"3 - Adicionar Cliente" << endl; //
	cout <<	"4 - Adicionar Veiculo a Cliente" << endl; //
	cout <<	"5 - Adicionar Serviço a Veículo" << endl;
	cout <<	"0 - Sair" << endl;

	int opcao;
	cin >> opcao;

	string nome;

	switch(opcao){
	case 0:
		break;
	case 1:
		oficina.criaFuncionario();
		oficina.guardaVeiculos();
		oficina.guardaClientes();
		oficina.guardaServicos();
		oficina.guardaFuncionarios();
		break;
	case 2:
		oficina.criaVeiculoFuncionario();
		oficina.guardaVeiculos();
		oficina.guardaClientes();
		oficina.guardaServicos();
		oficina.guardaFuncionarios();
		break;
	case 3:
		oficina.criaCliente();
		oficina.guardaVeiculos();
		oficina.guardaClientes();
		oficina.guardaServicos();
		oficina.guardaFuncionarios();
		break;
	case 4:
		oficina.criaVeiculoCliente();
		oficina.guardaVeiculos();
		oficina.guardaClientes();
		oficina.guardaServicos();
		oficina.guardaFuncionarios();
		break;
	case 5:
		oficina.criaServicoVeiculo();
		oficina.guardaVeiculos();
		oficina.guardaClientes();
		oficina.guardaServicos();
		oficina.guardaFuncionarios();
		break;
	default:
		cout << "Opção inválida. Insira outra vez." << endl;
		break;
	}
}

void menu(Oficina &oficina){
	cout << "1 - Funções de adicionar" << endl;
	cout <<	"2 - Funções de remover" << endl;
	cout <<	"3 - Funções de display" << endl;
	cout <<	"4 - Funções de modificar" << endl;
	cout <<	"0 - Sair" << endl;

	int opcao;
	cin >> opcao;

	switch(opcao){
	case 0:
		break;
	case 1:
		addMenu(oficina);
		break;
	case 2:
		//removeMenu();
		break;
	case 3:
		//displayMenu();
		break;
	case 4:
		//modifyMenu();
		break;
	default:
		cout << "Opção inválida. Insira outra vez." << endl;
		break;
	}
}



void showRemoveMenu(){
	cout << "1 - Remover Funcionário \n" <<
			"2 - Remover Veiculo de Funcionário \n" <<
			"3 - Remover Cliente \n" <<
			"4 - Remover Veiculo de Cliente \n" <<
			"0 - Sair \n";
}

void showDisplayMenu(){
	cout << "1 - Display Funcionários \n" <<
			"2 - Display Veículos do Funcionário \n" <<
			"3 - Display Clientes \n" <<
			"4 - Display Veículos do Cliente \n" <<
			"5 - Display de Serviços do Veículo \n" <<
			"0 - Sair \n";
}

void showModifyMenu(){
	cout<<  "1 - Modificar nome Cliente \n"<<
			"2 - Modificar nome Funcionario \n ";
}
