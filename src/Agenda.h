#ifndef SRC_AGENDA_H_
#define SRC_AGENDA_H_

#include "Oficina.h"

using namespace std;

class Agenda{
	BST<Servico *> arvoreServicos;
public:
	Agenda() : arvoreServicos(new Servico("",0,0,Date())){};

	BST<Servico *> getServicos() const;
	vector<Servico *> getServicos(const Date d) const;

	void adicionaServico(Servico *s);
	bool remarcaServico(Servico *s, const Date &d);
	bool removeServico(Servico *s);
};

#endif
