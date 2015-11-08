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
Standard:: Standard (string nome, float preco, int duracao): Servico(nome){
	this->preco=preco;
	this->duracao= duracao;
}


naoStandard:: naoStandard(string nome, float preco, int duracao): Servico(nome){
	this->preco=preco;
	this->duracao=duracao;
}


=======
>>>>>>> b77e5ef6ee156b41f250a2dec113aedcff8b5f58
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
<<<<<<< HEAD
	cout<<"preco: "<< preco <<"duracao: "<< duracao;
=======
	cout << "preco: "<< preco <<" duracao: "<< duracao << endl;
>>>>>>> b77e5ef6ee156b41f250a2dec113aedcff8b5f58
}

void Standard:: addTaxa(float tx){
	preco=preco+ preco*tx;
}

<<<<<<< HEAD

=======
>>>>>>> b77e5ef6ee156b41f250a2dec113aedcff8b5f58
/*
 * NaoStandard
 */
naoStandard:: naoStandard (string nome, float preco, int duracao): Servico(nome){
	this-> preco= preco;
	this-> duracao= duracao;
}
<<<<<<< HEAD

=======
>>>>>>> b77e5ef6ee156b41f250a2dec113aedcff8b5f58

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

