/*
 * Test_coda.cpp
 *
 *  Created on: 13 nov 2017
 *      Author: Gianni
 */

#include "coda.h"
#include <iostream>
#include <stdlib.h>

int main(){
	class_queue<int> int_queue;

	int_queue.enqueue(3);
	int_queue.enqueue(2);
	int_queue.enqueue(1);

	while(!int_queue.empty()){
		cout << int_queue.read() << "\n";
		int_queue.dequeue();
	}

	system("pause");
	return 0;
}


