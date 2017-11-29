#ifndef MENUS_MENUS_H
#define MENUS_MENUS_H

#endif //MENUS_MENUS_H

void traiterChoixCreerAgenda();

void traiterChoixOuvrirAgenda();

void traiterChoixModifierUnRdv(struct Agenda *);

void traiterChoixAjouterRDV(struct Agenda *);

void traiterChoixSupprimerRDV(struct Agenda *);

void traiterChoixSupprimerTousLesRDV(struct Agenda *);

void traiterChoixSauvegarderEtFermer(struct Agenda *);

void afficherMenu1();

void afficherMenu2();

int lireChoix(int, int);