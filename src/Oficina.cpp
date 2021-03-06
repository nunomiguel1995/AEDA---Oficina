#include "Oficina.h"



using namespace std;

/**
 * Construtor da Oficina
 * @param n nome da oficina
 */
Oficina::Oficina(string n) : nome(n),arvoreServicos(new Servico("",0,0,Date(0,0,0,0,0))){}

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
 * Retorna os funcionarios da Oficina
 */
vector<Funcionario> Oficina::getFuncionarios() const{return funcionarios;}

/**
 * Retorna um Funcionario com o nome passado como parametro
 * @param nome nome do Funcionario a procurar
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
 * Retorna os Funcionarios responsavel pelo Veiculo passado como parametro
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
 * Retorna os servicos standard oferecidos pela Oficina
 */
vector <Standard *> Oficina:: getServicosStandard() const{
	return servicosStandard;
}

/**
 * Adiciona um cliente; lanca uma excepcao caso esse cliente ja exista
 * @param c cliente a adicionar
 */
void Oficina::addCliente(Cliente &c){
	for(unsigned int i = 0; i < clientes.size(); i++){
		if(clientes[i].getNome() == c.getNome()) throw(ClienteExistente(c.getNome()));
	}
	clientes.push_back(c);
	maisPontos.push(c);
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
		if(veiculos[i]->getMatricula() == v->getMatricula()) throw(VeiculoExistente(v->getMatricula()));
	}
	veiculos.push_back(v);
}

/**
 * Adiciona servi�o standard a Oficina
 * @param s servi�o stantard a adicionar
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
 * Remove Funcionario da oficina, lan�a exep��o caso nao exista
 * @param f
 */
void Oficina::removeFuncionario(Funcionario & f){
	bool existe=false;
	unsigned int pos;

	for(pos=0; pos<funcionarios.size();pos++){
		if(funcionarios[pos].getNome() == f.getNome()){
			existe = true;
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
 * Remove um veiculo de um cliente, lan�a excep��o caso o cliente ou veiculo nao existam
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
 * Remove veiculo da oficina, lanca excep�ao caso nao exista
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
 * Remove um servico standard da oficina, lan�a excepcao caso nao exista
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
 * Mostra os funcionarios da Oficina
 */
void Oficina::displayFuncionarios() const{
	cout << "Funcion�rio(s) da oficina: \n";
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
 * Mostra os servi�os standard da Oficina
 */
void Oficina:: displayServicosStandard() {
	for(unsigned int i=0; i< servicosStandard.size();i++){
		string n = servicosStandard[i]->getNome();
		float preco= servicosStandard[i]->getPreco();
		int duracao= servicosStandard[i]->getDuracao();

		cout<<"nome: "<<nome<<"preco: "<<preco<<"dura��o: "<<duracao << endl;
	}
}

/**
 * Ordena os funcionarios da oficina por numero crescente de veiculos a ele associado
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

void Oficina::adicionaServicoArvore(Servico *s){
	arvoreServicos.insert(s);
}

/**
 * Le veiculos de um ficheiro de texto e guarda-os na Oficina
 */
bool Oficina::leVeiculos(){
	ifstream veicFile;
	veicFile.open("veiculos.txt",ifstream::in);
	if(veicFile.is_open()){
		string marca, matricula, tipo, nome ,tipoServ;
		float preco;
		int ano, duracao, anoD,mesD,diaD,horaD,minutoD;
		while(veicFile >> tipo >> marca >> matricula >> ano){
			if(tipo == "m"){
				Veiculo *m = new Motorizada(marca,matricula,ano);
				try{
					addVeiculo(m);
					while(veicFile >> tipoServ >> nome >> preco >> duracao >> anoD >> mesD >> diaD >> horaD >> minutoD){
						Date d(anoD,mesD,diaD,horaD,minutoD);
						if(tipoServ == "s"){
							Servico *s = new Standard(nome,preco,duracao,d);
							m->addServico(s,false);
						}else if(tipoServ == "ns"){
							Servico *s = new naoStandard(nome,preco,duracao,d);
							m->addServico(s,false);
						}
					}
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " j� � um ve�culo existente.\n";
				}
			}else if(tipo == "c"){
				Veiculo *c = new Camiao(marca,matricula,ano);
				try{
					addVeiculo(c);
					while(veicFile >> tipoServ >> nome >> preco >> duracao >> anoD >> mesD >> diaD >> horaD >> minutoD){
						Date d(anoD,mesD,diaD,horaD,minutoD);
						if(tipoServ == "s"){
							Servico *s = new Standard(nome,preco,duracao,d);
							c->addServico(s,false);
						}else if(tipoServ == "ns"){
							Servico *s = new naoStandard(nome,preco,duracao,d);
							c->addServico(s,false);
						}
					}
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " j� � um ve�culo existente.\n";
				}
			}else if(tipo == "at"){
				Veiculo *at = new Autocarro(marca,matricula,ano);
				try{
					addVeiculo(at);
					while(veicFile >> tipoServ >> nome >> preco >> duracao >> anoD >> mesD >> diaD >> horaD >> minutoD){
						Date d(anoD,mesD,diaD,horaD,minutoD);
						if(tipoServ == "s"){
							Servico *s = new Standard(nome,preco,duracao,d);
							at->addServico(s,false);
						}else if(tipoServ == "ns"){
							Servico *s = new naoStandard(nome,preco,duracao,d);
							at->addServico(s,false);
						}
					}
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " j� � um ve�culo existente.\n";
				}
			}else if(tipo == "am"){
				Veiculo *am = new Automovel(marca,matricula,ano);
				try{
					addVeiculo(am);
					while(veicFile >> tipoServ >> nome >> preco >> duracao >> anoD >> mesD >> diaD >> horaD >> minutoD){
						Date d(anoD,mesD,diaD,horaD,minutoD);
						if(tipoServ == "s"){
							Servico *s = new Standard(nome,preco,duracao,d);
							am->addServico(s,false);
						}else if(tipoServ == "ns"){
							Servico *s = new naoStandard(nome,preco,duracao,d);
							am->addServico(s,false);
						}
					}
				}catch(VeiculoExistente &e){
					cout << e.getMatricula() << " j� � um ve�culo existente.\n";
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
				veicFile << " " << tipoServ << " " << serv[j]->getNome() << " " << serv[j]->getPreco() << " " << serv[j]->getDuracao() << " ";
				veicFile << serv[j]->getDate().getAno() << " " << serv[j]->getDate().getMes() << " " << serv[j]->getDate().getDia() << " "
						<< serv[j]->getDate().getHora() << " " << serv[j]->getDate().getMinutos();
			}else if(veiculos[i]->getServicos()[j]->classname() == "naoStandard"){
				tipoServ = "ns";
				vector<Servico *> serv= veiculos[i]->getServicos();
				if(j!=0){veicFile << endl;}
				veicFile << " " << tipoServ << " " << serv[j]->getNome() << " " << serv[j]->getPreco() << " " << serv[j]->getDuracao() << " ";
				veicFile << serv[j]->getDate().getAno() << " " << serv[j]->getDate().getMes() << " " << serv[j]->getDate().getDia() << " "
						<< serv[j]->getDate().getHora() << " " << serv[j]->getDate().getMinutos();
			}
		}
	}
	veicFile.close();
	return true;
}

/**
 * Le clientes de um ficheiro de texto e guarda-os na Oficina
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
						cout << e.getMatricula() << " j� � um ve�culo existente.\n";
					}
				}else if(tipo == "c"){
					Camiao *c = new Camiao(marca,matricula,ano);
					try{
						cl.addVeiculo(c);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " j� � um ve�culo existente.\n";
					}
				}else if(tipo == "at"){
					Autocarro *at = new Autocarro(marca,matricula,ano);
					try{
						cl.addVeiculo(at);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " j� � um ve�culo existente.\n";
					}
				}else if(tipo == "am"){
					Automovel *am = new Automovel(marca,matricula,ano);
					try{
						cl.addVeiculo(am);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " j� � um ve�culo existente.\n";
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
 * Le funcionarios de um ficheiro de texto e guarda-os na Oficina
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
						cout << e.getMatricula() << " j� � um ve�culo existente.\n";
					}
				}else if(tipo == "c"){
					Camiao *c = new Camiao(marca,matricula,ano);
					try{
						f.addVeiculo(c);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " j� � um ve�culo existente.\n";
					}
				}else if(tipo == "at"){
					Autocarro *at = new Autocarro(marca,matricula,ano);
					try{
						f.addVeiculo(at);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " j� � um ve�culo existente.\n";
					}
				}else if(tipo == "am"){
					Automovel *am = new Automovel(marca,matricula,ano);
					try{
						f.addVeiculo(am);
					}catch(VeiculoExistente &e){
						cout << e.getMatricula() << " j� � um ve�culo existente.\n";
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
 * Guarda os funcionarios num ficheiro de texto
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
 * Le servi�os de um ficheiro de texto e guarda-os na Oficina
 */
bool Oficina::leServicos(){
	ifstream servFile;
	servFile.open("standard.txt",ifstream::in);
	if(servFile.is_open()){
		string n, lixo;
		float preco;
		int duracao;
		while(servFile >> n >> preco >> duracao){
			Date d;
			Standard *s = new Standard(n,preco,duracao,d);
			addServicoStandard(s);
		}
		servFile.close();
	}
	return true;
}

/**
 * Guarda os servi�os standard num ficheiro de texto
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
 * Retorna a posicaoo de um veiculo no vetor veiculos; retorna -1 caso nao exista
 * @param mt matricula do veiculo a procurar
 */
int Oficina:: posVeiculo(string mt){
	for(unsigned int i=0; i< veiculos.size();i++){
		if(veiculos[i]->getMatricula() == mt) return i;
	}
	return -1;
}

/**
 * Retorna a posi�ao de um servico standard no vetor veiculos; retorna -1 caso nao exista
 * @param nome nome do servi�o a procurar
 */
int Oficina:: isStandard(string nome){
	for(unsigned int i=0; i< servicosStandard.size();i++){
		if(servicosStandard[i]->getNome() == nome) return i;
	}
	return -1;
}

/**
 * Remove da Tabela de Dispersao um Cliente de deixou de ser inativo
 */
void Oficina::removeClienteInativo(Cliente &c){
	tabHInativos::const_iterator it = inativos.begin();
	while(it != inativos.end()){
		if ((*it).getId() == c.getId()){
			inativos.erase(c);
			return;
		}
		it++;
	}
	throw ClienteInativoNaoExistente(c.getId());
}

/**
 * Funcao auxiliar: calcula os pontos que a oficina oferece ao cliente quando este realiza um servico
 */
int calculaPontos(Servico* s){
	float preco= s->getPreco();

	if(preco<100) return 20;
	if(preco>=100 && preco<200) return 50;
	else return 100;
}

/**
 * Verifica se o cliente pertence a Tabela de Dispersao de clientes inativos
 */
bool Oficina:: pertenceInativos(Cliente c){
	tabHInativos::iterator it= inativos.begin();

	while(it != inativos.end()){
		if((*it).getId() == c.getId()){
			return true;
		}
		it++;
	}

	return false;
}

/**
 * Atualiza a Tabela de Dispersao de cliente inativos; adiciona os clientes inativos que ainda nao pertencam a tabela
 */
void Oficina::atualizaInativos(Date d){

	for(unsigned int i=0; i< clientes.size();i++){
		if(clientes[i].isInativo(d)){
			if(pertenceInativos(clientes[i]) == false){
				inativos.insert(clientes[i]);
			}
		}
	}
}

/**
 * Adiciona um servico a um veiculo do cliente, lancando expecoes quando o cliente ou veiculo nao existe
 * Se o cliente fosse inativo retira-o da Tabela de Dispersao de clientes inativos
 */
void Oficina::addServico(Cliente &c, Veiculo *v, Servico *s, Date &d){

	int posCli = -1, posVeic = -1;

	for (unsigned int i=0; i < clientes.size(); i++){
		if (clientes[i].getNome() == c.getNome()){
			posCli = i;
			break;
		}
	}

	if (posCli == -1 ) throw ClienteInexistente(c.getNome());

	Cliente c1 = clientes[posCli];
	vector<Veiculo*> veic = c1.getVeiculos();

	for (unsigned int j=0; j<veiculos.size();j++){
		if (veiculos[j]->getMatricula() == v->getMatricula()){
			posVeic=j;
			break;
		}
	}

	if (posVeic == -1) throw VeiculoInexistente(v->getMatricula());

	veiculos[posVeic]->addServico(s,false);

	adicionaServicoArvore(s);

	if(clientes[posCli].isInativo(d)) inativos.erase(c);

	int pontos= clientes[posCli].getPontos(), novos= calculaPontos(s);
	clientes[posCli].setPontos(pontos+novos);

	pair<int, Date> p(novos, d);
	clientes[posCli].adicionaPontosData(p);
}

/**
 * Imprime todos os clientes que estao inativos
 */
void Oficina::displayClientesInativos(){
	tabHInativos::const_iterator it= inativos.begin();
	while(it != inativos.end()){
		cout << (*it).getNome() << endl;
		it++;
	}
}

/**
 * Oferece um servico aleatorio aos 3 clientes com mais pontos em troca dos seus pontos
 */
void Oficina:: happyHour(){
	srand (time(NULL));

	int n=3;
	int servico, veiculo;
	vector<Cliente> ofertas;

	while(n!=0){
		Cliente c= maisPontos.top();
		maisPontos.pop();

		veiculo= rand() % (c.getVeiculos().size());
		Veiculo * v= c.getVeiculos().at(veiculo);

		servico= rand() % (v->getServicos().size());
		Servico * s=v->getServicos().at(servico);

		cout<< "O cliente aceita o servico "<<s->getNome() <<" por "<<c.getPontos()<<" pontos? (s/n) \n";

		char resposta;
		cin>>resposta;

		if(resposta == 's'){
			c.removeServicoCliente(v,s);
			c.incServicosRealizados();
			c.setPontos(0);
			c.erasePontosData();
			ofertas.push_back(c);
			n--;
		}
		if(resposta=='n'){
			ofertas.push_back(c);
		}
	}

	vector<Cliente>::iterator it= ofertas.begin();

	while(it != ofertas.end()){
		maisPontos.push(*it);
	}
}

/**
 * Funcao auxiliar: verifica se os pontos com dada data caducaram (nao foram utilizados durante 1 ano)
 */
bool Caducou(Date atual, Date servico){
	int difAno= atual.getAno() - servico.getAno();
	int difMes= atual.getMes()- servico.getMes();
	int difDia= atual.getDia()- servico.getDia();


	if(difAno > 1) return true;
	if(difAno < 1)return false;
	if(difAno == 1){
		if(difMes < 0) return true;
		if(difMes > 0) return false;
		if(difMes == 0){
			if(difDia <= 0) return true;
		}
	}
	return false;
}

/**
 * Atualiza os pontos dos cliente da Oficina retirando aqueles que caducaram
 */
void Oficina:: atualizaPontos(Date d){

	for(unsigned int i=0; i<clientes.size();i++){
		int pontosCliente=clientes[i].getPontos();
		int pontosRetirar=0;
		vector <pair <int, Date > > p= clientes[i].getPontosData();
		for(unsigned int j=0; j< p.size();j++){
			Date data= p[j].second;
			int pontos= p[j].first;

			if(Caducou(d,data)){
				pontosRetirar += pontos;
				p.erase(p.begin()+j);
			}
		}
		clientes[i].setPontos(pontosCliente - pontosRetirar);
		clientes[i].setPontosData(p);
	}
}

/**
 * Retorna todos os servicos da oficina presentes na Arvore Binaria de Pesquisa
 */
BST<Servico *> Oficina::getServicos() const{
	return arvoreServicos;
}

/**
 * Retorna todos os servicos a serem efetuados na data passada como parametro
 */
vector<Servico *> Oficina::getServicos(const Date d) const{
	BSTItrIn<Servico *> it(arvoreServicos);
	vector<Servico *> servData;
	while(!it.isAtEnd()){
		if(it.retrieve()->getDate() == d){
			servData.push_back(it.retrieve());
		}
		it.advance();
	}
	return servData;
}


/**
 * Modifica a data de um dado servico para a data passada como parametro
 */
bool Oficina::remarcaServico(Servico *s, const Date &d){
	BSTItrIn<Servico *> it(arvoreServicos);
	while(!it.isAtEnd()){
		if(it.retrieve()->getDate() == s->getDate()){
			it.retrieve()->setDate(d);
			return true;
		}
		it.advance();
	}
	return false;
}

/**
 * Remove um servico da Oficina
 */
bool Oficina::removeServico(Servico *s){
	BSTItrIn<Servico *> it(arvoreServicos);
	while(!it.isAtEnd()){
		if(it.retrieve() == s){
			arvoreServicos.remove(it.retrieve());
			return true;
		}
		it.advance();
	}
	return false;
}

/**
 * Imprime todos os servicos da Oficina presentes na Arvore Binaria
 */
void Oficina:: printArvore(){
	BSTItrIn<Servico *> it(arvoreServicos);
	int n=0;

	while(!it.isAtEnd()){
		cout<<"Servico "<<n<<":";
		(it.retrieve())->print();
		cout<<"\n";
		it.advance();
		n++;
	}
}

/**
 * Imprime os clientes por ordem de pontos dispostos na Fila de Prioridade
 */
void Oficina::displayFila(){
	FilaPrioridade copy= maisPontos;

	while(!copy.empty()){
		Cliente c= copy.top();
		copy.pop();
		cout<<c.getNome()<<" "<<c.getPontos()<<endl;
	}
}
