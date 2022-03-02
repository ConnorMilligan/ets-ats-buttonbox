#ifndef TRUCKINFO_H
#define TRUCKINFO_H

#include <cjson/cJSON.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct truckInfo
{
    double speed;
    int headlights;
    int highbeams;
} truckInfo;

truckInfo buildTruck(cJSON *json);

#endif