/**
  * @file   :   cadran.cpp
  * @author :   Philippe Cruchet
  * @date   :   24/08/2020
  * @detail :   Assure la gestion d'un Cadran en Mode texte
  *             à partir des séquences d’échappement ANSI
  */
#include "cadran.h"

/**
 * @brief Cadran::Cadran
 * @details : Constructeur de la classe Cadran, initialise et trace le contour du cadran
 * @param _posX     :   Coordonnée en X du coin gauche du cadran
 * @param _posY     :   Coordonnée en Y du coin gauche du cadran
 * @param _hauteur  :   Nombre de lignes d'affichage du cadran
 * @param _largeur  :   Nombre de caractères par ligne
 */
Cadran::Cadran(const int _posX, const int _posY, const int _hauteur, const int _largeur):
    posX(_posX+1),
    posY(_posY+1),
    hauteur(_hauteur),
    largeur(_largeur)
{
    PositionnerCurseur(_posX,_posY);
    cout << '+' <<  setfill('-') << setw(_largeur+1) << '+' << setfill(' ');
    for(int indice = 1 ; indice <= _hauteur ; indice++)
    {
        PositionnerCurseur(_posX + indice,_posY);
        cout << '+' ;
        cout << "\e[0;33;42m";  // Fixe la couleur fond en vert et le texte en jaune
        cout <<  setfill(' ') << setw(_largeur) << ' '  ;
        cout << "\e[0m";        // Remet à zéro les attributs de couleur
        cout << '+' ;
    }
    PositionnerCurseur(posX + _hauteur,_posY);
    cout << '+' <<  setfill('-') << setw(_largeur+1) << '+' << setfill(' ') ;
    cout << "\e[?25l" << flush;         // Fait disparaître le curseur
}

/**
 * @brief Cadran::~Cadran
 * @details : Destructeur de la classe restitue le contexte de l'application
 */
Cadran::~Cadran()
{
    cout << "\e[?25h";          // Refait apparaître le curseur
    cout << "\e[0m";            // Remet à zéro les attributs de couleur
    cout << "\e[2J" << flush;   // Efface l'écran
}

/**
 * @brief Cadran::Afficher
 * @details : Affiche une valeur entière sur 2 caractères à une position donnée dans le cadran
 * @param _valeur   : Entier à afficher
 * @param _position : Position du premier caractère par défaut 0 pour le premier caractère
 */
void Cadran::Afficher(const int _valeur, const int _position, const int _ligne)
{
    PositionnerCurseur(posX + _ligne,posY + _position);
    cout << "\e[0;33;42m";
    cout << setfill('0') << setw(2) << _valeur ;
    cout << "\e[0m" << flush;            // Remet à zéro les attributs de couleur
}

void Cadran::Effacer()
{

    cout << "\e[0;33;42m";
    for(int indice =0; indice < hauteur; indice++)
    {
        PositionnerCurseur(posX+indice,posY);
        cout << setfill(' ') << setw(largeur-1) << " " << endl;
    }


    cout << "\e[0m" << flush;
}

/**
 * @brief Cadran::Afficher
 * @details : Affiche un texte à une position donnée sur l'écran
 * @param _texte    : Texte à afficher dans le cadran
 * @param _position : Position du premier caractère par défaut 0 pour le premier caractère
 */
void Cadran::Afficher(const string _texte, const int _position, const int _ligne)
{
    PositionnerCurseur(posX + _ligne,posY + _position);
    cout << "\e[0;33;42m";
    cout << _texte ;
    cout << "\e[0m" << flush;            // Remet à zéro les attributs de couleur
}
/**
 * @brief Cadran::PositionnerCurseur
 * @details :   Positionne le curseur sur l'écran de l'ordinateur
 * @param _posx :   Coordonnée en X
 * @param _posy :   Coordonnée en Y
 */
void Cadran::PositionnerCurseur(const int _posx, const int _posy)
{
    cout << "\e[" << _posx <<";" << _posy << 'f' ;
}
