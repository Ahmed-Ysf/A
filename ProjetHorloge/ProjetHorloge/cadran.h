/**
  * @file   :   cadran.h
  * @author :   Ahmed YOUSFI
  * @date   :   24/08/2020
  * @detail :   Assure la gestion d'un cadran en mode texte
  *             à partir des séquences d’échappement ANSI
  */

#ifndef CADRAN_H
#define CADRAN_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Cadran
{
public:
    Cadran(const int _posX=1,const int _posY=1,const int _hauteur=1,const int _largeur=7);
    ~Cadran();
    void Afficher(const string _texte, const int _position=0, const int _ligne=0);
    void Afficher(const int _valeur, const int _position=0, const int _ligne=0);
    void Effacer();
private:
    void PositionnerCurseur(const int _posx, const int _posy);
    int posX;   /// coordonnée en X du premier caractère dans le cadran
    int posY;   /// coordonnée en Y du premier caractère dans le cadran
    int hauteur;    /// nombre de lignes du cadran
    int largeur;    /// nombre de caractères par ligne
};

#endif // CADRAN_H
