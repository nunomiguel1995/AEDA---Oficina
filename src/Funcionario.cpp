#include "Funcionario.h"

/**
 * Construtor da classe Funcionario
 * @param n nome do funcionario
 */
Funcionario:: Funcionario(string n): nome(n){}

/**
 * Retorna o vetor veiculos pelos quais o funcionario e responsável
 */
vector <Veiculo *> Funcionario:: getVeiculos() const{ return veiculos;}

/**
 * Adiciona um veiculo ao vetor de veiculos de cada funcionario e lança uma exceçao, caso ele ja exista
 * @param v1 veiculo a adicionar
 */
void Funcionario:: addVeiculo(Veiculo * v1){
	for(unsigned int i=0; i<veiculos.size();i++){
		if(veiculos[i]->getMatricula()== v1->getMatricula()) throw (VeiculoExistente(v1->getMatricula()));
	}
	veiculos.push_back(v1);
}

/**
 * Remove um veiculo do vetor de veiculos de cada funcionario e lança uma exceçao, caso ele nao exista
 * @param v1 veiculo a adicionar
 */

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

/**
 * Retorna o nome do funcionario
 */
string Funcionario:: getNome() const{
	return nome;
}

/**
 * Mostra o vetor de veiculos pelos quais o funcionario é responsavel
 */

void Funcionario::displayVeiculos() const{
	for(unsigned int i = 0; i < veiculos.size(); i++){
		veiculos[i]->displayVeiculo();
	}
}

/**
 * Modifica o vetor veiculos, ficando este igual ao vetor passado como argumento
 * @param veic vetor de veiculos
 */

void Funcionario::setVeiculos(vector<Veiculo*> veic){
	veiculos = veic;
}

/**
 * Overload do operador <
 * @param f1, f2
 */
bool operator<(const Funcionario f1, const Funcionario f2){
	int size1= f1.getVeiculos().size();
	int size2= f2.getVeiculos().size();

	if(size1 < size2) return true;
	if(size1> size2) return false;
	if(size1 == size2){
		if(f1.getNome()<f2.getNome()) return true;
		else return false;
	}
}

/**
 * Mostra o nome do funcionario e todos os veiculos associado a ele
 */
void Funcionario:: displayFuncionario() const{
	cout<< nome << " ";
	this->displayVeiculos();
}
