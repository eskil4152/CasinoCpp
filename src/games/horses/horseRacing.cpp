#include <string>
#include <iostream>

#include "games/horses/horseRacing.h"
#include "games/horses/createHorses.h"
#include "entities/horses.h"

#define HORSES_COUNT 12

using namespace std;
void horseRacing(){
    Horse* horses = create();
    int totalPoints = 0;

    for (size_t i = 0; i < HORSES_COUNT; i++)
    {
        cout << "Horse " << horses[i].name << " has " << horses[i].points() << " points and " << horses[i].odds << "x payout ratio" << endl;
    }
    

    cout << "Total points for this race: " << totalPoints << endl;
}