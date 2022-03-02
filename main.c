#include <stdio.h>
#include <stdlib.h>
#include "rest.h"

int main() {
    char* test = (char *) malloc(sizeof(char)*1024);
    RESTget(test);
    printf("rest: %s\n",test);
    free(test);
    printf("end of thing:");
    return 0;
}