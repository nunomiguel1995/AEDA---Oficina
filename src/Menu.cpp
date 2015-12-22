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
	case 1:{
		string nomeF;
		cin.sync();
		cout << "Nome do funcionário: ";
		getline(cin,nomeF);
		Funcionario f(nomeF);
		try{
			oficina.addFuncionario(f);
		}catch(FuncionarioExistente &e){
			cout << e.getNome() << " já é um funcionário.\n";
		}
	}
	oficina.guardaFuncionarios();
	addMenu(oficina);
	break;
	case 2:{
		string matricula, nome;
		cin.sync();
		cout << "Insira o nome do funcionário: ";
		getline(cin,nome);
		try{
			oficina.getFuncionarioNome(nome);
		}catch(FuncionarioInexistente &e){
			cout << e.getNome() << " não é um funcionário.\n";
		}
		cout << "Insira a matrícula do veículo: ";
		cin >> matricula;
		try{
			Veiculo *v = oficina.getVeiculoMatricula(matricula);
			oficina.addVeiculoFuncionario(v,nome);
		}catch(VeiculoInexistente &e){
			cout << e.getMatricula() << " não existe.\n";
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
			cout << e.getNome() << " já é um cliente.\n";
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
			}else if(tipo == "Camião" || tipo == "Camiao"){
				Veiculo *c = new Camiao(marca,matricula,ano);
				oficina.addVeiculo(c);
				oficina.addVeiculoCliente(c,nome);
			}else if(tipo == "Autocarro"){
				Veiculo *at = new Autocarro(marca,matricula,ano);
				oficina.addVeiculo(at);
				oficina.addVeiculoCliente(at,nome);
			}else if(tipo == "Automóvel" || tipo == "Automovel"){
				Veiculo *am = new Automovel(marca,matricula,ano);
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
			cout<<"Veiculo não existe na Oficina! \n";
			return;
		}

		int tiposervico;
		cout<<"Que tipo de serviço deseja adicionar? \n"<<"1 Standard \n"<<"2 Não Standard\n "<<"Opcção: ";
		cin>>tiposervico;

		switch(tiposervico){
		case 1:
		{
			string nome;
			cout << "Qual o nome para o Serviço Standard: ";
			cin >> nome;

			int i = oficina.isStandard(nome);

			if(i == -1){
				cout << "Serviço Standard não oferecido pela oficina!\n";
				break;
			}

			Servico *s = oficina.getServicosStandard().at(i);
			vector <Veiculo *> veic = oficina.getVeiculos();
			veic[pos]->addServico(s,true);
			oficina.setVeiculos(veic);
			cout<<"Serviço adicionado com sucesso! \n";
			break;
		}
		case 2:
		{
			string nome;
			int duracao;
			float preco;
			vector <string> descricao;

			cout<<"Escolha um nome para o serviço: ";
			cin>>nome;
			cout<<"Qual a duração do serviço: ";
			cin>>duracao;
			cout<<"Qual o preço do serviço: ";
			cin>>preco;

			int ano,mes,dia,hora,minutos;
			cout << "Data para agendamento" << endl;
			cout << "Ano: ";
			cin >> ano;
			cout << "Mês: ";
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
			cout<<"Serviço adicionado com sucesso! \n";
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
		oficina.guardaFuncionarios();
		removeMenu(oficina);
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
			cout << e.getNome() << " não é um cliente.\n";
		}catch(VeiculoInexistente &e){
			cout << e.getMatricula() << " não existe.\n";
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
		oficina.guardaFuncionarios();
		removeMenu(oficina);
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
		displayMenu(oficina);
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
			cout << e.getNome() << " não é um cliente.\n";
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
			cout << e.getMatricula() << " não existe.\n";
		}
		displayMenu(oficina);
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
