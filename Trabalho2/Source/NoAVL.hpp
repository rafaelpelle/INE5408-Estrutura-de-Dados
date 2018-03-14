/*! Copyright <Rafael Pelle> [2015]
 * Classe NoAVL<T>
 * Cada objeto da classe é um nó de árvore AVL.
 * \author Rafael Pelle.
 * \since 18/06/15
 * \version 1.0
 */

#ifndef NO_AVL_HPP
#define NO_AVL_HPP

#include <cstdio>
#include <vector>

template <typename T>
class NoAVL  {
 private:
    int altura;  //!< Representa a altura do nó AVL.
    T* dado;  //!< Ponteiro para o dado que esse nó armazena.
    NoAVL<T>* esquerda;  //!< Ponteiro para o nó filho da esquerda.
    NoAVL<T>* direita;  //!< Ponteiro para o nó filho da direita.
    std::vector<NoAVL<T>* > elementos; //!< Vetor de nós para imprimir os percorrimentos*/

    //! simp_roda_esq
    /*!
     * realiza uma rotação à esquerda
     * \param NoAVL<T>* nodo2, que vai ser rotacionado com seus filhos.
     * \return NoAVL<T>* nova raiz da árvore.
     */
    NoAVL<T>* simp_roda_esq(NoAVL<T>* nodo2);

    //! simp_roda_dir
    /*!
     * realiza uma rotação à direita
     * \param NoAVL<T>* nodo2, que vai ser rotacionado com seus filhos.
     * \return NoAVL<T>* nova raiz da árvore.
     */
    NoAVL<T>* simp_roda_dir(NoAVL<T>* nodo2);

    //! rebalancear
    /*!
     * Verifica se a árvore está desbalanceada e se necessário realiza o rebalanceamento.
     * \param nodo que vai ser rebalanceado caso necessário.
     * \return NoAVL<T>* nova raiz da árvore.
     */
    NoAVL<T>* rebalancear(NoAVL<T>* nodo);

    //! getBalanceamento
    /*!
     * \param NoAVL<T>* nodo, que terá seu balanceamento verificado.
     * \return Inteiro, diferença entre a altura dos filhos da árvore.
     */
    int getBalanceamento(NoAVL<T>* nodo);

    //! ajustarAltura
    /*!
     * Ajusta a altura do nodo para 1 + (maior altura entre os filhos)
     * \param NoAVL<T>* nodo que terá sua altura ajustada.
     * \return void
     */
    void ajustarAltura(NoAVL<T>* nodo);

 public:
    //! Construtor.
    /*!
     * Responsável por construir um nó de árvore AVL.
     * armazena o dado, aponta esquerda e direita para NULL,
     * ajusta altura para 0 e inicializa o vetor elementos.
     *
     * \param Dado que será armazenado no nó AVL criado.
     * \return Objeto da classe NoAVL
     */
    NoAVL<T>(const T& dado);

    //! Destrutor.
    /*!
     * Destrói a árvore AVL e todos os seus descendentes.
     * \param void
     * \return void
     */
    virtual ~NoAVL();

    //! getAltura
    /*!
     * \param void
     * \return Inteiro que representa a altura do NoAVL
     */
    int getAltura();

    //! setAltura
    /*!
     * \param Inteiro que será a nova altura do NoAVL
     * \return void
     */
    void setAltura(int alt);

    //! getElementos
    /*!
     * \param void
     * \return vector<NoAVL<T>*> com o NoAVL e todos os seus descendentes.
     */
    std::vector<NoAVL<T>*> getElementos();

	//! getEsquerda
	/*!
	 * \param void
	 * \return NoAVL<T>* filho da esquerda.
	 */
    NoAVL<T>* getEsquerda();

	//! setEsquerda
	/*!
	 * \param nodo, um ponteiro para NoAVL
	 * \return void
	 */
    void setEsquerda(NoAVL<T>* nodo);

	//! getDireita
	/*!
	 * \param void
	 * \return NoAVL<T>* filho da direita.
	 */
    NoAVL<T>* getDireita();

	//! setDireita
	/*!
	 * \param nodo, um ponteiro para NoAVL
	 * \return void
	 */
    void setDireita(NoAVL<T>* nodo);

	//! inserir
	/*!
	 * \param dado, dado a ser inserido na árvore.
	 * \param arv, NoAVL em que o dado vai ser inserido.
	 * \return NoAVL<T>* raiz da árvore.
	 */
    NoAVL<T>* inserir(const T& dado, NoAVL<T>* arv);

	//! remover
	/*!
	 * \param dado, dado a ser removido na árvore.
	 * \param arv, NoAVL que o dado vai ser removido.
	 * \return NoAVL<T>*
	 */
    NoAVL<T>* remover(NoAVL<T>* arv, const T& dado);

	//! minimo
	/*!
	 * \param nodo, NoAVL em que o menor dado vai ser buscado.
	 * \return NoAVL<T>* ponteiro para o nó "mais à esquerda" da árvore.
	 */
    NoAVL<T>* minimo(NoAVL<T>* nodo);

    //! getDado()
	/*!
	 * \return T* ponteiro para o dado do NoAVL
	 */
    T* getDado();

	//! setDado
	/*!
	 * \param T& dado, o dado que será armazenado no NoAVL
	 * \return void
	 */
    void setDado(const T& dado);

	//! busca
	/*!
	 * \param dado, dado a ser buscado na árvore.
	 * \param arv, NoAVL em que o dado vai ser buscado.
	 * \return T* ponteiro para o dado buscado.
	 */
    T* busca(const T& dado, NoAVL<T>* arv);

	//! preOrdem
	/*!
	 * \param nodo, NoAVL que vai ser impresso em preOrdem, dentro do vetor elementos.
	 * \return void
	 */
    void preOrdem(NoAVL<T>* nodo);

	//! emOrdem
	/*!
	 * \param nodo, NoAVL que vai ser impresso emOrdem, dentro do vetor elementos.
	 * \return void
	 */
    void emOrdem(NoAVL<T>* nodo);

	//! posOrdem
	/*!
	 * \param nodo, NoAVL que vai ser impresso em posOrdem, dentro do vetor elementos.
	 * \return void
	 */
    void posOrdem(NoAVL<T>* nodo);
};

template <typename T>
NoAVL<T>::NoAVL(const T& dado) {
	this->altura = 0;
	this->dado = new T(dado);
	this->esquerda = NULL;
	this->direita = NULL;
	this->elementos.clear();
}

template <typename T>
NoAVL<T>::~NoAVL() {
	if (esquerda != NULL) {
		esquerda->~NoAVL();
	}
	if (direita != NULL) {
		direita->~NoAVL();
	}
	delete dado;
}

template <typename T>
int NoAVL<T>::getAltura() {
	if (this != NULL)
		return this->altura;
	else
		return -1;
}

template <typename T>
void NoAVL<T>::setAltura(int alt) {
	if (this != NULL) {
		this->altura = alt;
	}
}

template <typename T>
std::vector<NoAVL<T>* > NoAVL<T>::getElementos() {
	return this->elementos;
}

template <typename T>
NoAVL<T>* NoAVL<T>::getEsquerda() {
	if (this != NULL) {
		return this->esquerda;
	} else {
		return NULL;
	}
}

template <typename T>
void NoAVL<T>::setEsquerda(NoAVL<T>* nodo) {
	if (this != NULL) {
		this->esquerda = nodo;
	}
}

template <typename T>
NoAVL<T>* NoAVL<T>::getDireita() {
	if (this != NULL) {
		return this->direita;
	} else {
		return NULL;
	}
}

template <typename T>
void NoAVL<T>::setDireita(NoAVL<T>* nodo) {
	if (this != NULL) {
		this->direita = nodo;
	}
}

template <typename T>
NoAVL<T>* NoAVL<T>::inserir(const T& dado, NoAVL<T>* arv) {
    if (arv == NULL) {
    	return new NoAVL<T>(dado);
    }
    if (dado < *arv->getDado()) {
    	arv->setEsquerda(inserir(dado, arv->getEsquerda()));
    } else if (dado > *arv->getDado()) {
    	arv->setDireita(inserir(dado, arv->getDireita()));
    } else {
    	throw "Não pode inserir dado duplicado.";
    }
    return rebalancear(arv);
}

template <typename T>
NoAVL<T>* NoAVL<T>::remover(NoAVL<T>* arv, const T& dado) {
	if (arv == NULL) {
		return arv;
	} else {
		if (dado < *arv->getDado()) {
			arv->setEsquerda(remover(arv->getEsquerda(), dado));
			return rebalancear(arv);
		} else  {
			if (dado > *arv->getDado()) {
				arv->setDireita(remover(arv->getDireita(), dado));
				return rebalancear(arv);
			} else {
				if (arv->getDireita() != NULL && arv->getEsquerda() != NULL) {
					NoAVL<T>* temp = minimo(arv->getDireita());
					arv->setDado(*temp->getDado());
					arv->setDireita(remover(arv->getDireita(), *arv->getDado()));
					return rebalancear(arv);
				} else {
					if (arv->getDireita() != NULL) {
						NoAVL<T>* filho = arv->getDireita();
						return filho;
					} else {
						if (arv->getEsquerda() != NULL) {
							NoAVL<T>* filho = arv->getEsquerda();
							return filho;
						} else {
							delete arv;
							return NULL;
						}
					}
				}
			}
		}
	}
}

template <typename T>
NoAVL<T>* NoAVL<T>::minimo(NoAVL<T>* nodo) {
	NoAVL<T>* min = nodo;
	while (min->getEsquerda() != NULL) {
		min = min->getEsquerda();
	}
	return min;
}

template <typename T>
T* NoAVL<T>::getDado() {
	if (this != NULL)
		return this->dado;
	else
		return NULL;
}

template <typename T>
void NoAVL<T>::setDado(const T& dado) {
	this->dado = new T(dado);
}

template <typename T>
T* NoAVL<T>::busca(const T& dado, NoAVL<T>* arv) {
	while (arv != NULL && *arv->getDado() != dado) {
		if (*arv->dado < dado) {
			arv = arv->getDireita();
		} else {
			arv = arv->getEsquerda();
		}
	}
	if (arv != NULL) {
		return arv -> getDado();
	}
	return NULL;
}

template <typename T>
void NoAVL<T>::preOrdem(NoAVL<T>* nodo) {
	if (nodo != NULL) {
		elementos.push_back(nodo);
		preOrdem(nodo->getEsquerda());
		preOrdem(nodo->getDireita());
	}
}

template <typename T>
void NoAVL<T>::emOrdem(NoAVL<T>* nodo) {
	if (nodo != NULL) {
		emOrdem(nodo->getEsquerda());
		elementos.push_back(nodo);
		emOrdem(nodo->getDireita());
	}
}

template <typename T>
void NoAVL<T>::posOrdem(NoAVL<T>* nodo) {
	if (nodo != NULL) {
		posOrdem(nodo->getEsquerda());
		posOrdem(nodo->getDireita());
		elementos.push_back(nodo);
	}
}

template <typename T>
NoAVL<T>* NoAVL<T>::simp_roda_esq(NoAVL<T>* nodo1) {
    NoAVL<T>* nodo2 = nodo1->getDireita();
    nodo1->setDireita(nodo2->getEsquerda());
    nodo2->setEsquerda(nodo1);
    ajustarAltura(nodo1);
    ajustarAltura(nodo2);
	return nodo2;
}

template <typename T>
NoAVL<T>* NoAVL<T>::simp_roda_dir(NoAVL<T>* nodo2) {
    NoAVL<T>* nodo1 = nodo2->getEsquerda();
    nodo2->setEsquerda(nodo1->getDireita());
    nodo1->setDireita(nodo2);
    ajustarAltura(nodo2);
    ajustarAltura(nodo1);
    return nodo1;
}

template <typename T>
int NoAVL<T>::getBalanceamento(NoAVL<T>* nodo) {
	return nodo->getDireita()->getAltura() - nodo->getEsquerda()->getAltura();
}

template <typename T>
NoAVL<T>* NoAVL<T>::rebalancear(NoAVL<T>* nodo) {
    ajustarAltura(nodo);
    if (getBalanceamento(nodo) == 2) {
        if (getBalanceamento(nodo->getDireita()) < 0) {
        	nodo->setDireita(simp_roda_dir(nodo->getDireita()));
        }
        return simp_roda_esq(nodo);
    }
    if (getBalanceamento(nodo) == -2) {
        if (getBalanceamento(nodo->getEsquerda()) > 0) {
        	nodo->setEsquerda(simp_roda_esq(nodo->getEsquerda()));
        }
        return simp_roda_dir(nodo);
    }
    return nodo;
}

template <typename T>
void NoAVL<T>::ajustarAltura(NoAVL<T>* nodo) {
    int alturaEsquerda = nodo->getEsquerda()->getAltura();
    int alturaDireita = nodo->getDireita()->getAltura();
    nodo->setAltura(
    (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1);
}

#endif /* NO_AVL_HPP */
