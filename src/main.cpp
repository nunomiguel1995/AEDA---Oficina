#include <iostream>
#include <stdlib.h>
#include "Veiculo.h"
#include "Funcionario.h"
#include "Oficina.h"
#include "Cliente.h"
#include "Excepcoes.h"

using namespace std;

void showMenu(){
	cout << "1 - Funções de adicionar \n" <<
			"2 - Funções de remover \n" <<
			"3 - Funções de display \n" <<
			"0 - Sair \n";
}

void showAddMenu(){
	cout << "1 - Adicionar Funcionário \n" <<
			"2 - Adicionar Veiculo a Funcionário \n" <<
			"3 - Adicionar Cliente \n" <<
			"4 - Adicionar Veiculo a Cliente \n" <<
			"5 - Adicionar Serviço a Veículo \n" <<
			"0 - Sair \n";
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

//feito - funcemina
void addMenu(Oficina &oficina, int opcao){
	switch(opcao){
	case 1: //adiciona funcionario
	{
		string nomeF;
		cin.sync();
		cout << "Insira o nome do funcionário: ";
		getline(cin,nomeF);
		Funcionario f(nomeF);
		try{
			oficina.addFuncionario(f);
		}catch(FuncionarioExistente &e){
			cout << e.getNome() << " já é um funcionário.\n";
		}
	}
	break;
	case 2: //adiciona veiculo a funcionario
	{
		string matricula, nome;
		try{
			cin.sync();
			cout << "Insira o nome do funcionário: ";
			getline(cin,nome);
			oficina.getFuncionarioNome(nome);
			cout << "Insira a matrícula do veículo: ";
			cin >> matricula;
			Veiculo *v = oficina.getVeiculoMatricula(matricula);
			oficina.addVeiculoFuncionario(v,nome);
		}catch(FuncionarioInexistente &e){
			cout << e.getNome() << " não é um funcionário.\n";
		}catch(VeiculoInexistente &e){
			cout << e.getMatricula() << " não existe.\n";
		}
	}
	break;
	case 3: //adiciona cliente
	{
		string nome;
		cin.sync();
		cout << "Insira o nome do cliente: ";
		getline(cin,nome);
		Cliente c(nome);
		try{
			oficina.addCliente(c);
		}catch(ClienteExistente &e){
			cout << e.getNome() << " já é um cliente.\n";
		}
	}
	break;
	case 4: //adiciona veiculo a cliente
	{
		string marca, matricula, tipo, nome;
		int ano;
		try{
			string nome;
			cin.sync();
			cout << "Insira o nome do cliente: ";
			getline(cin,nome);
			cout << "Insira o tipo do veiculo: ";
			cin >> tipo;
			cout << "Insira a marca do veiculo: ";
			cin >> marca;
			cout << "Insira a matricula do veiculo: ";
			cin >> matricula;
			cout << "Insira o ano do veiculo: ";
			cin >> ano;
			oficina.getClienteNome(nome);
			if(tipo == "Motorizada"){
				Motorizada *m = new Motorizada(marca,matricula,ano);
				oficina.addVeiculo(m);
				oficina.addVeiculoCliente(m,nome);
			}else if(tipo == "Camião" || tipo == "Camiao"){
				Camiao *c = new Camiao(marca,matricula,ano);
				oficina.addVeiculo(c);
				oficina.addVeiculoCliente(c,nome);
			}else if(tipo == "Autocarro"){
				Autocarro *at = new Autocarro(marca,matricula,ano);
				oficina.addVeiculo(at);
				oficina.addVeiculoCliente(at,nome);
			}else if(tipo == "Automóvel" || tipo == "Automovel"){
				Automovel *am = new Automovel(marca,matricula,ano);
				oficina.addVeiculo(am);
				oficina.addVeiculoCliente(am,nome);
			}else{
				cout << "Tipo de veículo inválido.\n";
				return;
			}
		}catch(VeiculoExistente &e){
			cout << e.getMatricula() << " já existe.\n";
		}catch(ClienteInexistente &e){
			cout << e.getNome() << " não é um cliente.\n";
		}
	}
	break;
	case 5: //adicionar serviço a veículo
	{
		string matricula;
		cout<<"Insira a matricula do Veiculo: ";
		cin>>matricula;

		int pos= oficina.posVeiculo(matricula);
		if(pos==-1){
			cout<<"Veiculo não existe na Oficina! \n";
			break;
		}

		int tiposervico;
		cout<<"Que tipo de serviço deseja adicionar? \n"<<"1 Standard \n"<<"2 Não Standard\n "<<"Opcção: ";
		cin>>tiposervico;

		switch(tiposervico){
		case 1:
		{
			string nome;
			cout<<"Escolha um nome para o serviço: ";
			cin>>nome;

			Standard s1(nome);
			vector <Veiculo *> veic= oficina.getVeiculos();
			veic[pos]->addServico(s1);
			oficina.setVeiculos(veic);

			break;

		}
		case 2:
		{
			string nome;
			int duracao;
			float preco;
			vector <string> descricao;
			bool continua= true;

			cout<<"Escolha um nome para o serviço: ";
			cin>>nome;
			cout<<"Qual a duração do serviço: ";
			cin>>duracao;
			cout<<"Qual o preço do serviço: ";
			cin>>preco;
			cout<<"Qual a descrição do serviço (0 para terminar): ";
			do{
				string d;
				cin>>d;
				if(d == "0"){
					continua=false;
					break;
				}
				descricao.push_back(d);
			}while(continua);

			naoStandard s1(nome,preco,duracao,descricao);
			vector <Veiculo *> veic= oficina.getVeiculos();
			veic[pos]->addServico(s1);
			oficina.setVeiculos(veic);
		}
		break;
		default:
			break;
		}
	}
	}
}

void removeMenu(Oficina &oficina, int opcao){
	switch(opcao){
		case 1: //remove funcionario
		{
			string nomeF;
			cin.sync();
			cout << "Insira o nome do funcionário: ";
			getline(cin,nomeF);
			Funcionario f(nomeF);
			try{
				oficina.removeFuncionario(f);
			}catch(FuncionarioInexistente &e){
				cout << e.getNome() << " não é um funcionário.\n";
			}
		}
		break;
		case 2: //remove veiculo do funcionario
		{
			string matricula, nome;
			try{
				cin.sync();
				cout << "Insira o nome do funcionário: ";
				getline(cin,nome);
				oficina.getFuncionarioNome(nome);
				cout << "Insira a matrícula do veículo: ";
				cin >> matricula;
				oficina.removeVeiculoFuncionario(oficina.getVeiculoMatricula(matricula),nome);
			}catch(FuncionarioInexistente &e){
				cout << e.getNome() << " não é um funcionário.\n";
			}catch(VeiculoInexistente &e){
				cout << e.getMatricula() << " não existe.\n";
			}
		}
		break;
		case 3: //remove cliente
		{
			string nome;
			cin.sync();
			cout << "Insira o nome do cliente: ";
			getline(cin,nome);
			Cliente c(nome);
			vector<Veiculo*> veic = c.getVeiculos();
			vector<Funcionario> f;
			try{
				for(unsigned int i = 0; i < veic.size(); i++){
					f = oficina.getFuncionariosVeiculo(oficina.getVeiculoMatricula(veic[i]->getMatricula()));
					for(unsigned int j = 0; j < f.size(); j++){
						oficina.removeVeiculoFuncionario(oficina.getVeiculoMatricula(veic[i]->getMatricula()),f[j].getNome());
					}
					oficina.removeVeiculo(veic[i]);
				}
				oficina.removeCliente(c);
			}catch(ClienteInexistente &e){
				cout << e.getNome() << " não é um cliente.\n";
			}
		}
		break;
		case 4: //remove veiculo a cliente
		{
			string matricula, nome;
			try{
				cin.sync();
				cout << "Insira o nome do cliente: ";
				getline(cin,nome);
				oficina.getClienteNome(nome);
				cout << "Insira a matrícula do veículo: ";
				cin >> matricula;
				vector<Funcionario> f = oficina.getFuncionariosVeiculo(oficina.getVeiculoMatricula(matricula));
				for(unsigned int i = 0; i < f.size(); i++){
					oficina.removeVeiculoFuncionario(oficina.getVeiculoMatricula(matricula),f[i].getNome());
				}
				oficina.removeVeiculoCliente(oficina.getVeiculoMatricula(matricula),nome);
				oficina.removeVeiculo(oficina.getVeiculoMatricula(matricula));
			}catch(ClienteInexistente &e){
				cout << e.getNome() << " não é um funcionário.\n";
			}catch(VeiculoInexistente &e){
				cout << e.getMatricula() << " não existe.\n";
			}
		}
		break;
		default:
			break;
		}
}

//feito - funcemina
void displayMenu(Oficina &oficina, int opcao){
switch(opcao){
case 1: //display funcionários
	oficina.displayFuncionarios();
	break;
case 2: //display veiculos do funcionario
{
	string nome;
	try{
		cin.sync();
		cout << "Insira o nome do funcionário: ";
		getline(cin,nome);
		Funcionario f = oficina.getFuncionarioNome(nome);
		f.displayFuncionario();
	}catch(FuncionarioInexistente &e){
		cout << e.getNome() << " não é um funcionário.\n";
	}
}
break;
case 3: //display clientes
	oficina.displayClientes();
	break;
case 4: //display veiculos do cliente
{
	string nome;
	try{
		cin.sync();
		cout << "Insira o nome do cliente: ";
		getline(cin,nome);
		Cliente c = oficina.getClienteNome(nome);
		c.displayCliente();
	}catch(ClienteInexistente &e){
		cout << e.getNome() << " não é um cliente.\n";
	}
}
break;
default:
	break;
}
}

//feito - funcemina
void option(Oficina &oficina, int opcao){
	int opcaoAdd,opcaoRemove, opcaoDisplay;
	switch(opcao){
	case 1: //adicionar
		do{
			showAddMenu();
			cout << "Insira a opção: ";
			cin >> opcaoAdd;
			if(opcaoAdd == 0){
				return;
			}
			addMenu(oficina,opcaoAdd);
		}while(opcaoAdd != 0);
		break;
	case 2: //remover
		do{
			showRemoveMenu();
			cout << "Insira a opção: ";
			cin >> opcaoRemove;
			if(opcaoRemove == 0){
				return;
			}
			removeMenu(oficina,opcaoRemove);
		}while(opcaoRemove != 0);
	case 3: //display
		do{
			showDisplayMenu();
			cout << "Insira a opção: ";
			cin >> opcaoDisplay;
			if(opcaoDisplay == 0){
				return;
			}
			displayMenu(oficina,opcaoDisplay);
		}while(opcaoDisplay != 0);
		break;
	default:
		break;
	}
}

//feito - funcemina
int main(){
	Oficina oficina("Oficina");
	oficina.leFuncionarios();
	oficina.leClientes();
	oficina.leVeiculos();

	int opcao;
	do{
		showMenu();
		cout << "Insira a opção: ";
		cin >> opcao;
		option(oficina,opcao);
	}while(opcao != 0);

	oficina.guardaFuncionarios();
	oficina.guardaClientes();
	oficina.guardaVeiculos();

	return 0;
}
