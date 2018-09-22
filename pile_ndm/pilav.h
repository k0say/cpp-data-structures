/*
 * pilav.h
 *
 *  Created on: 13 nov 2017
 *      Author: Gianni
 */

#ifndef PILAV_H_
#define PILAV_H_

#include "nodo_pilav.h"

const int MAXLUNGH=100;

class Pila
  {
    friend void stampaPila(Pila & L);

  public:
    Pila();
    ~Pila();
    void creaPila();
    bool pilaVuota() const;
    tipoelem leggiPila() const;
    void fuoriPila();
    void inPila(tipoelem);
  private:
    Nodo elementi[MAXLUNGH];
    int testa;
  };

#endif /* PILAV_H_ */
