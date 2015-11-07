#ifndef SRC_EXCEPCOES_H_
#define SRC_EXCEPCOES_H_

#include <iostream>

using namespace std;

class ClienteExistente{
	string nome;
public:
	ClienteExistente(string nome){ this->nome = nome;}
	string getNome() const{return nome;}
};

class ClienteInexistente{
	string nome;
public:
	ClienteInexistente(string nome){ this->nome = nome;}
	string getNome() const{return nome;}
};

class FuncionarioExistente{
	string nome;
public:
	FuncionarioExistente(string nome){this->nome = nome;}
	string getNome() const{return nome;}
};

class FuncionarioInexistente{
	string nome;
public:
	FuncionarioInexistente(string nome){this->nome = nome;}
	string getNome() const{return nome;}
};

class VeiculoExistente{
	string matricula;
public:
	VeiculoExistente(string mt){ matricula= mt;}
	string getMatricula() const{ return matricula;}
};

class VeiculoInexistente{
	string matricula;
public:
	VeiculoInexistente(string mt){ matricula=mt;}
	string getMatricula() const{ return matricula;}
};




#endif /* SRC_EXCEPCOES_H_ */
