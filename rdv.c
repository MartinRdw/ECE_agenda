#include <stdio.h>
#include <string.h>
#include "agenda.h"
#include "date.h"
#include "horaire.h"
#include "rdv.h"

int horaireCoherents(struct Appointment appointment) {

    return (appointment.startSchedule.hour < appointment.endSchedule.hour) ||
           (appointment.startSchedule.hour == appointment.endSchedule.hour &&
            appointment.startSchedule.minute <= appointment.endSchedule.minute);
}

struct Appointment lireRDV() {

    struct Appointment appointment;

    // titre
    printf("\nPlanification d'un nouveau rendez-vous\nTitre : ");
    strcpy(appointment.title, lireLibelleRDV());

    // date
    printf("\nDate (format JJ/MM/AAAA) : ");
    appointment.date = lireDate();

    do {

        // horaire debut
        printf("\nHoraire de debut (format HH:MM) : ");
        appointment.startSchedule = lireHoraire();

        // horaire fin
        printf("\nHoraire de fin (format HH:MM) : ");
        appointment.endSchedule = lireHoraire();

    } while (!horaireCoherents(appointment));

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