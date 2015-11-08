#include "Servico.h"

 /*
  * Servi�o
  */

/**
 * Construtor da classe servi�o
 * @param nome
 * @param preco
 * @param duracao
 */
Servico:: Servico(string nome,float preco, int duracao){
	this-> nome =nome;
	this->preco = preco;
	this->duracao = duracao;
}

/**
 * Destrutor da classe servi�o
 */
Servico::~Servico(){}

/**
 * Retorna o nome do servi�o
 */
string Servico::getNome(){
	return nome;
}

/**
 * Retorna o pre�o do servi�o
 */
float Servico:: getPreco() const{
	return preco;
}

/**
 * Retorna a dura��o do servi�o
 */
int Servico:: getDuracao() const{
	return duracao;
}

/**
 * Mostra os atributos do servi�o- nome, pre�o e dura��o
 */
void Servico:: displayServico() const{
	cout<< "nome: " << nome << " preco: "<< preco <<" duracao: "<< duracao;
}

/**
 * Adiciona taxa ao servi�o
 */
void Servico:: addTaxa(float tx){preco=preco+ preco*tx;}

/**
 * Nome do Servi�o
 */
string Servico::classname() const{}
/*
 * Standard
 */

/**
 * Construtor da classe Standard
 */
Standard:: Standard (string nome, float preco, int duracao): Servico(nome,preco,duracao){}

/**
 * Destrutor da classe Standard
 */
Standard:: ~Standard(){}

/**
 * Nome da Classe
 */
string Standard::classname() const{return "Standard";}

/*
 * NaoStandard
 */

/**
 * Construtor da classe n�o Standard
 */
naoStandard:: naoStandard (string nome, float preco, int duracao): Servico(nome,preco,duracao){}

/**
 * Destrutor da classe n�o Standard
 */
naoStandard::~naoStandard(){}


/**
 * Nome da Classe
 */
string naoStandard:: classname() const{return "naoStandard";}
