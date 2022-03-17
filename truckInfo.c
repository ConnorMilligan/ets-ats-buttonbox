#include "truckInfo.h"

truckInfo buildTruck(cJSON *json) {
    truckInfo truck = {
        cJSON_GetObjectItemCaseSensitive(json, "speed")->valuedouble,
        cJSON_GetObjectItemCaseSensitive(json, "lightsBeamLowOn")->valueint,
        //cJSON_GetObjectItemCaseSensitive(json, "lightsBeamHighOn")->valueint
    };

    return truck;
}

void writeTruckInfo(int starty, int startx, truckInfo *truck) {
    if (has_colors() == TRUE) {
        start_color();
	    init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
    }
    mvprintw(starty, startx, "Speed: %.0f km/h", truck->speed);

    if (has_colors() == TRUE) {
        mvprintw(starty + 1, startx, "Headlights: ");
        if (truck->headlights == TRUE) {
            attron(COLOR_PAIR(1));
            mvprintw(starty + 1, startx + 13, "ON");
            attroff(COLOR_PAIR(1));
        } else {
            attron(COLOR_PAIR(2));
            mvprintw(starty + 1, startx + 13, "OFF");
            attroff(COLOR_PAIR(2));
        }
        mvprintw(starty + 2, startx, "Highbeams: ");
        if (truck->highbeams == TRUE) {
            attron(COLOR_PAIR(1));
            mvprintw(starty + 2, startx + 13, "ON");
            attroff(COLOR_PAIR(1));
        } else {
            attron(COLOR_PAIR(2));
            mvprintw(starty + 2, startx + 13, "OFF");
            attroff(COLOR_PAIR(2));
        }
        
    } else {
        mvprintw(starty, startx + 1, "Headlights status: %d", truck->headlights);
    }
    
    
    move(0,0);
}