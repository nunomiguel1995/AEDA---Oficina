#include "Oficina.h"

using namespace std;


/*
 * Cliente
 */
static int ID=1;

Cliente:: Cliente(string nome, int id){
	this->nome=nome;
	id=ID;
	ID++;
}

string Cliente:: getNome()const{
	return nome;
}

int Cliente:: getId() const{
	return id;
}

vector <Veiculo*> Cliente:: getVeiculos() const{
	return veiculos;
}

void Cliente:: addVeiculo(Veiculo *v1){
	for(unsigned int i=0; i<veiculos.size();i++){
		if(veiculos[i]->getMatricula() ==v1->getMatricula()) throw(VeiculoExistente(v1->getMatricula()));
	}

	veiculos.push_back(v1);

}

void Cliente:: removeVeiculo (Veiculo *v1){
	bool existe=false;
	int pos;
	for(pos=0; pos<veiculos.size();pos++){
		if(veiculos[pos]->getMatricula()==v1->getMatricula()){
			existe=true;
			break;
		}
	}

	if(!existe) throw(VeiculoInexistente(v1->getMatricula()));

	veiculos.erase(veiculos.begin()+pos);
}
