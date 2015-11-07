#include "Veiculo.h"

/**
 * Classe Veículo
 */
Veiculo::Veiculo(string m, string mt, int a) : marca(m), matricula(mt), ano(a){}

Veiculo::~Veiculo(){}

string Veiculo::getMarca() const {return marca;}

string Veiculo::getMatricula() const {return matricula;}

<<<<<<< HEAD
int Veiculo:: getAno() const {return ano;}
=======
int Veiculo::getAno() const{return ano;}
>>>>>>> 371aca2d380cf9c492e620d60ae93ec428693df3

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
	cout<<marca<< "; "<< matricula<<"; "<<ano<<endl;
}

/**
 * Motorizada
 */
Motorizada::Motorizada(string m, string mt, int a) : Veiculo(m,mt,a){}

Motorizada::~Motorizada(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico> Motorizada::getServicos() const{return servicos;}

void Motorizada::addServico(const Servico & s){servicos.push_back(s);}

/**
 * Camiao
 */
Camiao::Camiao(string m, string mt,int a) : Veiculo(m,mt,a){}

Camiao::~Camiao(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico> Camiao::getServicos() const{return servicos;}

void Camiao::addServico(const Servico & s){servicos.push_back(s);}

/**
 * Autocarro
 */
Autocarro::Autocarro(string m, string mt,int a) : Veiculo(m,mt,a){}

Autocarro::~Autocarro(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico> Autocarro::getServicos() const{return servicos;}

void Autocarro::addServico(const Servico & s){servicos.push_back(s);}

/**
 * Automóvel
 */
Automovel::Automovel(string m, string mt,int a) : Veiculo(m,mt,a){}

Automovel::~Automovel(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico> Automovel::getServicos() const{return servicos;}

void Automovel::addServico(const Servico & s){servicos.push_back(s);}



