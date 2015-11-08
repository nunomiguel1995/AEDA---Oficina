#include "Servico.h"

 /*
  * Serviço
  */

/**
 * Construtor da classe serviço
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
 * Destrutor da classe serviço
 */
Servico::~Servico(){}

/**
 * Retorna o nome do serviço
 */
string Servico::getNome(){
	return nome;
}

/**
 * Retorna o preço do serviço
 */
float Servico:: getPreco() const{
	return preco;
}

/**
 * Retorna a duração do serviço
 */
int Servico:: getDuracao() const{
	return duracao;
}

/**
 * Mostra os atributos do serviço- nome, preço e duração
 */
void Servico:: displayServico() const{
	cout<< "nome: " << nome << " preco: "<< preco <<" duracao: "<< duracao;
}

/**
 * Adiciona taxa ao serviço
 */
void Servico:: addTaxa(float tx){preco=preco+ preco*tx;}

/**
 * Nome do Serviço
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
 * Construtor da classe não Standard
 */
naoStandard:: naoStandard (string nome, float preco, int duracao): Servico(nome,preco,duracao){}

/**
 * Destrutor da classe não Standard
 */
naoStandard::~naoStandard(){}


/**
 * Nome da Classe
 */
string naoStandard:: classname() const{return "naoStandard";}
