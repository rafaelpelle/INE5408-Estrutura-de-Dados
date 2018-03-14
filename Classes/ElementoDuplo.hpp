// Copyright <Rafael Pelle> [2015]
/*! Classe Elemento Duplo
 * Cada objeto da classe é um elemento dentro de uma lista encadeada dupla.
 * \author Rafael Pelle
 * \since 08/04/2015
 * \version 1.0
 */
#ifndef ELEMENTODUPLO_HPP
#define ELEMENTODUPLO_HPP

template<typename T>
class ElementoDuplo {
 public:
  //! Construtor.
  /*! Responsável por construir um objeto elemento de lista encadeada dupla.
   * \param &info, referência do dado que será guardado no elemento.
   * \param *next, ponteiro para o próximo elemento da lista.
   * \param *prev, ponteiro para o elemento anterior da lista.
   */
	ElementoDuplo(const T& info, ElementoDuplo<T>* next, ElementoDuplo<T>* prev) {
	  _info = new T(info);
	  _next = next;
	  _prev = prev;
	}

	//! Destrutor
	/*! Destrói o elemento e o dado armazenado nele.
	 */
	~ElementoDuplo() {
		delete _info;
	}

	//! getProximo()
	/*! \return _next, ponteiro para o próximo elemento.
	 */
	ElementoDuplo<T>* getProximo() const {
		return _next;
	}


	//! getAnterior()
	/*! \return _prev, ponteiro para o elemento anterior da lista.
	 */
	ElementoDuplo<T>* getAnterior() const {
	  return _prev;
	}

	//! getInfo()
	/*! \return *info, o objeto do tipo T que o ponteiro info "apontava"
	 */
	T getInfo() const {
		return *_info;
	}

	//! setProximo(Elemento<T>* next)
	/*! \param next, um ponteiro para o próximo elemento da lista.
	 */
	void setProximo(ElementoDuplo<T>* next) {
		_next = next;
	}

	//! setAnterior(Elemento<T>* prev)
	/*! \param prev, um ponteiro para o elemento anterior da lista.
	 */
	void setAnterior(ElementoDuplo<T>* prev) {
	  _prev = prev;
	}

 private:
    T *_info; /*!< Ponteiro para o dado guardado no elemento.*/
    ElementoDuplo<T> *_next; /*!< Ponteiro para o próximo elemento da lista.*/
    ElementoDuplo<T> *_prev; /*!< Ponteiro para o elemento anterior da lista.*/
};

#endif
