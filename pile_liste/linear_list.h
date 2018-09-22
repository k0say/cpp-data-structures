/*
 * linear_list.h
 *
 *  Created on: 08 nov 2017
 *      Author: Gianni
 */

#ifndef LINEAR_LIST_H_
#define LINEAR_LIST_H_

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template <class T, class P>
class linear_list {
public:
	typedef T value_type;
	typedef P position;

	//virtual void create() = 0; //è un costrutto per esprimere una sorta di costruttore virtuale; viene riscritto nelle classi derivate

	virtual bool empty() const = 0; //const suffisso al nome di funzione rende costante l'oggetto a cui il metodo viene applicato

	virtual value_type read(position) const = 0;
	virtual void write(const value_type&, position) = 0;

	virtual position begin() const = 0;
	virtual position last() const = 0;
	virtual bool end(position) const = 0; //vero se la posizione è successiva a quella dell'ultimo elemento

	virtual position next(position) const = 0;
	virtual position previous(position) const = 0;

	virtual void insert(const value_type&, position) = 0;
	virtual void erase(position) = 0;

	virtual int size() const{
		int i=0;
		if (!empty()){
			position p = begin();
			for(i=0; !end(p); i++){
				p=next(p);
			}
		}
		return i;
	}

};

template <class T, class P>
	ostream& operator<< (ostream& os, const linear_list<T,P>& l){
		typename linear_list<T,P>::position p = l.begin();
		os << "[";
		while (!l.end(p)){
			if (p == l.begin())
				os << l.read(p);
			else
				os << ", " << l.read(p);
			p = l.next(p);
		}
		os << "]" << endl;

		return os;
	}



#endif /* LINEAR_LIST_H_ */
