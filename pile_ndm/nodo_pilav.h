/*
 * nodo_pilav.h
 *
 *  Created on: 13 nov 2017
 *      Author: Gianni
 */

#ifndef NODO_PILAV_H_
#define NODO_PILAV_H_

#include <iostream>

typedef int tipoelem;

class Nodo
  {
  public:

    Nodo();
    Nodo(tipoelem);
    ~Nodo();

    void setElemento(tipoelem);
    tipoelem getElemento() const;
    bool operator ==(Nodo &);

  private:
    tipoelem elemento;
  };

std::ostream & operator<<(std::ostream & out, const Nodo & nodo);



#endif /* NODO_PILAV_H_ */
