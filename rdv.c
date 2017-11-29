#include <stdio.h>
#include "agenda.h"
#include "date.h"
#include "horaire.h"
#include "rdv.h"

int horaireCoherents(struct Appointment appointment) {
    return 0;
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