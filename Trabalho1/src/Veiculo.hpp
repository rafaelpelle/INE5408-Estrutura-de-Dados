#ifndef VEICULO_H_
#define VEICULO_H_

#include <stdlib.h>
#include <time.h>

class Veiculo {
 public:
	// Construtor sem parâmetros da classe Veiculo
	Veiculo();

	// Destrutor da classe Veiculo
	virtual ~Veiculo();

	// Retorna o tamanho do Veiculo
	int getTamanho();

	// Retorna o número correspondente a posição da pista de destino do
	// Veiculo, no arranjo de Pista* da Pista onde o Veiculo está
	int getDestino();

 private:
	int _tamanho;
	int _destino;
	int gerarTamanhoAleatorio();
	int gerarDestinoAleatorio();
};


Veiculo::Veiculo() {
	int distanciaEntreCarros = 3;
	_tamanho = gerarTamanhoAleatorio() + distanciaEntreCarros;
	_destino = gerarDestinoAleatorio();
}

Veiculo::~Veiculo() {}

int Veiculo::getTamanho() {
	return _tamanho;
}

int Veiculo::getDestino() {
	return _destino;
}

int Veiculo::gerarTamanhoAleatorio() {
	srand((unsigned)time(NULL));
	return (rand() % 9) + 2;
}


int Veiculo::gerarDestinoAleatorio() {
	srand((unsigned)time(NULL));
	return rand() % 10;
}

#endif
