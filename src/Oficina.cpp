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
 * Adiciona serviço standard a Oficina
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
 * Remove Funcionario da oficina, lança exepção caso nao exista
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
 * Remove um veiculo de um cliente, lança excepção caso o cliente ou veiculo nao existam
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
 * Remove veiculo da oficina, lanca excepçao caso nao exista
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
 * Remove um servico standard da oficina, lança excepcao caso nao exista
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

/**
 * Funcao auxiliar para criacao de veiculos da Oficina
 */
Veiculo* Oficina::createVeiculo(string tipo, string marca, string matricula, int ano){
	Veiculo *v;

	if(tipo == "Camiao"){
		v = new Camiao(marca,matricula,ano);
	}else if(tipo == "Motorizada"){
		v = new Motorizada(marca,matricula,ano);
	}else if(tipo == "Autocarro"){
		v = new Autocarro(marca,matricula,ano);
	}else if(tipo == "Automovel"){
		v = new Automovel(marca,matricula,ano);
	}

	return v;
}

/**
 * Funcao auxiliar para criacao de servicos da Oficina
 */
Servico* Oficina::createServico(string tipo, string nome, float preco, int duracao){
	Servico *s;

	if(tipo == "Standard"){
		s = new Standard(nome,preco,duracao);
	}else if(tipo == "naoStandard"){
		s = new naoStandard(nome,preco,duracao);
	}

	return s;
}


/**
 * Le veiculos de um ficheiro de texto e guarda-os na Oficina
 */
bool Oficina::leVeiculos(){
	ifstream veiculoFile;
	veiculoFile.open("veiculos.txt",ifstream::in);

	string lixo;
	string tipo, tipoS, marca, matricula, nomeS;
	int ano, duracao;
	unsigned int numVeic, numServ;
	float precoS;

	if(veiculoFile.is_open()){
		veiculoFile >> lixo >> lixo >> lixo >> numVeic;

		for(unsigned int i = 0; i < numVeic; i++){
			veiculoFile >> lixo >> tipo;
			veiculoFile >> lixo >> marca;
			veiculoFile >> lixo >> matricula;
			veiculoFile >> lixo >> ano;
			veiculoFile >> numServ >> lixo;

			Veiculo *v = createVeiculo(tipo,marca,matricula,ano);
			addVeiculo(v);

			for(unsigned int j = 0; j < numServ; j++){
				veiculoFile >> lixo >> tipoS;
				veiculoFile >> lixo >> nomeS;
				veiculoFile >> lixo >> precoS;
				veiculoFile >> lixo >> duracao;

				Servico *s = createServico(tipo,nomeS,precoS,duracao);
				v->addServico(s,true);
			}
		}
	}

	veiculoFile.close();
	return true;
}

/**
 * Guarda os veiculos num ficheiro de texto
 */
bool Oficina::guardaVeiculos(){
	ofstream veiculoFile;
	veiculoFile.open("veiculos.txt");

	veiculoFile << "Número de veículos: " << veiculos.size() << endl;
	veiculoFile << endl;

	for(unsigned int i = 0; i < veiculos.size(); i++){
		vector<Servico *> servVeiculo = veiculos[i]->getServicos();

		if(i != 0) veiculoFile << endl;

		veiculoFile << "Tipo: " << veiculos[i]->classname() << endl;
		veiculoFile << "Marca: " << veiculos[i]->getMarca() << endl;
		veiculoFile << "Matricula: " << veiculos[i]->getMatricula() << endl;
		veiculoFile << "Ano: " << veiculos[i]->getAno() << endl;
		if(servVeiculo.size() != 0){
			if(servVeiculo.size() == 1){
				veiculoFile << servVeiculo.size() << " servico:" << endl;
			}else{
				veiculoFile << servVeiculo.size() << " servicos:" << endl;
			}
		}
		for(unsigned int j = 0; j < servVeiculo.size(); j++){
			veiculoFile << "\tTipo: " << servVeiculo[j]->classname() << endl;
			veiculoFile << "\tNome: " << servVeiculo[j]->getNome() << endl;
			veiculoFile << "\tPreco: " << servVeiculo[j]->getPreco() << endl;
			veiculoFile << "\tDuração: " << servVeiculo[j]->getDuracao() << endl;
		}
	}

	veiculoFile << endl <<"Fim do ficheiro";

	veiculoFile.close();
	return true;
}

/**
 * Le clientes de um ficheiro de texto e guarda-os na Oficina
 */
bool Oficina::leClientes(){
	ifstream clienteFile;
	clienteFile.open("clientes.txt",ifstream::in);

	string lixo;
	string tipo, marca, matricula, nomeC;
	int ano;
	unsigned int numVeic, numCli;

	if(clienteFile.is_open()){
		clienteFile >> lixo >> lixo >> lixo >> numCli;

		for(unsigned int i = 0; i < numCli; i++){
			clienteFile >> lixo >> nomeC;
			clienteFile >> numVeic >> lixo;

			Cliente c(nomeC);
			addCliente(c);

			for(unsigned int j = 0; j < numVeic; j++){
				clienteFile >> lixo >> tipo;
				clienteFile >> lixo >> marca;
				clienteFile >> lixo >> matricula;
				clienteFile >> lixo >> ano;

				Veiculo *v = createVeiculo(tipo,marca,matricula,ano);
				c.addVeiculo(v);
			}
		}
	}

	clienteFile.close();
	return true;
}

/**
 * Guarda os clintes num ficheiro de texto
 */
bool Oficina::guardaClientes(){
	ofstream clienteFile;
	clienteFile.open("clientes.txt");

	clienteFile << "Número de clientes: " << clientes.size() << endl;
	clienteFile << endl;

	for(unsigned int i = 0; i < clientes.size(); i++){
		vector<Veiculo *> veiculosCli = clientes[i].getVeiculos();

		if(i != 0) clienteFile << endl;

		clienteFile << "Nome: " << clientes[i].getNome() << endl;
		if(veiculosCli.size() != 0){
			if(veiculosCli.size() == 1){
				clienteFile << veiculosCli.size() << " veiculo:" << endl;
			}else{
				clienteFile << veiculosCli.size() << " veiculos:" << endl;
			}
		}
		for(unsigned int j = 0; j < veiculosCli.size(); j++){
			clienteFile << "\tTipo: " << veiculosCli[i]->classname() << endl;
			clienteFile << "\tMarca: " << veiculosCli[i]->getMarca() << endl;
			clienteFile << "\tMatricula: " << veiculosCli[i]->getMatricula() << endl;
			clienteFile << "\tAno: " << veiculosCli[i]->getAno() << endl;
		}
	}

	clienteFile << endl << "Fim do ficheiro";

	clienteFile.close();
	return true;
}

/**
 * Le funcionarios de um ficheiro de texto e guarda-os na Oficina
 */
bool Oficina::leFuncionarios(){
	ifstream funcFile;
	funcFile.open("funcionarios.txt",ifstream::in);

	string lixo;
	string tipo, marca, matricula, nomeF;
	int ano;
	unsigned int numVeic, numFunc;

	if(funcFile.is_open()){
		funcFile >> lixo >> lixo >> lixo >> numFunc;

		for(unsigned int i = 0; i < numFunc; i++){
			funcFile >> lixo >> nomeF;
			funcFile >> numVeic >> lixo;

			Funcionario f(nomeF);
			addFuncionario(f);

			for(unsigned int j = 0; j < numVeic; j++){
				funcFile >> lixo >> tipo;
				funcFile >> lixo >> marca;
				funcFile >> lixo >> matricula;
				funcFile >> lixo >> ano;

				Veiculo *v = createVeiculo(tipo,marca,matricula,ano);
				f.addVeiculo(v);
			}
		}
	}

	funcFile.close();
	return true;
}

/**
 * Guarda os funcionarios num ficheiro de texto
 */
bool Oficina::guardaFuncionarios(){
	ofstream funcFile;
	funcFile.open("funcionarios.txt");

	funcFile << "Número de funcionários: " << funcionarios.size() << endl;
	funcFile << endl;

	for(unsigned int i = 0; i < funcionarios.size(); i++){
		vector<Veiculo *> veiculosF = funcionarios[i].getVeiculos();

		if(i != 0) funcFile << endl;

		funcFile << "Nome: " << funcionarios[i].getNome() << endl;
		if(veiculosF.size() != 0){
			if(veiculosF.size() == 1){
				funcFile << veiculosF.size() << " veiculo:" << endl;
			}else{
				funcFile << veiculosF.size() << " veiculos:" << endl;
			}
		}
		for(unsigned int j = 0; j < veiculosF.size(); j++){
			funcFile << "\tTipo: " << veiculosF[i]->classname() << endl;
			funcFile << "\tMarca: " << veiculosF[i]->getMarca() << endl;
			funcFile << "\tMatricula: " << veiculosF[i]->getMatricula() << endl;
			funcFile << "\tAno: " << veiculosF[i]->getAno() << endl;
		}
	}

	funcFile << endl << "Fim do ficheiro";

	funcFile.close();
	return true;
}

/**
 * Le serviços de um ficheiro de texto e guarda-os na Oficina
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
 * Retorna a posiçao de um servico standard no vetor veiculos; retorna -1 caso nao exista
 * @param nome nome do serviço a procurar
 */
int Oficina:: isStandard(string nome){
	for(unsigned int i=0; i< servicosStandard.size();i++){
			if(servicosStandard[i]->getNome() == nome) return i;
		}

		return -1;
}
