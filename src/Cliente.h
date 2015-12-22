#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include "Veiculo.h"
#include "Excepcoes.h"
#include "Date.h"
#include <stdlib.h>

using namespace std;

class Cliente{
	string nome;
	int id;
	int cartaoFidelizacao;
	vector<Veiculo *> veiculos;
	vector <pair <int, Date> > pontosData;
	int servicosRealizados;
	string email;
	int telef;
	string morada;
public:
	Cliente(string nome);

	string getNome() const {return nome;};
	string getMorada() const {return morada;};
	string getEmail() const {return email;};
	int getId() const {return id;};
	int getTelef() const {return telef;};
	int getPontos() const {return cartaoFidelizacao;};
	int getServicosRealizados() const {return servicosRealizados;};
	Veiculo * getVeiculoMatricula(string mt) const;
	vector <Veiculo*> getVeiculos() const;
	vector <pair <int, Date > > getPontosData();

	void setId(unsigned int id);
	void setVeiculos(vector<Veiculo*> veiculos);
	void setNome(string nome);
	void setPontos(int pontos);
	void setPontosData(vector <pair < int,Date > > p);

	void addVeiculo(Veiculo *v1);
	void removeVeiculo (Veiculo *v1);
	void displayCliente() const;
	void removeServicoCliente(Veiculo* v, Servico* s);
	void incServicosRealizados();
	void erasePontosData();
	bool isInativo(Date &d1);

	friend bool operator <( const Cliente  c1, const Cliente c2);

};

#endif /* SRC_CLIENTE_H_ */
