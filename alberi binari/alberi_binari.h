/*
 * aberi_binari.h
 *
 *  Created on: 02 gen 2018
 *      Author: Gianni
 */

#ifndef ALBERI_BINARI_H_
#define ALBERI_BINARI_H_

#include <iostream>
#include "exceptions.h"

template <class item>
class binary_tree{
	typedef binary_tree* node;
private:
	item value;
	node _parent;
	node r_child;
	node l_child;
public:
	binary_tree(item n_value);
	~binary_tree();
	item getValue();
	void setValue(item n_value);

	node parent();
	node rChild();
	node lChild();
	node root();

	void insertR_Child(node subtree);
	void insertL_Child(node subtree);

	void eraseR_Child();
	void eraseL_Child();

	bool isaleaf();

	void postvisit();

};

template <class item>
binary_tree<item>:: binary_tree(item n_value){
	value = n_value;

	_parent = 0;
	r_child = 0;
	l_child = 0;
}

template <class item>
binary_tree<item>:: ~binary_tree(){
	this->eraseR_Child();
	this->eraseL_Child();
	delete this;
}

template <class item>
item binary_tree<item>:: getValue(){
	if (this != NULL)
		return value;
	else
		throw null_node();
}

template <class item>
void binary_tree<item>:: setValue(item n_value){
	if (this != NULL)
		value = n_value;
	else
		throw null_node();
}

template <class item>
typename binary_tree<item>::node binary_tree<item>:: parent(){
	return _parent;
}

template <class item>
typename binary_tree<item>::node  binary_tree<item>:: rChild(){
	return r_child;
}

template <class item>
typename binary_tree<item>::node  binary_tree<item>:: lChild(){
	return l_child;
}

template <class item>
typename binary_tree<item>::node binary_tree<item>:: root(){
	typename binary_tree<item>::node root;
	root = this;

	while (root->_parent != NULL)
		root = root->_parent;

	return root;
}

template <class item>
void binary_tree<item>:: insertR_Child(node subtree){
	if (subtree->parent() != NULL)
		std::cout << "Il sottoalbero ha gia' un nodo padre" << std::endl;
	else if (r_child != NULL)
		std::cout << "L'albero ha gia' un figlio destro" << std::endl;
	else {
		r_child = subtree;
		subtree->_parent = this;
	}
}

template <class item>
void binary_tree<item>:: insertL_Child(node subtree){
	if (subtree->parent() != NULL)
		std::cout << "Il sottoalbero ha gia' un nodo padre" << std::endl;
	else if (l_child != NULL)
		std::cout << "L'albero ha gia' un figlio sinistro" << std::endl;
	else {
		l_child = subtree;
		subtree->_parent = this;
	}
}

template <class item>
void binary_tree<item>:: eraseR_Child(){
	if (r_child != NULL){
		r_child->eraseR_Child();
		r_child->eraseL_Child();
		delete r_child;
		r_child = NULL;
	}
}

template <class item>
void binary_tree<item>:: eraseL_Child(){
	if (l_child != NULL){
		l_child->eraseR_Child();
		l_child->eraseL_Child();
		delete l_child;
	}
}

template <class item>
bool binary_tree<item>:: isaleaf(){
	return (r_child == NULL and l_child == NULL);
}

template <class item>
void binary_tree<item>:: postvisit(){
	if (r_child != NULL)
		r_child->postvisit();
	if (l_child != NULL)
		l_child->postvisit();
	std::cout << value << std::endl;
}
#endif /* ALBERI_BINARI_H_ */
