#include <stdio.h>
#include "../headers/agenda.h"

int horaireCorrect(struct Schedule schedule) {
    return !(schedule.hour < 0 || schedule.hour > 23 || schedule.minute < 0 || schedule.minute > 59);
}

struct Schedule lireHoraire() {
    struct Schedule schedule;

    int hour;
    int minute;

    do {

        scanf("%d:%d", &hour, &minute);

        schedule.hour = hour;
        schedule.minute = minute;

    } while (!horaireCorrect(schedule));

    return schedule;
}

void afficherHoraire(struct Schedule schedule) {
    printf("%02d:%02d", schedule.hour, schedule.minute);
}