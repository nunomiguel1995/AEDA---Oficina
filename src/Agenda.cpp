#include "Agenda.h"

BST<Servico *> Agenda::getServicos() const{
	return arvoreServicos;
}

vector<Servico *> Agenda::getServicos(const Date d) const{
	BSTItrIn<Servico *> it(arvoreServicos);
	vector<Servico *> servData;
	while(!it.isAtEnd()){
		if(it.retrieve()->getDate() == d){
			servData.push_back(it.retrieve());
		}
		it.advance();
	}
	return servData;
}

void Agenda::adicionaServico(Servico *s){
	arvoreServicos.insert(s);
}

bool Agenda::remarcaServico(Servico *s, const Date &d){
	BSTItrIn<Servico *> it(arvoreServicos);
	while(!it.isAtEnd()){
		if(it.retrieve() == s){
			it.retrieve()->setDate(d);
			return true;
		}
		it.advance();
	}
	return false;
}

bool Agenda::removeServico(Servico *s){
	BSTItrIn<Servico *> it(arvoreServicos);
	while(!it.isAtEnd()){
		if(it.retrieve() == s){
			arvoreServicos.remove(it.retrieve());
			return true;
		}
		it.advance();
	}
	return false;
}
