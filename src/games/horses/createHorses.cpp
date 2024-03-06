#include "games/horses/createHorses.h"
#include "entities/horses.h"

#include <iostream>
#include <string>
#include <iomanip>

#define HORSES_COUNT 12

Horse* create(){
    int totalPoints = 0;

    Horse* horses = new Horse[HORSES_COUNT];

    srand(time(NULL));
    
    for (size_t i = 0; i < HORSES_COUNT; i++){
        int randomSpeed = rand() % 5 + 1;
        int randomRider = rand() % 5 + 1;

        horses[i].name = "HORSE " + std::to_string(i + 1);
        horses[i].speed = static_cast<HORSE_SPEED>(randomSpeed);
        horses[i].rider = static_cast<RIDER_LEVEL>(randomRider);

        totalPoints += horses[i].points();
    }

    for (size_t i = 0; i < HORSES_COUNT; i++) {
        int points = horses[i].points();

        double odds = (double)points / (double)totalPoints * 100;
        double payoutRatio = totalPoints / points / 4;

        if (payoutRatio <= 1){
            payoutRatio = 1.1;
        }

        horses[i].odds = odds;
        horses[i].payoutRatio = payoutRatio;
    }
    
    std::cout << "Total points for this race: " << totalPoints << std::endl;
    return horses;
}