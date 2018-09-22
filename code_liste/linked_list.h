/*
 * linked_list.h
 *
 *  Created on: 08 nov 2017
 *      Author: Gianni
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "linear_list.h"

template <class T>
class linked_list; //forward declaration

template <class T>
class list_node {
	friend class linked_list<T>;
private:
	T value;
	list_node<T>* previous;
	list_node<T>* next;
};

template <class T>
class linked_list: public linear_list<T, list_node<T>*>{ //quindi i tipi/classi del template, anche se rimangono generici (si usa sempre T)
														//devono essere specificati come tipi/classi dichiarati in ambiente visibile alla classe derivata

	typedef typename linear_list<T, list_node<T>*>::value_type value_type; //perché non scrivere typedef T value_type come nella superclasse?
	typedef typename linear_list<T, list_node<T>*>::position position;

public:
	linked_list();
	linked_list(int); //inizializza la lista con una certa lunghezza? non ha senso...
	linked_list(const linked_list<T>&);

	~linked_list();

	//void create();

	bool empty() const;

	value_type read(position) const;
	void write(const value_type&, position); //si usa la reference per value_type perché è sempre un tipo generico

	position begin() const;
	position last() const;
	bool end(position) const;

	position next(position) const;
	position previous(position) const;

	void insert(const value_type&, position);
	void erase(position);

	linked_list<T>& operator=(const linked_list<T>&);
	bool operator==(const linked_list<T>&) const;

private:
	list_node<T>* head;
	int length;
};

template <class T>
linked_list <T>::linked_list() {
	head = new list_node<T>;
	head->next = head;
	head->previous = head;
	length = 0;
}

template <class T>
linked_list<T>::linked_list (int l){
	head = new list_node<T>;
	head->next = head;
	head->previous = head;
	length = l;
}

template <class T>
linked_list<T>::linked_list(const linked_list<T>& L){

	length = L.size();

	head = new list_node<T>;
	head->next = head;
	head->previous = head;

	if (!L.empty()){
		position p = L.last();
		for (int i=0; i < L.length; i++){ //si mette sull'ultimo e aggiunge in testa, sul penultimo, e in testa..
			insert(L.read(p), begin());
			p = L.previous(p);
		}
	}
}

template <class T>
linked_list<T>::~linked_list(){
	while (!empty())
		erase(begin());
	delete head;
}

/*template <class T>
void linked_list<T>::create(){
	if (empty())
		length = 0;
} non capisco il senso di questo finto costruttore */

template <class T>
bool linked_list<T>::empty() const{
	return (head->next == head);
}

template <class T>
typename linked_list<T>::value_type linked_list<T>::read(position p) const{
	if (!end(p))
		return p->value;
}

template <class T>
void linked_list<T>::write(const value_type& val, position p){
	if (!end(p))
		p->value = val;
}

template <class T>
typename linked_list<T>::position linked_list<T>::begin() const{
	return (head->next); //quindi head è usato come sentinella
}

template< class T >
typename linked_list<T>::position linked_list<T>::last() const {
	return (head->previous);
}

template <class T>
bool linked_list<T>::end(position p) const{ //vero se la posizione è successiva all'ultimo elemento, ovvero è la testa
	return (p == head);
}

template <class T>
typename linked_list<T>::position linked_list<T>::next(position p) const{
	return p->next;
}

template <class T>
typename linked_list<T>::position linked_list<T>::previous(position p) const{
	return p->previous;
}

template <class T>
void linked_list<T>::insert(const value_type& el, position p){
	position t = new list_node<T>;
	t->value = el;

	p->previous->next = t;
	t->previous = p->previous;
	p->previous = t;
	t->next = p;

	length++;
}

template <class T>
void linked_list<T>::erase(position p){
	if (!empty() and !end(p)){
		p->previous->next = p->next;
		p->next->previous = p->previous;
		delete p;
	}
}

template <class T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& L){
	if (this != &L){
		/*position p = begin();
		while (p->previous != last()){
			p = p->next;
			delete p->previous;
		}
		non bisogna liberare la memoria dalla vecchia lista? come si fa? */
		length = L.size();

		head = new list_node<T>;
		head->next = head;
		head->previous = head;

		if (!L.empty()){
			position p = L.last();
			for (int i=0; i < L.size(); i++){ //si mette sull'ultimo e aggiunge in testa, sul penultimo, e in testa..
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
	}
	return *this;
}

template <class T>
bool linked_list<T>::operator==(const linked_list<T>& L) const{
	bool equal = true;
	if (L.size() != length)
		return false;
	else{
		position p = begin(), q = L.begin();
		for (int i=0; !end(p) and equal; i++){
			if (p->value != q->value)
				equal = false;
			p = p->next;
			q = q->next;
		}
	}
	return equal;
}

#endif /* LINKED_LIST_H_ */
