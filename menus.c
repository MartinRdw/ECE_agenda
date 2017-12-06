#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include "menus.h"
#include "rdv.h"
#include "colors.h"
#include "colors.c"

void traiterChoixCreerAgenda() {

    char agendaName[256];
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

void traiterChoixAfficherUnRDV(struct Agenda *agenda) {

    // print libelles
    afficherTousLesAppointments(agenda);
    printf("Numero du rendez-vous : ");
    afficherRDV(agenda->appointments[lireIdRDV(agenda->rdvAmount) - 1]);
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

void traiterChoixAjouterRDV(struct Agenda *agenda) {

    agenda->appointments[agenda->rdvAmount] = lireRDV();
    agenda->rdvAmount++;

    afficherRDV(agenda->appointments[agenda->rdvAmount - 1]);
    printf("Rendez-vous '%s' enregistré", agenda->appointments[agenda->rdvAmount - 1].title);
}

void traiterChoixSupprimerRDV(struct Agenda *agenda) {

    afficherTousLesAppointments(agenda);

    printf("Identifiant du rendez-vous a supprimer : ");

    int rdvToDelete = lireIdRDV(agenda->rdvAmount);

    supprimerRDV(rdvToDelete - 1, agenda);

    printf("Rendez-vous supprimé");
}

void traiterChoixSupprimerTousLesRDV(struct Agenda *agenda) {

    printf("Etes-vous sûr de vouloir supprimer tous les rendez-vous ? (1 = oui/0 = non) : ");

    int confirm = -1;
    scanf("%d", &confirm);
    while (confirm != 1 && confirm != 0) {
        printf("\nTapez 1 pour confirmer, 0 sinon : ");
        scanf("%d", &confirm);
    }

    if (confirm == 1) {

        int nbRdv = agenda->rdvAmount;
        for (int i = 0; i < nbRdv; i++) {
            supprimerRDV(0, agenda);
        }
        printf("\nTous les rendez-vous ont été effacés.");
    }
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

void afficherMenu1() {
    printf("\n");
    printfColour("> Menu 1", "cyan", "green");
    printf("\n\n1 - Creer un nouvel agenda\n");
    printf("2 - Ouvrir un agenda existant\n");
    printf("3 - Quitter\n\n");
}

void afficherMenu2() {
    printf("\n> Menu 2\n\n");
    printf("1 - Afficher un RDV\n");
    printf("2 - Afficher tous les RDV\n");
    printf("3 - Modifier un RDV\n");
    printf("4 - Ajouter un RDV\n");
    printf("5 - Supprimer un RDV\n");
    printf("6 - Supprimer tous les RDV\n");
    printf("7 - Sauvegarder & fermer l’agenda\n\n");
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