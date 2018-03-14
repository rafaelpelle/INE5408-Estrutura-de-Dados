#include "ListaEnc.hpp"
#include "Evento.hpp"

class Relogio: private ListaEnc<Evento*> {
 public:
	// Construtor da classe Relogio com o tempo pedido de simulação
	Relogio(double tempoLimite);

	// Construtor sem parâmetros da classe Relogio
	Relogio();

	// Destrutor da classe Relogio
	~Relogio();

	// Retorna o tempo de simulação atual
	double getTempoAtual();

	// Retorna o tempo limite de simulação
	double getTempoLimite();

	// Adiciona um Evento na ListaEnc de Eventos (em ordem
	// de horário, caso ele ocorra dentro do tempo limite)
	void adicionarEvento(Evento* evento);

	// Retira um Evento da ListaEnc de Eventos
	Evento* retirarEvento();

	// Retorna "verdadeiro" se a Lista de Eventos
	// contiver algum Evento
	bool aindaTemEventos();

	// Destroi o Relogio
	void destroiRelogio();

	// Retorna a quantidade de Evento que faltam executar
	int getTamanho() { return ListaEnc::getTamanho();}

 private:
	double _tempoAtual;
	double _tempoLimite;
};

Relogio::Relogio(double tempoLimite) {
	_tempoAtual = 0;
	_tempoLimite = tempoLimite;
}

Relogio::Relogio() {
	_tempoAtual = 0;
	_tempoLimite = 0;
}

Relogio::~Relogio() {
	destroiRelogio();
}

double Relogio::getTempoAtual() {
	return _tempoAtual;
}

double Relogio::getTempoLimite() {
	return _tempoLimite;
}

void Relogio::adicionarEvento(Evento* evento) {
	if (evento->getHorario() <= _tempoLimite) {
		ListaEnc::adicionaEmOrdem(evento);
	}
}

Evento* Relogio::retirarEvento() {
	return ListaEnc::retiraDoInicio();
}

void Relogio::destroiRelogio() {
	ListaEnc::destroiLista();
}

bool Relogio::aindaTemEventos() {
	return !ListaEnc::listaVazia();
}
