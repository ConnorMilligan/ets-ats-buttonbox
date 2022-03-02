#include <stdio.h>
#include "rest.h"
#include "cjson/cJSON.h"

int main() {
    char* restCall = RESTget();

    cJSON *json = cJSON_Parse(restCall);

    printf("%s\n",cJSON_Print(json));

    return 0;
}