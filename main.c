#include "agenda.c"

int main() {

    int choix;

    afficherMenu1();
    choix = lireChoix(1, 3);

    switch (choix) {
        case 1:
            traiterChoixCreerAgenda();
            break;
        case 2:
            traiterChoixOuvrirAgenda();
            break;
        case 3:
            printf("Application fermee.");
            return 0;
    }

    afficherMenu2();
    choix = lireChoix(1, 7);

    switch (choix) {
        case 1:
            printf("TODO : Afficher un RDV");
            break;
        case 2:
            printf("TODO : Afficher tous les RDV");
            break;
        case 3:
            printf("TODO : Modifier un RDV");
            break;
        case 4:
            printf("TODO : Ajouter un RDV");
            break;
        case 5:
            printf("TODO : Supprimer un RDV");
            break;
        case 6:
            printf("TODO : Supprimer tous les RDV");
            break;
        case 7:
            printf("TODO : Sauvegarder & fermer l’agenda");
            printf("Application fermee.");
            return 0;

    }

    return 0;
}
