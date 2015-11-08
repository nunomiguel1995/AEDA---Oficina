#include "Servico.h"

 /*
  * Serviço
  */

/**
 * Construtor da classe servico
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
 * Destrutor da classe servico
 */
Servico::~Servico(){}

/**
 * Retorna o nome do servico
 */
string Servico::getNome(){
	return nome;
}

/**
 * Retorna o preço do servico
 */
float Servico:: getPreco() const{
	return preco;
}

/**
 * Retorna a duração do servico
 */
int Servico:: getDuracao() const{
	return duracao;
}

/**
 * Mostra os atributos do servico- nome, preço e duracao
 */
void Servico:: displayServico() const{
	cout<< "nome: " << nome << " preco: "<< preco <<" duracao: "<< duracao;
}

/**
 * Adiciona taxa ao servico
 */
void Servico:: addTaxa(float tx){preco=preco+ preco*tx;}

/**
 * Nome do Servico
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
 * Construtor da classe nao Standard
 */
naoStandard:: naoStandard (string nome, float preco, int duracao): Servico(nome,preco,duracao){}

/**
 * Destrutor da classe nao Standard
 */
naoStandard::~naoStandard(){}


/**
 * Nome da Classe
 */
string naoStandard:: classname() const{return "naoStandard";}
