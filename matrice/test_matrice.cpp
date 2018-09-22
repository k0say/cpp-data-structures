/*
 * test_matrice.cpp
 *
 *  Created on: 03 nov 2017
 *      Author: Gianni
 */

#include "matrice.h"
#include <stdlib.h>
#include <iostream>

int main(){
	class matrice quadrata_4(4, 4);
	int i, j;
	for (i=0; i<4; i++)
		for(j=0; j<4; j++)
			quadrata_4.scrivimatrice(i, j, 1);
	for (i=0; i<4; i++){
		std::cout << "\n";
		for(j=0; j<4; j++)
			std::cout << quadrata_4.leggimatrice(i,j) << " ";
	}

	class matrice matrice_copia(quadrata_4);
	matrice_copia.prodottoScalare(5);
	matrice_copia.scrivimatrice(2,3,7);
	matrice_copia.scrivimatrice(1,1,1);
	for (i=0; i<4; i++){
		std::cout << "\n";
		for(j=0; j<4; j++)
			std::cout << matrice_copia.leggimatrice(i,j) << " ";
	}

	class matrice matrice_ass = matrice_copia.trasposta();
	for (i=0; i<4; i++){
		std::cout << "\n";
		for(j=0; j<4; j++)
			std::cout << matrice_ass.leggimatrice(i,j) << " ";
	}
	matrice_copia.prodotto(matrice_ass);
	for (i=0; i<4; i++){
		std::cout << "\n";
		for(j=0; j<4; j++)
			std::cout << matrice_copia.leggimatrice(i,j) << " ";
	}
	system("pause");
	return 0;
}


