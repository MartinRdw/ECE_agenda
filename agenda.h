#ifndef AGENDA_AGENDA_H
#define AGENDA_AGENDA_H

#endif //AGENDA_AGENDA_H

// constants
#define NBMAX_RDV 300
#define LGMAX_LIBEL 50

void afficherMenu1();
void afficherMenu2();
int lireChoix();


typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

typedef struct Schedule
{
    int hour;
    int minute;
} Schedule;

typedef struct Appointment
{
    int date;
    int startSchedule;
    int endSchedule;
    char title[50];
    int remind;
} Appointment;

typedef struct Agenda
{
    char title[50];
    Appointment appointments[NBMAX_RDV];
} Agenda;
