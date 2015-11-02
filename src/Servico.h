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
	void setPreco(float p1);
	void setDuracao(int d1);
	void setDescricao(vector<string> d1);
	float getPreco() const;
	int getDuracao() const;
	vector<string> getDescricao() const;
};


class naoStandard: public Servico{
	float preco;
	int duracao;
	vector <string> descricao;
public:
	naoStandard (string nome, float preco, int duracao, vector<string> descricao);
	float getPreco() const;
	int getDuracao() const;
	vector<string> getDescricao() const;
};



#endif /* SRC_SERVICO_H_ */
