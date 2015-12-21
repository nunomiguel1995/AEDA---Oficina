#ifndef SRC_SERVICO_H_
#define SRC_SERVICO_H_

#include <string>
#include <iostream>
#include <vector>
#include "Excepcoes.h"
#include "Date.h"

using namespace std;

/**
 * Classe Servico- classe base
 */
class Servico{
	string nome;
	float preco;
	int duracao;
	Date *date;

public:
	Servico (string nome, float preco, int duracao, Date d);
	virtual ~Servico();
	string getNome();
	float getPreco() const;
	int getDuracao() const;
	Date getDate() const;
	void displayServico() const;
	void addTaxa(float tx);
	virtual string classname() const;
};

/**
 * Classe Standard- classe derivada
 */
class Standard: public Servico{

public:
	Standard (string nome, float preco, int duracao, Date data);
	~Standard();
	string classname() const;
};


/**
 * Classe nao Standard- classe derivada
 */
class naoStandard: public Servico{

public:
	naoStandard (string nome, float preco, int duracao, Date date);
	~naoStandard();
	string classname() const;
};



#endif /* SRC_SERVICO_H_ */
