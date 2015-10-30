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

Motorizada::~Motorizada(){}

vector<Servico> Motorizada::getServicos() const{return servicos;}

void Motorizada::addServico(const Servico & s){servicos.push_back(s);}

/**
 * Camiao
 */
Camiao::Camiao(string m, string mt) : Veiculo(m,mt){}

Camiao::~Camiao(){}

vector<Servico> Camiao::getServicos() const{return servicos;}

void Camiao::addServico(const Servico & s){servicos.push_back(s);}
