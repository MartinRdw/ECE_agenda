#include <stdio.h>
#include <stdlib.h>
#include "agenda.c"

int main() {

    int choiceMenu = 0;

    do
    {
        choiceMenu = displayMenu();
    } while (choiceMenu < 1 || choiceMenu > 3);

    printf("%d", choiceMenu);

    switch (choiceMenu)
    {
        case 1:
            //1
            break;
        case 2:
            //2
            break;
        case 3:
            return 0;
        default:
            return 0;
    }

    return 0;
}