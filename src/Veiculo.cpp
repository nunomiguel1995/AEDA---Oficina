#include "Veiculo.h"

/**
 * Classe Ve�culo
 */

/**
 * Construtor da classe Veiculo
 * @param m marca do veiculo
 * @param mt matricula do veiculo
 * @param a ano do veiculo
 */
Veiculo::Veiculo(string m, string mt, int a) : marca(m), matricula(mt), ano(a){}

/**
 * Destrutor da Classe Veiculo
 */
Veiculo::~Veiculo(){}

/**
 * Retorna a marca do veiculo
 */
string Veiculo::getMarca() const {return marca;}

/**
 * Retorna a matricula do veiculo
 */
string Veiculo::getMatricula() const {return matricula;}

/**
 * Retorna o ano do veiculo
 */
int Veiculo::getAno() const{return ano;}

/**
 * Overload do operador <
 */
bool operator <(const Veiculo v1, const Veiculo v2){
	int ano1= v1.getAno();
	int ano2= v2.getAno();

		if(ano1 < ano2) return true;
		if(ano1> ano2) return false;
		if(ano1 == ano2){
			if(v1.getMarca()<v2.getMarca()) return true;
			else return false;
		}
}

/**
 * Mostra as informa��es do Veiculo- marca, matricula e ano
 */
void Veiculo::displayVeiculo() const{
	cout<< marca << "; "<< matricula <<"; " << ano << endl;
}

/**
 * Retorna o nome da classe Veiculo
 */
string Veiculo::classname() const{return "Veiculo";}

/**
 * Adiciona um servi�o
 * @param s servi�o a adicionar
 */
void Veiculo:: addServico(Servico *&s, bool control){}

vector<Servico *> Veiculo::getServicos() const{}

/**
 * Motorizada
 */

/**
 * Construtor da classe Motorizada
 * @param m marca da motorizada
 * @param mt matricula
 * @param a ano
 */
Motorizada::Motorizada(string m, string mt, int a) : Veiculo(m,mt,a){}

/**
 * Destrutor da classe Motorizada
 */
Motorizada::~Motorizada(){servicos.erase(servicos.begin(),servicos.end());}

/**
 * Retorna o vetor servi�os associados ao objeto da classe motorizada
 */
vector<Servico *> Motorizada::getServicos() const{return servicos;}

/**
 * Adiciona um servi�o, aplicando a taxa associada � classe Motorizada
 * @param s servi�o a adicionar
 */

void Motorizada::addServico(Servico * & s, bool control){
	if(control){s->addTaxa(taxa);}
	servicos.push_back(s);}

/**
 * Retorna o nome da classe Motorizada
 */
string Motorizada::classname() const{return "Motorizada";}


/**
 * Camiao
 */

/**
 * Construtor da classe Cami�o
 * @param m marca da motorizada
 * @param mt matricula
 * @param a ano
 */
Camiao::Camiao(string m, string mt,int a) : Veiculo(m,mt,a){}

/**
 * Destrutor da classe cami�o
 */
Camiao::~Camiao(){servicos.erase(servicos.begin(),servicos.end());}

/**
 * Retorna os servi�os do Cami�o
 */
vector<Servico *> Camiao::getServicos() const{return servicos;}

/**
 * Adiciona um servi�o, aplicando a taxa associada ao Cami�o
 * @param s servi�o a adicionar
 */

void Camiao::addServico(Servico * & s, bool control){
	if(control){s->addTaxa(taxa);}
	servicos.push_back(s);}

/**
 * Retorna o nome da classe
 */
string Camiao::classname() const{return "Camiao";}
/**
 * Autocarro
 */

/**
 * Construtor da classe Autocarro
 * @param m marca da motorizada
 * @param mt matricula
 * @param a ano
 */
Autocarro::Autocarro(string m, string mt,int a) : Veiculo(m,mt,a){}

/**
 * Destrutor da classe Autocarro
 */
Autocarro::~Autocarro(){servicos.erase(servicos.begin(),servicos.end());}

/**
 * Retorna o vetor servi�os
 */
vector<Servico *> Autocarro::getServicos() const{return servicos;}

/**
 * Adiciona um servi�o, aplicando a taxa associada a Autocarro
 * @param s servi�o a adicionar
 */
void Autocarro::addServico(Servico * & s, bool control){
	if(control){s->addTaxa(taxa);}
	servicos.push_back(s);}

/**
 * Retorna o nome da classe
 */
string Autocarro::classname() const{return "Autocarro";}


/**
 * Autom�vel
 */

/**
 * Construtor da classe Automovel
 * @param m marca da motorizada
 * @param mt matricula
 * @param a ano
 */
Automovel::Automovel(string m, string mt,int a) : Veiculo(m,mt,a){}

/**
 * Destrutor da classe
 */
Automovel::~Automovel(){servicos.erase(servicos.begin(),servicos.end());}

/**
 * Retorna os servi�os do autom�vel
 */
vector<Servico *> Automovel::getServicos() const{return servicos;}

/**
 * Adiciona um servi�o, aplicando a taxa associada ao Automovel
 * @param s servi�o a adicionar
 */
void Automovel::addServico(Servico * & s, bool control){
	if(control){s->addTaxa(taxa);}
	servicos.push_back(s);}

/**
 * Retorna o nome da classe
 */
string Automovel::classname() const{return "Automovel";}


