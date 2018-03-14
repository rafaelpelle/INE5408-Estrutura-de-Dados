/*! Copyright <Rafael Pelle> [2015]
 * Classe FilaEnc
 * Cada objeto da classe é uma "cabeça" de uma fila encadeada.
 * \author Rafael Pelle.
 * \since 08/04/15
 * \version 1.0
 */

#include <stddef.h>
#include "Elemento.hpp"

template <typename T>
class FilaEnc {
 public:
  //! Construtor.
  /*!
   * Responsável por construir uma fila encadeada.
   * O tamanho da fila recebe o valor zero e os ponteiros inicio e fim recebem NULL.
   */
	FilaEnc();

  //! Destrutor
  /*!
   * Chama a função limparLista() para que todos os elementos da fila sejam apagados.
   */
	~FilaEnc();

  //! Inclui um elemento.
  /*!
   *  \param dado um elemento a ser inserido no no fim da fila.
   *  \return void
   */
	void inclui(const T& dado);

  //! Retira um elemento.
  /*!
   *  Retira o elemento que estava no inicio da fila.
   *  \return Objeto T.
   */
	T retira();

  //! Último.
  /*!
   *  Retorna o último elemento da fila.
   *  \return Objeto T.
   */
	T ultimo();

  //! Primeiro.
  /*!
   *  Retorna o primeiro elemento da fila.
   *  \return Objeto T.
   */
	T primeiro();

  //! Fila vazia.
  /*!
   * Verifica se a fila está vazia.
   * \return boolean que indica se a fila está vazia ou não.
   */
	bool filaVazia();

  //! Limpar fila
  /*!
   * Destrói a fila e todos os seus elementos.
   */
	void limparFila();

 private:
	Elemento<T> *inicio; /*!< Ponteiro para o primeiro elemento da fila.*/
	Elemento<T> *fim; /*!< Ponteiro para o último elemento da fila.*/
	int tamanho; /*!< Inteiro que representa o tamanho da pilha.*/
};

template<typename T>
FilaEnc<T>::FilaEnc() {
  inicio = NULL;
  fim = NULL;
  tamanho = 0;
}

template<typename T>
FilaEnc<T>::~FilaEnc() {
  limparFila();
}

template<typename T>
void FilaEnc<T>::inclui(const T& dado) {
  Elemento<T> *novo = new Elemento<T>(dado, NULL);
  if (novo == NULL) {
    throw "ERROFILACHEIA";
  }
  if (filaVazia()) {
    inicio = novo;
  } else {
    fim->setProximo(novo);
  }
  fim = novo;
  tamanho++;
}

template<typename T>
T FilaEnc<T>::retira() {
  if (filaVazia()) {
    throw "ERROFILAVAZIA";
  } else {
    Elemento<T> *saiu = inicio;
    T volta = saiu->getInfo();
    inicio = saiu->getProximo();
    if (tamanho == 1) {
      fim = NULL;
    }
    tamanho--;
    delete saiu;
    return volta;
  }
}

template<typename T>
T FilaEnc<T>::ultimo() {
  if (filaVazia()) {
    throw "ERROFILAVAZIA";
  } else {
    return fim->getInfo();
  }
}

template<typename T>
T FilaEnc<T>::primeiro() {
  if (filaVazia()) {
    throw "ERROFILAVAZIA";
  } else {
    return inicio->getInfo();
  }
}

template<typename T>
bool FilaEnc<T>::filaVazia() {
  return tamanho == 0;
}

template<typename T>
void FilaEnc<T>::limparFila() {
  Elemento<T> *atual, *anterior;
  if (!filaVazia()) {
    atual = inicio;
    while (atual != NULL) {
        anterior = atual;
        atual = atual->getProximo();
        delete anterior;
    }
    tamanho = 0;
  }
}
