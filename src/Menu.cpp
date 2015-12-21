#include "Oficina.h"

using namespace std;

void addMenu(Oficina &oficina){
	cout << "1 - Adicionar Funcion�rio" << endl; //
	cout <<	"2 - Adicionar Veiculo a Funcion�rio" << endl; //
	cout <<	"3 - Adicionar Cliente" << endl; //
	cout <<	"4 - Adicionar Veiculo a Cliente" << endl; //
	cout <<	"5 - Adicionar Servi�o a Ve�culo" << endl;
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
		cout << "Op��o inv�lida. Insira outra vez." << endl;
		break;
	}
}

void menu(Oficina &oficina){
	cout << "1 - Fun��es de adicionar" << endl;
	cout <<	"2 - Fun��es de remover" << endl;
	cout <<	"3 - Fun��es de display" << endl;
	cout <<	"4 - Fun��es de modificar" << endl;
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
		cout << "Op��o inv�lida. Insira outra vez." << endl;
		break;
	}
}



void showRemoveMenu(){
	cout << "1 - Remover Funcion�rio \n" <<
			"2 - Remover Veiculo de Funcion�rio \n" <<
			"3 - Remover Cliente \n" <<
			"4 - Remover Veiculo de Cliente \n" <<
			"0 - Sair \n";
}

void showDisplayMenu(){
	cout << "1 - Display Funcion�rios \n" <<
			"2 - Display Ve�culos do Funcion�rio \n" <<
			"3 - Display Clientes \n" <<
			"4 - Display Ve�culos do Cliente \n" <<
			"5 - Display de Servi�os do Ve�culo \n" <<
			"0 - Sair \n";
}

void showModifyMenu(){
	cout<<  "1 - Modificar nome Cliente \n"<<
			"2 - Modificar nome Funcionario \n ";
}
