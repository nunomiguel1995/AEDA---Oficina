#ifndef SRC_SERVICO_H_
#define SRC_SERVICO_H_

#include <string>
#include <iostream>
#include <vector>
#include "Excepcoes.h"

using namespace std;


class Servico{
	string nome;

public:
	Servico (string nome);
	string getNome();
	virtual void displayServico() const;
	virtual void addTaxa(float tx);
};

class Standard: public Servico{
	float preco;
	int duracao;

public:
	Standard (string nome, float preco, int duracao);
	float getPreco() const;
	int getDuracao() const;
	void displayServico() const;
	void addTaxa(float tx);
};


class naoStandard: public Servico{
	float preco;
	int duracao;

public:
	naoStandard (string nome, float preco, int duracao);
	float getPreco() const;
	int getDuracao() const;
	void displayServico() const;
	void addTaxa(float tx);
};



#endif /* SRC_SERVICO_H_ */
