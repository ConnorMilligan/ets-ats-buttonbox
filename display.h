#ifndef DISPLAY_H
#define DISPLAY_H
#include <stdio.h>
#include <math.h>
#include <wiringPi.h>
#include "pindef.h"

int getdigit(int num, int n);

void resetDisplay();

void initDisplay();

void setNum(int num);

int displayNum(int num);
#endif