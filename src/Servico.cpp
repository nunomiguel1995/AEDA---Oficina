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
naoStandard:: naoStandard(string nome, float preco, int duracao, vector<string> descricao): Servico(nome){
	this->preco=preco;
	this->duracao=duracao;
	this->descricao=descricao;
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
	cout<<"preco: "<< preco <<"duracao: "<< duracao <<"descricao: ";
	for(unsigned int i=0; i< descricao.size();i++){
		cout<<descricao[i]<<", ";
	}
	cout<<endl;

	cout<<"preco: "<< preco<<" duracao: "<< duracao;

	cout<<endl;
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

