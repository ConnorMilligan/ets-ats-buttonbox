#include <stdio.h>

#include "rest.h"
#include "truckInfo.h"


int main() {

    initscr();
    cbreak();

    cJSON *json;
    truckInfo truck;

    for (;;) {
        erase();
        json = cJSON_Parse(RESTget());
        json = cJSON_GetObjectItemCaseSensitive(json, "truck");
        truck = buildTruck(json);
        writeTruckInfo(1, 1, &truck);
        refresh();
    }
    
    free(json);

    endwin();
    return 0;
}