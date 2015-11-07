#include <iostream>
#include "Veiculo.h"
#include "Funcionario.h"
#include "Oficina.h"
#include "Cliente.h"
#include "Excepcoes.h"

using namespace std;

void showMenu(){
	cout << "1 - Adicionar funcion�rio \n" <<
			"2 - Adicionar cliente \n" <<
			"3 - Adicionar ve�culo \n" <<
			"4 - Remove funcion�rio \n" <<
			"5 - Remove cliente \n" <<
			"6 - Remove veiculo \n" <<
			"7 - Mostra funcion�rios \n" <<
			"8 - Mostra clientes \n" <<
			"9 - Mostra ve�culos \n";
}

void optionMenu(Oficina &oficina, int opcao){
	switch(opcao){
		case 1: //adiciona funcionario
		{
			string nomeF;
			cin.sync();
			cout << "Insira o nome do funcion�rio: ";
			getline(cin,nomeF);
			Funcionario f(nomeF);
			try{
				oficina.addFuncionario(f);
			}catch(FuncionarioExistente &e){
				cout << e.getNome() << " j� � um funcion�rio.\n";
			}
		}
		break;
		case 2: //adiciona cliente
		{
			string nomeC;
			cout << "Insira o nome do cliente: ";
			getline(cin,nomeC);
			Cliente c(nomeC);
			try{
				oficina.addCliente(c);
			}catch(ClienteExistente &e){
				cout << e.getNome() << " j� � um cliente.\n";
			}
		}
		break;
		case 3: //adiciona veiculo
		{
			string marca, matricula, tipo;
			int ano;
			cout << "Insira o tipo do veiculo: ";
			cin >> tipo;
			cout << "Insira a marca do veiculo: ";
			cin >> marca;
			cout << "Insira a matricula do veiculo: ";
			cin >> matricula;
			cout << "Insira o ano do veiculo: ";
			cin >> ano;

			if(tipo == "Motorizada"){
				Motorizada *m = new Motorizada(marca,matricula,ano);
				try{
					oficina.addVeiculo(m);
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " j� � um ve�culo existente.\n";
				}
			}else if(tipo == "Cami�o" || tipo == "Camiao"){
				Camiao *c = new Camiao(marca,matricula,ano);
				try{
					oficina.addVeiculo(c);
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " j� � um ve�culo existente.\n";
				}
			}else if(tipo == "Autocarro"){
				Autocarro *at = new Autocarro(marca,matricula,ano);
				try{
					oficina.addVeiculo(at);
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " j� � um ve�culo existente.\n";
				}
			}else if(tipo == "Autom�vel" || tipo == "Automovel"){
				Automovel *am = new Automovel(marca,matricula,ano);
				try{
					oficina.addVeiculo(am);
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " j� � um ve�culo existente.\n";
				}
			}
		}
		break;
		case 4: //remove funcion�rio
		{
			string nomeF;
			cout << "Insira o nome do funcion�rio: ";
			getline(cin,nomeF);
			Funcionario f(nomeF);
			try{
				oficina.removeFuncionario(f);
			}catch(FuncionarioInexistente &e){
				cout << e.getNome() << " n�o � um funcion�rio.\n";
			}
		}
		break;
		case 5: //remove cliente
		{
			string nomeC;
			cout << "Insira o nome do cliente: ";
			getline(cin,nomeC);
			Cliente c(nomeC);
			try{
				oficina.removeCliente(c);
			}catch(ClienteInexistente &e){
				cout << e.getNome() << " n�o � um cliente.\n";
			}
		}
		break;
		case 6: //remove veiculo
		{
			string marca, matricula;
			int ano;
			cout << "Insira a marca do veiculo: ";
			cin >> marca;
			cout << "Insira a matricula do veiculo: ";
			cin >> matricula;
			cout << "Insira o ano do veiculo: ";
			cin >> ano;
			Veiculo *v = new Veiculo(marca,matricula,ano);
			try{
				oficina.removeVeiculo(v);
			}catch(VeiculoInexistente &e){
				cout << e.getMatricula() << " n�o � um ve�culo da oficina.\n";
			}
		}
		break;
		case 7: //mostra funcion�rios
			oficina.displayFuncionarios();
			break;
		case 8: //mostra clientes
			oficina.displayClientes();
			break;
		case 9: //mostra veiculos
			oficina.displayVeiculos();
			break;
		default:
			break;
		}
}

int main(){
	Oficina oficina("Oficina");
	//oficina.leFuncionarios();
	//oficina.leClientes();
	//oficina.leVeiculos();

	int opcao;
	showMenu();
	do{
		cout << "Insira a op��o: ";
		cin >> opcao;
		optionMenu(oficina,opcao);
	}while(opcao != 0);

	oficina.guardaFuncionarios();
	oficina.guardaClientes();
	oficina.guardaVeiculos();

	return 0;
}
