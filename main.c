#include <stdio.h>
#include <wiringPi.h>

#include "rest.h"
#include "truckInfo.h"
#include "display.h"

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#define PORT 8080

int truckSpeed = 0;

void *displayThread(int *num) {
    for (;;) {
        displayNum(*num);
    }
    pthread_exit(NULL);
}

int main() {
    wiringPiSetupGpio();
    initscr();
    cbreak();

    pinMode(highbeamPin, INPUT);

    cJSON *json;
    truckInfo truck, tempTruck;

    int server_fd, new_socket, rc;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
 
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0))
        == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
 
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
 
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket
         = accept(server_fd, (struct sockaddr*)&address,
                  (socklen_t*)&addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    pthread_t thread;
    rc = pthread_create(&thread, NULL, displayThread, &truckSpeed);
    if (rc) {
        printf("Error:unable to create thread, %d\n", rc);
        exit(-1);
    }

    for (;;) {
        erase();
        json = cJSON_Parse(RESTget());
        tempTruck = buildTruck(json);
        tempTruck.highbeam = (digitalRead(highbeamPin) == HIGH);
        tempTruck.pbrake = (digitalRead(pbrakePin) == HIGH);
        tempTruck.ebrake = (digitalRead(ebrakePin) == HIGH);
        tempTruck.ldax = (digitalRead(ldaxPin) == HIGH);
        tempTruck.diffLock = (digitalRead(diffLockPin) == HIGH);
        tempTruck.trailer = (digitalRead(trailerPin) == HIGH);

        if (tempTruck.highbeam != truck.highbeam) {
            send(new_socket, "1) Highbeams toggled", 21, 0);
        } if (tempTruck.pbrake != truck.pbrake) {
            send(new_socket, "2) Parking Brake toggled", 25, 0);
        } if (tempTruck.ebrake != truck.ebrake) {
            send(new_socket, "3) Engine Brake toggled", 24, 0);
        } if (tempTruck.ldax != truck.ldax) {
            send(new_socket, "4) Drop/Lift Axel toggled", 26, 0);
        } if (tempTruck.diffLock != truck.diffLock) {
            send(new_socket, "5) Differential Lock toggled", 29, 0);
        } if (tempTruck.trailer != truck.trailer) {
            send(new_socket, "6) Trailler Attach/Detach toggled", 34, 0);
        }

        writeTruckInfo(1, 1, &truck);
        truck = tempTruck;
        truckSpeed = truck.speed;
        refresh();
    }
    
    free(json);

    endwin();
    return 0;
}