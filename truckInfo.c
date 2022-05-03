#include "truckInfo.h"

truckInfo buildTruck(cJSON *json) {
    truckInfo truck = {
        cJSON_GetObjectItemCaseSensitive(cJSON_GetObjectItemCaseSensitive(json, "truck"), "speed")->valuedouble,
        cJSON_GetObjectItemCaseSensitive(cJSON_GetObjectItemCaseSensitive(json, "truck"), "parkBrakeOn")->valueint,
        cJSON_GetObjectItemCaseSensitive(cJSON_GetObjectItemCaseSensitive(json, "truck"), "motorBrakeOn")->valueint,
        cJSON_GetObjectItemCaseSensitive(cJSON_GetObjectItemCaseSensitive(json, "truck"), "lightsBeamHighOn")->valueint,
        cJSON_GetObjectItemCaseSensitive(cJSON_GetObjectItemCaseSensitive(json, "trailer"), "attached")->valueint
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
        mvprintw(starty + 1, startx, "Highbeams: ");
        if (truck->highbeam == TRUE) {
            attron(COLOR_PAIR(1));
            mvprintw(starty + 1, startx + 13, "ON");
            attroff(COLOR_PAIR(1));
        } else {
            attron(COLOR_PAIR(2));
            mvprintw(starty + 1, startx + 13, "OFF");
            attroff(COLOR_PAIR(2));
        }
        mvprintw(starty + 2, startx, "Parking Brake: ");
        if (truck->pbrake == TRUE) {
            attron(COLOR_PAIR(1));
            mvprintw(starty + 2, startx + 16, "ON");
            attroff(COLOR_PAIR(1));
        } else {
            attron(COLOR_PAIR(2));
            mvprintw(starty + 2, startx + 16, "OFF");
            attroff(COLOR_PAIR(2));
        }
        mvprintw(starty + 3, startx, "Engine Brake: ");
        if (truck->ebrake == TRUE) {
            attron(COLOR_PAIR(1));
            mvprintw(starty + 3, startx + 15, "ON");
            attroff(COLOR_PAIR(1));
        } else {
            attron(COLOR_PAIR(2));
            mvprintw(starty + 3, startx + 15, "OFF");
            attroff(COLOR_PAIR(2));
        }
        mvprintw(starty + 4, startx, "Trailer: ");
        if (truck->trailer == TRUE) {
            attron(COLOR_PAIR(1));
            mvprintw(starty + 4, startx + 10, "Attached");
            attroff(COLOR_PAIR(1));
        } else {
            attron(COLOR_PAIR(2));
            mvprintw(starty + 4, startx + 10, "Detached");
            attroff(COLOR_PAIR(2));
        }
        
    } else {
        mvprintw(starty, startx + 1, "This program requires terminal colors.");
    }
    
    
    move(0,0);
}