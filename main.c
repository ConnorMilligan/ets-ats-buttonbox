#include <stdio.h>
#include <ncurses.h>

#include "rest.h"
#include "truckInfo.h"


int main() {
    char* restCall = RESTget();

    initscr();

    cJSON *json = cJSON_Parse(restCall);
    json = cJSON_GetObjectItemCaseSensitive(json, "truck");
    truckInfo truck = buildTruck(json);
    printw("speed: %f\nlowbeans: %d\n highbeams: %d",truck.speed, truck.headlights, truck.highbeams);
    refresh();
    getch();

    free(restCall);
    free(json);

    endwin();
    return 0;
}