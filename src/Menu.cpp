#include "Oficina.h"

using namespace std;

void menu(){
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
		cout << "Op��o inv�lida. Insira outra vez." << endl;
		break;
	}
}

void addMenu(Oficina &oficina){
	cout << "1 - Adicionar Funcion�rio" << endl; //
	cout <<	"2 - Adicionar Veiculo a Funcion�rio" << endl;
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

void showaddMenu(Oficina &oficina, int opcao){
	switch(opcao){
	case 2: //adiciona veiculo a funcionario
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
		break;
	break;
	case 5: //adicionar servi�o a ve�culo
	{
		string matricula;
		cout<<"Insira a matricula do Veiculo: ";
		cin>>matricula;

		int pos= oficina.posVeiculo(matricula);
		if(pos==-1){
			cout<<"Veiculo n�o existe na Oficina! \n";
			break;
		}

		int tiposervico;
		cout<<"Que tipo de servi�o deseja adicionar? \n"<<"1 Standard \n"<<"2 N�o Standard\n "<<"Opc��o: ";
		cin>>tiposervico;

		switch(tiposervico){
		case 1:
		{

			string nome;
			cout<<"Qual o nome para o Servi�o Standard: ";
			cin>>nome;
			int i= oficina.isStandard(nome);
			if(i==-1){
				cout<<"Servi�o Standard n�o oferecido pela oficina! \n";
				break;
			}
			Servico *s;
			s = oficina.getServicosStandard().at(i);
			vector <Veiculo *> veic= oficina.getVeiculos();
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
			bool continua= true;

			cout<<"Escolha um nome para o servi�o: ";
			cin>>nome;
			cout<<"Qual a dura��o do servi�o: ";
			cin>>duracao;
			cout<<"Qual o pre�o do servi�o: ";
			cin>>preco;
			cout<<"Qual a descri��o do servi�o (0 para terminar): ";

			Servico *s1 = new naoStandard(nome,preco,duracao);
			vector <Veiculo *> veic= oficina.getVeiculos();
			veic[pos]->addServico(s1,true);
			oficina.setVeiculos(veic);
			cout<<"Servi�o adicionado com sucesso! \n";

		}
		break;
		default:
			break;
		}
	}
	}
}
