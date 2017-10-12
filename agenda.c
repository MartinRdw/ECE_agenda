#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

void afficherMenu1()
{
    printf("> Menu 1\n\n");
    printf("1- Creer un nouvel agenda\n");
    printf("2- Ouvrir un agenda existant\n");
    printf("3- Quitter\n\n");
}

void afficherMenu2()
{
    printf("> Menu 2\n\n");
    printf("1- Afficher un RDV\n");
    printf("2- Afficher tous les RDV\n");
    printf("3- Modifier un RDV\n");
    printf("4- Ajouter un RDV\n");
    printf("5- Supprimer un RDV\n");
    printf("6- Supprimer tous les RDV\n");
    printf("7- Sauvegarder & fermer l’agenda\n\n");
}

int lireChoix(int minVal, int maxVal)
{
    int choiceMenu = -1;
    do
    {
        printf("Votre choix (entre %d et %d) : ", minVal, maxVal);
        scanf("%d", &choiceMenu);
    }
    while(choiceMenu < minVal || choiceMenu > maxVal);
    printf("\n");
    return choiceMenu;
}

Date lireDate()
{
    int day;
    int month;
    int year;
    printf("\nEntrez une date au format JJ/MM/AAAA : ");
    scanf("%d/%d/%d", &day, &month, &year);
    printf("%d/%d/%d", day, month, year);

    struct Date date;
    date.day = day;
    date.month = month;
    date.year = year;

    return date;
}
