/*
 * matrice.cpp
 *
 *  Created on: 27 ott 2017
 *      Author: Gianni
 */
#include "matrice.h"
#include <iostream>

//costruttore
matrice::matrice(int c, int r){
  colonne = c;
  righe = r;
  // allocazione dinamica della matrice
  int i, j;
  elementi = new tipoEl* [righe];
  for (i=0; i < righe; i++)
  elementi[i] = new tipoEl[colonne];
  for (i=0; i < righe; i++)
	  for (j=0; j < colonne; j++)
  		elementi[i][j] = 0;
}

//costruttore di copia
matrice:: matrice (const matrice& A){
	colonne = A.colonne;
	righe = A.righe;
	//allocazione nuova matrice
	int i, j;
	elementi = new tipoEl* [righe];
	for (i=0; i < righe; i++)
		elementi[i] = new tipoEl[colonne];
	for (i=0; i < righe; i++)
		for (j=0; j < colonne; j++)
			elementi[i][j] = A.elementi[i][j];
}

matrice:: ~matrice(){
	int i;
	for (i=0; i < this->righe; i++){
		delete[] this->elementi[i];
	}
	delete[] this->elementi;
}

tipoEl matrice:: leggimatrice(int r, int c){
	return elementi[r][c];
}

void matrice:: scrivimatrice(int r, int c, tipoEl nuovoEl){
	elementi[r][c] = nuovoEl;
}

void matrice:: prodottoScalare (double scalare){
	int i,j;
	for (i=0; i < righe; i++)
		for(j=0; j < colonne; j++)
			elementi[i][j] = elementi[i][j]*scalare;
}

matrice matrice:: trasposta(){
	class matrice trasposta(colonne, righe);
	int i, j;
	for (i=0; i < righe; i++)
		for (j=0; j < colonne; j++)
			trasposta.scrivimatrice(j, i, elementi[i][j]);
	return trasposta; //perché si può restituire trasposta che è stata definita nel metodo?
	//perché è sovraccaricato l'operatore di assegnamento... (??)
}

matrice matrice:: prodotto(const matrice& matrice1){
	if (this->colonne == matrice1.righe){
		int i, j;
		for (i=0; i<this->righe; i++)
			for (j=0; j<this->colonne; j++)
				this->elementi[i][j] = this->elementi[i][j]*matrice1.elementi[j][i];
	}
	else std::cout << "non si puo' eseguire il prodotto";
	return *this;
}

matrice& matrice::operator= (const matrice& matrice1){
	if (this->righe == matrice1.righe and this->colonne == matrice1.colonne){
		if (*this == matrice1){
		int i, j;
		for(i=0; i < this->righe; i++)
			for (j=0; j < this->colonne; j++)
				this->elementi[i][j]=matrice1.elementi[i][j];
		}
		else
			std::cout << "matrici uguali";
	}
	else {
		/*cambia le dimensioni di this con quelle di matrice1*/
		int i, j;

		//deallocazione
		for (i=0; i < this->righe; i++){
			delete[] this->elementi[i];
		}
		delete[] this->elementi;

		//allocazione con nuove dimensioni
		this->righe = matrice1.righe;
		this->colonne = matrice1.colonne;
		this->elementi = new tipoEl*[matrice1.righe];
		for(i=0; i < this->righe; i++){
			this->elementi[i] = new tipoEl[this->colonne];
		}

		//assegnamento
		for(i=0; i < this->righe; i++)
			for (j=0; j < this->colonne; j++)
				this->elementi[i][j]=matrice1.elementi[i][j];
	}
	return *this;
}

bool matrice::operator ==(const matrice& matrice1){
	if (this->righe != matrice1.righe or this->colonne != matrice1.colonne){
		std::cout << "matrici di dimensioni diverse";
		return false;
	}
	else{
		int i, j;
		bool equal = true;
		for (i=0; i < this->righe and equal; i++)
			for (j=0; j < this->colonne and equal; j++)
				if (this->elementi[i][j] != matrice1.elementi[i][j])
					equal = false;
		return equal;
	}
}
