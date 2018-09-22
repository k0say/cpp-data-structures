/*
 * test.cpp
 *
 *  Created on: 30 dic 2017
 *      Author: Gianni
 */

#include "alberi n-ari.h"
#include <stdlib.h>

int main(){
	tree <std::string> tassonomia("Regno vegetale");

	tree <std::string> crittogame("Crittogame");
	tree <std::string> fanerogame("Fanerogame");
	tassonomia.insertFirstChild(&crittogame);
	crittogame.insertSibling(&fanerogame);

	tree <std::string> tallofite("Tallofite");
	tree <std::string> archegoniate("Archegoniate");
	tree <std::string> gimnosperme("Gimnosperme");
	tree <std::string> angiosperme("Angiosperme");

	crittogame.insertFirstChild(&tallofite);
	tallofite.insertSibling(&archegoniate);
	fanerogame.insertFirstChild(&gimnosperme);
	gimnosperme.insertSibling(&angiosperme);

	std::cout << archegoniate.getParent()->getValue() << std::endl;
	std::cout << tassonomia.getChild()->getSibling()->getValue() << std::endl;
	std::cout << angiosperme.getRoot()->getValue() << std::endl;

	tassonomia.postvisit();

	tassonomia.eraseChild();
	std::cout << tassonomia.getChild()->getValue() << std::endl;
	if (tassonomia.isaleaf()) std::cout << "Il nodo inserito e' un nodo foglia" <<std::endl;

	system("pause");
	return 0;
}


