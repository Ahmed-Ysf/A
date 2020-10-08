#include <iostream>
#include <unistd.h>
#include "cadran.h"
using namespace std;

int main()
{
/*
    Cadran leCadran(1,1);

    for(int indice = 0; indice < 11; indice++)
    {
        leCadran.Afficher(indice, 3);
        sleep(1);
        if(indice == 10)
        {
            leCadran.Afficher("Fin", 1);
            char touche;
            cin >> touche;
        }

    }
*/

    Cadran autreCadran(10, 10, 2, 20);

    for(int indice = 0; indice < 11; indice++)
    {
        autreCadran.Afficher(indice, 3, 1);
        sleep(1);

        for(int indice2 = 10; indice2 > -1; indice2--)
        {
            autreCadran.Afficher(indice2, 5, 1);
            sleep(1);
        }

        if(indice == 10)
        {
            autreCadran.Afficher("Fin", 1, 1);
            sleep(1);
        }

    }

    autreCadran.Effacer();
    char touche;
    cin >> touche;

    return 0;
}
