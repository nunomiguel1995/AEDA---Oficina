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
Servico:: Servico(string n,float p, int dur, Date d) : nome(n), preco(p), duracao(dur), date(d){}

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

Date Servico::getDate() const{
	return this->date;
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

void Servico::setDate(Date d){
	this->date = d;
}

//organizados na árvore a partir da dada e hora do seu
//agendamento.
//Para agendamentos marcados para o mesmo dia e hora, estes deverão ser
//organizados pelo nome dos seus clientes.
bool Servico::operator < (const Servico *s) const {
	if(getDate() < s->getDate()){
		return true;
	}else if(nomeCliente < s->nomeCliente){
		return true;
	}
	return false;
}


/**
 * Construtor da classe Standard
 */
Standard:: Standard (string n, float p, int dur, Date d) : Servico(n,p,dur,d){}

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
naoStandard:: naoStandard (string n, float p, int dur, Date d): Servico(n,p,dur,d){}

/**
 * Destrutor da classe nao Standard
 */
naoStandard::~naoStandard(){}


/**
 * Nome da Classe
 */
string naoStandard:: classname() const{return "naoStandard";}

/**
 * Altera a data do servico para a data passada como parametro
 */
bool Servico::alteraDataServico(Date s){
	if( s == date) return false;

	date=s;
	return true;
}

void Servico:: print(){
	cout<<"Nome: "<< nome << " Data: ";
	date.print() ;
	cout << endl;
}
