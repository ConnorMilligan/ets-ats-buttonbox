#include <stdio.h>
#include <ncurses.h>

#include "rest.h"
#include "truckInfo.h"


int main() {

    initscr();
    cbreak();

    char* rest;
    cJSON *json;

    for (;;) {
        rest = RESTget();
        erase();
        json = cJSON_Parse(rest);
        json = cJSON_GetObjectItemCaseSensitive(json, "truck");
        truckInfo truck = buildTruck(json);
        printw("speed: %f\nlowbeans: %d\n highbeams: %d",truck.speed, truck.headlights, truck.highbeams);
        refresh();
    }
    
    free(json);

    endwin();
    return 0;
}