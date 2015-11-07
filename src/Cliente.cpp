#include "Cliente.h"


static int ID=1;

Cliente:: Cliente(string nome){
	this->nome=nome;
	this->id=ID;
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
	unsigned int pos;
	for(pos=0; pos<veiculos.size();pos++){
		if(veiculos[pos]->getMatricula()==v1->getMatricula()){
			existe=true;
			veiculos.erase(veiculos.begin()+pos);
			break;
		}
	}

	if(!existe) throw(VeiculoInexistente(v1->getMatricula()));
}

bool operator <(const Cliente c1, const Cliente c2){
	int size1= c1.getVeiculos().size();
	int size2= c2.getVeiculos().size();

	if(size1 < size2) return true;
	if(size1> size2) return false;
	if(size1 == size2){
		if(c1.getNome()<c2.getNome()) return true;
		else return false;
	}
}

void Cliente:: displayCliente() const{
	cout<<nome<<"; "<<id<<"veiculos: ";

	for(unsigned int i=0; i< veiculos.size();i++){
		veiculos[i]->displayVeiculo();
		cout<<", ";
	}
	cout<<endl;
}
