#include <stdio.h>
#include "agenda.h"

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

struct Date lireDate() {

    struct Date date;

    int day;
    int month;
    int year;

    do {

        scanf("%02d/%02d/%04d", &day, &month, &year);

        date.day = day;
        date.month = month;
        date.year = year;

    } while (dateCorrecte(date) == 0);

    return date;
}

void afficherDate(struct Date date) {
    printf("%02d/%02d/%04d", date.day, date.month, date.year);
}