#include "agenda.c"

int main() {

    if (2) {
        printf("");
    }

    int choix;

    afficherMenu1();
    choix = lireChoix(1, 3);

    traiterChoixMenu1(choix);

    return 0;
}