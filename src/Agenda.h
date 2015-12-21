#ifndef SRC_AGENDA_H_
#define SRC_AGENDA_H_

#include "Oficina.h"

using namespace std;

class Agenda{
	BST<Servico *> arvoreServicos;
public:
	Agenda() : arvoreServicos(new Servico("",0,0,Date())){};
	BST<Servico *> getServicos() const;
	vector<Servico *> getServicos(Date d) const;
	bool adicionaServico(Servico *s);
	bool remarcaServico(Servico *s, Date d);
	bool removeServico(Servico *s);
};

#endif
