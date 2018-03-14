/*! Copyright <Rafael Pelle> [2015]
 * \class NoAVLString
 * \author Rafael Pelle.
 * \since 30/06/15
 * \version 1.0
 *
 * Cada objeto da classe é um nó de árvore AVL modificado para o tipo string.
 * Faz as comparações (maior que, menor que, igual à e diferente de) usando
 * string::compare(string str1, string str2)
 */

#ifndef NO_AVL_String_HPP
#define NO_AVL_String_HPP

#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

class NoAVLString  {
 private:
    int altura;  //!< Representa a altura do nó AVL.
    string* dado;  //!< Ponteiro para o dado que esse nó armazena.
    NoAVLString* esquerda;  //!< Ponteiro para o nó filho da esquerda.
    NoAVLString* direita;  //!< Ponteiro para o nó filho da direita.
    std::vector<NoAVLString* > elementos; //!< Vetor de nós para imprimir os percorrimentos*/

    //! simp_roda_esq
    /*!
     * realiza uma rotação à esquerda
     * \param NoAVL* nodo2, que vai ser rotacionado com seus filhos.
     * \return NoAVL* nova raiz da árvore.
     */
    NoAVLString* simp_roda_esq(NoAVLString* nodo2);

    //! simp_roda_dir
    /*!
     * realiza uma rotação à direita
     * \param NoAVL* nodo2, que vai ser rotacionado com seus filhos.
     * \return NoAVL* nova raiz da árvore.
     */
    NoAVLString* simp_roda_dir(NoAVLString* nodo2);

    //! rebalancear
    /*!
     * Verifica se a árvore está desbalanceada e se necessário realiza o rebalanceamento.
     * \param nodo que vai ser rebalanceado caso necessário.
     * \return NoAVL* nova raiz da árvore.
     */
    NoAVLString* rebalancear(NoAVLString* nodo);

    //! getBalanceamento
    /*!
     * \param NoAVL* nodo, que terá seu balanceamento verificado.
     * \return Inteiro, diferença entre a altura dos filhos da árvore.
     */
    int getBalanceamento(NoAVLString* nodo);

    //! ajustarAltura
    /*!
     * Ajusta a altura do nodo para 1 + (maior altura entre os filhos)
     * \param NoAVL* nodo que terá sua altura ajustada.
     * \return void
     */
    void ajustarAltura(NoAVLString* nodo);

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
    NoAVLString(const string& dado);

    //! Destrutor.
    /*!
     * Destrói a árvore AVL e todos os seus descendentes.
     * \param void
     * \return void
     */
    virtual ~NoAVLString();

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
     * \return vector<NoAVL*> com o NoAVL e todos os seus descendentes.
     */
    std::vector<NoAVLString*> getElementos();

	//! getEsquerda
	/*!
	 * \param void
	 * \return NoAVL* filho da esquerda.
	 */
    NoAVLString* getEsquerda();

	//! setEsquerda
	/*!
	 * \param nodo, um ponteiro para NoAVL
	 * \return void
	 */
    void setEsquerda(NoAVLString* nodo);

	//! getDireita
	/*!
	 * \param void
	 * \return NoAVL* filho da direita.
	 */
    NoAVLString* getDireita();

	//! setDireita
	/*!
	 * \param nodo, um ponteiro para NoAVL
	 * \return void
	 */
    void setDireita(NoAVLString* nodo);

	//! inserir
	/*!
	 * \param dado, dado a ser inserido na árvore.
	 * \param arv, NoAVL em que o dado vai ser inserido.
	 * \return NoAVL* raiz da árvore.
	 */
    NoAVLString* inserir(const string& dado, NoAVLString* arv);

	//! remover
	/*!
	 * \param dado, dado a ser removido na árvore.
	 * \param arv, NoAVL que o dado vai ser removido.
	 * \return NoAVL*
	 */
    NoAVLString* remover(NoAVLString* arv, const string& dado);

	//! minimo
	/*!
	 * \param nodo, NoAVL em que o menor dado vai ser buscado.
	 * \return NoAVL* ponteiro para o nó "mais à esquerda" da árvore.
	 */
    NoAVLString* minimo(NoAVLString* nodo);

    //! getDado()
	/*!
	 * \return string* ponteiro para o dado do NoAVL
	 */
    string* getDado();

	//! setDado
	/*!
	 * \param string& dado, o dado que será armazenado no NoAVL
	 * \return void
	 */
    void setDado(const string& dado);

	//! busca
	/*!
	 * \param dado, dado a ser buscado na árvore.
	 * \param arv, NoAVL em que o dado vai ser buscado.
	 * \return string* ponteiro para o dado buscado.
	 */
    string* busca(const string& dado, NoAVLString* arv);

	//! preOrdem
	/*!
	 * \param nodo, NoAVL que vai ser impresso em preOrdem, dentro do vetor elementos.
	 * \return void
	 */
    void preOrdem(NoAVLString* nodo);

	//! emOrdem
	/*!
	 * \param nodo, NoAVL que vai ser impresso emOrdem, dentro do vetor elementos.
	 * \return void
	 */
    void emOrdem(NoAVLString* nodo);

	//! posOrdem
	/*!
	 * \param nodo, NoAVL que vai ser impresso em posOrdem, dentro do vetor elementos.
	 * \return void
	 */
    void posOrdem(NoAVLString* nodo);
};

NoAVLString::NoAVLString(const string& dado) {
	this->altura = 0;
	this->dado = new string(dado);
	this->esquerda = NULL;
	this->direita = NULL;
	this->elementos.clear();
}

NoAVLString::~NoAVLString() {
	if (esquerda != NULL) {
		esquerda->~NoAVLString();
	}
	if (direita != NULL) {
		direita->~NoAVLString();
	}
	delete dado;
}

int NoAVLString::getAltura() {
	if (this != NULL)
		return this->altura;
	else
		return -1;
}

void NoAVLString::setAltura(int alt) {
	if (this != NULL) {
		this->altura = alt;
	}
}

std::vector<NoAVLString* > NoAVLString::getElementos() {
	return this->elementos;
}

NoAVLString* NoAVLString::getEsquerda() {
	if (this != NULL) {
		return this->esquerda;
	} else {
		return NULL;
	}
}

void NoAVLString::setEsquerda(NoAVLString* nodo) {
	if (this != NULL) {
		this->esquerda = nodo;
	}
}

NoAVLString* NoAVLString::getDireita() {
	if (this != NULL) {
		return this->direita;
	} else {
		return NULL;
	}
}

void NoAVLString::setDireita(NoAVLString* nodo) {
	if (this != NULL) {
		this->direita = nodo;
	}
}

NoAVLString* NoAVLString::inserir(const string& dado, NoAVLString* arv) {
    if (arv == NULL) {
    	return new NoAVLString(dado);
    }
    if (dado < *arv->getDado()) {
    	arv->setEsquerda(inserir(dado, arv->getEsquerda()));
    } else if (dado > *arv->getDado()) {
    	arv->setDireita(inserir(dado, arv->getDireita()));
    }
    return rebalancear(arv);
}

NoAVLString* NoAVLString::remover(NoAVLString* arv, const string& dado) {
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
					NoAVLString* temp = minimo(arv->getDireita());
					arv->setDado(*temp->getDado());
					arv->setDireita(remover(arv->getDireita(), *arv->getDado()));
					return rebalancear(arv);
				} else {
					if (arv->getDireita() != NULL) {
						NoAVLString* filho = arv->getDireita();
						return filho;
					} else {
						if (arv->getEsquerda() != NULL) {
							NoAVLString* filho = arv->getEsquerda();
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

NoAVLString* NoAVLString::minimo(NoAVLString* nodo) {
	NoAVLString* min = nodo;
	while (min->getEsquerda() != NULL) {
		min = min->getEsquerda();
	}
	return min;
}

string* NoAVLString::getDado() {
	if (this != NULL)
		return this->dado;
	else
		return NULL;
}

void NoAVLString::setDado(const string& dado) {
	this->dado = new string(dado);
}

string* NoAVLString::busca(const string& dado, NoAVLString* arv) {
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

void NoAVLString::preOrdem(NoAVLString* nodo) {
	if (nodo != NULL) {
		elementos.push_back(nodo);
		preOrdem(nodo->getEsquerda());
		preOrdem(nodo->getDireita());
	}
}

void NoAVLString::emOrdem(NoAVLString* nodo) {
	if (nodo != NULL) {
		emOrdem(nodo->getEsquerda());
		elementos.push_back(nodo);
		emOrdem(nodo->getDireita());
	}
}

void NoAVLString::posOrdem(NoAVLString* nodo) {
	if (nodo != NULL) {
		posOrdem(nodo->getEsquerda());
		posOrdem(nodo->getDireita());
		elementos.push_back(nodo);
	}
}

NoAVLString* NoAVLString::simp_roda_esq(NoAVLString* nodo1) {
    NoAVLString* nodo2 = nodo1->getDireita();
    nodo1->setDireita(nodo2->getEsquerda());
    nodo2->setEsquerda(nodo1);
    ajustarAltura(nodo1);
    ajustarAltura(nodo2);
	return nodo2;
}

NoAVLString* NoAVLString::simp_roda_dir(NoAVLString* nodo2) {
    NoAVLString* nodo1 = nodo2->getEsquerda();
    nodo2->setEsquerda(nodo1->getDireita());
    nodo1->setDireita(nodo2);
    ajustarAltura(nodo2);
    ajustarAltura(nodo1);
    return nodo1;
}

int NoAVLString::getBalanceamento(NoAVLString* nodo) {
	return nodo->getDireita()->getAltura() - nodo->getEsquerda()->getAltura();
}

NoAVLString* NoAVLString::rebalancear(NoAVLString* nodo) {
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

void NoAVLString::ajustarAltura(NoAVLString* nodo) {
    int alturaEsquerda = nodo->getEsquerda()->getAltura();
    int alturaDireita = nodo->getDireita()->getAltura();
    nodo->setAltura(
    (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1);
}

#endif /* NO_AVL_HPP */
