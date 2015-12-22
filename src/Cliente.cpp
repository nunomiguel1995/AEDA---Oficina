#include "Cliente.h"


static int ID=1;

/**
 * Construtor da classe Cliente
 * @param nome nome do cliente
 */

Cliente:: Cliente(string nome){
	this->nome=nome;
	this->id=ID;
	cartaoFidelizacao=0;
	servicosRealizados=0;
	ID++;
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
vector<Veiculo*> Cliente::getVeiculos() const{
	return veiculos;
}

/**
 * Retorna o veiculo cuja matricula � igual a mt
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
 * Adiciona o ve�culo ao vetor de veiculos do cliente e lan�a uma excecao, caso o veiculo ja exista
 * @param *v1
 */
void Cliente:: addVeiculo(Veiculo *v1){
	for(unsigned int i = 0; i < veiculos.size(); i++){
		if(veiculos[i]->getMatricula() == v1->getMatricula()) throw VeiculoExistente(v1->getMatricula());
	}
	veiculos.push_back(v1);
}

/**
 * Remove o veiculo do vetor de veiculos do cliente e lanca uma excecao, caso o veiculo nao exista
 * @param *v1
 */

void Cliente::removeVeiculo (Veiculo *v1){
	bool existe=false;
	unsigned int pos;
	for(pos = 0; pos < veiculos.size(); pos++){
		if(veiculos[pos]->getMatricula() == v1->getMatricula()){
			existe = true;
			veiculos.erase(veiculos.begin()+pos);
			break;
		}
	}
	if(!existe) throw VeiculoInexistente(v1->getMatricula());
}

/**
 * Overload do operador <
 * @param c1 , c2
 */
bool operator <(const Cliente   c1, const  Cliente c2) {
	if(c1.getPontos() < c2.getPontos()) return true;
	if(c1.getPontos() == c2.getPontos()){
		return (c1.getServicosRealizados() < c2.getServicosRealizados());
	}else return false;
}


/**
 * Mostra as informacoes do cliente - ID, nome e veiculos que possui
 */
void Cliente::displayCliente() const{
	cout << "Cliente n�" << id << " -> "<<  nome << ";\nVeiculos: \n";
	for(unsigned int i=0; i< veiculos.size();i++){
		veiculos[i]->displayVeiculo();
	}
}

/**
 * Muda o nome do cliente
 * @param nome novo nome do cliente
 */
void Cliente::setNome(string nome){
 this->nome = nome;
}

/*
 * Remove um servico associado a um veiculo do cliente
 * @param v, s
 */
void Cliente::removeServicoCliente(Veiculo* v, Servico* s){
	int posVeic=-1;
	//encontra veiculo
	for(unsigned int i = 0; i < veiculos.size(); i++){
		if(veiculos[i]->getMatricula() == v->getMatricula()) {
			posVeic = i;
			break;
		}
	}
	if(posVeic == -1) throw VeiculoInexistente(v->getMatricula());
	veiculos[posVeic]->removeServico(s);
}

/**
 * Incrementa o numero de servicos realizados
 */
void Cliente::incServicosRealizados(){
	servicosRealizados++;
}

/**
 * Muda os pontos do cliente para o int passado como parametro
 * @param pontos novos pontos do cliente
 */
void Cliente::setPontos(int pontos){
	cartaoFidelizacao = pontos;
}

/**
 * Retorna os pontos do cliente
 */
vector<pair <int, Date > > Cliente::getPontosData(){
	return pontosData;
}

/**
 * Altera o vetor de pares que contem quantos pontos foram adicionados numa dada data, para um novo vetor passado
 * @param p
 */
void Cliente::setPontosData(vector<pair < int, Date > > p){
	pontosData = p;
}

/**
 * Retiras os pares do vetor pontosData , quando os pontos sao utilizados numa oferta
 */
void Cliente::erasePontosData(){
	pontosData.erase(pontosData.begin(), pontosData.end());
}

/**
 * Verifica se o cliente esta inativo (nao realiza servicos pelo menos a um ano)
 */
bool Cliente::isInativo(Date &d1){
	bool inativo= true;
	for (unsigned int i=0; i < veiculos.size(); i++){
		vector<Servico*> servicos = veiculos[i]->getServicos();
		for (unsigned int j = 0; j < servicos.size(); j++){
			int dif = abs(d1.getAno() - servicos[j]->getDate().getAno());
			if (dif < 1) return false;
		}
	}
	return inativo;
}

/**
 * Overload do operador ==
 */
bool operator == (const Cliente c1, const Cliente c2){
	if(c1.getId()== c2.getId()) return true;
	else return false;
}
