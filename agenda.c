#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "agenda.h"

void afficherMenu1() {
    printf("> Menu 1\n\n");
    printf("1- Creer un nouvel agenda\n");
    printf("2- Ouvrir un agenda existant\n");
    printf("3- Quitter\n\n");
}

void afficherMenu2() {
    printf("> Menu 2\n\n");
    printf("1- Afficher un RDV\n");
    printf("2- Afficher tous les RDV\n");
    printf("3- Modifier un RDV\n");
    printf("4- Ajouter un RDV\n");
    printf("5- Supprimer un RDV\n");
    printf("6- Supprimer tous les RDV\n");
    printf("7- Sauvegarder & fermer l’agenda\n\n");
}

int lireChoix(int minVal, int maxVal) {
    int choiceMenu = -1;
    do {
        printf("Votre choix (entre %d et %d) : ", minVal, maxVal);
        scanf("%d", &choiceMenu);
    } while (choiceMenu < minVal || choiceMenu > maxVal);
    printf("\n");
    return choiceMenu;
}

struct Date lireDate() {
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

int dateCorrecte(struct Date date) {
    int daysinmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int legit = 0;

    if (date.year % 400 == 0 || (date.year % 100 != 0 && date.year % 4 == 0))
        daysinmonth[1] = 29;
    if (date.month < 13)
        if (date.day <= daysinmonth[date.month - 1]) {
            legit = 1;
        }

    return legit;
}

void afficherDate(struct Date date) {
    printf("%02d/%02d/%02d", date.day, date.month, date.year);
}

struct Schedule lireHoraire() {
    struct Schedule schedule;

    int hour;
    int minute;

    printf("\nEntrez un horaire au format HH:MM : ");
    scanf("%d:%d", &hour, &minute);

    schedule.hour = hour;
    schedule.minute = minute;

    return schedule;
}

int horaireCorrect(struct Schedule schedule) {
    return !(schedule.hour < 0 || schedule.hour > 23 || schedule.minute < 0 || schedule.minute > 59);
}

void afficherHoraire(struct Schedule schedule) {
    printf("%02d:%02d", schedule.hour, schedule.minute);
}

struct Appointment lireRDV() {
    struct Appointment appointment;
    return appointment;
}

void afficherRDV(struct Appointment appointment) {

}

int horaireCoherents(struct Appointment appointment) {
    return 0;
}

int comparerCreneauxRDV(struct Appointment rdv1, struct Appointment rdv2) {
    return 0;
}

void traiterChoixCreerAgenda() {
    // reads new agenda s name and creates new empty file in created_agenda/
    char agendaName[256];
    /*do
    {
        printf("Nom du nouvel agenda : ");
        scanf("%s", agendaName);
        printf("%s", agendaName);
    }
    while();*/
    printf("Nom du nouvel agenda : ");
    scanf("%s", agendaName);
    printf("\n");


    FILE *fp;

    char pathToAgenda[256];
    strcpy(pathToAgenda, "./created_agenda/");
    strcat(pathToAgenda, agendaName);
    strcat(pathToAgenda, ".txt");
    fp = fopen(pathToAgenda, "w+");
    fclose(fp);
}

void traiterChoixOuvrirAgenda() {

    DIR *d;
    struct dirent *dir;
    d = opendir("./created_agenda");
    if (d) {

        printf("Liste des agendas : ");

        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        printf("\n");

        closedir(d);
    }

    // asking for agenda name
    char agendaName[256];
    printf("Nom du fichier agenda : ");
    scanf("%s", agendaName);
    printf("\n");

    // prints agenda content
    FILE *fp;
    char *line = NULL;
    char *split;
    size_t len = 0;
    ssize_t read;

    char buff[255];

    char pathToAgenda[256];
    strcpy(pathToAgenda, "./created_agenda/");
    strcat(pathToAgenda, agendaName);
    strcat(pathToAgenda, ".txt");
    fp = fopen(pathToAgenda, "r");

    struct Appointment appointments[NBMAX_RDV];
    int i = 0;
    //display line by line
    while ((read = getline(&line, &len, fp)) != -1) {

        // day
        split = strtok(line, ",");
        appointments[i].date.day = strtol(split, (char **) NULL, 10);
        printf("%d ", appointments[i].date.day);

        // month
        split = strtok(NULL, ",");
        appointments[i].date.month = strtol(split, (char **) NULL, 10);
        printf("%d ", appointments[i].date.month);

        // year
        split = strtok(NULL, ",");
        appointments[i].date.year = strtol(split, (char **) NULL, 10);
        printf("%d ", appointments[i].date.year);

        // start hour
        split = strtok(NULL, ",");
        appointments[i].startSchedule.hour = strtol(split, (char **) NULL, 10);
        printf("%d ", appointments[i].startSchedule.hour);

        // start minute
        split = strtok(NULL, ",");
        appointments[i].startSchedule.minute = strtol(split, (char **) NULL, 10);
        printf("%d ", appointments[i].startSchedule.minute);

        // end hour
        split = strtok(NULL, ",");
        appointments[i].endSchedule.hour = strtol(split, (char **) NULL, 10);
        printf("%d ", appointments[i].endSchedule.hour);

        // end minute
        split = strtok(NULL, ",");
        appointments[i].endSchedule.minute = strtol(split, (char **) NULL, 10);
        printf("%d ", appointments[i].endSchedule.minute);

        // title
        split = strtok(NULL, ",");
        strcpy(appointments[i].title, split);
        printf("%s", appointments[i].title);

        i++;
    }

    fclose(fp);
}

struct Date convertStringToDate(char dateString[]) {

    struct Date date;

    char *split;
    split = strtok(dateString, "/");
    date.day = strtol(split, (char **) NULL, 10);

    split = strtok(NULL, "/");
    date.month = strtol(split, (char **) NULL, 10);

    split = strtok(NULL, "/");
    date.year = strtol(split, (char **) NULL, 10);

    printf("%02d/%02d/%02d", date.day, date.month, date.year);

    return date;
}

struct Schedule convertStringToSchedule(char scheduleString[]) {

    struct Schedule schedule;

    char *split;
    split = strtok(scheduleString, ":");
    schedule.hour = strtol(split, (char **) NULL, 10);

    split = strtok(NULL, ":");
    schedule.minute = strtol(split, (char **) NULL, 10);
    printf("%02d:%02d", schedule.hour, schedule.minute);
    return schedule;
}

