/*! Copyright <Rafael Pelle> [2015]
 * Classe ListaDuplaCirc
 * Cada objeto da classe é uma "cabeça" de uma lista circular duplamente encadeada.
 * \author Rafael Pelle.
 * \since 14/04/15
 * \version 1.0
 */
#include <stddef.h>
#include "ListaDupla.hpp"
#include "ElementoDuplo.hpp"

template<typename T>
class ListaDuplaCirc : private ListaDupla<T> {
 public:
  //! Construtor.
  /*!
   * Responsável por construir uma lista duplamente encadeada.
   * O tamanho da lista recebe o valor zero e dados aponta para NULL.
   */
  ListaDuplaCirc();

  //! Destrutor
  /*!
   * Chama a função destroiListaDuplo() para que todos os elementos da lista sejam deletados.
   */
  ~ListaDuplaCirc();

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido na primeira posição da lista.
   *  \return void
   */
  void adicionaNoInicioDuplo(const T& dado);

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento que estava na primeira posição da lista.
   *  \return Objeto T.
   */
  T retiraDoInicioDuplo();

  //! Exclui um elemento da lista.
  /*!
   *  Exclui o elemento que estava na primeira posição da lista.
   *  \return void.
   */
  void eliminaDoInicioDuplo();

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido na lista em uma determinada posição.
   *  \param posicao um inteiro que representa a posição da lista em que o dado será inserido.
   *  \return void
   */
  void adicionaNaPosicaoDuplo(const T& dado, int pos);

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido na lista em uma determinada posição.
   *  \param anterior um ponteiro para o elemento anterior à posição em que o novo dado será inserido.
   *  \return void
   */
  void adicionaNaPosicaoDuplo(const T& dado, ElementoDuplo<T> *anterior);

  //! Informa a posição de um elemento da lista.
  /*!
   * \param dado o elemento que terá sua posição informada.
   * \return inteiro que representa a posição do dado.
   */
  int posicaoDuplo(const T& dado) const;

  //! Informa o endereço na memória de um elemento da lista.
  /*!
   * \param dado o elemento que terá sua posição informada.
   * \return Ponteiro que aponta para a posição do dado.
   */
  T* posicaoMemDuplo(const T& dado) const;

  //! Informa se um elemento existe na lista.
  /*!
   * \param dado o elemento que terá sua existência na lista verificada.
   * \return boolean que indica a existência do elemento na lista.
   */
  bool contemDuplo(const T& dado);

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento que estava em uma determinada posição da lista.
   *  \param posicao um inteiro que representa a posição da lista em que o elemento será retirado.
   *  \return Objeto T.
   */
  T retiraDaPosicaoDuplo(int pos);

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido na última posição da lista.
   *  \return void
   */
  void adicionaDuplo(const T& dado);

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento que estava na última posição da lista.
   *  \return Objeto T.
   */
  T retiraDuplo();

  //! Retira um elemento da lista.
  /*!
   *  Retira um elemento específico lista.
   *  \param dado o elemento a ser retirado da lista.
   *  \return Objeto T.
   */
  T retiraEspecificoDuplo(const T& dado);

  //! Mostra um elemento da lista.
  /*!
   * \param pos, posição da lista que terá seu dado retornado.
   * \return Objeto T.
   */
  T mostra(int pos);

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido em ordem crescente na lista.
   *  \return void
   */
  void adicionaEmOrdem(const T& data);

  //! Ver Último
  /*!
   *  \return inteiro que representa a posição do último elemento da lista.
   */
  int verUltimo();

  //! Verifica se a lista está vazia.
  /*!
   * \return boolean que indica se a lista está vazia.
   */
  bool listaVazia() const;

  //! Compara dois elementos.
  /*!
   * \param dado1 um dos elementos que vâo ser comparados.
   * \param dado2 um dos elementos que vão ser comparados.
   * \return boolean que indica se o dado1 é igual ao dado2.
   * \sa maior(T dado1, T dado2) and menor(T dado1, T dado2).
   */
  bool igual(T dado1, T dado2);

  //! Compara dois elementos.
  /*!
   * \param dado1 um dos elementos que vâo ser comparados.
   * \param dado2 um dos elementos que vão ser comparados.
   * \return boolean que indica se o dado1 é maior do que o dado2.
   * \sa igual(T dado1, T dado2) and menor(T dado1, T dado2).
   */
  bool maior(T dado1, T dado2);

  //! Compara dois elementos.
  /*!
   * \param dado1 um dos elementos que vâo ser comparados.
   * \param dado2 um dos elementos que vão ser comparados.
   * \return boolean que indica se o dado1 é menor do que o dado2.
   * \sa maior(T dado1, T dado2) and igual(T dado1, T dado2).
   */
  bool menor(T dado1, T dado2);

  //! Destrói a lista
  /*!
   * Destrói a lista e todos os seus elementos.
   */
  void destroiListaDuplo();
};

template<typename T>
ListaDuplaCirc<T>::ListaDuplaCirc() {
  this->dados = NULL;
  this->tamanho = 0;
}

template<typename T>
ListaDuplaCirc<T>::~ListaDuplaCirc() {
  destroiListaDuplo();
}

template<typename T>
void ListaDuplaCirc<T>::adicionaNoInicioDuplo(const T& dado) {
  ListaDupla<T>::adicionaNoInicioDuplo(dado);
}

template<typename T>
T ListaDuplaCirc<T>::retiraDoInicioDuplo() {
  return ListaDupla<T>::retiraDoInicioDuplo();
}

template<typename T>
void ListaDuplaCirc<T>::eliminaDoInicioDuplo() {
  ListaDupla<T>::eliminaDoInicioDuplo();
}

template<typename T>
void ListaDuplaCirc<T>::adicionaNaPosicaoDuplo(const T& dado, int pos) {
  ListaDupla<T>::adicionaNaPosicaoDuplo(dado, pos);
}

template<typename T>
int ListaDuplaCirc<T>::posicaoDuplo(const T& dado) const {
  return ListaDupla<T>::posicaoDuplo(dado);
}

template<typename T>
T* ListaDuplaCirc<T>::posicaoMemDuplo(const T& dado) const {
  return ListaDupla<T>::posicaoMemDuplo(dado);
}

template<typename T>
bool ListaDuplaCirc<T>::contemDuplo(const T& dado) {
  return ListaDupla<T>::contemDuplo(dado);
}

template<typename T>
T ListaDuplaCirc<T>::retiraDaPosicaoDuplo(int pos) {
  return ListaDupla<T>::retiraDaPosicaoDuplo(pos);
}

template<typename T>
void ListaDuplaCirc<T>::adicionaDuplo(const T& dado) {
  return ListaDupla<T>::adicionaDuplo(dado);
}

template<typename T>
T ListaDuplaCirc<T>::retiraDuplo() {
  return ListaDupla<T>::retiraDuplo();
}

template<typename T>
T ListaDuplaCirc<T>::retiraEspecificoDuplo(const T& dado) {
  return ListaDupla<T>::retiraEspecificoDuplo(dado);
}

template<typename T>
T ListaDuplaCirc<T>::mostra(int pos) {
  return ListaDupla<T>::mostra(pos);
}

template<typename T>
void ListaDuplaCirc<T>::adicionaEmOrdem(const T& dado) {
  ListaDupla<T>::adicionaEmOrdem(dado);
}

template<typename T>
int ListaDuplaCirc<T>::verUltimo() {
  return ListaDupla<T>::verUltimo();
}

template<typename T>
bool ListaDuplaCirc<T>::listaVazia() const {
  return ListaDupla<T>::listaVazia();
}

template<typename T>
bool ListaDuplaCirc<T>::igual(T dado1, T dado2) {
  return ListaDupla<T>::igual(dado1, dado2);
}

template<typename T>
bool ListaDuplaCirc<T>::maior(T dado1, T dado2) {
  return ListaDupla<T>::maior(dado1, dado2);
}

template<typename T>
bool ListaDuplaCirc<T>::menor(T dado1, T dado2) {
  return ListaDupla<T>::menor(dado1, dado2);
}

template<typename T>
void ListaDuplaCirc<T>::destroiListaDuplo() {
  ListaDupla<T>::destroiListaDuplo();
}
