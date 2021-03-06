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
	string nomeCliente;
	float preco;
	int duracao;
	Date date;
public:
	Servico (string n, float p, int dur, Date d);
	virtual ~Servico();
	void setCliente(string nome){this->nomeCliente = nome;};
	string getNome();
	void setDate(Date d);
	float getPreco() const;
	int getDuracao() const;
	Date getDate() const;
	void displayServico() const;
	void addTaxa(float tx);
	virtual string classname() const;
	void removeServico(Servico* s);
	bool operator < (const Servico *s);
	bool alteraDataServico(Date s);
	void print();
};

/**
 * Classe Standard- classe derivada
 */
class Standard: public Servico{

public:
	Standard (string n, float p, int dur, Date d);
	~Standard();
	string classname() const;
};


/**
 * Classe nao Standard- classe derivada
 */
class naoStandard: public Servico{

public:
	naoStandard (string n, float p, int dur, Date d);
	~naoStandard();
	string classname() const;
};



#endif /* SRC_SERVICO_H_ */
