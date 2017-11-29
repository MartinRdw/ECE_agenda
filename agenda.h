#ifndef AGENDA_AGENDA_H
#define AGENDA_AGENDA_H

#endif //AGENDA_AGENDA_H

// constants
#define NBMAX_RDV 300
#define LGMAX_LIBEL 50

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

typedef struct Schedule {
    int hour;
    int minute;
} Schedule;

typedef struct Appointment {
    Date date;
    Schedule startSchedule;
    Schedule endSchedule;
    char title[50];
    int remind;
} Appointment;

typedef struct Agenda {
    char title[50];
    struct Appointment appointments[NBMAX_RDV];
    int rdvAmount;
} Agenda;

char *lireNomFichierAgenda();

char *lireLibelleRDV();

void gererAgenda(struct Agenda *);

void afficherTousLesAppointments(struct Agenda *);

int reorganiserDeuxDates(struct Agenda *, int, int);

void triABulles(struct Agenda *);

void traiterChoixMenu1(int);

void traiterChoixMenu2(int, struct Agenda *);

int lireIdRDV(int);

void reorganiserRDV(struct Agenda *, int);
