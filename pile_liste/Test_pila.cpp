/*
 * Test_pila.cpp
 *
 *  Created on: 13 nov 2017
 *      Author: Gianni
 */

#include "pila.h"
#include <iostream>
#include <stdlib.h>

int main (){
	class_pila<char> pila_char;

	pila_char.push('a');
	pila_char.push('b');
	pila_char.push('c');

	while(!pila_char.empty()){
		cout << pila_char.read() << "\n";
		pila_char.pop();
	}

	system ("pause");
	return 0;
}
