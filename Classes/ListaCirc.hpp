/*! Copyright <Rafael Pelle> [2015]
 * Classe ListaCirc
 * Cada objeto da classe é uma "cabeça" de uma lista circular simples.
 * \author Rafael Pelle.
 * \since 14/04/15
 * \version 1.0
 */
#include <stddef.h>
#include "ListaEnc.hpp"
#include "Elemento.hpp"

template<typename T>
class ListaCirc: private ListaEnc<T> {
 public:
  //! Construtor.
  /*!
   * Responsável por construir uma lista encadeada.
   * O tamanho da lista recebe o valor zero e dados aponta para NULL.
   */
  ListaCirc();

  //! Destrutor
  /*!
   * Chama a função destroiLista() para que os elementos da lista também sejam apagados.
   */
  ~ListaCirc();

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido na primeira posição da lista.
   *  \return void
   */
  void adicionaNoInicio(const T& dado);

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento que estava na primeira posição da lista.
   *  \return Objeto T.
   */
  T retiraDoInicio();

  //! Exclui um elemento da lista.
  /*!
   *  Exclui o elemento que estava na primeira posição da lista.
   *  \return void.
   */
  void eliminaDoInicio();

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido na lista em uma determinada posição.
   *  \param posicao um inteiro que representa a posição da lista em que o dado será inserido.
   *  \return void
   */
  void adicionaNaPosicao(const T& dado, int pos);

  //! Informa a posição de um elemento da lista.
  /*!
   * \param dado o elemento que terá sua posição informada.
   * \return inteiro que representa a posição do dado.
   */
  int posicao(const T& dado) const;

  //! Informa o endereço na memória de um elemento da lista.
  /*!
   * \param dado o elemento que terá sua posição informada.
   * \return Ponteiro que aponta para a posição do dado.
   */
  T* posicaoMem(const T& dado) const;

  //! Informa se um elemento existe na lista.
  /*!
   * \param dado o elemento que terá sua existência na lista verificada.
   * \return boolean que indica a existência do elemento na lista.
   */
  bool contem(const T& dado);

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento que estava em uma determinada posição da lista.
   *  \param posicao um inteiro que representa a posição da lista em que o elemento será retirado.
   *  \return Objeto T.
   */
  T retiraDaPosicao(int pos);

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido na última posição da lista.
   *  \return void
   */
  void adiciona(const T& dado);

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento que estava na última posição da lista.
   *  \return Objeto T.
   */
  T retira();

  //! Retira um elemento da lista.
  /*!
   *  Retira um elemento específico lista.
   *  \param dado o elemento a ser retirado da lista.
   *  \return Objeto T.
   */
  T retiraEspecifico(const T& dado);

  //! Mostra um elemento da lista.
  /*!
   *  Mostra um elemento específico lista.
   *  \param pos inteiro que representa a posição do dado que vai ser mostrado.
   *  \return Objeto T.
   */
  T mostra(int pos);

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido em ordem crescente na lista.
   *  \return void
   */
  void adicionaEmOrdem(const T& data);

  //! Ver Último.
  /*!
   * \return inteiro que representa a posição do último elemento da lista.
   */
  int verUltimo();

  //! Verifica se a lista está vazia.
  /*!
   * Verifica se a lista está vazia comparando o tamanho da lista.
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
  void destroiLista();
};

template<typename T>
ListaCirc<T>::ListaCirc() {
  this->dados = NULL;
  this->tamanho = 0;
}

template<typename T>
ListaCirc<T>::~ListaCirc() {
  destroiLista();
}

template<typename T>
void ListaCirc<T>::adicionaNoInicio(const T& dado) {
  ListaEnc<T>::adicionaNoInicio(dado);
}

template<typename T>
T ListaCirc<T>::retiraDoInicio() {
  return ListaEnc<T>::retiraDoInicio();
}

template<typename T>
void ListaCirc<T>::eliminaDoInicio() {
  ListaEnc<T>::eliminaDoInicio();
}

template<typename T>
void ListaCirc<T>::adicionaNaPosicao(const T& dado, int pos) {
  ListaEnc<T>::adicionaNaPosicao(dado, pos);
}

template<typename T>
int ListaCirc<T>::posicao(const T& dado) const {
  return ListaEnc<T>::posicao(dado);
}

template<typename T>
T* ListaCirc<T>::posicaoMem(const T& dado) const {
  return ListaEnc<T>::posicaoMem(dado);
}

template<typename T>
bool ListaCirc<T>::contem(const T& dado) {
  return ListaEnc<T>::contem(dado);
}

template<typename T>
T ListaCirc<T>::retiraDaPosicao(int pos) {
  return ListaEnc<T>::retiraDaPosicao(pos);
}

template<typename T>
void ListaCirc<T>::adiciona(const T& dado) {
  ListaEnc<T>::adiciona(dado);
}

template<typename T>
T ListaCirc<T>::retira() {
  return ListaEnc<T>::retira();
}

template<typename T>
T ListaCirc<T>::retiraEspecifico(const T& dado) {
  return ListaEnc<T>::retiraEspecifico(dado);
}

template<typename T>
T ListaCirc<T>::mostra(int pos) {
  Elemento<T> *aux = this->dados;
  for (int i = 0; i <= pos; i++) {
    aux = aux->getProximo();
  }
  return aux->getInfo();
}

template<typename T>
void ListaCirc<T>::adicionaEmOrdem(const T& dado) {
  ListaEnc<T>::adicionaEmOrdem(dado);
}

template<typename T>
int ListaCirc<T>::verUltimo() {
  return this->tamanho-1;
}

template<typename T>
bool ListaCirc<T>::listaVazia() const {
  return ListaEnc<T>::listaVazia();
}

template<typename T>
bool ListaCirc<T>::igual(T dado1, T dado2) {
  return ListaEnc<T>::igual(dado1, dado2);
}

template<typename T>
bool ListaCirc<T>::maior(T dado1, T dado2) {
  return ListaEnc<T>::maior(dado1, dado2);
}

template<typename T>
bool ListaCirc<T>::menor(T dado1, T dado2) {
  return ListaEnc<T>::menor(dado1, dado2);
}

template<typename T>
void ListaCirc<T>::destroiLista() {
  ListaEnc<T>::destroiLista();
}
