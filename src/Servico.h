#ifndef SRC_SERVICO_H_
#define SRC_SERVICO_H_

#include <string>
#include <iostream>
#include <vector>
#include "Excepcoes.h"

using namespace std;

/**
 * Classe Serviço- classe base
 */
class Servico{
	string nome;
	float preco;
	int duracao;
public:
	Servico (string nome, float preco, int duracao);
	virtual ~Servico();
	string getNome();
	float getPreco() const;
	int getDuracao() const;
	void displayServico() const;
	void addTaxa(float tx);
	virtual string classname() const;
};

/**
 * Classe Standard- classe derivada
 */
class Standard: public Servico{

public:
	Standard (string nome, float preco, int duracao);
	~Standard();
	string classname() const;
};


/**
 * Classe não Standard- classe derivada
 */
class naoStandard: public Servico{

public:
	naoStandard (string nome, float preco, int duracao);
	~naoStandard();
	string classname() const;
};



#endif /* SRC_SERVICO_H_ */
