#include "truckInfo.h"

truckInfo buildTruck(cJSON *json) {
    truckInfo truck = {
        cJSON_GetObjectItemCaseSensitive(json, "speed")->valuedouble,
        cJSON_GetObjectItemCaseSensitive(json, "lightsBeamLowOn")->valueint,
        cJSON_GetObjectItemCaseSensitive(json, "lightsBeamHighOn")->valueint
    };

    return truck;
}