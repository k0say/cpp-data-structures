/*
 * pila.h
 *
 *  Created on: 13 nov 2017
 *      Author: Gianni
 */

#ifndef PILA_H_
#define PILA_H_
#include "linked_list.h"

template <class value_type>
class class_pila{
public:
	class_pila();
	~class_pila();
	bool empty() const;
	value_type read() const;
	void push(value_type);
	void pop();

private:
	linked_list<value_type> pila;
};
template <class value_type>
class_pila<value_type>::class_pila(){

}
template <class value_type>
class_pila<value_type>::~class_pila(){
	pila.~linked_list();
}

template <class value_type>
bool class_pila<value_type>::empty() const{
	return pila.empty();
}

template <class value_type>
value_type class_pila<value_type>::read() const{
	return pila.read(pila.begin());
}

template <class value_type>
void class_pila<value_type>::push(value_type value){
	pila.insert(value, pila.begin());
}

template <class value_type>
void class_pila<value_type>::pop(){
	pila.erase(pila.begin());
}

#endif /* PILA_H_ */
