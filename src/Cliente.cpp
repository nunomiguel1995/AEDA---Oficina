#include "Cliente.h"


static int ID=1;

/**
 * Construtor da classe Cliente
 * @param nome
 */

Cliente:: Cliente(string nome){
	this->nome=nome;
	this->id=ID;
	ID++;
}

/**
 * Retorna o nome do cliente
 */

string Cliente:: getNome()const{
	return nome;
}

/**
 * Retorna o id do cliente
 */

int Cliente:: getId() const{
	return id;
}

/**
 * Modifica o ID do cliente
 * @param id
 */

void Cliente::setId(unsigned int id){
	this->id = id;
}

<<<<<<< HEAD
/**
 * Retorna o vetor de ve�culos do cliente
 */
void Cliente::setVeiculos(vector<Veiculo*> veiculos){
	this->veiculos = veiculos;
}
=======

/**
 * Retorna o vetor de ve�culos do cliente
 */

void Cliente::setVeiculos(vector<Veiculo*> veiculos){
	this->veiculos = veiculos;
}

>>>>>>> 09d1e7ddd638a0ab9fb671853c0a08be51ea0d7b

vector <Veiculo*> Cliente:: getVeiculos() const{
	return veiculos;
}

<<<<<<< HEAD
=======

>>>>>>> 09d1e7ddd638a0ab9fb671853c0a08be51ea0d7b
/**
 * Adiciona o ve�culo ao vetor de ve�culos do cliente e lan�a uma exce��o, caso o ve�culo j� l� exista
 * @param *v1
 */
<<<<<<< HEAD
=======

>>>>>>> 09d1e7ddd638a0ab9fb671853c0a08be51ea0d7b
Veiculo * Cliente::getVeiculoMatricula(string mt) const{
	for(unsigned int i = 0; i < veiculos.size(); i++){
		if(veiculos[i]->getMatricula() == mt){
			return veiculos[i];
		}
	}
	throw VeiculoInexistente(mt);
}
<<<<<<< HEAD
=======

>>>>>>> 09d1e7ddd638a0ab9fb671853c0a08be51ea0d7b

void Cliente:: addVeiculo(Veiculo *v1){
	for(unsigned int i=0; i<veiculos.size();i++){
		if(veiculos[i]->getMatricula() ==v1->getMatricula()) throw(VeiculoExistente(v1->getMatricula()));
	}

	veiculos.push_back(v1);

}

/**
 * Remove o ve�culo do vetor de v�culos do cliente e lan�a uma exce�ao, caso o ve�culo n�o exista
 * @param *v1
 */

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

/**
 * Overload do operador <
 * @param c1, c2
 */

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


/**
 * Mostra as informa��es do cliente - ID, nome e ve�culos que possui
 */

void Cliente:: displayCliente() const{
	cout << "Cliente n�" << id << " -> "<<  nome << ";\nVeiculos: \n";
	for(unsigned int i=0; i< veiculos.size();i++){
		veiculos[i]->displayVeiculo();
	}
}
