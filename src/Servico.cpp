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
<<<<<<< HEAD
Standard:: Standard (string nome): Servico(nome){
	preco=50;
	duracao= 2;
	descricao.push_back("revisao");
	descricao.push_back("mudanca de oleo");
	descricao.push_back("limpeza");
	descricao.push_back("mudanca de pneus");
}

void Standard:: setPreco(float p1){
	preco= p1;
}

void Standard:: setDuracao(int d1){
	duracao=d1;
}


naoStandard:: naoStandard(string nome, float preco, int duracao, vector<string> descricao): Servico(nome){
	this->preco=preco;
	this->duracao=duracao;
	this->descricao=descricao;
}

void Standard:: setDescricao(vector<string> d1){
	descricao= d1;
=======
Standard:: Standard (string nome, float preco, int duracao): Servico(nome){
	this->preco=preco;
	this->duracao= duracao;
>>>>>>> 41424a8c60163e2566de67a1a4f2dfc359c8b104
}

float Standard:: getPreco() const{
	return preco;
}

int Standard:: getDuracao() const{
	return duracao;
}


void Standard:: displayServico() const{
<<<<<<< HEAD
	cout<<"preco: "<< preco <<"duracao: "<< duracao <<"descricao: ";
	for(unsigned int i=0; i< descricao.size();i++){
		cout<<descricao[i]<<", ";
	}
	cout<<endl;

=======
	cout<<"preco: "<< preco<<" duracao: "<< duracao;

	cout<<endl;
>>>>>>> 41424a8c60163e2566de67a1a4f2dfc359c8b104
}

void Standard:: addTaxa(float tx){
	preco=preco+ preco*tx;
}

<<<<<<< HEAD
=======
/*
 * NaoStandard
 */
naoStandard:: naoStandard (string nome, float preco, int duracao): Servico(nome){
	this-> preco= preco;
	this-> duracao= duracao;
}
>>>>>>> 41424a8c60163e2566de67a1a4f2dfc359c8b104

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

