/*
 * liste_cursori.h
 *
 *  Created on: 10 ott 2017
 *      Author: Gianni
 */

#ifndef LISTE_CURSORI_H_
#define LISTE_CURSORI_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define DIM 40

typedef struct {
	int forw_index;
	int value;
} item ;

typedef struct {
	item* list_pointer;
	int list_cardinality;
	item* e_list_pointer;
	int e_list_cardinality;
} type_list;

/* Crea uno spazio per una lista da 40 elementi, inizializzando ogni elemento come membro di una lista libera
 * collegato al successivo. L'ultimo elemento ha valore del cursore -1, per indicare che e' l'ultimo.*/
type_list create_list ();

/* Controlla se la lista in input e' vuota in base al valore del campo cardinality. */
_Bool is_empty(type_list list);

/* Legge l'elemento della lista che si trova in posizione item_position
 * (questa è indicata considerando solo l'ordine degli elementi
 * e non l'effettivo indice dell'elemento nel vettore di cursori. Se la lista è vuota stampa un avviso,
 * se item_position ha un valore scorretto viene stampato un avviso.
 * Cosa restituisce?*/
int read_item (int item_position, item* list);

/* La funzione aggiorna il valore dell'elemento in posizione item_position e restituisce la sua posizione nel vettore.
 * Se la lista è vuota stampa un avviso (cosa viene restituito?). Se item_position ha un valore scorretto viene stampato un avviso e
 * restituito -1.*/
int overwrite_item(int new_value, int item_position, item* list);

int new_item(int value, int position, item* list);




#endif /* LISTE_CURSORI_H_ */
