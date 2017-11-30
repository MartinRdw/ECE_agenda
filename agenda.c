#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include "agenda.h"
#include "menus.h"
#include "date.h"
#include "horaire.h"
#include "rdv.h"

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

void gererAgenda(struct Agenda *agenda) {

    int choix = -1;
    while (choix != 7) {

        afficherMenu2();
        choix = lireChoix(1, 7);
        traiterChoixMenu2(choix, agenda);
    }

    traiterChoixSauvegarderEtFermer(agenda);

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

void triABulles(struct Agenda *agenda) {
    for (int i = 0; i < agenda->rdvAmount - 1; i++) {
        if (reorganiserDeuxDates(agenda, i + 1, i)) {
            i = 0;
            reorganiserDeuxDates(agenda, i + 1, i);
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

            if (agenda->rdvAmount > 0) {
                afficherRDV(agenda->appointments[lireIdRDV(agenda->rdvAmount) - 1]);
            } else {
                printf("\nL'agenda est vide.");
            }
            break;
        case 2:

            if (agenda->rdvAmount > 0) {
                for (int i = 0; i < agenda->rdvAmount; i++) {
                    afficherRDV(agenda->appointments[i]);
                }
            } else {
                printf("\nL'agenda est vide.");
            }
            break;
        case 3:

            if (agenda->rdvAmount > 0) {
                traiterChoixModifierUnRdv(agenda);
            } else {
                printf("\nL'agenda est vide.");
            }
            break;
        case 4:

            traiterChoixAjouterRDV(agenda);
            break;
        case 5:

            if (agenda->rdvAmount > 0) {
                traiterChoixSupprimerRDV(agenda);
            } else {
                printf("\nL'agenda est vide.");
            }
            break;
        case 6:

            if (agenda->rdvAmount > 0) {
                traiterChoixSupprimerTousLesRDV(agenda);
            } else {
                printf("\nL'agenda est vide.");
            }
            break;
    }
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