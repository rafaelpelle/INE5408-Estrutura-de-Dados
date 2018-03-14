// Copyright <Rafael Pelle> [2015]

int const std_pilha = 15;

template<typename T>
class Pilha {
  T* dados;
  int atualTopo;
  int tamanhoPilha;

 public:
  Pilha();
  Pilha<T>(int t);
	void empilha(T dado);
	T desempilha();
	T topo();
	int getPosTopo();
	void limparPilha();
	bool PilhaVazia();
	bool PilhaCheia();

};


template<typename T>
Pilha<T>::Pilha() {
  tamanhoPilha = std_pilha;
  dados = new T[tamanhoPilha];
  atualTopo = -1;
}

template<typename T>
Pilha<T>::Pilha(int t) {
	tamanhoPilha = t;
	dados = new T[t];
	atualTopo = -1;
}

template<typename T>
void Pilha<T>::empilha(T dado) {
	if (PilhaCheia()) {
		throw "ERRO_PILHA_CHEIA";
	} else {
		atualTopo += 1;
		dados[atualTopo] = dado;
	}
}

template<typename T>
T Pilha<T>::desempilha() {
	if (PilhaVazia()) {
		throw "ERRO_PILHA_VAZIA";
	} else {
		atualTopo -= 1;
		return dados[atualTopo+1];
	}
}

template<typename T>
T Pilha<T>::topo() {
	if (PilhaVazia()) {
		throw "ERRO_PILHA_VAZIA";
	} else {
		return dados[atualTopo];
	}
}

template<typename T>
int Pilha<T>::getPosTopo() {
    if (PilhaVazia()) {
		throw "ERRO_PILHA_VAZIA";
	} else {
		return atualTopo;
	}
}

template<typename T>
void Pilha<T>::limparPilha() {
	atualTopo = -1;
	delete[] dados;
	dados = new T[tamanhoPilha];
}

template<typename T>
bool Pilha<T>::PilhaVazia() {
	return atualTopo == -1;
}

template<typename T>
bool Pilha<T>::PilhaCheia() {
	return atualTopo == tamanhoPilha-1;
}
