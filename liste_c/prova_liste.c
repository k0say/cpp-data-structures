/*
 * prova_liste.c
 *
 *  Created on: 10 ott 2017
 *      Author: Gianni
 */

#include "liste_cursori.h"

int main(){
	item* lista = create_list();

	if (is_empty(lista)) printf("bellaaa\n");
	read_item(4, lista);
	if (overwrite_item(5, 45, lista) == -1){
		printf("L'indice indicato non e' valido.\n");
	}

	system ("pause");
	return 0;
}
