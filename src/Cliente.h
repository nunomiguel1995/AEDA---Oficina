#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include "Veiculo.h"
#include "Excepcoes.h"
#include "Date.h"
<<<<<<< HEAD
=======
#include <stdlib.h>
>>>>>>> 43f711f759709609df12b97f64e2fb90762f02a6

using namespace std;

class Cliente{
	string nome;
	int id;
	int cartaoFidelizacao;
	vector<Veiculo *> veiculos;
<<<<<<< HEAD
	vector <pair <int, Date> > pontosData;
	int servicosRealizados;
=======
	string email;
	int telef;
	string morada;

>>>>>>> 43f711f759709609df12b97f64e2fb90762f02a6
public:
	Cliente(string nome);
	string getNome() const;
	int getId() const;
	string getEmail() const {return email;};
	int getTelef() const {return telef;};
	string getMorada() const {return morada;};
	void setId(unsigned int id);
	void setVeiculos(vector<Veiculo*> veiculos);
	void setNome(string nome);
	Veiculo * getVeiculoMatricula(string mt) const;
	vector <Veiculo*> getVeiculos() const;
	void addVeiculo(Veiculo *v1);
	void removeVeiculo (Veiculo *v1);
	void displayCliente() const;
<<<<<<< HEAD
	int getPontos() const {return cartaoFidelizacao;};
	int getServicosRealizados() const {return servicosRealizados;};
	friend bool operator <( const Cliente  c1, const Cliente c2);
	void removeServicoCliente(Veiculo* v, Servico* s);
	void incServicosRealizados();
	void setPontos(int pontos);
	vector <pair <int, Date > > getPontosData();
	void setPontosData(vector <pair < int,Date > > p);
	void erasePontosData();
=======
	bool isInativo(Date &d1);
>>>>>>> 43f711f759709609df12b97f64e2fb90762f02a6
};

#endif /* SRC_CLIENTE_H_ */
