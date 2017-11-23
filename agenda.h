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

void afficherMenu1();

void afficherMenu2();

int lireChoix(int, int);

struct Date lireDate();

int dateCorrecte(struct Date);

void afficherDate(struct Date);

struct Schedule lireHoraire();

int horaireCorrect(struct Schedule);

void afficherHoraire(struct Schedule);

struct Appointment lireRDV();

void afficherRDV(struct Appointment);

int horaireCoherents(struct Appointment);

int comparerCreneauxRDV(struct Appointment, struct Appointment);

void traiterChoixCreerAgenda();

char *lireNomFichierAgenda();

char *lireLibelleRDV();

void traiterChoixOuvrirAgenda();

void gererAgenda(struct Agenda *);

void traiterChoixSauvegarderEtFermer(struct Agenda *);

void afficherTousLesAppointments(struct Agenda *);

int reorganiserDeuxDates (struct Agenda *, int, int);

void triABulles (struct Agenda *);

void traiterChoixMenu1(int);

void traiterChoixMenu2(int, struct Agenda *);

void traiterChoixAjouterRDV(struct Agenda *);

void traiterChoixSupprimerRDV(struct Agenda *);

int lireIdRDV(int rdvIdMax);

void reorganiserRDV(struct Agenda *agenda, int rdvId);