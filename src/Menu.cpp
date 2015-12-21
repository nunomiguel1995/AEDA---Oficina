#include "Oficina.h"

using namespace std;

void menu(){
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
		addMenu();
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

void addMenu(Oficina &oficina){
	cout << "1 - Adicionar Funcionário" << endl; //
	cout <<	"2 - Adicionar Veiculo a Funcionário" << endl;
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
		break;
	case 2:
		break;
	case 3:
		oficina.criaCliente();
		break;
	case 4:
		oficina.criaVeiculoCliente();
		break;
	case 5:
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

void showaddMenu(Oficina &oficina, int opcao){
	switch(opcao){
	case 2: //adiciona veiculo a funcionario
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
		break;
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
			cout<<"Qual o nome para o Serviço Standard: ";
			cin>>nome;
			int i= oficina.isStandard(nome);
			if(i==-1){
				cout<<"Serviço Standard não oferecido pela oficina! \n";
				break;
			}
			Servico *s;
			s = oficina.getServicosStandard().at(i);
			vector <Veiculo *> veic= oficina.getVeiculos();
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
			bool continua= true;

			cout<<"Escolha um nome para o serviço: ";
			cin>>nome;
			cout<<"Qual a duração do serviço: ";
			cin>>duracao;
			cout<<"Qual o preço do serviço: ";
			cin>>preco;
			cout<<"Qual a descrição do serviço (0 para terminar): ";

			Servico *s1 = new naoStandard(nome,preco,duracao);
			vector <Veiculo *> veic= oficina.getVeiculos();
			veic[pos]->addServico(s1,true);
			oficina.setVeiculos(veic);
			cout<<"Serviço adicionado com sucesso! \n";

		}
		break;
		default:
			break;
		}
	}
	}
}
