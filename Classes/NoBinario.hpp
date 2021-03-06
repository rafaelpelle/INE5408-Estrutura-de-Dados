/*! Copyright <Rafael Pelle> [2015]
 * Classe NoBinario
 * Cada objeto da classe é uma árvore de busca binária.
 * \author Rafael Pelle.
 * \since 15/05/15
 * \version 1.0
 */

#ifndef NOBINARIO_H_
#define NOBINARIO_H_

#include <cstdio>
#include <vector>

template<typename T>
class NoBinario {
 protected:
	T* dado; /*!< Ponteiro para o dado que esse nó armazena.*/
	NoBinario<T>*  filhoEsquerda; /*!< Ponteiro para o nó filho da esquerda.*/
	NoBinario<T>* filhoDireita; /*!< Ponteiro para o nó filho da direita.*/
	std::vector<NoBinario<T>*> elementos; /*!< Vetor de nós para percorrer*/

 public:
    //! Construtor.
    /*!
     * Responsável por construir um nó de árvore binária.
     * armazena o dado, aponta filhoEsquerda e filhoDireita para NULL e
     * instancia o vetor elementos.
     */
	NoBinario<T>(const T& dado);

    // Destrutor
	virtual ~NoBinario();

	//! getFilhoEsquerda
	/*!
	 * \return um ponteiro para o filho da esquerda.
	 */
	NoBinario<T>* getFilhoEsquerda();

	//! setFilhoEsquerda(NoBinario<T>* filho)
	/*!
	 * \param filho um ponteiro para NoBinario<T>
	 * \return void
	 */
	void setFilhoEsquerda(NoBinario<T>* filho);

	//! getFilhoDireita
	/*!
	 * \return um ponteiro para o filho da direita.
	 */
	NoBinario<T>* getFilhoDireita();

	//! setFilhoDireita(NoBinario<T>* filho)
	/*!
	 * \param filho um ponteiro para NoBinario<T>
	 * \return void
	 */
	void setFilhoDireita(NoBinario<T>* filho);

	//! getDado()
	/*!
	 * \return T* ponteiro para o dado do NoBinario
	 */
	T* getDado();

	//! setDado(T* dado)
	/*!
	 * \param T* dado, ponteiro para o dado armazenado no NoBinario
	 * \return void
	 */
	void setDado(T* dado);

	//! getElementos()
	/*!
	 *  \return vector<NoBinario<T>*> vetor de elementos da árvore binária.
	 */
	std::vector<NoBinario<T>*> getElementos();

	//! busca(const T& dado, NoBinario<T>* arv)
	/*!
	 * \param dado, dado a ser buscado na árvore.
	 * \param arv, árvore binária em que o dado vai ser buscado.
	 * \return T* dado da árvore binária.
	 */
	T* busca(const T& dado, NoBinario<T>* arv);

	//! inserir(const T& dado, NoBinario<T>* arv)
	/*!
	 * \param dado, dado a ser inserido na árvore.
	 * \param arv, árvore binária em que o dado vai ser inserido.
	 * \return NoBinario<T>* ponteiro para um nó da árvore binária.
	 */
	NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv);

	//! remover(NoBinario<T>* arv, const T& dado)
	/*!
	 * \param dado, dado a ser removido na árvore.
	 * \param arv, árvore binária em que o dado vai ser removido.
	 * \return NoBinario<T>* ponteiro para um nó da árvore binária.
	 */
	NoBinario<T>* remover(NoBinario<T>* arv, const T& dado);

	//! minimo(NoBinario<T>* arv)
	/*!
	 * \param arv, árvore binária em que o menor dado vai ser buscado.
	 * \return NoBinario<T>* ponteiro para o nó "mais da esquerda" da árvore binária.
	 */
	NoBinario<T>* minimo(NoBinario<T>* arv);

	//! preOrdem(NoBinario<T>* arv)
	/*!
	 * \param arv, árvore binária que vai ser impressa em preOrdem.
	 * \return void
	 */
	void preOrdem(NoBinario<T>* arv);

	//! emOrdem(NoBinario<T>* arv)
	/*!
	 * \param arv, árvore binária que vai ser impressa em emOrdem.
	 * \return void
	 */
	void emOrdem(NoBinario<T>* arv);

	//! posOrdem(NoBinario<T>* arv)
	/*!
	 * \param arv, árvore binária que vai ser impressa em posOrdem.
	 * \return void
	 */
	void posOrdem(NoBinario<T>* arv);
};

template<typename T>
NoBinario<T>::NoBinario(const T& dado) {
	this->dado = new T(dado);
	this->filhoEsquerda = NULL;
	this->filhoDireita = NULL;
	elementos.clear();
}

template<typename T>
NoBinario<T>::~NoBinario() {
    if (filhoEsquerda != NULL) {
        filhoEsquerda -> ~NoBinario();
    }
    if (filhoDireita != NULL) {
        filhoDireita -> ~NoBinario();
    }
    delete dado;
}


template<typename T>
NoBinario<T>* NoBinario<T>::getFilhoEsquerda() {
	return this->filhoEsquerda;
}

template<typename T>
void NoBinario<T>::setFilhoEsquerda(NoBinario<T>* filho) {
	this->filhoEsquerda = filho;
}

template<typename T>
NoBinario<T>* NoBinario<T>::getFilhoDireita() {
	return this->filhoDireita;
}

template<typename T>
void NoBinario<T>::setFilhoDireita(NoBinario<T>* filho) {
	this->filhoDireita = filho;
}

template<typename T>
T* NoBinario<T>::getDado() {
	return this->dado;
}

template<typename T>
void NoBinario<T>::setDado(T* dado) {
	this->dado = dado;
}

template<typename T>
std::vector<NoBinario<T>*> NoBinario<T>::getElementos() {
	return this->elementos;
}

template<typename T>
T* NoBinario<T>::busca(const T& dado, NoBinario<T>* arv) {
	while (arv != NULL && *arv->getDado() != dado) {
		if (*arv->dado < dado) {
			arv = arv->getFilhoDireita();
		} else {
			arv = arv->getFilhoEsquerda();
		}
	}
	if (arv != NULL) {
        return arv -> getDado();
    }
    throw "Erro dado nao esta na arvore!";
}


template<typename T>
NoBinario<T>* NoBinario<T>::inserir(const T& dado, NoBinario<T>* arv) {
	if (dado < *arv->getDado()) {
		if (arv->getFilhoEsquerda() == NULL) {
			NoBinario<T>* novo = new NoBinario<T>(dado);
			arv->setFilhoEsquerda(novo);
		} else {
			arv->setFilhoEsquerda(inserir(dado, arv->getFilhoEsquerda()));
		}
	} else if (dado > *arv->getDado()) {
		if (arv->getFilhoDireita() == NULL) {
			NoBinario<T>* novo = new NoBinario<T>(dado);
			arv->setFilhoDireita(novo);
		} else {
			arv->setFilhoDireita(inserir(dado, arv->getFilhoDireita()));
		}
	} else {
		throw "Não pode inserir dado duplicado";
	}
	return arv;
}

template<typename T>
NoBinario<T>* NoBinario<T>::remover(NoBinario<T>* arv, const T& dado) {
	if (arv == NULL) {
		return arv;
	} else {
		if (dado < *arv->getDado()) {
			arv->setFilhoEsquerda(remover(arv->getFilhoEsquerda(), dado));
			return arv;
		} else  {
			if (dado > *arv->getDado()) {
				arv->setFilhoDireita(remover(arv->getFilhoDireita(), dado));
				return arv;
			} else {
				if (arv->getFilhoDireita() != NULL && arv->getFilhoEsquerda() != NULL) {
					NoBinario<T>* temp = minimo(arv->getFilhoDireita());
					arv->setDado(temp->getDado());
					arv->setFilhoDireita(remover(arv->getFilhoDireita(), *arv->getDado()));
					return arv;
				} else {
					if (arv->getFilhoDireita() != NULL) {
						NoBinario<T>* filho = arv->getFilhoDireita();
						return filho;
					} else {
						if (arv->getFilhoEsquerda() != NULL) {
							NoBinario<T>* filho = arv->getFilhoEsquerda();
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


template<typename T>
NoBinario<T>* NoBinario<T>::minimo(NoBinario<T>* arv) {
	NoBinario<T>* minimo = arv;
	while (minimo->getFilhoEsquerda() != NULL) {
		minimo = minimo->getFilhoEsquerda();
	}
	return minimo;
}

template<typename T>
void NoBinario<T>::preOrdem(NoBinario<T>* arv) {
	if (arv != NULL) {
		elementos.push_back(arv);
		preOrdem(arv->getFilhoEsquerda());
		preOrdem(arv->getFilhoDireita());
	}
}

template<typename T>
void NoBinario<T>::emOrdem(NoBinario<T>* arv) {
	if (arv != NULL) {
		emOrdem(arv->getFilhoEsquerda());
		elementos.push_back(arv);
		emOrdem(arv->getFilhoDireita());
	}
}

template<typename T>
void NoBinario<T>::posOrdem(NoBinario<T>* arv) {
	if (arv != NULL) {
		posOrdem(arv->getFilhoEsquerda());
		posOrdem(arv->getFilhoDireita());
		elementos.push_back(arv);
	}
}


#endif /* NOBINARIO_HPP_ */


