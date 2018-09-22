/*
 * test_dictionary.cpp
 *
 *  Created on: 04 gen 2018
 *      Author: Gianni
 */

#include "dictionary.h"
#include <stdlib.h>

int main(){
using namespace std;

	dictionary <string> rubrica(3);

	rubrica.insert("Gianni", "3466413150");
	rubrica.insert("fabiola", "3457772948");
	rubrica.insert("antonella", "3387726830");

	string number = rubrica.lookup("Gianni");
	cout << number << endl;
	rubrica.remove("Gianni");
	rubrica.insert("Gianni", "0000000000");
	number = rubrica.lookup("Gianni");
	cout << number << endl;
	try{
		rubrica.lookup("ciccio");
	}
	catch(exception &err){
		cerr << err.what() << endl;
	}
	rubrica.insert("Gianni", "1111111111");
	number = rubrica.lookup("Gianni");
	cout << number << endl;

	system("pause");
	return 0;
}


