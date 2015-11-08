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

void Servico:: addtaxa(float tx){}
/*
 * Standard
 */
Standard:: Standard (string nome): Servico(nome){
	preco=50;
	duracao= 2;
	descricao.push_back("revisao");
	descricao.push_back("mudanca de oleo");
	descricao.push_back("limpeza");
}

void Standard:: setPreco(float p1){
	preco= p1;
}

void Standard:: setDuracao(int d1){
	duracao=d1;
}

void Standard:: setDescricao(vector<string> d1){
	descricao= d1;
}

float Standard:: getPreco() const{
	return preco;
}

int Standard:: getDuracao() const{
	return duracao;
}

vector<string> Standard:: getDescricao() const{
	return descricao;
}

void Standard:: displayServico() const{
	cout<<"preco: "<< preco<<" duracao: "<< duracao<<""
			"descricao: ";
	for(unsigned int i=0; i< descricao.size();i++){
		cout<<descricao[i]<<", ";
	}
	cout<<endl;
}

void Standard:: addtaxa(float tx){
	preco=preco+ preco*tx;
}

/*
 * NaoStandard
 */
naoStandard:: naoStandard (string nome, float preco, int duracao, vector<string> descricao): Servico(nome){
	this-> preco= preco;
	this-> duracao= duracao;
	this-> descricao= descricao;
}

float naoStandard:: getPreco() const{
	return preco;
}

int naoStandard:: getDuracao() const{
	return duracao;
}

vector<string> naoStandard:: getDescricao() const{
	return descricao;
}

void naoStandard:: displayServico() const{
	cout<<"preco: "<< preco<<"duracao: "<< duracao<<"descricao: ";
	for(unsigned int i=0; i< descricao.size();i++){
		cout<<descricao[i]<<", ";
	}
	cout<<endl;
}

void naoStandard:: addtaxa(float tx){
	preco=preco+ preco*tx;
}

