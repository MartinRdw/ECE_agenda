#ifndef AGENDA_AGENDA_H
#define AGENDA_AGENDA_H

#endif //AGENDA_AGENDA_H

int lenghtTitleAppointment = 0;

int displayMenu();

struct Date {
    int day;
    int month;
    int year;
};

struct Schedule {
    int hour;
    int minute;
};

struct Appointment {
    int date;
    int startSchedule;
    int endSchedule;
    char title[lenghtTitleAppointment];
    int remind = 0;
};