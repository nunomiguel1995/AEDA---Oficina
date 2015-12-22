#include "Menu.h"

void Menu::addMenu(Oficina &oficina){
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
		menu(oficina);
		break;
	case 1:{
		string nomeF;
		cin.sync();
		cout << "Nome do funcion�rio: ";
		getline(cin,nomeF);
		Funcionario f(nomeF);
		try{
			oficina.addFuncionario(f);
		}catch(FuncionarioExistente &e){
			cout << e.getNome() << " j� � um funcion�rio.\n";
		}
	}
	oficina.guardaFuncionarios();
	addMenu(oficina);
	break;
	case 2:{
		string matricula, nome;
		cin.sync();
		cout << "Insira o nome do funcion�rio: ";
		getline(cin,nome);
		try{
			oficina.getFuncionarioNome(nome);
		}catch(FuncionarioInexistente &e){
			cout << e.getNome() << " n�o � um funcion�rio.\n";
		}
		cout << "Insira a matr�cula do ve�culo: ";
		cin >> matricula;
		try{
			Veiculo *v = oficina.getVeiculoMatricula(matricula);
			oficina.addVeiculoFuncionario(v,nome);
		}catch(VeiculoInexistente &e){
			cout << e.getMatricula() << " n�o existe.\n";
		}
	}
	oficina.guardaFuncionarios();
	addMenu(oficina);
	break;
	case 3:{
		string nomeC;
		cin.sync();
		cout << "Insira o nome do cliente: ";
		getline(cin,nomeC);
		Cliente c(nomeC);
		try{
			oficina.addCliente(c);
		}catch(ClienteExistente &e){
			cout << e.getNome() << " j� � um cliente.\n";
		}
	}
	oficina.guardaClientes();
	addMenu(oficina);
	break;
	case 4:{
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
				Veiculo *m = new Motorizada(marca,matricula,ano);
				oficina.addVeiculo(m);
				oficina.addVeiculoCliente(m,nome);
			}else if(tipo == "Cami�o" || tipo == "Camiao"){
				Veiculo *c = new Camiao(marca,matricula,ano);
				oficina.addVeiculo(c);
				oficina.addVeiculoCliente(c,nome);
			}else if(tipo == "Autocarro"){
				Veiculo *at = new Autocarro(marca,matricula,ano);
				oficina.addVeiculo(at);
				oficina.addVeiculoCliente(at,nome);
			}else if(tipo == "Autom�vel" || tipo == "Automovel"){
				Veiculo *am = new Automovel(marca,matricula,ano);
				oficina.addVeiculo(am);
				oficina.addVeiculoCliente(am,nome);
			}else{
				cout << "Tipo de ve�culo inv�lido.\n";
				return;
			}
		}catch(VeiculoExistente &e){
			cout << e.getMatricula() << " j� existe.\n";
		}catch(ClienteInexistente &e){
			cout << e.getNome() << " n�o � um cliente.\n";
		}
	}
	oficina.guardaVeiculos();
	oficina.guardaClientes();
	addMenu(oficina);
	break;
	case 5:{
		string matricula;
		cout<<"Insira a matricula do Veiculo: ";
		cin>>matricula;

		int pos = oficina.posVeiculo(matricula);
		if(pos==-1){
			cout<<"Veiculo n�o existe na Oficina! \n";
			return;
		}

		int tiposervico;
		cout<<"Que tipo de servi�o deseja adicionar? \n"<<"1 Standard \n"<<"2 N�o Standard\n "<<"Opc��o: ";
		cin>>tiposervico;

		switch(tiposervico){
		case 1:
		{
			string nome;
			cout << "Qual o nome para o Servi�o Standard: ";
			cin >> nome;

			int i = oficina.isStandard(nome);

			if(i == -1){
				cout << "Servi�o Standard n�o oferecido pela oficina!\n";
				break;
			}

			Servico *s = oficina.getServicosStandard().at(i);
			vector <Veiculo *> veic = oficina.getVeiculos();
			veic[pos]->addServico(s,true);
			oficina.setVeiculos(veic);
			cout<<"Servi�o adicionado com sucesso! \n";
			break;
		}
		case 2:
		{
			string nome;
			int duracao;
			float preco;
			vector <string> descricao;

			cout<<"Escolha um nome para o servi�o: ";
			cin>>nome;
			cout<<"Qual a dura��o do servi�o: ";
			cin>>duracao;
			cout<<"Qual o pre�o do servi�o: ";
			cin>>preco;

			int ano,mes,dia,hora,minutos;
			cout << "Data para agendamento" << endl;
			cout << "Ano: ";
			cin >> ano;
			cout << "M�s: ";
			cin >> mes;
			cout << "Dia: ";
			cin >> dia;
			cout << "Hora: ";
			cin >> hora;
			cout << "Minuto: ";
			cin >> minutos;

			Date d(ano,mes,dia,hora,minutos);

			Servico *s1 = new naoStandard(nome,preco,duracao,d);
			vector <Veiculo *> veic = oficina.getVeiculos();
			veic[pos]->addServico(s1,true);
			oficina.setVeiculos(veic);
			cout<<"Servi�o adicionado com sucesso! \n";
		}
		break;
		default:
			break;
		}
	}
	oficina.guardaVeiculos();
	oficina.guardaServicos();
	addMenu(oficina);
	break;
	default:
		cout << "Op��o inv�lida. Insira outra vez." << endl;
		addMenu(oficina);
		break;
	}
}

void Menu::removeMenu(Oficina &oficina){
	cout << "1 - Remover Funcion�rio" << endl;
	cout <<	"2 - Remover Veiculo de Funcion�rio" << endl;
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
		cout << "Insira o nome do funcion�rio: ";
		getline(cin,nomeF);
		Funcionario f(nomeF);
		try{
			oficina.removeFuncionario(f);
		}catch(FuncionarioInexistente &e){
			cout << e.getNome() << " n�o � um funcion�rio.\n";
		}
		oficina.guardaFuncionarios();
		removeMenu(oficina);
		break;
	}
	case 2:{
		string matricula, nome;
		try{
			cin.sync();
			cout << "Insira o nome do funcion�rio: ";
			getline(cin,nome);
			oficina.getFuncionarioNome(nome);
			cout << "Insira a matr�cula do ve�culo: ";
			cin >> matricula;
			Veiculo *v = oficina.getVeiculoMatricula(matricula);
			oficina.removeVeiculoFuncionario(v,nome);
		}catch(FuncionarioInexistente &e){
			cout << e.getNome() << " n�o � um funcion�rio.\n";
		}catch(VeiculoInexistente &e){
			cout << e.getMatricula() << " n�o existe.\n";
		}
		oficina.guardaFuncionarios();
		removeMenu(oficina);
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
			cout << e.getNome() << " n�o � um cliente.\n";
		}catch(VeiculoInexistente &e){
			cout << e.getMatricula() << " n�o existe.\n";
		}
		oficina.guardaVeiculos();
		oficina.guardaClientes();
		oficina.guardaFuncionarios();
		removeMenu(oficina);
		break;
	}
	case 4:{
		string matricula, nome;
		try{
			cin.sync();
			cout << "Insira o nome do cliente: ";
			getline(cin,nome);
			oficina.getClienteNome(nome);
			cout << "Insira a matr�cula do ve�culo: ";
			cin >> matricula;
			vector<Funcionario> f = oficina.getFuncionariosVeiculo(oficina.getVeiculoMatricula(matricula));
			Veiculo *v = oficina.getVeiculoMatricula(matricula);
			for(unsigned int i = 0; i < f.size(); i++){
				oficina.removeVeiculoFuncionario(v,f[i].getNome());
			}
			oficina.removeVeiculoCliente(v,nome);
			oficina.removeVeiculo(v);
		}catch(ClienteInexistente &e){
			cout << e.getNome() << " n�o � um funcion�rio.\n";
		}catch(VeiculoInexistente &e){
			cout << e.getMatricula() << " n�o existe.\n";
		}
		oficina.guardaVeiculos();
		oficina.guardaClientes();
		oficina.guardaFuncionarios();
		removeMenu(oficina);
		break;
	}
	default:
		cout << "Op��o inv�lida. Insira outra vez." << endl;
		removeMenu(oficina);
		break;
	}
}

void Menu::displayMenu(Oficina &oficina){
	cout << "1 - Display Funcion�rios" << endl;
	cout <<	"2 - Display Ve�culos do Funcion�rio" << endl;
	cout <<	"3 - Display Clientes" << endl;
	cout <<	"4 - Display Ve�culos do Cliente" << endl;
	cout <<	"5 - Display de Servi�os do Ve�culo" << endl;
	cout <<	"0 - Sair" << endl;

	int opcao;
	cin >> opcao;

	switch(opcao){
	case 0:
		menu(oficina);
		break;
	case 1:
		oficina.displayFuncionarios();
		displayMenu(oficina);
		break;
	case 2:{
		string nome;
		try{
			cin.sync();
			cout << "Insira o nome do funcion�rio: ";
			getline(cin,nome);
			Funcionario f = oficina.getFuncionarioNome(nome);
			f.displayFuncionario();
		}catch(FuncionarioInexistente &e){
			cout << e.getNome() << " n�o � um funcion�rio.\n";
		}
		displayMenu(oficina);
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
			cout << e.getNome() << " n�o � um cliente.\n";
		}
		displayMenu(oficina);
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
			cout << e.getMatricula() << " n�o existe.\n";
		}
		displayMenu(oficina);
		break;
	}
	default:
		cout << "Op��o inv�lida. Insira outra vez." << endl;
		displayMenu(oficina);
		break;
	}
}

void Menu::modifyMenu(Oficina &oficina){
	cout << "1 - Modificar nome Cliente" << endl;
	cout <<	"2 - Modificar nome Funcionario" << endl;
}

void Menu::menu(Oficina &oficina){
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
		removeMenu(oficina);
		break;
	case 3:
		displayMenu(oficina);
		break;
	case 4:
		modifyMenu(oficina);
		break;
	default:
		cout << "Op��o inv�lida. Insira outra vez." << endl;
		menu(oficina);
		break;
	}
}
