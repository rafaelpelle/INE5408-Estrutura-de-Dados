// Copyright
/*! Classe Elemento
 * Cada objeto da classe é um elemento dentro de uma lista encadeada.
 * \author 
 * \since 
 * \version
 */
#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template<typename T>
class Elemento {
 public:
//! Construtor.
/*! Responsável por construir um objeto elemento de lista encadeada.
 * \param &info, endereço do dado que será guardado no elemento.
 * \param *next, ponteiro para o próximo elemento da lista.
 */
	Elemento(const T& info, Elemento<T>* next) : info(new T(info)), _next(next) {}

//! Destrutor
/*! Destrói o elemento e o dado armazenado nele.
 */
	~Elemento() {
		delete info;
	}

//! getProximo()
/*! \return _next, ponteiro para o próximo elemento.
 */
	Elemento<T>* getProximo() const {
		return _next;
	}

//! getInfo()
/*! \return *info, o objeto do tipo T que o ponteiro info "apontava"
 */
	T getInfo() const {
		return *info;
	}

//! setProximo(Elemento<T>* next)
/*! \param next, um ponteiro para o próximo elemento da lista.
 */
	void setProximo(Elemento<T>* next) {
		_next = next;
	}

 private:
    T *info; /*!< Ponteiro para o dado guardado no elemento.*/
    Elemento<T> *_next; /*!< Ponteiro para o próximo elemento da lista.*/
};

#endif
