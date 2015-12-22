#include "Menu.h"

void Menu::addMenu(Oficina &oficina){
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
		menu(oficina);
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
		addMenu(oficina);
		break;
	}
}

void Menu::removeMenu(Oficina &oficina){
	cout << "1 - Remover Funcionário" << endl;
	cout <<	"2 - Remover Veiculo de Funcionário" << endl;
	cout <<	"3 - Remover Cliente" << endl;
	cout <<	"4 - Remover Veiculo de Cliente" << endl;
	cout << "0 - Sair" << endl;

	int opcao;
	cin >> opcao;

	switch(opcao){
	case 0:
		menu(oficina);
		break;
	case 1:{
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
		oficina.guardaVeiculos();
		oficina.guardaClientes();
		oficina.guardaServicos();
		oficina.guardaFuncionarios();
		break;
	}
	case 2:{
		string matricula, nome;
		try{
			cin.sync();
			cout << "Insira o nome do funcionário: ";
			getline(cin,nome);
			oficina.getFuncionarioNome(nome);
			cout << "Insira a matrícula do veículo: ";
			cin >> matricula;
			Veiculo *v = oficina.getVeiculoMatricula(matricula);
			oficina.removeVeiculoFuncionario(v,nome);
		}catch(FuncionarioInexistente &e){
			cout << e.getNome() << " não é um funcionário.\n";
		}catch(VeiculoInexistente &e){
			cout << e.getMatricula() << " não existe.\n";
		}
		oficina.guardaVeiculos();
		oficina.guardaClientes();
		oficina.guardaServicos();
		oficina.guardaFuncionarios();
		break;
	}
	case 3:{
		string nome;
		cin.sync();
		cout << "Insira o nome do cliente: ";
		getline(cin,nome);
		try{
			oficina.getClienteNome(nome);
			Cliente c(nome);
			oficina.removeCliente(c);
		}catch(ClienteInexistente &e){
			cout << e.getNome() << " não é um cliente.\n";
		}catch(VeiculoInexistente &e){
			cout << e.getMatricula() << " não existe.\n";
		}
		oficina.guardaVeiculos();
		oficina.guardaClientes();
		oficina.guardaServicos();
		oficina.guardaFuncionarios();
		break;
	}
	case 4:{
		string matricula, nome;
		try{
			cin.sync();
			cout << "Insira o nome do cliente: ";
			getline(cin,nome);
			oficina.getClienteNome(nome);
			cout << "Insira a matrícula do veículo: ";
			cin >> matricula;
			vector<Funcionario> f = oficina.getFuncionariosVeiculo(oficina.getVeiculoMatricula(matricula));
			Veiculo *v = oficina.getVeiculoMatricula(matricula);
			for(unsigned int i = 0; i < f.size(); i++){
				oficina.removeVeiculoFuncionario(v,f[i].getNome());
			}
			oficina.removeVeiculoCliente(v,nome);
			oficina.removeVeiculo(v);
		}catch(ClienteInexistente &e){
			cout << e.getNome() << " não é um funcionário.\n";
		}catch(VeiculoInexistente &e){
			cout << e.getMatricula() << " não existe.\n";
		}
		oficina.guardaVeiculos();
		oficina.guardaClientes();
		oficina.guardaServicos();
		oficina.guardaFuncionarios();
		break;
	}
	default:
		cout << "Opção inválida. Insira outra vez." << endl;
		removeMenu(oficina);
		break;
	}
}

void Menu::displayMenu(Oficina &oficina){
	cout << "1 - Display Funcionários" << endl;
	cout <<	"2 - Display Veículos do Funcionário" << endl;
	cout <<	"3 - Display Clientes" << endl;
	cout <<	"4 - Display Veículos do Cliente" << endl;
	cout <<	"5 - Display de Serviços do Veículo" << endl;
	cout <<	"0 - Sair" << endl;

	int opcao;
	cin >> opcao;

	switch(opcao){
	case 0:
		menu(oficina);
		break;
	case 1:
		oficina.displayFuncionarios();
		break;
	case 2:{
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
		break;
	}
	case 3:
		oficina.displayClientes();
		break;
	case 4:{
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
		break;
	}
	case 5:	{
		string matricula;
		try{
			cout << "Insira a matricula do veiculo: ";
			cin >> matricula;
			Veiculo *v = oficina.getVeiculoMatricula(matricula);
			vector<Servico *> serv = v->getServicos();
			for(unsigned int i = 0; i < serv.size(); i++){
				serv[i]->displayServico();
				cout << endl;
			}
		}catch(VeiculoInexistente &e){
			cout << e.getMatricula() << " não existe.\n";
		}
		break;
	}
	default:
		cout << "Opção inválida. Insira outra vez." << endl;
		displayMenu(oficina);
		break;
	}
}

void Menu::modifyMenu(Oficina &oficina){
	cout << "1 - Modificar nome Cliente" << endl;
	cout <<	"2 - Modificar nome Funcionario" << endl;
}

void Menu::menu(Oficina &oficina){
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
		removeMenu(oficina);
		break;
	case 3:
		displayMenu(oficina);
		break;
	case 4:
		modifyMenu(oficina);
		break;
	default:
		cout << "Opção inválida. Insira outra vez." << endl;
		menu(oficina);
		break;
	}
}
