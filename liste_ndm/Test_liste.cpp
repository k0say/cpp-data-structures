/*
 * Test_liste.cpp
 *
 *  Created on: 09 nov 2017
 *      Author: Gianni
 */

#include "linked_list.h"
#include <iostream>
#include <stdlib.h>

int main(){
	linked_list<int> int_list;
	if (int_list.empty())
		cout << "lista vuota" << "\n";
	int_list.insert(10, int_list.begin());
	int_list.write(12, int_list.begin());
	cout << int_list.read(int_list.begin()) << "\n";
	cout << int_list.read(int_list.last()) << "\n";
	if (int_list.end(int_list.previous(int_list.begin())))
		cout << "yee" << "\n";
	cout << int_list << "\n";
	linked_list<int> int_list2(int_list);
	cout << int_list2;
	if (int_list == int_list2)
		cout << "weila" << "\n";
	int_list2.write(8, int_list2.begin());
	int_list = int_list2;
	cout << int_list.read(int_list.begin()) << "\n";
	system("pause");
	return 0;
}


