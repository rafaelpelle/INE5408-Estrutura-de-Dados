#include <string>
#include "Veiculo.hpp"
#include "FilaEnc.hpp"
#include "ListaEnc.hpp"

class Pista : private FilaEnc<Veiculo*> {
public:
	// Construtor sem parâmetros da classe Pista
	Pista();

	// Construtor da classe Pista
	Pista(std::string& _nome, int _v, int _s, int _freq, int _var, bool _fonte, bool _sumidouro);

	// Destrutor da classe Pista
	~Pista();

	// Retorna o nome da Pista em forma de string (Ex:"C1oeste")
	std::string getNome();

	// Retorna a velocidade dos veiculos na Pista
	int getVelocidade();

	// Retorna o tamanho da Pista
	int getTamanho();

	// Retorna o espaço ainda desocupado da Pista
	int getEspacoLivre();

	// Retorna a frequência com que os carros entram na Pista.
	int getTempoEntreCarros();

	// Retorna "verdadeiro" caso a Pista seja uma pista fonte,
	// caso contrário, retorna "falso"
	bool getFonte();

	// Retorna "verdadeiro" caso a Pista seja uma pista sumidouro,
	// caso contrário, retorna "falso"
	bool getSumidouro();

	// Insere um veículo (parâmetro) na Pista
	void inserirVeiculo(Veiculo* v);

	// Retira o primeiro veículo da Pista
	Veiculo* retirarVeiculo();

	// Coloca o semáforo da Pista como "verdadeiro", ou seja, aberto
	void abrirSemaforo();

	// Coloca o semáforo da Pista como "falso", ou seja, fechado
	void fecharSemaforo();

	// Retorna "verdadeiro" caso o semáforo esteja aberto,
	// caso contrário, retorna "falso"
	bool getSemaforoEstaAberto();

	// Retorna a quantidade de veículos que entraram na Pista (0 se não for fonte)
	int getQtdVeiculosQueEntraram();

	// Retorna a quantidade de veículos que saíram da Pista (0 se não for sumidouro)
	int getQtdVeiculosQueSairam();

	// Estabelece as pistas de destino em um arranjo de Pista* que respeita
	// as probabilidades de destino estabelecidas.
	void setPistasDestino(Pista** pistasDestino);

	// Retorna o ponteiro para a pista de destino da posição "destino" do
	// arranjo de Pista* com os possíveis destinos
	Pista* getPistaDestino(int destino);

private:
	std::string _nome;
	int _v;
	int _s;
	int _freq;
	int _var;
	bool _cheia;
	bool _fonte;
	bool _sumidouro;
	Pista** _pistasDestino;
	bool _semaforoEstaAberto;
	int _qtdVeiculosQueEntraram;
	int _qtdVeiculosQueSairam;
	int _tamanhoOcupado;
};

Pista::Pista() {
	_nome = "Vazio";
	_v = 0;
	_s = 0;
	_freq = 0;
	_var = 0;
	_cheia = 0;
	_fonte = 0;
	_sumidouro = 0;
	_pistasDestino = 0;
	_semaforoEstaAberto = 0;
	_qtdVeiculosQueEntraram = 0;
	_qtdVeiculosQueSairam = 0;
	_tamanhoOcupado = 0;
}

Pista::Pista(std::string& nome, int v, int s, int freq, int var, bool fonte, bool sumidouro) {
	_nome = nome;
	_v = v;
	_s = s;
	_freq = freq;
	_var = var;
	_cheia = false;
	_fonte = fonte;
	_sumidouro = sumidouro;
	_pistasDestino = NULL;
	_semaforoEstaAberto = false;
	_qtdVeiculosQueEntraram = 0;
	_qtdVeiculosQueSairam = 0;
	_tamanhoOcupado = 0;
}

Pista::~Pista() {}

std::string Pista::getNome() {
	return _nome;
}

int Pista::getVelocidade() {
	return _v;
}

int Pista::getTamanho() {
	return _s;
}

int Pista::getEspacoLivre() {
	return getTamanho() - _tamanhoOcupado;
}

int Pista::getTempoEntreCarros() {
	srand((unsigned)time(NULL));
	return (rand() % _var) + _freq;
}

bool Pista::getFonte() {
	return _fonte;
}

bool Pista::getSumidouro() {
	return _sumidouro;
}

void Pista::inserirVeiculo(Veiculo* v) {
	FilaEnc::inclui(v);
	_qtdVeiculosQueEntraram++;
	_tamanhoOcupado += v->getTamanho();
}

Veiculo* Pista::retirarVeiculo() {
	Veiculo* veiculo = FilaEnc::retira();
	_qtdVeiculosQueSairam++;
	_tamanhoOcupado -= veiculo->getTamanho();
	return veiculo;
}

void Pista::abrirSemaforo() {
	_semaforoEstaAberto = true;
}

void Pista::fecharSemaforo() {
	_semaforoEstaAberto = false;
}

bool Pista::getSemaforoEstaAberto() {
	return _semaforoEstaAberto;
}

int Pista::getQtdVeiculosQueEntraram() {
	return _qtdVeiculosQueEntraram;
}

int Pista::getQtdVeiculosQueSairam() {
	return _qtdVeiculosQueSairam;
}

void Pista::setPistasDestino(Pista** pistasDestino) {
	_pistasDestino = pistasDestino;
}

Pista* Pista::getPistaDestino(int destino) {
	return _pistasDestino[destino];
}
