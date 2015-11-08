#include "Servico.h"

 /*
  * Serviço
  */
Servico:: Servico(string nome){
	this-> nome =nome;
}


string Servico::getNome(){
	return nome;
}

void Servico:: displayServico() const{
	cout<<nome<< " ";
}

void Servico:: addTaxa(float tx){}
/*
 * Standard
 */

Standard:: Standard (string nome, float preco, int duracao): Servico(nome){
	this->preco=preco;
	this->duracao= duracao;
}


naoStandard:: naoStandard(string nome, float preco, int duracao): Servico(nome){
	this->preco=preco;
	this->duracao=duracao;
}


Standard:: Standard (string nome, float preco, int duracao): Servico(nome){
	this->preco=preco;
	this->duracao= duracao;
}

float Standard:: getPreco() const{
	return preco;
}

int Standard:: getDuracao() const{
	return duracao;
}


void Standard:: displayServico() const{
	cout<<"preco: "<< preco <<"duracao: "<< duracao;
}

void Standard:: addTaxa(float tx){
	preco=preco+ preco*tx;
}


/*
 * NaoStandard
 */
naoStandard:: naoStandard (string nome, float preco, int duracao): Servico(nome){
	this-> preco= preco;
	this-> duracao= duracao;
}


float naoStandard:: getPreco() const{
	return preco;
}

int naoStandard:: getDuracao() const{
	return duracao;
}


void naoStandard:: displayServico() const{
	cout<<"preco: "<< preco<<"duracao: "<< duracao;

	cout<<endl;
}

void naoStandard:: addTaxa(float tx){
	preco=preco+ preco*tx;
}

