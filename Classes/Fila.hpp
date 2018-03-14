// Copyright <Rafael Pelle> [2015]

int const std_fila = 15;

template <typename T>
class Fila {
  T* dados;
  int ultimoDaFila;
  int tamanhoFila;

 public:
  Fila();
  Fila<T>(int tam);
  void inclui(T dado);
  T retira();
  T ultimo();
  int getUltimo();
  bool filaCheia();
  bool filaVazia();
  void inicializaFila();

 private:
  void fazerAFilaAndarUmaPosicao();
};


template<typename T>
Fila<T>::Fila() {
  tamanhoFila = std_fila;
  dados = new T[tamanhoFila];
  ultimoDaFila = -1;
}

template<typename T>
Fila<T>::Fila(int tam) {
  tamanhoFila = tam;
  dados = new T[tamanhoFila];
  ultimoDaFila = -1;
}

template<typename T>
void Fila<T>::inclui(T dado) {
  if(filaCheia()) {
    throw "ERRO_FILA_CHEIA";
  } else {
    ultimoDaFila += 1;
    dados[ultimoDaFila] = dado;
  }
}

template<typename T>
T Fila<T>::retira() {
  if(filaVazia()) {
    throw "ERRO_FILA_VAZIA";
  } else {
    T dadoASerRetornado = dados[0];
    fazerAFilaAndarUmaPosicao();
    ultimoDaFila -= 1;
    return dadoASerRetornado;
  }
}

template<typename T>
T Fila<T>::ultimo() {
    if (filaVazia()) {
        throw "ERRO_FILA_VAZIA";
    } else {
        return dados[ultimoDaFila];
    }
}

template<typename T>
int Fila<T>::getUltimo() {
  return ultimoDaFila;
}

template<typename T>
bool Fila<T>::filaCheia() {
  return ultimoDaFila == tamanhoFila-1;
}

template<typename T>
bool Fila<T>::filaVazia() {
  return ultimoDaFila == -1;
}

template<typename T>
void Fila<T>::inicializaFila() {
  ultimoDaFila = -1;
  delete[] dados;
  dados = new T[tamanhoFila];
}

template<typename T>
void Fila<T>::fazerAFilaAndarUmaPosicao() {
  for(int i = 0; i <= ultimoDaFila; i++) {
    dados[i] = dados[i+1];
  }
}
