#include <stdlib.h>
#include <iostream>
#include "ListaEnc.hpp"
#include "Pista.hpp"
#include "Relogio.hpp"
#include <time.h>

using namespace std;

int const ChegadaDeUmNovoVeiculo = -1;
int const AberturaDeSemaforo = -2;
int const FechamentoDeSemaforo = -3;
int const ChegadaDeVeiculoAoSemaforo = -4;
int const TrocaDePista = -5;
int const SumirVeiculo = -6;

ListaEnc<Pista*> listaDePistas; // Lista que contem todas as Pistas do Sistema.
Relogio relogio; //Relógio do Sistema.

// Mostra na tela os parâmetros de execução e quantos carros entraram e saíram do sistema .
void mostrarResultados(double tempoDeExecucao, double t_Oeste, double t_Leste, double t_Sul, double t_Norte) {
	cout << "Tempo de execução: " << tempoDeExecucao << " segundos." << endl;
	cout << "Tempo de abertura semárofos sentido oeste: " << t_Oeste << " segundos." << endl;
	cout << "Tempo de abertura semárofos sentido leste: " << t_Leste << " segundos." << endl;
	cout << "Tempo de abertura semárofos sentido sul: " << t_Sul << " segundos." << endl;
	cout << "Tempo de abertura semárofos sentido norte: " << t_Norte << " segundos." << endl;
	int totalVeiculosQueEntraram = 0;
	int totalVeiculosQueSairam = 0;
	for (int i = 0; i < 14; i++) {
		Pista pista = *listaDePistas.retira();
		if (pista.getFonte()) {
			cout << "Entraram na pista " << pista.getNome() << " " << pista.getQtdVeiculosQueEntraram() << " veículos." << endl;
			totalVeiculosQueEntraram += pista.getQtdVeiculosQueEntraram();
		} else if (pista.getSumidouro()) {
			cout << "Sumiram da pista " << pista.getNome() << " " << pista.getQtdVeiculosQueSairam() << " veículos." << endl;
			totalVeiculosQueSairam += pista.getQtdVeiculosQueSairam();
		}
	}
	cout << "Quantidade de veículos que entraram: " << totalVeiculosQueEntraram << endl;
	cout << "Quantidade de veículos que sairam: " << totalVeiculosQueSairam << endl;
}

// Insere um veiculo em uma pista.
// Se a pista não tiver espaço para receber o veiculo então
// o evento de inserção do veiculo é adiado 5 segundos.
void realizarChegadaDeUmNovoCarro(Evento* evento) {
	Pista* pista = evento->getLocal1();
	Veiculo* veiculo = evento->getVeiculo();
	if (pista->getEspacoLivre() >= veiculo->getTamanho()) {
		pista->inserirVeiculo(veiculo);
	} else {
		int tipo = evento->getTipo();
		double horario = evento->getHorario() + 10;
		Pista* local1 = evento->getLocal1();
		Veiculo* veiculo = evento->getVeiculo();
		Evento* chegadaRemarcada = new Evento(tipo, horario, local1, veiculo);
		relogio.adicionarEvento(chegadaRemarcada);
	}
}

// Quando um carro chega ao semáforo ele agenda um evento de troca de pista.
void realizarChegadaDeCarroAoSemaforo(Evento* evento) {
	int destinoAleatorio = evento->getVeiculo()->getDestino();
	double tempo = evento->getHorario();
	Pista* pistaOrigem = evento->getLocal1();
	Pista* pistaDestino = pistaOrigem->getPistaDestino(destinoAleatorio);
	Veiculo* veiculo = evento->getVeiculo();
	Evento* trocaPista = new Evento(TrocaDePista, tempo, pistaOrigem, pistaDestino, veiculo);
	relogio.adicionarEvento(trocaPista);
}

// Abre um semáforo em sincronia com o semafóro de mesmo sentido no outro cruzamento.
void realizarAberturaDeSemaforo(Evento* evento) {
	evento->getLocal1()->abrirSemaforo();
	evento->getLocal2()->abrirSemaforo();
}

// Fecha um semáforo em sincronia com o semafóro de mesmo sentido no outro cruzamento.
void realizarFechamentoDeSemaforo(Evento* evento) {
	evento->getLocal1()->fecharSemaforo();
	evento->getLocal2()->fecharSemaforo();
}

// Quando um veículo chega ao fim de uma pista sumidouro ele é retirado.
void realizarEventoSumirVeiculo(Evento* evento) {
	Pista* pistaSumidouro = evento->getLocal1();
	pistaSumidouro->retirarVeiculo();
}

// Adiciona ao relógio um evento para retirar um veículo de uma Pista sumidouro.
void adicionarEventoSumirVeiculo(Pista* pista, Veiculo* veiculo, int horaQueEntrouNaPista) {
	int distanciaAPercorrer = pista->getTamanho() - veiculo->getTamanho();
	double velocidadeMS = pista->getVelocidade() / 3.6;
	double tempoQueDemorou = distanciaAPercorrer / velocidadeMS;
	Evento* sumirVeiculo = new Evento(SumirVeiculo, horaQueEntrouNaPista + tempoQueDemorou, pista, veiculo);
	relogio.adicionarEvento(sumirVeiculo);
}

// Adiciona o evento de chegada de um veículo ao semafóro.
void adicionarChegadaDeVeiculoAoSemaforo(Pista* pista, Veiculo* veiculo, int tempo) {
	int distanciaAPercorrer = pista->getTamanho() - veiculo->getTamanho();
	double velocidadeMS = pista->getVelocidade() / 3.6;
	double tempoQueDemorou = distanciaAPercorrer / velocidadeMS;
	Evento* chegadaAoSemaforo = new Evento(ChegadaDeVeiculoAoSemaforo, tempo+tempoQueDemorou, pista, veiculo);
	relogio.adicionarEvento(chegadaAoSemaforo);
}

// Troca o veiculo, da pistaOrigem para a pistaDestino caso a pistaDestino tenha espaço suficiente e
// a pistaOrigem esteja com seu semáforo aberto, caso contrário remarca o evento para depois de 5 segundos.
// Se pistaDestino for sumidouro a função adicionarEventoSumirVeiculo é chamada, senão a função adicionarChegadaDeVeiculoAoSemaforo()
void realizarTrocaDePista(Evento* evento) {
	Pista* pistaOrigem = evento->getLocal1();
	Pista* pistaDestino = evento->getLocal2();
	Veiculo* veiculo = evento->getVeiculo();
	if (pistaOrigem->getSemaforoEstaAberto() && pistaDestino->getEspacoLivre() >= veiculo->getTamanho()) {
		pistaOrigem->retirarVeiculo();
		pistaDestino->inserirVeiculo(veiculo);
		if (pistaDestino->getSumidouro()) {
			adicionarEventoSumirVeiculo(pistaDestino, veiculo, evento->getHorario());
		} else {
			adicionarChegadaDeVeiculoAoSemaforo(pistaDestino, veiculo, evento->getHorario());
		}
	} else {
		int tipo = evento->getTipo();
		double horario = evento->getHorario() + 10;
		Evento* eventoRemarcado = new Evento(tipo, horario, pistaOrigem, pistaDestino, veiculo);
		relogio.adicionarEvento(eventoRemarcado);
	}
}

// Recebe um evento e redireciona para a função mais apta à realizá-lo.
void realizarEsseEvento(Evento* evento) {
	switch(evento->getTipo()) {
	case ChegadaDeUmNovoVeiculo: realizarChegadaDeUmNovoCarro(evento);
		break;
	case AberturaDeSemaforo: realizarAberturaDeSemaforo(evento);
		break;
	case FechamentoDeSemaforo: realizarFechamentoDeSemaforo(evento);
		break;
	case ChegadaDeVeiculoAoSemaforo: realizarChegadaDeCarroAoSemaforo(evento);
		break;
	case TrocaDePista: realizarTrocaDePista(evento);
		break;
	case SumirVeiculo: realizarEventoSumirVeiculo(evento);
		break;
	}
}

// Adiciona um evento de abertura e um evento de fechamento de dois semáforos no mesmo sentido.
void adicionaAbreEFechaSemaforo(double tempoAbre, double tempoFecha, string nome1, string nome2) {
	Pista* local1 = listaDePistas.buscaPeloNome(nome1);
	Pista* local2 = listaDePistas.buscaPeloNome(nome2);
	Evento* semaforoAbre = new Evento(AberturaDeSemaforo, tempoAbre, local1, local2);
	Evento* semaforoFecha = new Evento(FechamentoDeSemaforo, tempoFecha, local1, local2);
	relogio.adicionarEvento(semaforoAbre);
	relogio.adicionarEvento(semaforoFecha);
}

// Adiciona os eventos de transição dos semáforos até o final da execução.
void adicionarEventosTransicoesDeSemaforoAoRelogio(int t_Oeste, int t_Leste, int t_Sul, int t_Norte) {
	double tempo = 0;
	string nome1, nome2;
	while(tempo < relogio.getTempoLimite()) {
		nome1 = "L1oeste";
		nome2 = "O1oeste";
		adicionaAbreEFechaSemaforo(tempo, tempo + t_Oeste, nome1, nome2);
		tempo += t_Oeste;
		nome1 = "O1leste";
		nome2 = "C1leste";
		adicionaAbreEFechaSemaforo(tempo, tempo + t_Oeste, nome1, nome2);
		tempo += t_Leste;
		nome1 = "N1sul";
		nome2 = "N2sul";
		adicionaAbreEFechaSemaforo(tempo, tempo + t_Oeste, nome1, nome2);
		tempo += t_Sul;
		nome1 = "S1norte";
		nome2 = "S2norte";
		adicionaAbreEFechaSemaforo(tempo, tempo + t_Oeste, nome1, nome2);
		tempo += t_Norte;
	}
}


// Adiciona os eventos de chegada de um carro novo na pista.
// Cada pista tem uma frequência diferente para inserir carros.
void adicionarChegadaDeCarrosNovosNessaPista(string nomeDaPista) {
	double tempo = 0;
	Pista* pista = listaDePistas.buscaPeloNome(nomeDaPista);
	while (tempo < relogio.getTempoLimite()) {
		tempo += pista->getTempoEntreCarros();
		Veiculo* v = new Veiculo();
		Evento* insereVeiculo = new Evento(ChegadaDeUmNovoVeiculo, tempo, pista, v);
		relogio.adicionarEvento(insereVeiculo);
		adicionarChegadaDeVeiculoAoSemaforo(pista, v, tempo);
	}
}

// Manda criar os eventos de chegada de carro novo para cada pista.
void adicionarEventosChegadaDeCarrosNovosNasPistas() {
	adicionarChegadaDeCarrosNovosNessaPista("N1sul");
	adicionarChegadaDeCarrosNovosNessaPista("O1leste");
	adicionarChegadaDeCarrosNovosNessaPista("S1norte");
	adicionarChegadaDeCarrosNovosNessaPista("N2sul");
	adicionarChegadaDeCarrosNovosNessaPista("S2norte");
	adicionarChegadaDeCarrosNovosNessaPista("L1oeste");
}


int main(int argc, char **argv) {
	clock_t tStart = clock();
	double tempoDeExecucao = 21600.0; // Configura o tempo de execução para 1 hora.
	double t_Oeste = 40.0; // Configura o tempo de abertura dos semáforos sentido oeste.
	double t_Leste = 40.0; // Configura o tempo de abertura dos semáforos sentido leste.
	double t_Sul = 40.0;    // Configura o tempo de abertura dos semáforos sentido sul.
	double t_Norte = 40.0; // Configura o tempo de abertura dos semáforos sentido norte.
	relogio = Relogio(tempoDeExecucao);
	listaDePistas = ListaEnc<Pista*>();

	// Cria todas as pistas.
	string nome = "N1sul";
	Pista* N1sul = new Pista(nome, 60, 500, 15, 11, true, false);
	nome = "N1norte";
	Pista* N1norte = new Pista(nome, 60, 500, 0, 0, false, true);
	nome = "O1oeste";
	Pista* O1oeste = new Pista(nome, 80, 2000, 0, 0, false, true);
	nome = "O1leste";
	Pista* O1leste = new Pista(nome, 80, 2000, 8, 5, true, false);
	nome = "S1sul";
	Pista* S1sul = new Pista(nome, 60, 500, 0, 0, false, true);
	nome = "S1norte";
	Pista* S1norte = new Pista(nome, 60, 500, 23, 15, true, false);
	nome = "C1leste";
	Pista* C1leste = new Pista(nome, 60, 300, 0, 0, false, false);
	nome = "C1oeste";
	Pista* C1oeste = new Pista(nome, 60, 300, 0, 0, false, false);
	nome = "N2sul";
	Pista* N2sul = new Pista(nome, 40, 500, 15, 11, true, false);
	nome = "N2norte";
	Pista* N2norte = new Pista(nome, 40, 500, 0, 0, false, true);
	nome = "S2sul";
	Pista* S2sul = new Pista(nome, 40, 500, 0, 0, false, true);
	nome = "S2norte";
	Pista* S2norte = new Pista(nome, 40, 500, 45, 30, true, false);
	nome = "L1oeste";
	Pista* L1oeste = new Pista(nome, 30, 400, 8, 5, true, false);
	nome = "L1leste";
	Pista* L1leste = new Pista(nome, 30, 400, 0, 0, false, true);

	// Ajusta o atributo pistasDestino de cada Pista.
	Pista* destinoN1sul[10] = {C1leste, C1leste, C1leste, C1leste, C1leste, C1leste, C1leste, C1leste, O1oeste, S1sul};
	Pista* destinoO1leste[10] = {C1leste, C1leste, C1leste, C1leste, C1leste, C1leste, C1leste, C1leste, S1sul, N1norte};
	Pista* destinoS1norte[10] = {C1leste, C1leste, C1leste, C1leste, C1leste, C1leste, C1leste, C1leste, N1norte, O1oeste};
	Pista* destinoC1leste[10] = {L1leste, L1leste, L1leste, L1leste, S2sul, S2sul, S2sul, N2norte, N2norte, N2norte};
	Pista* destinoC1oeste[10] = {O1oeste, O1oeste, O1oeste, O1oeste, N1norte, N1norte, N1norte, S1sul, S1sul, S1sul};
	Pista* destinoN2sul[10] = {S2sul, S2sul, S2sul, C1oeste, C1oeste, C1oeste, L1leste, L1leste, L1leste, L1leste};
	Pista* destinoS2norte[10] = {S2sul, S2sul, S2sul, C1oeste, C1oeste, C1oeste, L1leste, L1leste, L1leste, L1leste};
	Pista* destinoL1oeste[10] = {C1leste, C1leste, C1leste, N2norte, N2norte, N2norte, N2norte, S2sul, S2sul, S2sul};
	N1sul->setPistasDestino(destinoN1sul);
	O1leste->setPistasDestino(destinoO1leste);
	S1norte->setPistasDestino(destinoS1norte);
	C1leste->setPistasDestino(destinoC1leste);
	C1oeste->setPistasDestino(destinoC1oeste);
	N2sul->setPistasDestino(destinoN2sul);
	S2norte->setPistasDestino(destinoS2norte);
	L1oeste->setPistasDestino(destinoL1oeste);

	// Adiciona todas as pistas à listaDePistas do Sistema.
	listaDePistas.adiciona(N1sul);
	listaDePistas.adiciona(N1norte);
	listaDePistas.adiciona(O1oeste);
	listaDePistas.adiciona(O1leste);
	listaDePistas.adiciona(S1sul);
	listaDePistas.adiciona(S1norte);
	listaDePistas.adiciona(C1leste);
	listaDePistas.adiciona(C1oeste);
	listaDePistas.adiciona(N2sul);
	listaDePistas.adiciona(N2norte);
	listaDePistas.adiciona(S2sul);
	listaDePistas.adiciona(S2norte);
	listaDePistas.adiciona(L1oeste);
	listaDePistas.adiciona(L1leste);

	//Adiciona os eventos de transição de semáforo que acontecerão até o final da execução.
	adicionarEventosTransicoesDeSemaforoAoRelogio(t_Oeste, t_Leste, t_Sul, t_Norte);

	// Adiciona os eventos de chagada de veiculos nas pistas fonte que acontecerão até o final da execução.
	adicionarEventosChegadaDeCarrosNovosNasPistas();

	// Os eventos serão realizados até que não haja mais nenhum dentro do relógio.
	while(relogio.aindaTemEventos()) {
		Evento* evento = relogio.retirarEvento();
		realizarEsseEvento(evento);
	}

	// Mostra na tela os resultados da execução.
	mostrarResultados(tempoDeExecucao, t_Oeste, t_Leste, t_Sul, t_Norte);
	cout << "Tempo de execução: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " segundos." << endl;

	// Libera memória alocada.
	relogio.destroiRelogio();
	listaDePistas.destroiLista();
	return 0;
}
