#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include "Veiculo.h"
#include "Excepcoes.h"
#include "Date.h"

using namespace std;

class Cliente{
	string nome;
	int id;
	int cartaoFidelizacao;
	vector<Veiculo *> veiculos;
	vector <pair <int, Date> > pontosData;
	int servicosRealizados;
public:
	Cliente(string nome);
	string getNome() const;
	int getId() const;
	void setId(unsigned int id);
	void setVeiculos(vector<Veiculo*> veiculos);
	void setNome(string nome);
	Veiculo * getVeiculoMatricula(string mt) const;
	vector <Veiculo*> getVeiculos() const;
	void addVeiculo(Veiculo *v1);
	void removeVeiculo (Veiculo *v1);
	void displayCliente() const;
	int getPontos() const {return cartaoFidelizacao;};
	int getServicosRealizados() const {return servicosRealizados;};
	friend bool operator <( const Cliente  c1, const Cliente c2);
	void removeServicoCliente(Veiculo* v, Servico* s);
	void incServicosRealizados();
	void setPontos(int pontos);
	vector <pair <int, Date > > getPontosData();
	void setPontosData(vector <pair < int,Date > > p);
	void erasePontosData();
};

#endif /* SRC_CLIENTE_H_ */
