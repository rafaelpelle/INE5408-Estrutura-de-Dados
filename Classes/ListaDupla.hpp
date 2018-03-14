/*! Copyright <Rafael Pelle> [2015]
 * Classe ListaDupla
 * Cada objeto da classe é uma "cabeça" de uma lista duplamente encadeada.
 * \author Rafael Pelle.
 * \since 09/04/15
 * \version 1.0
 */

#include <stddef.h>
#include "ElementoDuplo.hpp"

//!  Constantes da classe.
/*!
 * Constantes usadas para gerar exceções.
 */
int const ERROLISTACHEIA = -1;
int const ERROLISTAVAZIA = -2;
int const ERROPOSICAO = -3;

template<typename T>
class ListaDupla {
 public:
  //! Construtor.
  /*!
   * Responsável por construir uma lista duplamente encadeada.
   * O tamanho da lista recebe o valor zero e dados aponta para NULL.
   */
	ListaDupla();

  //! Destrutor
  /*!
   * Chama a função destroiListaDuplo() para que todos os elementos da lista sejam deletados.
   */
	~ListaDupla();

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

 private:
	ElementoDuplo<T> *dados; /*!< Ponteiro para o primeiro elemento da lista.*/
	int tamanho; /*!< Inteiro que representa o tamanho da lista.*/
};

template<typename T>
ListaDupla<T>::ListaDupla() {
  tamanho = 0;
  dados = NULL;
}

template<typename T>
ListaDupla<T>::~ListaDupla() {
  destroiListaDuplo();
}

template<typename T>
void ListaDupla<T>::adicionaNoInicioDuplo(const T& dado) {
  ElementoDuplo<T> *novo = new ElementoDuplo<T>(dado, dados, NULL);
  if (novo == NULL) {
    throw ERROLISTACHEIA;
  }
  dados = novo;
  if (novo->getProximo() != NULL) {
    novo->getProximo()->setAnterior(novo);
  }
  tamanho++;
}

template<typename T>
T ListaDupla<T>::retiraDoInicioDuplo() {
  if (listaVazia()) {
    throw ERROLISTAVAZIA;
  } else {
    ElementoDuplo<T> *saiu = dados;
    T volta = saiu->getInfo();
    dados = saiu->getProximo();
    if (dados != NULL) {
      dados->setAnterior(NULL);
    }
    tamanho--;
    delete saiu;
    return volta;
  }
}

template<typename T>
void ListaDupla<T>::eliminaDoInicioDuplo() {
  if (listaVazia()) {
      throw ERROLISTAVAZIA;
    } else {
      ElementoDuplo<T> *saiu = dados;
      dados = saiu->getProximo();
      if (dados != NULL) {
        dados->setAnterior(NULL);
      }
      tamanho--;
      delete saiu;
    }
}

template<typename T>
void ListaDupla<T>::adicionaNaPosicaoDuplo(const T& dado, int pos) {
    if (pos > tamanho || pos < 0) {
      throw ERROPOSICAO;
    } else if (pos == 0) {
      adicionaNoInicioDuplo(dado);
    } else {
      ElementoDuplo<T> *anterior = dados;
      for (int i = 1; i < pos; i++) {
        anterior = anterior->getProximo();
      }
      ElementoDuplo<T> *novo = new ElementoDuplo<T>(dado, anterior->getProximo()
      , anterior);
      if (novo->getProximo() != NULL) {
        novo->getProximo()->setAnterior(novo);
      }
      anterior->setProximo(novo);
      tamanho++;
    }
}

template<typename T>
void ListaDupla<T>::adicionaNaPosicaoDuplo(const T& dado,
    ElementoDuplo<T> *anterior) {
  ElementoDuplo<T> *novo = new ElementoDuplo<T>(dado, anterior->getProximo(),
    anterior);
  anterior->setProximo(novo);
  tamanho++;
}

template<typename T>
int ListaDupla<T>::posicaoDuplo(const T& dado) const {
  ElementoDuplo<T> *aux = dados;
  for (int i = 0; i < tamanho; i++) {
    if (aux->getInfo() == dado) {
      return i;
    }
    aux = aux->getProximo();
  }
  throw ERROPOSICAO;
}

template<typename T>
T* ListaDupla<T>::posicaoMemDuplo(const T& dado) const {
  ElementoDuplo<T> *aux = dados;
    for (int i = 0; i < tamanho; i++) {
      if (aux->getInfo() == dado) {
        return aux;
      }
      aux = aux->getProximo();
    }
    throw ERROPOSICAO;
}

template<typename T>
bool ListaDupla<T>::contemDuplo(const T& dado) {
  ElementoDuplo<T> *aux = dados;
    for (int i = 0; i < tamanho; i++) {
      if (aux->getInfo() == dado) {
        return true;
      }
      aux = aux->getProximo();
    }
    return false;
}

template<typename T>
T ListaDupla<T>::retiraDaPosicaoDuplo(int pos) {
  if (pos > tamanho || pos < 0) {
    throw ERROPOSICAO;
  }
  if (pos == 0) {
    return retiraDoInicioDuplo();
  } else {
    ElementoDuplo<T> *anterior = dados;
    for (int i = 1; i < pos; i++) {
      anterior = anterior->getProximo();
    }
    ElementoDuplo<T> *eliminar = anterior->getProximo();
    T volta = eliminar->getInfo();
    anterior->setProximo(eliminar->getProximo());
    if (eliminar->getProximo() != NULL) {
      eliminar->getProximo()->setAnterior(anterior);
    }
    tamanho--;
    delete eliminar;
    return volta;
  }
}

template<typename T>
void ListaDupla<T>::adicionaDuplo(const T& dado) {
  adicionaNaPosicaoDuplo(dado, tamanho);
}

template<typename T>
T ListaDupla<T>::retiraDuplo() {
  return retiraDaPosicaoDuplo(tamanho-1);
}

template<typename T>
T ListaDupla<T>::retiraEspecificoDuplo(const T& dado) {
  return retiraDaPosicaoDuplo(posicaoDuplo(dado));
}

template<typename T>
T ListaDupla<T>::mostra(int pos) {
  ElementoDuplo<T> *aux = dados;
  for (int i = 0; i <= pos; i++) {
    aux = aux->getProximo();
  }
  return aux->getInfo();
}

template<typename T>
void ListaDupla<T>::adicionaEmOrdem(const T& dado) {
  if (listaVazia()) {
    adicionaNoInicioDuplo(dado);
  } else {
    ElementoDuplo<T> *atual = dados;
    ElementoDuplo<T> *anterior = dados;
    while (atual->getProximo() != NULL && maior(dado, atual->getInfo())) {
      anterior = atual;
      atual = atual->getProximo();
    }
    if (maior(dado, atual->getInfo())) {
      adicionaNaPosicaoDuplo(dado, atual);
    } else {
      adicionaNaPosicaoDuplo(dado, anterior);
    }
  }
}

template<typename T>
int ListaDupla<T>::verUltimo() {
  return tamanho-1;
}

template<typename T>
bool ListaDupla<T>::listaVazia() const {
  return tamanho == 0;
}

template<typename T>
bool ListaDupla<T>::igual(T dado1, T dado2) {
  return dado1 == dado2;
}

template<typename T>
bool ListaDupla<T>::maior(T dado1, T dado2) {
  return dado1 > dado2;
}

template<typename T>
bool ListaDupla<T>::menor(T dado1, T dado2) {
  return dado1 < dado2;
}

template<typename T>
void ListaDupla<T>::destroiListaDuplo() {
  ElementoDuplo<T> *atual, *anterior;
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
