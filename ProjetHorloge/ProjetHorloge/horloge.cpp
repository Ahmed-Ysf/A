#include ".h"

void Horloge :: ChangerMode()
{
    mode = (++mode) % nbModes;
}

TOUCHES_CLAVIER Horloge::Controler(TOUCHES_CLAVIER _numTouche)
{
    TOUCHES_CLAVIER laTouche = leClavier ->ScruterClavier();
    if(laTouche == MODE)ChangerMode();
    switch(mode)
    {
    case AUCUN_REGLAGE
    }
}
