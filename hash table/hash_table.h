/*
 * hash_table.h
 *
 *  Created on: 03 gen 2018
 *      Author: Gianni
 */

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <cmath>
#include <stdlib.h>

using std::string;

struct key {
	string key_value;
	bool erased;
};

template <class item>
class hash_table {
private:
	key** keys;
	item* items;
	int m;
	int hash_f1(const string) const;
	int hash_f2(const string) const;
public:
	hash_table(int exp_2); //la tabella avrà dimensione di una potenza di 2 per far sì che l'hashing doppio sia efficace;
							// si dà quindi in input l'esponente della potenza di 2 più appropriata
	int scan(string, bool);
	item lookup(string);
	void insert(string, item);
	void remove(string);
};


template <class item>
int hash_table<item>::hash_f1(const string _key) const{
	int hash_value = _key[0];
	int length = _key.length();
	for (int i=1; i<length; i++){
		hash_value = (hash_value*64 + _key[i])%m;
	}
	return hash_value;
}

template <class item>
int hash_table<item>::hash_f2(const string _key) const{
	int i = _key[0];
	float c = (sqrt(5)-1)/2;
	int l = 256;
	int length = _key.length();

	for (int i=1; i<length; i++){
		i = (i*64 + _key[i])%m;
	}
	int hash_value = (int) l*(i*c - (int)(i*c));
	if (hash_value % 2 != 0)
		return hash_value;
	else return hash_value + 1;
}

template <class item>
hash_table<item>::hash_table(int exp_2){
	m = 2**exp_2;
	keys = new key*[m];
	items = new item[m];

	for (int i=0; i<m; i++){
		keys[i] = NULL;
		keys[i]->erased = false;
	}
}

template <class item>
int hash_table<item>::scan(string _key, bool insert){
	int eras_pos = m;
	int iterations = 0;
	int pos = hash_f1(_key);

	while (keys[pos]->key_value != _key and keys[pos] != NULL and iterations<m){
			if (keys[pos]->erased and eras_pos == m)
				eras_pos = pos;
			pos = (pos + iterations*hash_f2(_key))%m;
			iterations++;
	}
	if (insert and keys[pos]->key_value != _key and eras_pos<m)
		pos = eras_pos;
	return pos;
}

template <class item>
item hash_table<item>::lookup(string _key){
	int i = scan(_key, false);
	if (keys[i]->key_value == _key)
		return item[i];
	else
		return NULL;
}

template <class item>
void hash_table<item>::insert(string _key, item value){
	int i = scan(_key, true);
	if (keys[i]->key_value == NULL or keys[i]->erased or keys[i]->key_value == _key){
		keys[i]->key_value = _key;
		keys[i]->erased = false;
		items[i] = value;
	}
	else
		std::cout << "ERROR \nHash table is full!" << std::endl;
}

template <class item>
void hash_table<item>::remove(string _key){
	int i = scan(_key, false);
	if (keys[i]->key_value == _key){
		keys[i]->key_value = "";
		keys[i]->erased = true;
	}
}
#endif /* HASH_TABLE_H_ */
