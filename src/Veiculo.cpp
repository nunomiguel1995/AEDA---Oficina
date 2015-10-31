#include "Veiculo.h"

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



