/*
 * exceptions.h
 *
 *  Created on: 02 gen 2018
 *      Author: Gianni
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <stdexcept>

struct null_node:
public
	std::invalid_argument {
    	null_node(): invalid_argument("Il nodo non esiste.") {};
	};

#endif /* EXCEPTIONS_H_ */
