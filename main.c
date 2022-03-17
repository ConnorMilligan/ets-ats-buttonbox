#include <stdio.h>
#include <wiringPi.h>

#include "rest.h"
#include "truckInfo.h"
#include "pindef.h"


int main() {
    wiringPiSetupGpio();
    initscr();
    cbreak();

    pinMode(highbeamPin, INPUT);

    cJSON *json;
    truckInfo truck;

    for (;;) {
        erase();
        json = cJSON_Parse(RESTget());
        json = cJSON_GetObjectItemCaseSensitive(json, "truck");
        truck = buildTruck(json);
        truck.highbeams = (digitalRead(highbeamPin) == HIGH);
        writeTruckInfo(1, 1, &truck);
        refresh();
    }
    
    free(json);

    endwin();
    return 0;
}