#include "Servico.h"

Servico:: Servico(string nome){
	this-> nome =nome;
}


string Servico::getNome(){
	return nome;
}


Standard::Standard (string nome): Servico (nome){
	//falt inicializar as variaveis DECIDIR
};

naoStandard:: naoStandard(string nome, float preco, int duracao, vector<string> descricao): Servico(nome){
	this->preco=preco;
	this->duracao=duracao;
	this->descricao=descricao;
}

