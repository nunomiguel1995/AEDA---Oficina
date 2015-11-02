#include "Funcionario.h"


Funcionario:: Funcionario(string n): nome(n){}

vector <Veiculo *> Funcionario:: getVeiculos() const{ return veiculos;}

void Funcionario:: addVeiculo(Veiculo *v1){
	for(unsigned int i=0; i<veiculos.size();i++){
		if(veiculos[i]->getMatricula()== v1->getMatricula()) throw (VeiculoExistente(v1->getMatricula()));
	}
	veiculos.push_back(v1);
}

void Funcionario:: removeVeiculo(Veiculo *v1){
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

string Funcionario:: getNome() const{
	return nome;
}

void Funcionario::displayVeiculos() const{
	cout << "Veiculo(s) do funcionário " << nome << ": \n";
	for(unsigned int i = 0; i < veiculos.size(); i++){
		cout << veiculos[i]->getMarca() << " ; " << veiculos[i]->getMatricula() << endl;
	}
}



