#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_GREY   "\x1b[37m"

#define ANSI_BACKGROUND_RED     "\x1b[41m"
#define ANSI_BACKGROUND_GREEN   "\x1b[42m"
#define ANSI_BACKGROUND_YELLOW  "\x1b[43m"
#define ANSI_BACKGROUND_BLUE    "\x1b[44m"
#define ANSI_BACKGROUND_MAGENTA "\x1b[45m"
#define ANSI_BACKGROUND_CYAN    "\x1b[46m"
#define ANSI_BACKGROUND_GREY   "\x1b[47m"

#define ANSI_COLORS_RESET   "\x1b[0m"


void printfColour(char *str, char *textColour, char *backgroundColor) {

    // text
    if (strcmp(textColour, "red") == 0) {
        printf(ANSI_COLOR_RED);
    } else if (strcmp(textColour, "green") == 0) {
        printf(ANSI_COLOR_GREEN);
    } else if (strcmp(textColour, "yellow") == 0) {
        printf(ANSI_COLOR_YELLOW);
    } else if (strcmp(textColour, "blue") == 0) {
        printf(ANSI_COLOR_BLUE);
    } else if (strcmp(textColour, "magenta") == 0) {
        printf(ANSI_COLOR_MAGENTA);
    } else if (strcmp(textColour, "cyan") == 0) {
        printf(ANSI_COLOR_CYAN);
    } else if (strcmp(textColour, "grey") == 0) {
        printf(ANSI_COLOR_GREY);
    }

    // background
    if (strcmp(backgroundColor, "red") == 0) {
        printf(ANSI_BACKGROUND_RED);
    } else if (strcmp(backgroundColor, "green") == 0) {
        printf(ANSI_BACKGROUND_GREEN);
    } else if (strcmp(backgroundColor, "yellow") == 0) {
        printf(ANSI_BACKGROUND_YELLOW);
    } else if (strcmp(backgroundColor, "blue") == 0) {
        printf(ANSI_BACKGROUND_BLUE);
    } else if (strcmp(backgroundColor, "magenta") == 0) {
        printf(ANSI_BACKGROUND_MAGENTA);
    } else if (strcmp(backgroundColor, "cyan") == 0) {
        printf(ANSI_BACKGROUND_CYAN);
    } else if (strcmp(backgroundColor, "grey") == 0) {
        printf(ANSI_BACKGROUND_GREY);
    }

    printf("%s"   ANSI_COLORS_RESET, str);
}