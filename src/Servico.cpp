#include "Servico.h"

 /*
  * Servi�o
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
 * Retorna o pre�o do servico
 */
float Servico:: getPreco() const{
	return preco;
}

/**
 * Retorna a dura��o do servico
 */
int Servico:: getDuracao() const{
	return duracao;
}

Date Servico::getDate() const{
	return this->date;
}

/**
 * Mostra os atributos do servico- nome, pre�o e duracao
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
 * Modifica a data do Servico para a data passada como parametro
 */
void Servico::setDate(Date d){
	this->date = d;
}

/**
 * Overload do operador <
 */
bool Servico::operator < (const Servico *s){
	if(date < s->getDate()){
		return true;
	}else if(duracao < s->getDuracao()){
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

/**
 * Imprime os dados de um servico
 */
void Servico:: print(){
	cout<<"Nome: "<< nome << " Data: ";
	date.print() ;
	cout << endl;
}
