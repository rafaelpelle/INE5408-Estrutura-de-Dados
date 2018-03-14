/*! Copyright <Rafael Pelle> [2015]
 *  Estrutura de dados - Lista.hpp
 * \author Rafael Pelle.
 * \since 26/03/15
 * \version 1.0
 */

//!  Constantes da classe.
/*!
 * Constantes usadas para definir o tamanho padrão da lista e gerar exceções.
 */
int const TAMANHOPADRAO = 100;
int const ERROLISTACHEIA = -1;
int const ERROLISTAVAZIA = -2;
int const ERROPOSICAO = -3;

template<typename T>
class Lista {
  T *dados; /*!< Ponteiro para um array de elementos da lista.*/
  int posUltimo; /*!< Posição do último elemento da lista.*/
  int tamanho; /*!< Tamanho da lista.*/

 public:
  //! Construtor padrão.
  /*!
   * Responsável por construir uma lista em que o tamanho não foi especificado.
   * O tamanho da lista recebe o valor da constante TAMANHOPADRAO, um array com esse tamanho é criado e
   * posUltimo recebe o valor -1 para indicar que a lista está vazia.
   */
  Lista();

  //! Construtor com tamanho definido.
  /*!
  * Responsável por construir uma lista em que o tamanho foi especificado.
  * O tamanho da lista recebe o valor, um array com esse tamanho é criado e
  * posUltimo recebe o valor -1 para indicar que a lista está vazia.
  */
  explicit Lista(int tam);

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido na última posição da lista.
   *  \return void
   */
  void adiciona(T dado);

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido na primeira posição da lista.
   *  \return void
   */
  void adicionaNoInicio(T dado);

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido na lista em uma determinada posição.
   *  \param posicao um inteiro que representa a posição da lista em que o dado será inserido.
   *  \return void
   */
  void adicionaNaPosicao(T dado, int posicao);

  //! Adiciona um elemento na lista.
  /*!
   *  \param dado um elemento a ser inserido em ordem crescente na lista.
   *  \return void
   */
  void adicionaEmOrdem(T dado);

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento que estava na última posição da lista.
   *  \return Objeto T.
   */
  T retira();

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento que estava na primeira posição da lista.
   *  \return Objeto T.
   */
  T retiraDoInicio();

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento que estava em uma determinada posição da lista.
   *  \param posicao um inteiro que representa a posição da lista em que o elemento será retirado.
   *  \return Objeto T.
   */
  T retiraDaPosicao(int posicao);

  //! Retira um elemento da lista.
  /*!
   *  Retira o elemento específico lista.
   *  \param dado o elemento a ser retirado da lista.
   *  \return Objeto T.
   */
  T retiraEspecifico(T dado);

  //! Informa a posição de um elemento da lista.
  /*!
   * \param dado o elemento que terá sua posição informada.
   * \return inteiro que representa a posição do objeto.
   */
  int posicao(T dado);

  //! Informa se um elemento existe na lista.
  /*!
   * \param dado o elemento que terá sua existência na lista verificada.
   * \return boolean que indica a existência do elemento na lista.
   */
  bool contem(T dado);

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

  //! Verifica se a lista está cheia.
  /*!
   * Verifica se a lista está cheia comparando o tamanho da lista com a posição do último elemento.
   * \return boolean que indica se a lista está cheia.
   * \sa listaVazia().
   */
  bool listaCheia();

  //! Verifica se a lista está vazia.
  /*!
   * Verifica se a lista está vazia baseando-se na posição do último elemento.
   * \return boolean que indica se a lista está vazia.
   * \sa listaCheia().
   */
  bool listaVazia();

  //! Destrói a lista.
  /*!
   * Destrói a lista simplesmente alterando o atributo posUltimo para seu valor inicial.
   * \return void
   */
  void destroiLista();

 private:
  //! Muda todos os elementos de posição.
  /*!
   * Muda todos os elementos da lista, um por vez, uma posição para trás a partir de uma posição específica.
   * \param posicao um inteiro que representa a posição a partir da qual todos os elementos serão movidos.
   * \return void
   */
  void empurraTudoParaTrasAPartirDaPosicao(int posicao);

  //! Muda todos os elementos de posição.
  /*!
   * Muda todos os elementos da lista, um por vez, uma posição para frente a partir de uma posição específica.
   * \param posicao um inteiro que representa a posição a partir da qual todos os elementos serão movidos.
   * \return void
   */
  void empurraTudoParaFrenteAPartirDaPosicao(int posicao);
};


template<typename T>
Lista<T>::Lista() {
  tamanho = TAMANHOPADRAO;
  dados = new T[tamanho];
  posUltimo = -1;
}

template<typename T>
Lista<T>::Lista(int tam) {
  tamanho = tam;
  dados = new T[tamanho];
  posUltimo = -1;
}

template<typename T>
void Lista<T>::adiciona(T dado) {
  if (listaCheia()) {
    throw ERROLISTACHEIA;
  } else {
    posUltimo++;
    dados[posUltimo] = dado;
  }
}

template<typename T>
void Lista<T>::adicionaNoInicio(T dado) {
  if (listaCheia()) {
    throw ERROLISTACHEIA;
  } else {
    adicionaNaPosicao(dado, 0);
  }
}

template<typename T>
void Lista<T>::adicionaNaPosicao(T dado, int posicao) {
  if (listaCheia()) {
    throw ERROLISTACHEIA;
  } else {
    if (posicao > posUltimo+1 || posicao < 0) {
      throw ERROPOSICAO;
    }
    posUltimo++;
    empurraTudoParaTrasAPartirDaPosicao(posicao);
    dados[posicao] = dado;
  }
}

template<typename T>
void Lista<T>::adicionaEmOrdem(T dado) {
  int pos;
  if (listaCheia()) {
    throw ERROLISTACHEIA;
  } else {
    pos = 0;
    while (pos <= posUltimo && maior(dado, dados[pos])) {
      pos++;
    }
    adicionaNaPosicao(dado, pos);
  }
}

template<typename T>
T Lista<T>::retira() {
  if (listaVazia()) {
    throw ERROLISTAVAZIA;
  } else {
    posUltimo--;
    return dados[posUltimo + 1];
  }
}

template<typename T>
T Lista<T>::retiraDoInicio() {
  if (listaVazia()) {
    throw ERROLISTAVAZIA;
  } else {
    return retiraDaPosicao(0);
  }
}

template<typename T>
T Lista<T>::retiraDaPosicao(int posicao) {
  if (listaVazia()) {
    throw ERROLISTAVAZIA;
  } else {
    if (posicao > posUltimo || posicao < 0) {
      throw ERROPOSICAO;
    }
    posUltimo--;
    T dado = dados[posicao];
    empurraTudoParaFrenteAPartirDaPosicao(posicao);
    return dado;
  }
}

template<typename T>
T Lista<T>::retiraEspecifico(T dado) {
  if (listaVazia()) {
    throw ERROLISTAVAZIA;
  } else {
    int pos = posicao(dado);
    if (pos < 0) {
      throw ERROPOSICAO;
    } else {
      return retiraDaPosicao(pos);
    }
  }
}

template<typename T>
int Lista<T>::posicao(T dado) {
  for (int posicao = 0; posicao <= posUltimo; posicao++) {
    if (dados[posicao] == dado) {
      return posicao;
    }
  }
  throw ERROPOSICAO;
}

template<typename T>
bool Lista<T>::contem(T dado) {
  bool contem = false;
  for (int posicao = 0; posicao <= posUltimo; posicao++) {
    if (dados[posicao] == dado) {
      contem = true;
    }
  }
  return contem;
}

template<typename T>
bool Lista<T>::igual(T dado1, T dado2) {
  return dado1 == dado2;
}

template<typename T>
bool Lista<T>::maior(T dado1, T dado2) {
  return dado1 > dado2;
}

template<typename T>
bool Lista<T>::menor(T dado1, T dado2) {
  return dado1 < dado2;
}

template<typename T>
bool Lista<T>::listaCheia() {
  return posUltimo == tamanho - 1;
}

template<typename T>
bool Lista<T>::listaVazia() {
  return posUltimo == -1;
}

template<typename T>
void Lista<T>::destroiLista() {
  posUltimo = -1;
}

template<typename T>
void Lista<T>::empurraTudoParaTrasAPartirDaPosicao(int posicao) {
  for (int i = posUltimo; i > posicao; i--) {
    dados[i] = dados[i-1];
  }
}

template<typename T>
void Lista<T>::empurraTudoParaFrenteAPartirDaPosicao(int posicao) {
  for (int i = posicao; i <= posUltimo; i++) {
    dados[i] = dados[i+1];
  }
}
