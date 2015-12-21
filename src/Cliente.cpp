#include "Cliente.h"
#include <math.h>


static int ID=1;

/**
 * Construtor da classe Cliente
 * @param nome nome do cliente
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
 * Atribui o ID ao cliente
 * @param id
 */

void Cliente::setId(unsigned int id){
	this->id = id;
	ID = id;
}

/**
 * Atribui o vetor passado como parametro ao vetor de veiculos do Cliente
 * @param veiculos
 */
void Cliente::setVeiculos(vector<Veiculo*> veiculos){
	this->veiculos = veiculos;
}

/**
 * Retorna o vetor veiculos do Cliente
 */
vector <Veiculo*> Cliente:: getVeiculos() const{
	return veiculos;
}

/**
 * Retorna o veiculo cuja matricula é igual a mt
 * @param mt matricula do veiculo a procurar
 */
Veiculo * Cliente::getVeiculoMatricula(string mt) const{
	for(unsigned int i = 0; i < veiculos.size(); i++){
		if(veiculos[i]->getMatricula() == mt){
			return veiculos[i];
		}
	}
	throw VeiculoInexistente(mt);
}

/**
 * Adiciona o veículo ao vetor de veiculos do cliente e lança uma excecao, caso o veiculo ja exista
 * @param *v1
 */
void Cliente:: addVeiculo(Veiculo *v1){
	for(unsigned int i=0; i<veiculos.size();i++){
		if(veiculos[i]->getMatricula() ==v1->getMatricula()) throw(VeiculoExistente(v1->getMatricula()));
	}

	veiculos.push_back(v1);

}

/**
 * Remove o veiculo do vetor de veiculos do cliente e lanca uma excecao, caso o veiculo nao exista
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
 * @param c1 , c2
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
 * Mostra as informacoes do cliente - ID, nome e veiculos que possui
 */

void Cliente:: displayCliente() const{
	cout << "Cliente nº" << id << " -> "<<  nome << ";\nVeiculos: \n";
	for(unsigned int i=0; i< veiculos.size();i++){
		veiculos[i]->displayVeiculo();
	}
}

void Cliente:: setNome(string nome){
 this->nome= nome;
}


bool Cliente::isInativo(Date &d1){

bool inativo= true;

	for (unsigned int i=0; i<veiculos.size();i++){
		vector<Servico*> servicos = veiculos[i]->getServicos();
		for (unsigned int j=0; j<servicos.size(); j++){
			int dif = abs(d1.getAno() - servicos[j]->getDate().getAno());
			if (dif < 1) return false;
		}
	}
	return inativo;
}
