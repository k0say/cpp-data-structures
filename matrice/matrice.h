/*
 * matrice.h
 *
 *  Created on: 27 ott 2017
 *      Author: Gianni
 */

#ifndef MATRICE_H_
#define MATRICE_H_

typedef int tipoEl;

class matrice {
  public:
    matrice(int, int); /* costruttore */
    matrice(const matrice&); /*costruttore di copia*/
    ~matrice(); /*distruttore*/
    tipoEl leggimatrice(int, int);
    void scrivimatrice(int, int, tipoEl);
    void prodottoScalare(double);
    matrice trasposta();
    matrice prodotto(const matrice&);
    matrice& operator= (const matrice&);
    bool operator== (const matrice&);
  private:
    int righe;
    int colonne;
    tipoEl **elementi;
};


#endif /* MATRICE_H_ */
