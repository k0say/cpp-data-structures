/*
 * code.h
 *
 *  Created on: 13 nov 2017
 *      Author: Gianni
 */

#ifndef CODA_H_
#define CODA_H_

#include "linked_list.h"

template <class value_type>
class class_queue {
public:
	class_queue();
	~class_queue();
	bool empty() const;
	value_type read() const;
	void dequeue();
	void enqueue(value_type);
private:
	linked_list<value_type> queue;
};

template <class value_type>
class_queue<value_type>::class_queue(){}

template <class value_type>
class_queue<value_type>::~class_queue(){
	queue.~linked_list();
}

template <class value_type>
bool class_queue<value_type>::empty() const{
	return queue.empty();
}

template <class value_type>
value_type class_queue<value_type>::read() const{
	return queue.read(queue.last());
}

template <class value_type>
void class_queue<value_type>::dequeue(){
	queue.erase(queue.last());
}

template <class value_type>
void class_queue<value_type>::enqueue(value_type value){
	queue.insert(value, queue.begin());
}

#endif /* CODA_H_ */
