#include "agenda.c"
#include "menus.c"

int main() {

    int choix;

    afficherMenu1();
    choix = lireChoix(1, 3);

    traiterChoixMenu1(choix);

    return 0;
}