#include <iostream>
#include <stdlib.h>
#include "Veiculo.h"
#include "Funcionario.h"
#include "Oficina.h"
#include "Cliente.h"
#include "Excepcoes.h"
#include "Menu.h"

using namespace std;

int main(){
	Oficina oficina("Oficina");
	Menu m;

	oficina.leFuncionarios();
	oficina.leClientes();
	oficina.leVeiculos();
	oficina.leServicos();

	m.menu(oficina);

	oficina.guardaVeiculos();
	oficina.guardaClientes();
	oficina.guardaServicos();
	oficina.guardaFuncionarios();

	return 0;
}
