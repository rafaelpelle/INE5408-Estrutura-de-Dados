/*! Copyright <Rafael Pelle> [2015]
 * Classe ListaEnc
 * Cada objeto da classe é uma "cabeça" de uma lista encadeada.
 * \author Rafael Pelle.
 * \since 02/04/15
 * \version 1.0
 */
#ifndef LISTAENC_HPP
#define LISTAENC_HPP

#include <cstdio>
#include "Elemento.hpp"

//!  Constantes da classe.
/*!
 * Constantes usadas para gerar exceções.
 */
int const ERROLISTACHEIA = -1;
int const ERROLISTAVAZIA = -2;
int const ERROPOSICAO = -3;

template<typename T>
class ListaEnc {
 public:
  //! Construtor.
  /*!
   * Responsável por construir uma lista encadeada.
   * O tamanho da lista recebe o valor zero e dados aponta para NULL.
   */
  ListaEnc();

  //! Destrutor
  /*!
   * Chama a função destroiLista() para que os elementos da lista também sejam apagados.
   */
  ~ListaEnc();

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

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido na lista em uma determinada posição.
   *  \param anterior um ponteiro para o elemento anterior ao novo dado que será inserido.
   *  \return void
   */
  void adicionaNaPosicao(const T& dado, Elemento<T> *anterior);

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
  T* contem(const T& dado);

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento que estava em uma determinada posição da lista.
   *  \param posicao um inteiro que representa a posição da lista em que o elemento será retirado.
   *  \return Objeto T.
   */
  T retiraDaPosicao(int pos);

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento que estava em uma determinada posição da lista.
   *  \param um ponteiro para o elemento anterior ao que será retirado.
   *  \return Objeto T.
   */
  T retiraDaPosicao(Elemento<T> *anterior);

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

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido em ordem crescente na lista.
   *  \return void
   */
  void adicionaEmOrdem(const T& dado);

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

  int getTamanho();
  T* buscaNaPosicao(int posicao);
  T* buscaNoInicio();

 protected:
  Elemento<T>* dados; /*!< Ponteiro para o primeiro elemento da lista.*/
  int tamanho; /*!< Inteiro que representa o tamanho da lista.*/
};

template<typename T>
ListaEnc<T>::ListaEnc() {
  dados = NULL;
  tamanho = 0;
}

template<typename T>
ListaEnc<T>::~ListaEnc() {
  destroiLista();
}

template<typename T>
void ListaEnc<T>::adicionaNoInicio(const T& dado) {
  Elemento<T> *novo = new Elemento<T>(dado, dados);
  if (novo == NULL) {
    throw ERROLISTACHEIA;
  } else {
    dados = novo;
    tamanho++;
  }
}

template<typename T>
T ListaEnc<T>::retiraDoInicio() {
  Elemento<T> *saiu;
  T volta;
  if (listaVazia()) {
    throw ERROLISTAVAZIA;
  } else {
    saiu = dados;
    volta = *saiu->getInfo();
    dados = saiu->getProximo();
    tamanho--;
    delete saiu;
    return volta;
  }
}

template<typename T>
void ListaEnc<T>::eliminaDoInicio() {
  Elemento<T> *saiu;
  if (listaVazia()) {
    throw ERROLISTAVAZIA;
  } else {
    saiu = dados;
    dados = saiu->getProximo();
    tamanho--;
    delete saiu->getInfo();
    delete saiu;
  }
}

template<typename T>
void ListaEnc<T>::adicionaNaPosicao(const T& dado, int pos) {
  Elemento<T> *novo, *anterior;
    if (pos > tamanho || pos < 0) {
      throw ERROPOSICAO;
    } else if (pos == 0) {
      adicionaNoInicio(dado);
    } else {
      anterior = dados;
      for (int i = 1; i < pos; i++) {
        anterior = anterior->getProximo();
      }
      novo = new Elemento<T>(dado, anterior->getProximo());
      anterior->setProximo(novo);
      tamanho++;
    }
}

template<typename T>
void ListaEnc<T>::adicionaNaPosicao(const T& dado, Elemento<T> *anterior) {
  Elemento<T> *novo = new Elemento<T>(dado, anterior->getProximo());
  anterior->setProximo(novo);
  tamanho++;
}

template<typename T>
int ListaEnc<T>::posicao(const T& dado) const {
  Elemento<T> *aux = dados;
  for (int i = 0; i < tamanho; i++) {
    if (aux->getInfo() == dado) {
      return i;
    }
    aux = aux->getProximo();
  }
  throw ERROPOSICAO;
}

template<typename T>
T* ListaEnc<T>::posicaoMem(const T& dado) const {
  Elemento<T> *aux = dados;
    for (int i = 0; i < tamanho; i++) {
      if (aux->getInfo() == dado) {
        return aux;
      }
      aux = aux->getProximo();
    }
    throw ERROPOSICAO;
}

template<typename T>
T* ListaEnc<T>::contem(const T& dado) {
  Elemento<T> *aux = dados;
    for (int i = 0; i < tamanho; i++) {
      if (*aux->getInfo() == dado) {
        return aux->getInfo();
      }
      aux = aux->getProximo();
    }
    return NULL;
}

template<typename T>
T ListaEnc<T>::retiraDaPosicao(int pos) {
  Elemento<T> *anterior, *eliminar;
  T volta;
  if (pos >= tamanho || pos < 0) {
    throw ERROPOSICAO;
  } else if (pos == 0) {
    return retiraDoInicio();
  } else {
    anterior = dados;
    for (int i = 1; i < pos; i++) {
      anterior = anterior->getProximo();
    }
    eliminar = anterior->getProximo();
    volta = eliminar->getInfo();
    anterior->setProximo(eliminar->getProximo());
    tamanho--;
    delete eliminar;
    return volta;
  }
}

template<typename T>
T ListaEnc<T>::retiraDaPosicao(Elemento<T> *anterior) {
  Elemento<T> *eliminar;
  T volta;
  eliminar = anterior->getProximo();
  volta = eliminar->getInfo();
  anterior->setProximo(eliminar->getProximo());
  tamanho--;
  delete eliminar;
  return volta;
}

template<typename T>
void ListaEnc<T>::adiciona(const T& dado) {
  adicionaNaPosicao(dado, tamanho);
}

template<typename T>
T ListaEnc<T>::retira() {
  return retiraDaPosicao(tamanho-1);
}

template<typename T>
T ListaEnc<T>::retiraEspecifico(const T& dado) {
  return retiraDaPosicao(posicao(dado));
}

template<typename T>
void ListaEnc<T>::adicionaEmOrdem(const T& dado) {
  Elemento<T> *atual, *anterior;
  if (listaVazia()) {
    adicionaNoInicio(dado);
  } else {
    atual = dados;
    anterior = dados;
    while (atual->getProximo() != NULL && maior(dado, atual->getInfo())) {
      anterior = atual;
      atual = atual->getProximo();
    }
    if (maior(dado, atual->getInfo())) {
      adicionaNaPosicao(dado, atual);
    } else {
      adicionaNaPosicao(dado, anterior);
    }
  }
}

template<typename T>
bool ListaEnc<T>::listaVazia() const {
  return tamanho == 0;
}

template<typename T>
bool ListaEnc<T>::igual(T dado1, T dado2) {
    return dado1 == dado2;
}

template<typename T>
bool ListaEnc<T>::maior(T dado1, T dado2) {
    return dado1 > dado2;
}

template<typename T>
bool ListaEnc<T>::menor(T dado1, T dado2) {
    return dado1 < dado2;
}

template<typename T>
void ListaEnc<T>::destroiLista() {
  Elemento<T> *atual, *anterior;
  if (!listaVazia()) {
    atual = dados;
    while (atual != NULL) {
        anterior = atual;
        atual = atual->getProximo();
        delete anterior;
    }
    tamanho = 0;
  }
}

template <typename T>
int ListaEnc<T>::getTamanho() {
	return this->tamanho;
}

template <typename T>
T* ListaEnc<T>::buscaNaPosicao(int pos) {
	Elemento<T>* atual;
	if (pos >= tamanho || pos < 0) {
		throw ERROPOSICAO;
	} else if (pos == 0) {
		return buscaNoInicio();
	} else {
		atual = dados;
	    for (int i = 1; i <= pos; i++) {
	    	atual = atual->getProximo();
	    }
	    return atual->getInfo();
	}
}

template <typename T>
T* ListaEnc<T>::buscaNoInicio() {
	if (listaVazia()) {
		throw ERROLISTAVAZIA;
	} else {
	    return dados->getInfo();
	  }
}

#endif
