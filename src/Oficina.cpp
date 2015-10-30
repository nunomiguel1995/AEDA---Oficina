#include "Oficina.h"

using namespace std;

/**
 * Classe Veículo
 */
Veiculo::Veiculo(string m, string mt) : marca(m), matricula(mt){}

Veiculo::~Veiculo(){}

string Veiculo::getMarca() const {return marca;}

string Veiculo::getMatricula() const {return matricula;}

/**
 * Motorizada
 */
Motorizada::Motorizada(string m, string mt) : Veiculo(m,mt){}

Motorizada::~Motorizada(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico> Motorizada::getServicos() const{return servicos;}

void Motorizada::addServico(const Servico & s){servicos.push_back(s);}

/**
 * Camiao
 */
Camiao::Camiao(string m, string mt) : Veiculo(m,mt){}

Camiao::~Camiao(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico> Camiao::getServicos() const{return servicos;}

void Camiao::addServico(const Servico & s){servicos.push_back(s);}

/**
 * Autocarro
 */
Autocarro::Autocarro(string m, string mt) : Veiculo(m,mt){}

Autocarro::~Autocarro(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico> Autocarro::getServicos() const{return servicos;}

void Autocarro::addServico(const Servico & s){servicos.push_back(s);}

/**
 * Automóvel
 */
Automovel::Automovel(string m, string mt) : Veiculo(m,mt){}

Automovel::~Automovel(){servicos.erase(servicos.begin(),servicos.end());}

vector<Servico> Automovel::getServicos() const{return servicos;}

void Automovel::addServico(const Servico & s){servicos.push_back(s);}

/*
 * Cliente
 */
static int ID=1;

Cliente:: Cliente(string nome){
	this->nome=nome;
	this->id=ID;
	ID++;
}

string Cliente:: getNome()const{
	return nome;
}

int Cliente:: getId() const{
	return id;
}

vector <Veiculo*> Cliente:: getVeiculos() const{
	return veiculos;
}

void Cliente:: addVeiculo(Veiculo *v1){
	for(unsigned int i=0; i<veiculos.size();i++){
		if(veiculos[i]->getMatricula() ==v1->getMatricula()) throw(VeiculoExistente(v1->getMatricula()));
	}

	veiculos.push_back(v1);

}

void Cliente:: removeVeiculo (Veiculo *v1){
	bool existe=false;
	unsigned int pos;
	for(pos=0; pos<veiculos.size();pos++){
		if(veiculos[pos]->getMatricula()==v1->getMatricula()){
			existe=true;
			veiculos.erase(veiculos.begin()+pos);
			break;
		}
	}

	if(!existe) throw(VeiculoInexistente(v1->getMatricula()));
}

/**
 * Funcionario
 */

/**
 * Oficina
 */
