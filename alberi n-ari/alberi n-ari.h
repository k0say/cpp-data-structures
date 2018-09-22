/*
 * alberi n-ari.h
 *
 *  Created on: 30 dic 2017
 *      Author: Gianni
 */

#ifndef ALBERI_N_ARI_H_
#define ALBERI_N_ARI_H_

#include <iostream>

template <class item>
class tree{
	typedef tree* node;
private:
	item value;
	node parent;
	node child;
	node sibling;
public:
	tree(item n_value);
	~tree();
	item getValue();
	void setValue(item n_value);

	node getParent();
	node getChild();
	node getSibling();
	node getRoot();

	void insertFirstChild(node subtree);
	void insertSibling(node subtree);

	void eraseChild();
	void eraseSibling();
	void eraseSubtree(node subtree);

	bool isaleaf();

	void postvisit();
};

template <class item>
tree<item>:: tree(item n_value){
	value = n_value;

	parent = 0;
	child = 0;
	sibling = 0;
}

template <class item>
tree<item>:: ~tree(){
	eraseSubtree(this);
}

template <class item>
item tree<item>:: getValue(){
	return value;
}

template <class item>
void tree<item>:: setValue(item n_value){
	value = n_value;
}


template <class item>
typename tree<item>::node tree<item>:: getParent(){
	return parent;
}

template <class item>
typename tree<item>::node  tree<item>:: getChild(){
	return child;
}

template <class item>
typename tree<item>::node  tree<item>:: getSibling(){
	return sibling;
}

template <class item>
typename tree<item>::node tree<item>:: getRoot(){
	typename tree<item>::node root;
	root = this;

	while (root->parent != NULL)
		root = root->parent;

	return root;
}

template <class item>
void tree<item>:: insertFirstChild(node subtree){
	if (subtree->getParent() != NULL)
		std::cout << "Il sottoalbero ha gia' un nodo padre";
	else{
		subtree->sibling = child;
		child = subtree;
		subtree->parent = this;
	}
}

template <class item>
void tree<item>:: insertSibling(node subtree){
	if (subtree->parent != NULL)
		std::cout << "Il sottoalbero ha gia' un nodo padre";
	else{
		subtree->parent = parent;
		subtree->sibling = sibling;
		sibling = subtree;
	}
}

template <class item>
void tree<item>:: eraseSubtree(node subtree){
	typename tree<item>::node next_erase = subtree->child;
	typename tree<item>::node next;

	while (next_erase != NULL){
		next = next_erase->sibling;
		eraseSubtree(next_erase);
		next_erase = next;
	}
	delete subtree;
}

template <class item>
void tree<item>:: eraseChild(){
	typename tree<item>::node new_child;
	new_child = child->sibling;
	eraseSubtree(child);
	child = new_child;
}

template <class item>
void tree<item>:: eraseSibling(){
	typename tree<item>::node new_sibling;
	new_sibling = sibling->sibling;
	eraseSubtree(sibling);
	sibling = new_sibling;
}

template <class item>
bool tree<item>:: isaleaf(){
	return (child == NULL);
}

template <class item>
void tree<item>:: postvisit(){
	if (child != NULL)
		child->postvisit();
	node next_sibling = sibling;
	std::cout << value << std::endl;
	while (next_sibling != NULL){
		sibling->postvisit();
		next_sibling = sibling->sibling;
	}
}

#endif /* ALBERI_N_ARI_H_ */
