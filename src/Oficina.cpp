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

Funcionario Oficina::getFuncionarioNome(string nome) const{
	for(unsigned int i = 0; i < funcionarios.size(); i++){
		if(funcionarios[i].getNome() == nome){
			return funcionarios[i];
		}
	}
	throw FuncionarioInexistente(nome);
}

Cliente Oficina::getClienteNome(string nome) const{
	for(unsigned int i = 0; i < clientes.size(); i++){
		if(clientes[i].getNome() == nome){
			return clientes[i];
		}
	}
	throw ClienteInexistente(nome);
}
void Oficina::setFuncionarios(vector<Funcionario> func){
	funcionarios = func;
}

void Oficina::setClientes(vector<Cliente> clnts){
	clientes = clnts;
}

void Oficina:: setVeiculos(vector <Veiculo *> veic){
	veiculos=veic;
}

vector<Veiculo *> Oficina::getVeiculos() const{return veiculos;}

Veiculo * Oficina::getVeiculoMatricula(string mt) const{
	for(unsigned int i = 0; i < veiculos.size(); i++){
		if(veiculos[i]->getMatricula() == mt){
			return veiculos[i];
		}
	}
	throw VeiculoInexistente(mt);
}

vector<Funcionario> Oficina::getFuncionariosVeiculo(Veiculo *v) const{
	vector<Funcionario> f;
	for(unsigned int i = 0; i < funcionarios.size(); i++){
		for(unsigned int j = 0; j < funcionarios[i].getVeiculos().size();j++){
			if(funcionarios[i].getVeiculos()[j]->getMatricula() == v->getMatricula()){
				f.push_back(funcionarios[i]);
			}
		}
	}
	return f;
}

vector<Cliente> Oficina::getClientes() const{return clientes;}

void Oficina::addFuncionario(Funcionario & f){
	for(unsigned int i=0; i<funcionarios.size();i++){
		if(funcionarios[i].getNome() == f.getNome()) throw(FuncionarioExistente(f.getNome()));
	}
	funcionarios.push_back(f);
}

void Oficina::addCliente(Cliente &c){
	for(unsigned int i=0; i<clientes.size();i++){
		if(clientes[i].getNome() == c.getNome()) throw(ClienteExistente(c.getNome()));
	}
	clientes.push_back(c);
}

void Oficina::addVeiculoCliente(Veiculo *&v,string nome){
	for(unsigned int i = 0; i < clientes.size();i++){
		if(clientes[i].getNome() == nome){
			clientes[i].addVeiculo(v);
		}
	}
}

void Oficina::addVeiculoFuncionario(Veiculo *&v, string nome){
	for(unsigned int i = 0; i < funcionarios.size(); i++){
		if(funcionarios[i].getNome() == nome){
			funcionarios[i].addVeiculo(v);
		}
	}
}

void Oficina::addVeiculo(Veiculo *&v){
	for(unsigned int i=0; i<veiculos.size();i++){
		if(veiculos[i]->getMatricula() ==v->getMatricula()) throw(VeiculoExistente(v->getMatricula()));
	}
	veiculos.push_back(v);
}

void Oficina::removeFuncionario(Funcionario & f){

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

void Oficina::removeVeiculoFuncionario(Veiculo *&v, string nome){
	bool existeF = false, existeV = false;
	for(unsigned int i = 0; i < funcionarios.size(); i++){
		if(funcionarios[i].getNome() == nome){
			existeF = true;
			vector<Veiculo *> veic = funcionarios[i].getVeiculos();
			for(unsigned int j = 0; j < veic.size(); j++){
				if(veic[j]->getMatricula() == v->getMatricula()){
					existeV = true;
					funcionarios[i].removeVeiculo(v);
					break;
				}
			}
		}
	}
	if(!existeF) throw (FuncionarioInexistente(nome));
	if(!existeV) throw (VeiculoInexistente(v->getMatricula()));
}

void Oficina::removeCliente(Cliente &c){
	bool existe=false;
	unsigned int pos;
	for(pos=0; pos<clientes.size();pos++){
		if(clientes[pos].getNome()==c.getNome()){
			existe=true;
			vector<Veiculo *> v = clientes[pos].getVeiculos();
			clientes.erase(clientes.begin()+pos);
			for(unsigned int i = 0; i < funcionarios.size(); i++){
				for(unsigned int j = 0; j < v.size(); j++){
					removeVeiculoFuncionario(v[j],funcionarios[i].getNome());
					removeVeiculo(v[j]);
				}
			}
			break;
		}
	}

	if(!existe) throw(ClienteInexistente(c.getNome()));
}

void Oficina::removeVeiculoCliente(Veiculo *&v, string nome){
	bool existeC = false, existeV = false;
	for(unsigned int i = 0; i < clientes.size(); i++){
		if(clientes[i].getNome() == nome){
			existeC = true;
			for(unsigned int j = 0; j < clientes[i].getVeiculos().size(); j++){
				if(clientes[i].getVeiculos()[j]->getMatricula() == v->getMatricula()){
					existeV = true;
					vector<Veiculo *> veic = clientes[i].getVeiculos();
					veic.erase(veic.begin() + j);
					clientes[i].setVeiculos(veic);
					break;
				}
			}
		}
	}
	if(!existeC) throw (ClienteInexistente(nome));
	if(!existeV) throw (VeiculoInexistente(v->getMatricula()));
}

void Oficina::removeVeiculo(Veiculo *&v){
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

bool Oficina::leVeiculos(){
	ifstream veicFile;
	veicFile.open("veiculos.txt",ifstream::in);
	if(veicFile.is_open()){
		string marca, matricula, tipo;
		int ano;
		while(veicFile >> tipo >> marca >> matricula >> ano){
			if(tipo == "m"){
				Veiculo *m = new Motorizada(marca,matricula,ano);
				try{
					addVeiculo(m);
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " já é um veículo existente.\n";
				}
			}else if(tipo == "c"){
				Veiculo *c = new Camiao(marca,matricula,ano);
				try{
					addVeiculo(c);
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " já é um veículo existente.\n";
				}
			}else if(tipo == "at"){
				Veiculo *at = new Autocarro(marca,matricula,ano);
				try{
					addVeiculo(at);
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " já é um veículo existente.\n";
				}
			}else if(tipo == "am"){
				Veiculo *am = new Automovel(marca,matricula,ano);
				try{
					addVeiculo(am);
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " já é um veículo existente.\n";
				}
			}
		}
		veicFile.close();
	}
	return true;
}

bool Oficina::guardaVeiculos(){
	ofstream veicFile;
	veicFile.open("veiculos.txt");
	for(unsigned int i = 0; i < veiculos.size(); i++){
		string tipo;
		if(i!=0){veicFile << endl;}
		if(veiculos[i]->classname() == "Motorizada"){
			tipo = "m";
		}else if(veiculos[i]->classname() == "Camiao"){
			tipo = "c";
		}else if(veiculos[i]->classname() == "Autocarro"){
			tipo = "ac";
		}else if(veiculos[i]->classname() == "Automovel"){
			tipo = "am";
		}
		veicFile << tipo << " " << veiculos[i]->getMarca() << " " << veiculos[i]->getMatricula() <<
				" " << veiculos[i]->getAno();
	}
	veicFile.close();
	return true;
}

bool Oficina::leClientes(){
	ifstream clienteFile;
	clienteFile.open("clientes.txt",ifstream::in);
	if(clienteFile.is_open()){
		unsigned int numVeiculos, ano, id;
		string primNome, ultNome, marca, matricula, tipo;
		while(clienteFile >> id >> numVeiculos >> primNome >> ultNome){
			Cliente cl(primNome + " " + ultNome);
			cl.setId(id);
			while(numVeiculos != 0){
				clienteFile >> tipo >> marca >> ano >> matricula;
				if(tipo == "m"){
					Motorizada *m = new Motorizada(marca,matricula,ano);
					try{
						cl.addVeiculo(m);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " já é um veículo existente.\n";
					}
				}else if(tipo == "c"){
					Camiao *c = new Camiao(marca,matricula,ano);
					try{
						cl.addVeiculo(c);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " já é um veículo existente.\n";
					}
				}else if(tipo == "at"){
					Autocarro *at = new Autocarro(marca,matricula,ano);
					try{
						cl.addVeiculo(at);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " já é um veículo existente.\n";
					}
				}else if(tipo == "am"){
					Automovel *am = new Automovel(marca,matricula,ano);
					try{
						cl.addVeiculo(am);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " já é um veículo existente.\n";
					}
				}
				numVeiculos--;
			}
			clientes.push_back(cl);
		}
		clienteFile.close();
	}
	return true;
}

bool Oficina::guardaClientes(){
	ofstream clientFile;
	clientFile.open("clientes.txt");
	for(unsigned int i = 0; i < clientes.size();i++){
		vector<Veiculo *> veic = clientes[i].getVeiculos();
		if(i!=0){clientFile << endl;}
		clientFile << clientes[i].getId() << " " << veic.size() << " " << clientes[i].getNome();
		for(unsigned int j = 0; j < veic.size(); j++){
			string tipo;
			if(veiculos[i]->classname() == "Motorizada"){
				tipo = "m";
			}else if(veiculos[i]->classname() == "Camiao"){
				tipo = "c";
			}else if(veiculos[i]->classname() == "Autocarro"){
				tipo = "ac";
			}else if(veiculos[i]->classname() == "Automovel"){
				tipo = "am";
			}
			clientFile << " " << tipo << " " << veic[j]->getMarca() << " " << veic[j]->getAno() << " " << veic[j]->getMatricula() ;
		}
	}
	clientFile.close();
	return true;
}

bool Oficina::leFuncionarios(){
	ifstream funcFile;
	funcFile.open("funcionarios.txt",ifstream::in);
	if(funcFile.is_open()){
		unsigned int numVeiculos, ano;
		string primNome, ultNome, marca, matricula, tipo;
		while(funcFile >> numVeiculos >> primNome >> ultNome){
			Funcionario f(primNome + " " + ultNome);
			while(numVeiculos != 0){
				funcFile >> tipo >> marca >> ano >> matricula;
				if(tipo == "m"){
					Motorizada *m = new Motorizada(marca,matricula,ano);
					try{
						f.addVeiculo(m);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " já é um veículo existente.\n";
					}
				}else if(tipo == "c"){
					Camiao *c = new Camiao(marca,matricula,ano);
					try{
						f.addVeiculo(c);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " já é um veículo existente.\n";
					}
				}else if(tipo == "at"){
					Autocarro *at = new Autocarro(marca,matricula,ano);
					try{
						f.addVeiculo(at);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " já é um veículo existente.\n";
					}
				}else if(tipo == "am"){
					Automovel *am = new Automovel(marca,matricula,ano);
					try{
						f.addVeiculo(am);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " já é um veículo existente.\n";
					}
				}
				numVeiculos--;
			}
			funcionarios.push_back(f);
		}
		funcFile.close();
	}
	return true;
}

bool Oficina::guardaFuncionarios(){
	ofstream funcFile;
	funcFile.open("funcionarios.txt");
	for(unsigned int i = 0; i < funcionarios.size();i++){
		vector<Veiculo *> veic = funcionarios[i].getVeiculos();
		if(i!=0){funcFile << endl;}
		funcFile << veic.size() << " " << funcionarios[i].getNome();
		for(unsigned int j= 0; j < veic.size();j++){
			string tipo;
			if(veiculos[i]->classname() == "Motorizada"){
				tipo = "m";
			}else if(veiculos[i]->classname() == "Camiao"){
				tipo = "c";
			}else if(veiculos[i]->classname() == "Autocarro"){
				tipo = "ac";
			}else if(veiculos[i]->classname() == "Automovel"){
				tipo = "am";
			}
			funcFile << " " << tipo << " " <<  veic[j]->getMarca() << " " << veic[j]->getAno() << " " << veic[j]->getMatricula();
		}
	}
	funcFile.close();
	return true;
}

int Oficina:: posVeiculo(string mt){

	for(unsigned int i=0; i< veiculos.size();i++){
		if(veiculos[i]->getMatricula() == mt) return i;
	}

	return -1;
}
