#include "display.h"

int getdigit(int num, int n)
{
    int r;

    r = num / pow(10, n);

    r = r % 10;

    return r;
}

void resetDisplay() {
    digitalWrite (a, LOW);
    digitalWrite (b, LOW);
    digitalWrite (c, LOW);
    digitalWrite (d, LOW);
    digitalWrite (e, LOW);
    digitalWrite (f, LOW);
    digitalWrite (g, LOW);
    digitalWrite (dot, LOW);
    digitalWrite (d1, HIGH);
    digitalWrite (d2, HIGH);
    digitalWrite (d3, HIGH);
    digitalWrite (d4, HIGH);
}

void setNum(int num) {
    if (num <= 9 && num >= 0){
        digitalWrite (a, LOW);
        digitalWrite (b, LOW);
        digitalWrite (c, LOW);
        digitalWrite (d, LOW);
        digitalWrite (e, LOW);
        digitalWrite (f, LOW);
        digitalWrite (g, LOW);
        switch (num)
        {
        case 1:
            digitalWrite (a, LOW);
            digitalWrite (b, HIGH);
            digitalWrite (c, HIGH);
            digitalWrite (d, LOW);
            digitalWrite (e, LOW);
            digitalWrite (f, LOW);
            digitalWrite (g, LOW);
            break;
        case 2:
            digitalWrite (a, HIGH);
            digitalWrite (b, HIGH);
            digitalWrite (c, LOW);
            digitalWrite (d, HIGH);
            digitalWrite (e, HIGH);
            digitalWrite (f, LOW);
            digitalWrite (g, HIGH);
            break;
        case 3:
            digitalWrite (a, HIGH);
            digitalWrite (b, HIGH);
            digitalWrite (c, HIGH);
            digitalWrite (d, HIGH);
            digitalWrite (e, LOW);
            digitalWrite (f, LOW);
            digitalWrite (g, HIGH);
            break;
        case 4:
            digitalWrite (a, LOW);
            digitalWrite (b, HIGH);
            digitalWrite (c, HIGH);
            digitalWrite (d, LOW);
            digitalWrite (e, LOW);
            digitalWrite (f, HIGH);
            digitalWrite (g, HIGH);
            break;
        case 5:
            digitalWrite (a, HIGH);
            digitalWrite (b, LOW);
            digitalWrite (c, HIGH);
            digitalWrite (d, HIGH);
            digitalWrite (e, LOW);
            digitalWrite (f, HIGH);
            digitalWrite (g, HIGH);
            break;
        case 6:
            digitalWrite (a, HIGH);
            digitalWrite (b, LOW);
            digitalWrite (c, HIGH);
            digitalWrite (d, HIGH);
            digitalWrite (e, HIGH);
            digitalWrite (f, HIGH);
            digitalWrite (g, HIGH);
            break;
        case 7:
            digitalWrite (a, HIGH);
            digitalWrite (b, HIGH);
            digitalWrite (c, HIGH);
            digitalWrite (d, LOW);
            digitalWrite (e, LOW);
            digitalWrite (f, LOW);
            digitalWrite (g, LOW);
            break;
        case 8:
            digitalWrite (a, HIGH);
            digitalWrite (b, HIGH);
            digitalWrite (c, HIGH);
            digitalWrite (d, HIGH);
            digitalWrite (e, HIGH);
            digitalWrite (f, HIGH);
            digitalWrite (g, HIGH);
            break;
        case 9:
            digitalWrite (a, HIGH);
            digitalWrite (b, HIGH);
            digitalWrite (c, HIGH);
            digitalWrite (d, HIGH);
            digitalWrite (e, LOW);
            digitalWrite (f, HIGH);
            digitalWrite (g, HIGH);
            break;

        default:
            digitalWrite (a, HIGH);
            digitalWrite (b, HIGH);
            digitalWrite (c, HIGH);
            digitalWrite (d, HIGH);
            digitalWrite (e, HIGH);
            digitalWrite (f, HIGH);
            digitalWrite (g, LOW);
            break;
        }
    }
    
}

int displayNum(int num) {
    if (num < 10 && num > -1) {
        digitalWrite (d4, LOW);
        setNum(getdigit(num, 0));
        resetDisplay();
    }
    else if (num < 100 && num >= 10) {
        digitalWrite (d3, LOW);
        setNum(getdigit(num, 1));
        resetDisplay();
        digitalWrite (d4, LOW);
        setNum(getdigit(num, 0));
        resetDisplay();
    }
    else if (num < 1000 && num >= 100) {
        digitalWrite (d2, LOW);
        setNum(getdigit(num, 2));
        resetDisplay();
        digitalWrite (d3, LOW);
        setNum(getdigit(num, 1));
        resetDisplay();
        digitalWrite (d4, LOW);
        setNum(getdigit(num, 0));
        resetDisplay();
    }
    else if (num < 10000 && num >= 1000) {
        digitalWrite (d1, LOW);
        setNum(getdigit(num, 3));
        resetDisplay();
        digitalWrite (d2, LOW);
        setNum(getdigit(num, 2));
        resetDisplay();
        digitalWrite (d3, LOW);
        setNum(getdigit(num, 1));
        resetDisplay();
        digitalWrite (d4, LOW);
        setNum(getdigit(num, 0));
        resetDisplay();
    }
    

    
    return 1;
}
