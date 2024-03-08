#ifndef WHEEL_H
#define WHEEL_H

enum COLOR {
    RED, BLACK, GREEN
};

enum ODD_EVEN {
    ODD, EVEN, ZERO
};

struct WheelNumber {
    int number;
    COLOR color;
    ODD_EVEN oddEven;
};

#endif