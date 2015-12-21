#ifndef SRC_EXCEPCOES_H_
#define SRC_EXCEPCOES_H_

#include <iostream>

using namespace std;

/**
 * Excep�ao quando um cliente ja existe
 *
 */
class ClienteExistente{
	string nome;
public:
	ClienteExistente(string nome){ this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excep�ao quando um cliente nao existe
 *
 */
class ClienteInexistente{
	string nome;
public:
	ClienteInexistente(string nome){ this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excep�ao quando um funcion�rio ja existe
 *
 */
class FuncionarioExistente{
	string nome;
public:
	FuncionarioExistente(string nome){this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excep�ao quando um funcionario nao existe
 *
 */
class FuncionarioInexistente{
	string nome;
public:
	FuncionarioInexistente(string nome){this->nome = nome;}
	string getNome() const{return nome;}
};

/**
 * Excep�ao quando um veiculo ja existe
 *
 */
class VeiculoExistente{
	string matricula;
public:
	VeiculoExistente(string mt){ matricula= mt;}
	string getMatricula() const{ return matricula;}
};

/**
 * Excep�ao quando um veiculo nao existe
 *
 */
class VeiculoInexistente{
	string matricula;
public:
	VeiculoInexistente(string mt){ matricula=mt;}
	string getMatricula() const{ return matricula;}
};

/**
 * Excep�ao quando um servi�o standard ja existe na oficina
 *
 */
class ServicoExistente{
	string nome;

public:
	ServicoExistente(string nome){this->nome=nome;}
	string getNome() const{ return nome;}
};

/**
 * Excep�ao quando um servi�o standard nao existe na oficina
 *
 */
class ServicoInexistente{
	string nome;

public:
	ServicoInexistente(string nome){this->nome=nome;}
	string getNome() const{ return nome;}

};

class ClienteInativoNaoExistente{
	int id;
public:
	ClienteInativoNaoExistente (int id){this->id=id;}
	int getId() const {return id;}
};


#endif /* SRC_EXCEPCOES_H_ */
