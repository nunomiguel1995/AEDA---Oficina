#ifndef SRC_SERVICO_H_
#define SRC_SERVICO_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Servico{
	string nome;
public:
	Servico (string nome);
	string getNome();
};

class Standard: public Servico{
	float preco;
	int duracao;
	vector <string> descricao;
public:
	Standard (string nome);
};


class naoStandard: public Servico{
	float preco;
	int duracao;
	vector <string> descricao;
public:
	naoStandard (string nome, float preco, int duracao, vector<string> descricao);
};



#endif /* SRC_SERVICO_H_ */
