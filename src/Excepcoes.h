#ifndef SRC_EXCEPCOES_H_
#define SRC_EXCEPCOES_H_

#include <iostream>

using namespace std;

/**
 * Excep��o quando um cliente j� existe
 *
 */
class ClienteExistente{
	string nome;
public:
	ClienteExistente(string nome){ this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excep��o quando um cliente n�o existe
 *
 */
class ClienteInexistente{
	string nome;
public:
	ClienteInexistente(string nome){ this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excep��o quando um funcion�rio j� existe
 *
 */
class FuncionarioExistente{
	string nome;
public:
	FuncionarioExistente(string nome){this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excep��o quando um funcion�rio n�o existe
 *
 */
class FuncionarioInexistente{
	string nome;
public:
	FuncionarioInexistente(string nome){this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excep��o quando um veiculo j� existe
 *
 */
class VeiculoExistente{
	string matricula;
public:
	VeiculoExistente(string mt){ matricula= mt;}
	string getMatricula() const{ return matricula;}
};

/**
 * Excep��o quando um veiculo n�o existe
 *
 */
class VeiculoInexistente{
	string matricula;
public:
	VeiculoInexistente(string mt){ matricula=mt;}
	string getMatricula() const{ return matricula;}
};

/**
 * Excep��o quando um servi�o standard j� existe na oficina
 *
 */
class ServicoExistente{
	string nome;

public:
	ServicoExistente(string nome){this->nome=nome;}
	string getNome() const{ return nome;}
};

/**
 * Excep��o quando um servi�o standard n�o existe na oficina
 *
 */
class ServicoInexistente{
	string nome;

public:
	ServicoInexistente(string nome){this->nome=nome;}
	string getNome() const{ return nome;}

};


#endif /* SRC_EXCEPCOES_H_ */
