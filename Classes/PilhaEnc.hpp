/*! Copyright <Rafael Pelle> [2015]
 * Classe PilhaEnc
 * Cada objeto da classe é uma "cabeça" de uma pilha encadeada.
 * \author Rafael Pelle.
 * \since 07/04/15
 * \version 1.0
 */

#include <stddef.h>
#include "ListaEnc.hpp"
#include "Elemento.hpp"

template<typename T>
class PilhaEnc: private ListaEnc<T> {
 public:
  //! Construtor.
  /*!
   * Responsável por construir uma pilha encadeada.
   * O tamanho da pilha recebe o valor zero e dados aponta para NULL.
   */
  PilhaEnc();

  //! Destrutor
  /*!
   * Chama a função destroiLista() para que os elementos da pilha também sejam apagados.
   */
  ~PilhaEnc();

  //! Empilha um elemento.
  /*!
   *  \param dado um elemento a ser inserido no topo da pilha.
   *  \return void
   */
  void empilha(const T& dado);

  //! Desempilha um elemento.
  /*!
   *  Retira o elemento que estava no topo da pilha.
   *  \return Objeto T.
   */
  T desempilha();

  //! Topo.
  /*!
   *  Retorna o elemento que estava no topo da pilha.
   *  \return Objeto T.
   */
  T topo();

  //! Limpar Pilha
  /*!
   * Destrói a pilha e todos os seus elementos.
   */
  void limparPilha();

  //! Pilha vazia.
  /*!
   * Verifica se a pilha está vazia.
   * \return boolean que indica se a pilha está vazia ou não.
   */
  bool PilhaVazia();

 private:
  Elemento<T> *dados; /*!< Ponteiro para o primeiro elemento da pilha.*/
  int tamanho; /*!< Inteiro que representa o tamanho da pilha.*/
};

template<typename T>
PilhaEnc<T>::PilhaEnc() {
  dados = NULL;
  tamanho = 0;
}

template<typename T>
PilhaEnc<T>::~PilhaEnc() {
  this->destroiLista();
}

template<typename T>
void PilhaEnc<T>::empilha(const T& dado) {
  this->adicionaNoInicio(dado);
}

template<typename T>
T PilhaEnc<T>::desempilha() {
  return this->retiraDoInicio();
}

template<typename T>
T PilhaEnc<T>::topo() {
  if (PilhaVazia()) {
    throw ERROLISTAVAZIA;
  } else {
    return ListaEnc<T>::dados->getInfo();
  }
}

template<typename T>
void PilhaEnc<T>::limparPilha() {
  this->destroiLista();
}

template<typename T>
bool PilhaEnc<T>::PilhaVazia() {
  return this->listaVazia();
}

