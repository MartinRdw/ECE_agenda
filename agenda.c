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

struct Date lireDate()
{
    struct Date date;

    int day;
    int month;
    int year;

    printf("\nEntrez une date au format JJ/MM/AAAA : ");
    scanf("%d/%d/%d", &day, &month, &year);

    date.day = day;
    date.month = month;
    date.year = year;

    return date;
}

int dateCorrecte(struct Date date)
{
    int daysinmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int legit = 0;

    if(date.year % 400 == 0 || (date.year % 100 != 0 && date.year % 4 == 0))
        daysinmonth[1] = 29;
    if (date.month < 13)
        if(date.day <= daysinmonth[date.month-1])
        {
            legit = 1;
        }

    return legit;
}

void afficherDate(struct Date date)
{
    printf("%d/%d/%d", date.day, date.month, date.year);
}

struct Schedule lireHoraire()
{
    struct Schedule schedule;

    int hour;
    int minute;

    printf("\nEntrez un horaire au format HH:MM : ");
    scanf("%d:%d", &hour, &minute);

    schedule.hour = hour;
    schedule.minute = minute;

    return schedule;
}

int horaireCorrect(struct Schedule schedule)
{
    return !(schedule.hour < 0 || schedule.hour > 23 || schedule.minute < 0|| schedule.minute > 59);
}

void afficherHoraire(struct Schedule schedule)
{
    printf("%d:%d", schedule.hour, schedule.minute);
}

struct Appointment lireRDV()
{
    struct Appointment appointment;
    return appointment;
}

void afficherRDV(struct Appointment appointment)
{

}

int horaireCoherents(struct Appointment)
{
    return 0;
}

int comparerCréneauxRDV(rdv1, rdv2)
{
    return 0;
}
