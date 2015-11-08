#include "Funcionario.h"

/**
 * Construtor da classe Funcionario
 */
Funcionario:: Funcionario(string n): nome(n){}

/**
 * Retorna o vetor ve�culos pelos quais o funcion�rio � respons�vel
 */
vector <Veiculo *> Funcionario:: getVeiculos() const{ return veiculos;}

/**
 * Adiciona um ve�culo ao vetor de ve�culos de cada funcion�rio e lan�a uma exce��o, caso ele j� exista
 */
void Funcionario:: addVeiculo(Veiculo * v1){
	for(unsigned int i=0; i<veiculos.size();i++){
		if(veiculos[i]->getMatricula()== v1->getMatricula()) throw (VeiculoExistente(v1->getMatricula()));
	}
	veiculos.push_back(v1);
}

/**
 * Remove um ve�culo do vetor de ve�culos de cada funcion�rio e lan�a uma exce��o, caso ele n�o exista
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
 * Retorna o nome do funcion�rio
 */
string Funcionario:: getNome() const{
	return nome;
}

/**
 * Mostra o vetor de ve�culos pelos quais o funcion�rio � respons�vel
 */

void Funcionario::displayVeiculos() const{
	for(unsigned int i = 0; i < veiculos.size(); i++){
		veiculos[i]->displayVeiculo();
	}
}

/**
 * Modifica o vetor ve�culos, ficando este igual ao vetor passado como argumento
 * @param veic
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

void Funcionario:: displayFuncionario() const{
	cout<<nome<< "veiculos: ";
	this->displayVeiculos();
}
