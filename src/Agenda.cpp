#include "Agenda.h"

BST<Servico *> Agenda::getServicos() const{
	return arvoreServicos;
}

vector<Servico *> Agenda::getServicos(Date d) const{
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

bool Agenda::adicionaServico(Servico *s){
	arvoreServicos.insert(s);
	return true;
}

bool Agenda::remarcaServico(Servico *s, Date d){
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
