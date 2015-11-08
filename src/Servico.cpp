#include "Servico.h"

 /*
  * Serviço
  */
Servico:: Servico(string nome,float preco, int duracao){
	this-> nome =nome;
	this->preco = preco;
	this->duracao = duracao;
}

Servico::~Servico(){}

string Servico::getNome(){
	return nome;
}

float Servico:: getPreco() const{
	return preco;
}

int Servico:: getDuracao() const{
	return duracao;
}

void Servico:: displayServico() const{
	cout<< "nome: " << nome << " preco: "<< preco <<" duracao: "<< duracao;
}

void Servico:: addTaxa(float tx){preco=preco+ preco*tx;}

string Servico::classname() const{}
/*
 * Standard
 */

Standard:: Standard (string nome, float preco, int duracao): Servico(nome,preco,duracao){}

Standard:: ~Standard(){}

string Standard::classname() const{return "Standard";}

/*
 * NaoStandard
 */
naoStandard:: naoStandard (string nome, float preco, int duracao): Servico(nome,preco,duracao){}

naoStandard::~naoStandard(){}

string naoStandard:: classname() const{return "naoStandard";}
