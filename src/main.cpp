#include <iostream>
#include <stdlib.h>
#include "Veiculo.h"
#include "Funcionario.h"
#include "Oficina.h"
#include "Cliente.h"
#include "Excepcoes.h"

using namespace std;


//
//void removeMenu(Oficina &oficina, int opcao){
//	switch(opcao){
//		case 1: //remove funcionario
//		{
//			string nomeF;
//			cin.sync();
//			cout << "Insira o nome do funcionário: ";
//			getline(cin,nomeF);
//			Funcionario f(nomeF);
//			try{
//				oficina.removeFuncionario(f);
//			}catch(FuncionarioInexistente &e){
//				cout << e.getNome() << " não é um funcionário.\n";
//			}
//		}
//		break;
//		case 2: //remove veiculo do funcionario
//		{
//			string matricula, nome;
//			try{
//				cin.sync();
//				cout << "Insira o nome do funcionário: ";
//				getline(cin,nome);
//				oficina.getFuncionarioNome(nome);
//				cout << "Insira a matrícula do veículo: ";
//				cin >> matricula;
//				Veiculo *v = oficina.getVeiculoMatricula(matricula);
//				oficina.removeVeiculoFuncionario(v,nome);
//			}catch(FuncionarioInexistente &e){
//				cout << e.getNome() << " não é um funcionário.\n";
//			}catch(VeiculoInexistente &e){
//				cout << e.getMatricula() << " não existe.\n";
//			}
//		}
//		break;
//		case 3: //remove cliente
//		{
//			string nome;
//			cin.sync();
//			cout << "Insira o nome do cliente: ";
//			getline(cin,nome);
//			try{
//				oficina.getClienteNome(nome);
//				Cliente c(nome);
//				oficina.removeCliente(c);
//			}catch(ClienteInexistente &e){
//				cout << e.getNome() << " não é um cliente.\n";
//			}catch(VeiculoInexistente &e){
//				cout << e.getMatricula() << " não existe.\n";
//			}
//		}
//		break;
//		case 4: //remove veiculo a cliente
//		{
//			string matricula, nome;
//			try{
//				cin.sync();
//				cout << "Insira o nome do cliente: ";
//				getline(cin,nome);
//				oficina.getClienteNome(nome);
//				cout << "Insira a matrícula do veículo: ";
//				cin >> matricula;
//				vector<Funcionario> f = oficina.getFuncionariosVeiculo(oficina.getVeiculoMatricula(matricula));
//				Veiculo *v = oficina.getVeiculoMatricula(matricula);
//				for(unsigned int i = 0; i < f.size(); i++){
//					oficina.removeVeiculoFuncionario(v,f[i].getNome());
//				}
//				oficina.removeVeiculoCliente(v,nome);
//				oficina.removeVeiculo(v);
//			}catch(ClienteInexistente &e){
//				cout << e.getNome() << " não é um funcionário.\n";
//			}catch(VeiculoInexistente &e){
//				cout << e.getMatricula() << " não existe.\n";
//			}
//		}
//		break;
//		default:
//			break;
//		}
//}
//
////feito - funcemina
//void displayMenu(Oficina &oficina, int opcao){
//switch(opcao){
//case 1: //display funcionários
//	oficina.displayFuncionarios();
//	break;
//case 2: //display veiculos do funcionario
//{
//	string nome;
//	try{
//		cin.sync();
//		cout << "Insira o nome do funcionário: ";
//		getline(cin,nome);
//		Funcionario f = oficina.getFuncionarioNome(nome);
//		f.displayFuncionario();
//	}catch(FuncionarioInexistente &e){
//		cout << e.getNome() << " não é um funcionário.\n";
//	}
//}
//break;
//case 3: //display clientes
//	oficina.displayClientes();
//	break;
//case 4: //display veiculos do cliente
//{
//	string nome;
//	try{
//		cin.sync();
//		cout << "Insira o nome do cliente: ";
//		getline(cin,nome);
//		Cliente c = oficina.getClienteNome(nome);
//		c.displayCliente();
//	}catch(ClienteInexistente &e){
//		cout << e.getNome() << " não é um cliente.\n";
//	}
//}
//break;
//case 5: //display servicos do veiculo
//{
//	string matricula;
//	try{
//		cout << "Insira a matricula do veiculo: ";
//		cin >> matricula;
//		Veiculo *v = oficina.getVeiculoMatricula(matricula);
//		vector<Servico *> serv = v->getServicos();
//		for(unsigned int i = 0; i < serv.size(); i++){
//			serv[i]->displayServico();
//			cout << endl;
//		}
//	}catch(VeiculoInexistente &e){
//		cout << e.getMatricula() << " não existe.\n";
//	}
//}
//	break;
//default:
//	break;
//}
//}
//
////feito - funcemina
//void option(Oficina &oficina, int opcao){
//	int opcaoAdd,opcaoRemove, opcaoDisplay;
//	switch(opcao){
//	case 1: //adicionar
//		do{
//			showAddMenu();
//			cout << "Insira a opção: ";
//			cin >> opcaoAdd;
//			if(opcaoAdd == 0){
//				return;
//			}
//			addMenu(oficina,opcaoAdd);
//		}while(opcaoAdd != 0);
//		break;
//	case 2: //remover
//		do{
//			showRemoveMenu();
//			cout << "Insira a opção: ";
//			cin >> opcaoRemove;
//			if(opcaoRemove == 0){
//				return;
//			}
//			removeMenu(oficina,opcaoRemove);
//		}while(opcaoRemove != 0);
//	case 3: //display
//		do{
//			showDisplayMenu();
//			cout << "Insira a opção: ";
//			cin >> opcaoDisplay;
//			if(opcaoDisplay == 0){
//				return;
//			}
//			displayMenu(oficina,opcaoDisplay);
//		}while(opcaoDisplay != 0);
//		break;
//	default:
//		break;
//	}
//}

//feito - funcemina
int main(){
	Oficina oficina("Oficina");
	oficina.leFuncionarios();
	oficina.leClientes();
	oficina.leVeiculos();
	oficina.leServicos();

	//int opcao;
	//do{
		//showMenu();
		//cout << "Insira a opção: ";
		//cin >> opcao;
		//option(oficina,opcao);
	//}while(opcao != 0);



	return 0;
}
