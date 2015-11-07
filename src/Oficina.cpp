#include "Oficina.h"


using namespace std;

Oficina::Oficina(string n) : nome(n){}

Oficina::~Oficina(){
	funcionarios.erase(funcionarios.begin(),funcionarios.end());
	veiculos.erase(veiculos.begin(),veiculos.end());
	clientes.erase(clientes.begin(),clientes.end());
}

string Oficina::getNome() const{return nome;}

vector<Funcionario> Oficina::getFuncionarios() const{return funcionarios;}

void Oficina::setFuncionarios(vector<Funcionario> func){
	funcionarios = func;
}

void Oficina::setClientes(vector<Cliente> clnts){
	clientes = clnts;
}

vector<Veiculo *> Oficina::getVeiculos() const{return veiculos;}

vector<Cliente> Oficina::getClientes() const{return clientes;}

void Oficina::addFuncionario(Funcionario & f){
	for(unsigned int i=0; i<funcionarios.size();i++){
		if(funcionarios[i].getNome() == f.getNome()) throw(FuncionarioExistente(f.getNome()));
	}
	funcionarios.push_back(f);
}

void Oficina::addCliente(Cliente c){
	for(unsigned int i=0; i<clientes.size();i++){
		if(clientes[i].getNome() == c.getNome()) throw(ClienteExistente(c.getNome()));
	}
	clientes.push_back(c);
}

void Oficina::addVeiculo(Veiculo * v){
	for(unsigned int i=0; i<veiculos.size();i++){
		if(veiculos[i]->getMatricula() ==v->getMatricula()) throw(VeiculoExistente(v->getMatricula()));
	}
	veiculos.push_back(v);
}

void Oficina::removeFuncionario(Funcionario f){
	bool existe=false;
	unsigned int pos;
	for(pos=0; pos<funcionarios.size();pos++){
		if(funcionarios[pos].getNome()==f.getNome()){
			existe=true;
			funcionarios.erase(funcionarios.begin()+pos);
			break;
		}
	}

	if(!existe) throw(FuncionarioInexistente(f.getNome()));
}

void Oficina::removeCliente(Cliente c){
	bool existe=false;
	unsigned int pos;
	for(pos=0; pos<clientes.size();pos++){
		if(clientes[pos].getNome()==c.getNome()){
			existe=true;
			clientes.erase(clientes.begin()+pos);
			break;
		}
	}

	if(!existe) throw(ClienteInexistente(c.getNome()));
}

void Oficina::removeVeiculo(Veiculo *v){
	bool existe=false;
	unsigned int pos;
	for(pos = 0; pos < veiculos.size();pos++){
		if(veiculos[pos]->getMatricula()==v->getMatricula()){
			existe=true;
			break;
		}
	}
	if(!existe) throw(VeiculoInexistente(v->getMatricula()));
	veiculos.erase(veiculos.begin()+pos);
}

void Oficina::displayFuncionarios() const{
	cout << "Funcionário(s) da oficina: \n";
	for(unsigned int i = 0; i < funcionarios.size(); i++){
		cout << funcionarios[i].getNome() << endl;
	}
}

void Oficina::displayVeiculos() const{
	cout << "Veiculo(s) da oficina: \n";
	for(unsigned int i = 0; i < veiculos.size(); i++){
		cout << veiculos[i]->getMarca() << " ; " << veiculos[i]->getMatricula() << " ; " << veiculos[i]->getAno() << endl;
	}
}

void Oficina::displayClientes() const{
	cout << "Cliente(s) da oficina: \n";
	for(unsigned int i = 0; i < clientes.size(); i++){
		cout << clientes[i].getNome() << endl;
	}
}

void Oficina:: ordenaFuncionarios(){
	insertionSort(funcionarios);
}

void Oficina:: ordenaVeiculos(){
	insertionSort(veiculos);
}

void Oficina:: ordenaClientes(){
	insertionSort(clientes);
}

bool Oficina::guardaFuncionarios(){
	ofstream funcFile;
	funcFile.open("funcionarios.txt");
	for(unsigned int i = 0; i < funcionarios.size();i++){
		vector<Veiculo *> veic = funcionarios[i].getVeiculos();
		if(i!=0){funcFile << endl;}
		funcFile << veic.size() << " " << funcionarios[i].getNome();
		for(unsigned int j= 0; j < veic.size();j++){
			funcFile << " " <<  veic[j]->getMarca() << " " << veic[j]->getAno() << " " << veic[j]->getMatricula();
		}
	}
	funcFile.close();
	return true;
}

bool Oficina::guardaClientes(){
	ofstream clientFile;
	clientFile.open("clientes.txt");
	for(unsigned int i = 0; i < clientes.size();i++){
		vector<Veiculo *> veic = clientes[i].getVeiculos();
		if(i!=0){clientFile << endl;}
		clientFile << clientes[i].getId() << " " << veic.size() << " " << clientes[i].getNome() << " ";
		for(unsigned int j = 0; j < veic.size(); j++){
			clientFile << veic[j]->getMarca() << " " << veic[j]->getAno() << " " << veic[j]->getMatricula() ;
		}
	}
	clientFile.close();
	return true;
}

bool Oficina::guardaVeiculos(){
	ofstream veicFile;
	veicFile.open("veiculos.txt");
	for(unsigned int i = 0; i < veiculos.size(); i++){
		if(i!=0){veicFile << endl;}
		veicFile << veiculos[i]->getMarca() << " " << veiculos[i]->getMatricula() <<
				" " << veiculos[i]->getAno();
	}
	veicFile.close();
	return true;
}

bool Oficina::leVeiculos(){
	ifstream veicFile("veiculos.txt");
	if(veicFile.is_open()){
		string marca, matricula;
		int ano;
		while(veicFile >> marca >> matricula >> ano){
			Veiculo *v = new Veiculo(marca,matricula,ano);
			veiculos.push_back(v);
		}
		veicFile.close();
	}
	return true;
}

bool Oficina::leClientes(){
	ifstream clienteFile("clientes.txt");
	if(clienteFile.is_open()){
		unsigned int numVeiculos, ano, id;
		string primNome, ultNome, marca, matricula;
		while(clienteFile >> id >> numVeiculos >> primNome >> ultNome){
			Cliente c(primNome + " " + ultNome);
			c.setId(id);
			do{
				clienteFile >> marca >> ano >> matricula;
				Veiculo *v = new Veiculo(marca,matricula,ano);
				c.addVeiculo(v);
				numVeiculos--;
			}while(numVeiculos != 0);
			clientes.push_back(c);
		}
		clienteFile.close();
	}
	return true;
}

bool Oficina::leFuncionarios(){
	ifstream funcFile("funcionarios.txt");
	if(funcFile.is_open()){
		unsigned int numVeiculos, ano;
		string primNome, ultNome, marca, matricula;
		while(funcFile >> numVeiculos >> primNome >> ultNome){
			Funcionario f(primNome + " " + ultNome);
			do{
				funcFile >> marca >> ano >> matricula;
				Veiculo *v = new Veiculo(marca,matricula,ano);
				f.addVeiculo(v);
				numVeiculos--;
			}while(numVeiculos != 0);
			funcionarios.push_back(f);
		}
		funcFile.close();
	}
	return true;
}
