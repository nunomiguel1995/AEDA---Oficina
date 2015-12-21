#ifndef SRC_AGENDA_H_
#define SRC_AGENDA_H_

#include "Oficina.h"

using namespace std;

class Agenda{
	BST<Servico *> arvoreServicos;
public:
	Agenda() : arvoreServicos(Servico("",0,0,NULL)){};
	BST<Servico *> getServicos() const;
	vector<Servico *> getServicos(Date d) const;
	bool marca(Servico *s);
	bool remarca(Date d);
	bool remove(Servico *s);
	bool adicionaServico(Cliente c, Servico *s);
};

#endif
