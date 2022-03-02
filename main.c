#include "rest.h"

int main() {
    char* test = RESTget();
    printf("rest: %s\n",test);
    free(test);
    printf("end of thing:");
    return 0;
}