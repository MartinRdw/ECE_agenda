#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include  <string.h>
#include  <time.h>
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
        printf("Choisissez une option (entre %d et %d) : ", minVal, maxVal);
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

    scanf("%02d/%02d/%04d", &day, &month, &year);

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
    printf("%02d/%02d/%04d", date.day, date.month, date.year);
}

struct Schedule lireHoraire() {
    struct Schedule schedule;

    int hour;
    int minute;

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

    // titre
    printf("\nPlanification d'un nouveau rendez-vous\nTitre : ");
    scanf("%s", appointment.title);

    // date
    printf("\nDate (format JJ/MM/AAAA) : ");
    appointment.date = lireDate();

    // horaire debut
    printf("\nHoraire de debut (format HH:MM) : ");
    appointment.startSchedule = lireHoraire();

    // horaire fin
    printf("\nHoraire de fin (format HH:MM) : ");
    appointment.endSchedule = lireHoraire();

    return appointment;
}

void afficherRDV(struct Appointment appointment) {

    printf("\nRDV %02d/%02d/%04d %02d:%02d - %02d:%02d\n\t%s\n\n", appointment.date.day,
           appointment.date.month,
           appointment.date.year, appointment.startSchedule.hour,
           appointment.startSchedule.minute,
           appointment.endSchedule.hour, appointment.endSchedule.minute,
           appointment.title);
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

char *lireNomFichierAgenda() {

    DIR *d;
    struct dirent *dir;
    d = opendir("./created_agenda");
    if (d) {

        printf("Liste des agendas : ");

        int i = 0;
        while ((dir = readdir(d)) != NULL) {
            if (i > 1)
                printf("\n%s", dir->d_name);
            i++;
        }
        printf("\n\n");

        closedir(d);
    }

    char agendaName[256];
    printf("Nom du fichier agenda : ");
    scanf("%s", agendaName);
    printf("\n");

    return agendaName;
}

char *lireLibelleRDV() {

    char rdvName[256];
    scanf("%s", rdvName);
    printf("\n");

    return rdvName;
}

void traiterChoixOuvrirAgenda() {

    struct Agenda agenda;

    char *agendaName = lireNomFichierAgenda();

    // trying to open agenda with agendaName
    FILE *fp;
    char *line = NULL;
    char *split;
    size_t len = 0;
    ssize_t read;
    char pathToAgenda[256];
    strcpy(pathToAgenda, "./created_agenda/");
    strcat(pathToAgenda, agendaName);
    strcat(pathToAgenda, ".txt");
    fp = fopen(pathToAgenda, "r");

    // if file doesnt exist
    if (fp == NULL) {

        printf("L'agenda n'existe pas.\n");

    } else {

        int i = 0;
        while ((read = getline(&line, &len, fp)) != -1) {

            // day
            split = strtok(line, ",");
            agenda.appointments[i].date.day = strtol(split, (char **) NULL, 10);

            // month
            split = strtok(NULL, ",");
            agenda.appointments[i].date.month = strtol(split, (char **) NULL, 10);

            // year
            split = strtok(NULL, ",");
            agenda.appointments[i].date.year = strtol(split, (char **) NULL, 10);

            // start hour
            split = strtok(NULL, ",");
            agenda.appointments[i].startSchedule.hour = strtol(split, (char **) NULL, 10);

            // start minute
            split = strtok(NULL, ",");
            agenda.appointments[i].startSchedule.minute = strtol(split, (char **) NULL, 10);

            // end hour
            split = strtok(NULL, ",");
            agenda.appointments[i].endSchedule.hour = strtol(split, (char **) NULL, 10);

            // end minute
            split = strtok(NULL, ",");
            agenda.appointments[i].endSchedule.minute = strtol(split, (char **) NULL, 10);

            // title
            split = strtok(NULL, ",");
            strcpy(agenda.appointments[i].title, strtok(split, "\n"));

            i++;
        }

        agenda.rdvAmount = i;
        strcpy(agenda.title, pathToAgenda);

        printf("Agenda charge\n");

        gererAgenda(&agenda);
    }

    fclose(fp);
}

void gererAgenda(struct Agenda *agenda) {

    int choix = -1;
    while (choix != 7) {

        afficherMenu2();
        choix = lireChoix(1, 7);
        traiterChoixMenu2(choix, agenda);
    }

    traiterChoixSauvegarderEtFermer(agenda);

}

void traiterChoixSauvegarderEtFermer(struct Agenda *agenda) {

    triABulles(agenda);

    FILE *f = fopen(agenda->title, "w");
    for (int i = 0; i < agenda->rdvAmount; i++) {
        fprintf(f, "%02d,%02d,%04d,%02d,%02d,%02d,%02d,%s\n",
                agenda->appointments[i].date.day,
                agenda->appointments[i].date.month,
                agenda->appointments[i].date.year,
                agenda->appointments[i].startSchedule.hour,
                agenda->appointments[i].startSchedule.minute,
                agenda->appointments[i].endSchedule.hour,
                agenda->appointments[i].endSchedule.minute,
                agenda->appointments[i].title);
    }
    fclose(f);
}

void afficherTousLesAppointments(struct Agenda *agenda) {

    printf("Liste des rendez-vous\n");
    for (int i = 0; i < agenda->rdvAmount; i++) {
        printf("%d - %s\n", i + 1, agenda->appointments[i].title);
    }
}

int reorganiserDeuxDates(struct Agenda *agenda, int indiceEvent1, int indiceEvent2) {

    //return 1 si inversion des dates, sinon 0

    struct Appointment appointment1 = agenda->appointments[indiceEvent1];
    struct Appointment appointment2 = agenda->appointments[indiceEvent2];

    int returnCode = 0;

    if (appointment1.date.year > appointment2.date.year) {
    } else if (appointment1.date.year < appointment2.date.year) {
        returnCode = 1;
    } else {
        if (appointment1.date.month > appointment2.date.month) {
        } else if (appointment1.date.month < appointment2.date.month) {
            returnCode = 1;
        } else {
            if (appointment1.date.day > appointment2.date.day) {
            } else if (appointment1.date.day < appointment2.date.day) {
                returnCode = 1;
            } else {
                if (appointment1.startSchedule.hour > appointment2.startSchedule.hour) {
                } else if (appointment1.startSchedule.hour < appointment2.startSchedule.hour) {
                    returnCode = 1;
                } else {
                    if (appointment1.startSchedule.minute > appointment2.startSchedule.minute) {
                    } else {
                        returnCode = 1;
                    }
                }
            }
        }
    }

    if (returnCode == 1) {
        agenda->appointments[indiceEvent1] = appointment2;
        agenda->appointments[indiceEvent2] = appointment1;
    }

    return returnCode;
}

void triABulles (struct Agenda *agenda) {
    for (int i = 0; i < agenda->rdvAmount - 1 ; i++) {
        if (reorganiserDeuxDates(agenda, i+1, i)) {
            i = 0;
            reorganiserDeuxDates(agenda, i+1, i);
        }
    }
}

void traiterChoixMenu1(int choix) {

    switch (choix) {

        case 1:

            traiterChoixCreerAgenda();
            break;
        case 2:

            traiterChoixOuvrirAgenda();
            break;
        case 3:

            printf("Application fermee.");
    }
}

void traiterChoixMenu2(int choix, struct Agenda *agenda) {


    switch (choix) {

        case 1:

            // print libelles
            afficherTousLesAppointments(agenda);

            char rdvName[LGMAX_LIBEL];
            afficherRDV(agenda->appointments[lireIdRDV(agenda->rdvAmount) - 1]);

            break;
        case 2:

            for (int i = 0; i < agenda->rdvAmount; i++) {
                afficherRDV(agenda->appointments[i]);
            }
            break;
        case 3:

            traiterChoixModifierUnRdv(agenda);
            break;
        case 4:

            traiterChoixAjouterRDV(agenda);
            break;
        case 5:

            traiterChoixSupprimerRDV(agenda);
            break;
        case 6:

            traiterChoixSupprimerTousLesRDV(agenda);
            break;
    }
}

void traiterChoixAjouterRDV(struct Agenda *agenda) {

    agenda->appointments[agenda->rdvAmount] = lireRDV();
    agenda->rdvAmount++;
    printf("RDV sauvegarde\n\nTEST ENREGISTREMENT RDV : \n\n");
    afficherRDV(agenda->appointments[agenda->rdvAmount]);
}

void traiterChoixSupprimerTousLesRDV(struct Agenda *agenda) {

    printf("Etes-vous sûr de vouloir supprimer tous les rendez-vous ? (o/n) : ");

    char confirm[4];
    scanf("%s", confirm);
    while (strcmp(confirm, "o") != 0 && strcmp(confirm, "n") != 0) {
        printf("\nTapez 'o' pour confirmer, 'n' sinon : ");
        scanf("%s", confirm);
    }

    if (strcmp(confirm, "o") == 0) {

        int nbRdv = agenda->rdvAmount;
        for (int i = 0; i < nbRdv; i++) {
            supprimerRDV(0, agenda);
        }
        printf("\nTous les rendez-vous ont été effacés.");
    }
}

void traiterChoixSupprimerRDV(struct Agenda *agenda) {

    afficherTousLesAppointments(agenda);

    printf("Identifiant du rendez-vous a supprimer : ");

    int rdvToDelete = lireIdRDV(agenda->rdvAmount);

    supprimerRDV(rdvToDelete - 1, agenda);
}

int supprimerRDV(int rdvId, struct Agenda *agenda) {

    // si l'id du rendez vous est compris dans le tableau
    if (agenda->rdvAmount > rdvId) {

        strcpy(agenda->appointments[rdvId].title, "");
        agenda->appointments[rdvId].date.day = 0;
        agenda->appointments[rdvId].date.month = 0;
        agenda->appointments[rdvId].date.year = 0;
        agenda->appointments[rdvId].startSchedule.hour = 0;
        agenda->appointments[rdvId].startSchedule.minute = 0;
        agenda->appointments[rdvId].endSchedule.hour = 0;
        agenda->appointments[rdvId].endSchedule.minute = 0;
        agenda->rdvAmount--;

        // decalage de tous les rdv vers la gauche
        reorganiserRDV(agenda, rdvId);

        return 1;
    } else
        return 0;
}

int lireIdRDV(int rdvIdMax) {

    int rdvId = -1;
    printf("Numero du rendez-vous : ");
    scanf("%d", &rdvId);
    while (rdvId < 1 || rdvId > rdvIdMax) {

        printf("\nIdentifiant invalide, entrez un nombre compris entre 1 et %d : ", rdvIdMax);
        scanf("%d", &rdvId);
    }
    return rdvId;
}

void reorganiserRDV(struct Agenda *agenda, int rdvId) {

    for (int i = rdvId + 1; i < agenda->rdvAmount; i++) {

        agenda->appointments[i - 1] = agenda->appointments[i];
    }
}

void traiterChoixModifierUnRdv(struct Agenda *agenda) {

    afficherTousLesAppointments(agenda);

    printf("\nNuméro du rendez-vous à modifier : ");
    int idRDVToEdit = lireIdRDV(agenda->rdvAmount) - 1;

    printf("\nModification du rendez-vous '%s' :\n1 - Modifier le libellé\n2 - Modifier la date\n3 - Modifier l'heure de début\n4 - Modifier l'heure de fin",
           agenda->appointments[idRDVToEdit].title);
    int choixEdit = lireChoix(1, 4);
    switch (choixEdit) {

        // modif libelle
        case 1:

            printf("\nSaisir le nouveau libellé : ");
            strcpy(agenda->appointments[idRDVToEdit].title, lireLibelleRDV());

            break;

            // modif date
        case 2:

            printf("\nSaisir la nouvelle date (JJ/MM/AAAA) : ");
            agenda->appointments[idRDVToEdit].date = lireDate();

            break;

            // modif h debut
        case 3:

            printf("\nSaisir le nouvel horaire de début : ");
            agenda->appointments[idRDVToEdit].startSchedule = lireHoraire();

            break;

            // modif h fin
        case 4:

            printf("\nSaisir le nouvel horaire de fin : ");
            agenda->appointments[idRDVToEdit].endSchedule = lireHoraire();

            break;
    }
}