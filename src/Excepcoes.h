#ifndef SRC_EXCEPCOES_H_
#define SRC_EXCEPCOES_H_

#include <iostream>

using namespace std;

/**
 * Excepção quando um cliente já existe
 *
 */
class ClienteExistente{
	string nome;
public:
	ClienteExistente(string nome){ this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excepção quando um cliente não existe
 *
 */
class ClienteInexistente{
	string nome;
public:
	ClienteInexistente(string nome){ this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excepção quando um funcionário já existe
 *
 */
class FuncionarioExistente{
	string nome;
public:
	FuncionarioExistente(string nome){this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excepção quando um funcionário não existe
 *
 */
class FuncionarioInexistente{
	string nome;
public:
	FuncionarioInexistente(string nome){this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excepção quando um veiculo já existe
 *
 */
class VeiculoExistente{
	string matricula;
public:
	VeiculoExistente(string mt){ matricula= mt;}
	string getMatricula() const{ return matricula;}
};

/**
 * Excepção quando um veiculo não existe
 *
 */
class VeiculoInexistente{
	string matricula;
public:
	VeiculoInexistente(string mt){ matricula=mt;}
	string getMatricula() const{ return matricula;}
};

/**
 * Excepção quando um serviço standard já existe na oficina
 *
 */
class ServicoExistente{
	string nome;

public:
	ServicoExistente(string nome){this->nome=nome;}
	string getNome() const{ return nome;}
};

/**
 * Excepção quando um serviço standard não existe na oficina
 *
 */
class ServicoInexistente{
	string nome;

public:
	ServicoInexistente(string nome){this->nome=nome;}
	string getNome() const{ return nome;}

};


#endif /* SRC_EXCEPCOES_H_ */
