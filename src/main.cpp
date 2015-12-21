#include <iostream>
#include <stdlib.h>
#include "Veiculo.h"
#include "Funcionario.h"
#include "Oficina.h"
#include "Cliente.h"
#include "Excepcoes.h"

using namespace std;

//void showMenu(){
//	cout << "1 - Fun��es de adicionar \n" <<
//			"2 - Fun��es de remover \n" <<
//			"3 - Fun��es de display \n" <<
//			"4 - Fun��es de modificar \n"<<
//			"0 - Sair \n";
//}
//
//void showAddMenu(){
//	cout << "1 - Adicionar Funcion�rio \n" <<
//			"2 - Adicionar Veiculo a Funcion�rio \n" <<
//			"3 - Adicionar Cliente \n" <<
//			"4 - Adicionar Veiculo a Cliente \n" <<
//			"5 - Adicionar Servi�o a Ve�culo \n" <<
//			"0 - Sair \n";
//}
//
//void showRemoveMenu(){
//	cout << "1 - Remover Funcion�rio \n" <<
//			"2 - Remover Veiculo de Funcion�rio \n" <<
//			"3 - Remover Cliente \n" <<
//			"4 - Remover Veiculo de Cliente \n" <<
//			"0 - Sair \n";
//}
//
//void showDisplayMenu(){
//	cout << "1 - Display Funcion�rios \n" <<
//			"2 - Display Ve�culos do Funcion�rio \n" <<
//			"3 - Display Clientes \n" <<
//			"4 - Display Ve�culos do Cliente \n" <<
//			"5 - Display de Servi�os do Ve�culo \n" <<
//			"0 - Sair \n";
//}
//
//void showModifyMenu(){
//	cout<<  "1 - Modificar nome Cliente \n"<<
//			"2 - Modificar nome Funcionario \n ";
//}
//
////feito - funcemina
//void addMenu(Oficina &oficina, int opcao){
//	switch(opcao){
//	case 1: //adiciona funcionario
//	{
//		string nomeF;
//		cin.sync();
//		cout << "Insira o nome do funcion�rio: ";
//		getline(cin,nomeF);
//		Funcionario f(nomeF);
//		try{
//			oficina.addFuncionario(f);
//		}catch(FuncionarioExistente &e){
//			cout << e.getNome() << " j� � um funcion�rio.\n";
//		}
//	}
//	break;
//	case 2: //adiciona veiculo a funcionario
//	{
//		string matricula, nome;
//		try{
//			cin.sync();
//			cout << "Insira o nome do funcion�rio: ";
//			getline(cin,nome);
//			oficina.getFuncionarioNome(nome);
//			cout << "Insira a matr�cula do ve�culo: ";
//			cin >> matricula;
//			Veiculo *v = oficina.getVeiculoMatricula(matricula);
//			oficina.addVeiculoFuncionario(v,nome);
//		}catch(FuncionarioInexistente &e){
//			cout << e.getNome() << " n�o � um funcion�rio.\n";
//		}catch(VeiculoInexistente &e){
//			cout << e.getMatricula() << " n�o existe.\n";
//		}
//	}
//	break;
//	case 3: //adiciona cliente
//	{
//		string nome;
//		cin.sync();
//		cout << "Insira o nome do cliente: ";
//		getline(cin,nome);
//		Cliente c(nome);
//		try{
//			oficina.addCliente(c);
//		}catch(ClienteExistente &e){
//			cout << e.getNome() << " j� � um cliente.\n";
//		}
//	}
//	break;
//	case 4: //adiciona veiculo a cliente
//	{
//		string marca, matricula, tipo, nome;
//		int ano;
//		try{
//			string nome;
//			cin.sync();
//			cout << "Insira o nome do cliente: ";
//			getline(cin,nome);
//			cout << "Insira o tipo do veiculo: ";
//			cin >> tipo;
//			cout << "Insira a marca do veiculo: ";
//			cin >> marca;
//			cout << "Insira a matricula do veiculo: ";
//			cin >> matricula;
//			cout << "Insira o ano do veiculo: ";
//			cin >> ano;
//			oficina.getClienteNome(nome);
//			if(tipo == "Motorizada"){
//				Veiculo *m = new Motorizada(marca,matricula,ano);
//				oficina.addVeiculo(m);
//				oficina.addVeiculoCliente(m,nome);
//			}else if(tipo == "Cami�o" || tipo == "Camiao"){
//				Veiculo *c = new Camiao(marca,matricula,ano);
//				oficina.addVeiculo(c);
//				oficina.addVeiculoCliente(c,nome);
//			}else if(tipo == "Autocarro"){
//				Veiculo *at = new Autocarro(marca,matricula,ano);
//				oficina.addVeiculo(at);
//				oficina.addVeiculoCliente(at,nome);
//			}else if(tipo == "Autom�vel" || tipo == "Automovel"){
//				Veiculo *am = new Automovel(marca,matricula,ano);
//				oficina.addVeiculo(am);
//				oficina.addVeiculoCliente(am,nome);
//			}else{
//				cout << "Tipo de ve�culo inv�lido.\n";
//				return;
//			}
//		}catch(VeiculoExistente &e){
//			cout << e.getMatricula() << " j� existe.\n";
//		}catch(ClienteInexistente &e){
//			cout << e.getNome() << " n�o � um cliente.\n";
//		}
//	}
//	break;
//	case 5: //adicionar servi�o a ve�culo
//	{
//		string matricula;
//		cout<<"Insira a matricula do Veiculo: ";
//		cin>>matricula;
//
//		int pos= oficina.posVeiculo(matricula);
//		if(pos==-1){
//			cout<<"Veiculo n�o existe na Oficina! \n";
//			break;
//		}
//
//		int tiposervico;
//		cout<<"Que tipo de servi�o deseja adicionar? \n"<<"1 Standard \n"<<"2 N�o Standard\n "<<"Opc��o: ";
//		cin>>tiposervico;
//
//		switch(tiposervico){
//		case 1:
//		{
//
//			string nome;
//			cout<<"Qual o nome para o Servi�o Standard: ";
//			cin>>nome;
//			int i= oficina.isStandard(nome);
//			if(i==-1){
//				cout<<"Servi�o Standard n�o oferecido pela oficina! \n";
//				break;
//			}
//			Servico *s;
//			s = oficina.getServicosStandard().at(i);
//			vector <Veiculo *> veic= oficina.getVeiculos();
//			veic[pos]->addServico(s,true);
//			oficina.setVeiculos(veic);
//			cout<<"Servi�o adicionado com sucesso! \n";
//
//			break;
//
//		}
//		case 2:
//		{
//			string nome;
//			int duracao;
//			float preco;
//			vector <string> descricao;
//			bool continua= true;
//
//			cout<<"Escolha um nome para o servi�o: ";
//			cin>>nome;
//			cout<<"Qual a dura��o do servi�o: ";
//			cin>>duracao;
//			cout<<"Qual o pre�o do servi�o: ";
//			cin>>preco;
//			cout<<"Qual a descri��o do servi�o (0 para terminar): ";
//
//			Servico *s1 = new naoStandard(nome,preco,duracao);
//			vector <Veiculo *> veic= oficina.getVeiculos();
//			veic[pos]->addServico(s1,true);
//			oficina.setVeiculos(veic);
//			cout<<"Servi�o adicionado com sucesso! \n";
//
//		}
//		break;
//		default:
//			break;
//		}
//	}
//	}
//}
//
//void removeMenu(Oficina &oficina, int opcao){
//	switch(opcao){
//		case 1: //remove funcionario
//		{
//			string nomeF;
//			cin.sync();
//			cout << "Insira o nome do funcion�rio: ";
//			getline(cin,nomeF);
//			Funcionario f(nomeF);
//			try{
//				oficina.removeFuncionario(f);
//			}catch(FuncionarioInexistente &e){
//				cout << e.getNome() << " n�o � um funcion�rio.\n";
//			}
//		}
//		break;
//		case 2: //remove veiculo do funcionario
//		{
//			string matricula, nome;
//			try{
//				cin.sync();
//				cout << "Insira o nome do funcion�rio: ";
//				getline(cin,nome);
//				oficina.getFuncionarioNome(nome);
//				cout << "Insira a matr�cula do ve�culo: ";
//				cin >> matricula;
//				Veiculo *v = oficina.getVeiculoMatricula(matricula);
//				oficina.removeVeiculoFuncionario(v,nome);
//			}catch(FuncionarioInexistente &e){
//				cout << e.getNome() << " n�o � um funcion�rio.\n";
//			}catch(VeiculoInexistente &e){
//				cout << e.getMatricula() << " n�o existe.\n";
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
//				cout << e.getNome() << " n�o � um cliente.\n";
//			}catch(VeiculoInexistente &e){
//				cout << e.getMatricula() << " n�o existe.\n";
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
//				cout << "Insira a matr�cula do ve�culo: ";
//				cin >> matricula;
//				vector<Funcionario> f = oficina.getFuncionariosVeiculo(oficina.getVeiculoMatricula(matricula));
//				Veiculo *v = oficina.getVeiculoMatricula(matricula);
//				for(unsigned int i = 0; i < f.size(); i++){
//					oficina.removeVeiculoFuncionario(v,f[i].getNome());
//				}
//				oficina.removeVeiculoCliente(v,nome);
//				oficina.removeVeiculo(v);
//			}catch(ClienteInexistente &e){
//				cout << e.getNome() << " n�o � um funcion�rio.\n";
//			}catch(VeiculoInexistente &e){
//				cout << e.getMatricula() << " n�o existe.\n";
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
//case 1: //display funcion�rios
//	oficina.displayFuncionarios();
//	break;
//case 2: //display veiculos do funcionario
//{
//	string nome;
//	try{
//		cin.sync();
//		cout << "Insira o nome do funcion�rio: ";
//		getline(cin,nome);
//		Funcionario f = oficina.getFuncionarioNome(nome);
//		f.displayFuncionario();
//	}catch(FuncionarioInexistente &e){
//		cout << e.getNome() << " n�o � um funcion�rio.\n";
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
//		cout << e.getNome() << " n�o � um cliente.\n";
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
//		cout << e.getMatricula() << " n�o existe.\n";
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
//			cout << "Insira a op��o: ";
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
//			cout << "Insira a op��o: ";
//			cin >> opcaoRemove;
//			if(opcaoRemove == 0){
//				return;
//			}
//			removeMenu(oficina,opcaoRemove);
//		}while(opcaoRemove != 0);
//	case 3: //display
//		do{
//			showDisplayMenu();
//			cout << "Insira a op��o: ";
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
		//cout << "Insira a op��o: ";
		//cin >> opcao;
		//option(oficina,opcao);
	//}while(opcao != 0);

	oficina.guardaVeiculos();
	oficina.guardaFuncionarios();
	oficina.guardaClientes();
	oficina.guardaServicos();

	return 0;
}
