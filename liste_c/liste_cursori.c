/*
 * liste_cursori.c
 *
 *  Created on: 10 ott 2017
 *      Author: Gianni
 */
#include "liste_cursori.h"

type_list create_list (){
	int index;
	type_list new_list;

	item* e_list_ptr;
	e_list_ptr = malloc(DIM*sizeof(item));
	for (index = 0; index < 40; index++){
		if (index == 39) e_list_ptr[index].forw_index = -1;
		else e_list_ptr[index].forw_index = index + 1;
	}
	new_list.e_list_pointer = e_list_ptr;
	new_list.e_list_cardinality = DIM;
	new_list.list_pointer = &new_list.e_list_pointer[5]; //5 a caso
	new_list.list_cardinality = 0;

	return new_list;
}

_Bool is_empty(type_list list){
	if (list.list_cardinality <= 0)
		return true;
	else
		return false;
}

int read_item (int item_position, item* list){
	 /* current_position e next_position sono due tipi di indice diversi: current_position è la posizione ideale
	 * dell'elemento corrente (primo, secondo, terzo..); next_position fa riferimento invece alla posizione dell'elemento
	 * nel vettore di cursori e serve a scandire la lista.
	 *
	 * Per la totale sicurezza del programma non bisognerebbe che fosse possibile indirizzare elementi non ancora
	 * allocati all'interno dell'array, oltre che elementi esterni; ma come si può fare?*/

	int current_position = 0;
	int result = 000;
	int next_position = 0;

	if (item_position < 0 || item_position > (DIM - 1)){
		printf("Invalid index!\n");
	}
	else{
		if (is_empty(list)) printf("Empty list!\n");
		else {
			while (current_position < item_position){
				next_position  = list[next_position].forw_index;
				current_position++;
			}
			result = list[next_position].value;
		}
	}
	return result;
}

int overwrite_item(int new_value, int item_position, item* list){
	/*Per la totale sicurezza del programma non bisognerebbe che fosse possibile indirizzare elementi non ancora
	 * allocati all'interno dell'array, oltre che elementi esterni; ma come si può fare?*/

	int current_position = 0;
	int next_position = 0;

	if (item_position < 0 || item_position > (DIM - 1)){
			printf("Invalid index!\n");
			next_position = -1;
		}
	else{
		if (is_empty(list)) printf("Empty list!\n");
		else {
			while(current_position < item_position){
				next_position = list[next_position].forw_index;
				current_position++;
			}
			list[next_position].value = new_value;
		}
	}

	return next_position;
}

int new_item(int value, int position, item* list){
	int current_position = 0;
	int next_position = 0;

	while (current_position < (position - 2)){
		next_position = list[next_position].forw_index;
		current_position++;
	}
	list[next_position].forw_index = empty_list
}
