/*
 * test_alberibinari.cpp
 *
 *  Created on: 02 gen 2018
 *      Author: Gianni
 */

#include "alberi_binari.h"
#include <iostream>
#include <stdlib.h>

int main(){

	binary_tree<std::string> AZ("abcdefghilmnopqrstuvz");

	binary_tree<std::string> AL("abcdefghil");
	binary_tree<std::string> MZ("mnopqrstuvz");

	AZ.insertR_Child(&AL);
	AZ.insertL_Child(&MZ);

	binary_tree<std::string> AE("abcde");
	binary_tree<std::string> FL("fghil'");
	binary_tree<std::string> MR("mnopqr");
	binary_tree<std::string> SZ("stuvz'");

	AL.insertR_Child(&AE);
	AL.insertL_Child(&FL);
	MZ.insertR_Child(&MR);
	MZ.insertL_Child(&SZ);

	binary_tree<std::string> AC("abc");
	binary_tree<std::string> DE("de");
	binary_tree<std::string> FH("fgh");
	binary_tree<std::string> IL("il");
	binary_tree<std::string> MO("mno");
	binary_tree<std::string> PR("pqr");
	binary_tree<std::string> SU("stu");
	binary_tree<std::string> VZ("vz");

	AE.insertR_Child(&AC);
	AE.insertL_Child(&DE);
	FL.insertR_Child(&FH);
	FL.insertL_Child(&IL);
	MR.insertR_Child(&MO);
	MR.insertL_Child(&PR);
	SZ.insertR_Child(&SU);
	SZ.insertL_Child(&VZ);

	std::cout << "Radice: " << SZ.root()->getValue() << std::endl;
	std::cout << "Padre di SZ: " << SZ.parent()->getValue() << std::endl;
	std::cout << "Figlio sinistro di FL: " << FL.rChild()->getValue() << std::endl;
	if (VZ.isaleaf()) std::cout << "VZ e' una foglia" << std::endl;
	AZ.postvisit();
	AZ.eraseR_Child();
	try{
	std::cout << "Figlio destro di AZ: " << AZ.rChild()->getValue() << std::endl;
	}
	catch(null_node){}

	try{
	std::cout << "Figlio destro di AL:" << AL.rChild()->getValue()<< std::endl;
	}
	catch(null_node){}

	AZ.postvisit();
	system("pause");
	return 0;
}


