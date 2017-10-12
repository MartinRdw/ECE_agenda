#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int displayMenu() {
    int choiceMenu;

    printf("=== Menu ===\n\n");
    printf("1- Créer un nouvel agenda\n");
    printf("2- Ouvrir un agenda existant\n");
    printf("3- Quitter\n");
    printf("\nVotre choix ? ");
    scanf("%d", &choiceMenu);

    printf("\n");

    return choiceMenu;
}