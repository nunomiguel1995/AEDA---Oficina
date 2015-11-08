#include "Veiculo.h"

/**
 * Classe Veículo
 */
Veiculo::Veiculo(string m, string mt, int a) : marca(m), matricula(mt), ano(a){}

Veiculo::~Veiculo(){}

string Veiculo::getMarca() const {return marca;}

string Veiculo::getMatricula() const {return matricula;}

int Veiculo::getAno() const{return ano;}

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

void Veiculo::displayVeiculo() const{
	cout<< marca << "; "<< matricula <<"; " << ano << endl;
}

string Veiculo::classname() const{return "Veiculo";}

void Veiculo:: addServico(Servico *&s, bool control){}

vector<Servico *> Veiculo::getServicos() const{}

/**
 * Motorizada
 */
Motorizada::Motorizada(string m, string mt, int a) : Veiculo(m,mt,a){}

Motorizada::~Motorizada(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico *> Motorizada::getServicos() const{return servicos;}

void Motorizada::addServico(Servico * & s, bool control){
	if(control){s->addTaxa(taxa);}
	servicos.push_back(s);}

string Motorizada::classname() const{return "Motorizada";}
/**
 * Camiao
 */
Camiao::Camiao(string m, string mt,int a) : Veiculo(m,mt,a){}

Camiao::~Camiao(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico *> Camiao::getServicos() const{return servicos;}

void Camiao::addServico(Servico * & s, bool control){
	if(control){s->addTaxa(taxa);}
	servicos.push_back(s);}

string Camiao::classname() const{return "Camiao";}
/**
 * Autocarro
 */
Autocarro::Autocarro(string m, string mt,int a) : Veiculo(m,mt,a){}

Autocarro::~Autocarro(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico *> Autocarro::getServicos() const{return servicos;}

void Autocarro::addServico(Servico * & s, bool control){
	if(control){s->addTaxa(taxa);}
	servicos.push_back(s);}

string Autocarro::classname() const{return "Autocarro";}
/**
 * Automóvel
 */
Automovel::Automovel(string m, string mt,int a) : Veiculo(m,mt,a){}

Automovel::~Automovel(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico *> Automovel::getServicos() const{return servicos;}

void Automovel::addServico(Servico * & s, bool control){
	if(control){s->addTaxa(taxa);}
	servicos.push_back(s);}

string Automovel::classname() const{return "Automovel";}


