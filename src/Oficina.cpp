#include "Oficina.h"


using namespace std;

/**
 * Construtor da Oficina
 * @param n nome da oficina
 */
Oficina::Oficina(string n) : nome(n){}

/**
 * Destrutor da classe Oficina
 */
Oficina::~Oficina(){
	funcionarios.erase(funcionarios.begin(),funcionarios.end());
	veiculos.erase(veiculos.begin(),veiculos.end());
	clientes.erase(clientes.begin(),clientes.end());
}

/**
 * Retirna o nome da Oficina
 */
string Oficina::getNome() const{return nome;}

/**
 * Retorna os funcionários da Oficina
 */
vector<Funcionario> Oficina::getFuncionarios() const{return funcionarios;}

/**
 * Retorna um Funcionário com o nome passado como parametro
 * @param nome nome do Funcionário a procurar
 */
Funcionario Oficina::getFuncionarioNome(string nome) const{
	for(unsigned int i = 0; i < funcionarios.size(); i++){
		if(funcionarios[i].getNome() == nome){
			return funcionarios[i];
		}
	}
	throw FuncionarioInexistente(nome);
}

/**
 * Retorna o Cliente com nome passado como parametro
 * @param nome nome do Cliente a procurar
 */
Cliente Oficina::getClienteNome(string nome) const{
	for(unsigned int i = 0; i < clientes.size(); i++){
		if(clientes[i].getNome() == nome){
			return clientes[i];
		}
	}
	throw ClienteInexistente(nome);
}

/*
 * Atribui ao vetor funcionarios o vetor passado como parametro
 * @param func
 */
void Oficina::setFuncionarios(vector<Funcionario> func){
	funcionarios = func;
}

/*
 * Atribui ao vetor clientes o vetor passado como parametro
 * @param clnts
 */
void Oficina::setClientes(vector<Cliente> clnts){
	clientes = clnts;
}

/*
 * Atribui ao vetor veiculos o vetor passado como parametro
 * @param veic
 */
void Oficina:: setVeiculos(vector <Veiculo *> veic){
	veiculos=veic;
}

/*
 * Atribui ao vetor servicosStandard o vetor passado como parametro
 * @param stand
 */
void Oficina:: setServicosStandard(vector <Standard *> stand){
	servicosStandard= stand;
}

/**
 * Retorna o vetor veiculos
 */
vector<Veiculo *> Oficina::getVeiculos() const{return veiculos;}

/**
 * Retorna o Veiculo com a matricula passada como parametro
 * @param mt matricula do veiculo a procurar
 */
Veiculo * Oficina::getVeiculoMatricula(string mt) const{
	for(unsigned int i = 0; i < veiculos.size(); i++){
		if(veiculos[i]->getMatricula() == mt){
			return veiculos[i];
		}
	}
	throw VeiculoInexistente(mt);
}

/**
 * Retorna os Funcionários responsável pelo Veiculo passado como parametro
 * @param v
 */
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

/**
 * Retorna os clientes da Oficina
 */
vector<Cliente> Oficina::getClientes() const{return clientes;}

void Oficina::addFuncionario(Funcionario & f){
	for(unsigned int i=0; i<funcionarios.size();i++){
		if(funcionarios[i].getNome() == f.getNome()) throw(FuncionarioExistente(f.getNome()));
	}
	funcionarios.push_back(f);
}

/**
 * Retorna os serviços standard oferecidos pela Oficina
 */
vector <Standard *> Oficina:: getServicosStandard() const{
	return servicosStandard;
}

/**
 * Adiciona um cliente; lança uma excepção caso esse cliente já exista
 * @param c cliente a adicionar
 */
void Oficina::addCliente(Cliente &c){
	for(unsigned int i=0; i<clientes.size();i++){
		if(clientes[i].getNome() == c.getNome()) throw(ClienteExistente(c.getNome()));
	}
	clientes.push_back(c);
}

/**
 * Adiciona um Veiculo a um cliente
 * @param v veiculo a adicionar
 * @param nome nome do Cliente a adicionar o veiculo
 */
void Oficina::addVeiculoCliente(Veiculo *&v,string nome){
	for(unsigned int i = 0; i < clientes.size();i++){
		if(clientes[i].getNome() == nome){
			clientes[i].addVeiculo(v);
		}
	}
}

/**
 * Adiciona um Veiculo a um funcionario
 * @param v veiculo
 * @param nome nome do Funcionario
 */
void Oficina::addVeiculoFuncionario(Veiculo *&v, string nome){
	for(unsigned int i = 0; i < funcionarios.size(); i++){
		if(funcionarios[i].getNome() == nome){
			funcionarios[i].addVeiculo(v);
		}
	}
}

/**
 * Adiciona veiculo ao vetor veiculos da oficina
 * @param v veiculo a adicionar
 */
void Oficina::addVeiculo(Veiculo *&v){
	for(unsigned int i=0; i<veiculos.size();i++){
		if(veiculos[i]->getMatricula() ==v->getMatricula()) throw(VeiculoExistente(v->getMatricula()));
	}
	veiculos.push_back(v);
}

/**
 * Adiciona serviço standar à Oficina
 * @param s serviço stantard a adicionar
 */
void Oficina:: addServicoStandard(Standard *s){
	bool existe= false;
	string nome= s->getNome();
	for(unsigned int i=0; i< servicosStandard.size(); i++){
		if(servicosStandard[i]->getNome()==s->getNome()){
			existe=true;
			break;
		}
	}

	if(existe== true) throw (ServicoExistente(nome));

	servicosStandard.push_back(s);
	}


/**
 * Remove Funcionario fa oficina, lança exepção caso não exista
 * @param f
 */
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

/**
 * Remove um Veiculo de Funcionario
 * @param v
 * @param nome
 */
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

/**
 * Remove um cliente da oficina
 */
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

/**
 * Remove um veiculo de um cliente, lança excepção caso o cliente ou veiculo não existam
 *  @param v
 *  @param nome
 */
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

/**
 * Remove veiculo da oficina, lança excepção caso não exista
 */
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

/**
 * Remove um serviço standard da oficina, lança excepção caso não exista
 */
void Oficina:: removeServicoStandard(Standard *s){
	bool existe= false;
	string nome= s->getNome();
	unsigned int i;

	for(i=0; i<servicosStandard.size();i++){
		if(servicosStandard[i]->getNome()==nome){
			existe=true;
		}
	}

	if(existe==false) throw(ServicoInexistente(nome));

	servicosStandard.erase(servicosStandard.begin()+i);
}

/**
 * Mostra os funcionários da Oficina
 */
void Oficina::displayFuncionarios() const{
	cout << "Funcionário(s) da oficina: \n";
	for(unsigned int i = 0; i < funcionarios.size(); i++){
		cout << funcionarios[i].getNome() << endl;
	}
}

/**
 * Mostra os veiculos da Oficina
 */
void Oficina::displayVeiculos() const{
	cout << "Veiculo(s) da oficina: \n";
	for(unsigned int i = 0; i < veiculos.size(); i++){
		cout << veiculos[i]->getMarca() << " ; " << veiculos[i]->getMatricula() << " ; " << veiculos[i]->getAno() << endl;
	}
}

/**
 * Mostra os clientes da Oficina
 */
void Oficina::displayClientes() const{
	cout << "Cliente(s) da oficina: \n";
	for(unsigned int i = 0; i < clientes.size(); i++){
		cout << clientes[i].getNome() << endl;
	}
}

/**
 * Mostra os serviços standard da Oficina
 */
void Oficina:: displayServicosStandard() {
	for(unsigned int i=0; i< servicosStandard.size();i++){
		string n = servicosStandard[i]->getNome();
		float preco= servicosStandard[i]->getPreco();
		int duracao= servicosStandard[i]->getDuracao();

		cout<<"nome: "<<nome<<"preco: "<<preco<<"duração: "<<duracao << endl;
	}
}

/**
 * Ordena os funcionários da oficina por número crescente de veiculos a ele associado
 */
void Oficina:: ordenaFuncionarios(){
	insertionSort(funcionarios);
}

/**
 * Ordena os veiculos por ordem crecente de ano
 */
void Oficina:: ordenaVeiculos(){
	insertionSort(veiculos);
}

/**
 * Ordena os clientes por ordem crescente de veiculos
 */
void Oficina:: ordenaClientes(){
	insertionSort(clientes);
}

/**
 * Lê veiculos de um ficheiro de texto e guarda-os na Oficina
 */
bool Oficina::leVeiculos(){
	ifstream veicFile;
	veicFile.open("veiculos.txt",ifstream::in);
	if(veicFile.is_open()){
		string marca, matricula, tipo, nome ,tipoServ;
		float preco;
		int ano, duracao;
		while(veicFile >> tipo >> marca >> matricula >> ano){
			if(tipo == "m"){
				Veiculo *m = new Motorizada(marca,matricula,ano);
				try{
					addVeiculo(m);
					while(veicFile >> tipoServ >> nome >> preco >> duracao){
						if(tipoServ == "s"){
							Servico *s = new Standard(nome,preco,duracao);
							m->addServico(s,false);
						}else if(tipoServ == "ns"){
							Servico *s = new naoStandard(nome,preco,duracao);
							m->addServico(s,false);
						}
					}
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " já é um veículo existente.\n";
				}
			}else if(tipo == "c"){
				Veiculo *c = new Camiao(marca,matricula,ano);
				try{
					addVeiculo(c);
					while(veicFile >> tipoServ >> nome >> preco >> duracao){
						if(tipoServ == "s"){
							Servico *s = new Standard(nome,preco,duracao);
							c->addServico(s,false);
						}else if(tipoServ == "ns"){
							Servico *s = new naoStandard(nome,preco,duracao);
							c->addServico(s,false);
						}
					}
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " já é um veículo existente.\n";
				}
			}else if(tipo == "at"){
				Veiculo *at = new Autocarro(marca,matricula,ano);
				try{
					addVeiculo(at);
					while(veicFile >> tipoServ >> nome >> preco >> duracao){
						if(tipoServ == "s"){
							Servico *s = new Standard(nome,preco,duracao);
							at->addServico(s,false);
						}else if(tipoServ == "ns"){
							Servico *s = new naoStandard(nome,preco,duracao);
							at->addServico(s,false);
						}
					}
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " já é um veículo existente.\n";
				}
			}else if(tipo == "am"){
				Veiculo *am = new Automovel(marca,matricula,ano);
				try{
					addVeiculo(am);
					while(veicFile >> tipoServ >> nome >> preco >> duracao){
						if(tipoServ == "s"){
							Servico *s = new Standard(nome,preco,duracao);
							am->addServico(s,false);
						}else if(tipoServ == "ns"){
							Servico *s = new naoStandard(nome,preco,duracao);
							am->addServico(s,false);
						}
					}
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " já é um veículo existente.\n";
				}
			}
		}
		veicFile.close();
	}
	return true;
}

/**
 * Guarda os veiculos num ficheiro de texto
 */
bool Oficina::guardaVeiculos(){
	ofstream veicFile;
	veicFile.open("veiculos.txt");
	for(unsigned int i = 0; i < veiculos.size(); i++){
		string tipo, tipoServ;
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
		for(unsigned int j = 0; j < veiculos[i]->getServicos().size(); j++){
			if(veiculos[i]->getServicos()[j]->classname() == "Standard"){
				tipoServ = "s";
				vector<Servico *> serv = veiculos[i]->getServicos();
				if(j!=0){veicFile << endl;}
				veicFile << " " << tipoServ << " " << serv[j]->getNome() << " " << serv[j]->getPreco() << " " << serv[j]->getDuracao();
			}else if(veiculos[i]->getServicos()[j]->classname() == "naoStandard"){
				tipoServ = "ns";
				vector<Servico *> serv= veiculos[i]->getServicos();
				if(j!=0){veicFile << endl;}
				veicFile << " " << tipoServ << " " << serv[j]->getNome() << " " << serv[j]->getPreco() << " " << serv[j]->getDuracao();
			}
		}
	}
	veicFile.close();
	return true;
}

/**
 * Lê clientes de um ficheiro de texto e guarda-os na Oficina
 */
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

/**
 * Guarda os clintes num ficheiro de texto
 */
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

/**
 * Lê funcionários de um ficheiro de texto e guarda-os na Oficina
 */
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

/**
 * Guarda os funcionários num ficheiro de texto
 */
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

/**
 * Lê serviços de um ficheiro de texto e guarda-os na Oficina
 */
bool Oficina::leServicos(){
	ifstream servFile;
	servFile.open("standard.txt",ifstream::in);
	if(servFile.is_open()){
		string n;
		float preco;
		int duracao;
		while(servFile >> n >> preco >> duracao){
			Standard *s = new Standard(n,preco,duracao);
			addServicoStandard(s);
		}
		servFile.close();
	}
	return true;
}

/**
 * Guarda os serviços standard num ficheiro de texto
 */
bool Oficina::guardaServicos(){
	ofstream servFile;
	servFile.open("standard.txt");
	for(unsigned int i = 0; i < servicosStandard.size(); i++){
		if(i!=0){servFile << endl;}
		servFile << servicosStandard[i]->getNome() << " " << servicosStandard[i]->getPreco() << " "
				<< servicosStandard[i]->getDuracao();
	}
	servFile.close();
	return true;
}

/**
 * Retorna a posição de um veiculo no vetor veiculos; retorna -1 caso não exista
 * @param mt matricula do veiculo a procurar
 */
int Oficina:: posVeiculo(string mt){

	for(unsigned int i=0; i< veiculos.size();i++){
		if(veiculos[i]->getMatricula() == mt) return i;
	}

	return -1;
}

/**
 * Retorna a posição de um serviço standard no vetor veiculos; retorna -1 caso não exista
 * @param nome nome do serviço a procurar
 */
int Oficina:: isStandard(string nome){
	for(unsigned int i=0; i< servicosStandard.size();i++){
			if(servicosStandard[i]->getNome() == nome) return i;
		}

		return -1;
}
