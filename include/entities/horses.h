#ifndef HORSES_H
#define HORSES_H

#include <string>

enum HORSE_SPEED {
    SLOWEST = 5, SLOW = 4, AVERAGE = 3, FAST = 2, FASTEST = 1 
};

enum RIDER_LEVEL {
    NEW = 5, BAD = 4, MEDIOCRE = 3, SKILLED = 2, EXCELLENT = 1
};

struct Horse {
    std::string name;
    HORSE_SPEED speed;
    RIDER_LEVEL rider;

    int points() const {
        return static_cast<int>(speed) * static_cast<int>(rider);
    }

    double odds;
    double payoutRatio;
};

#endif
