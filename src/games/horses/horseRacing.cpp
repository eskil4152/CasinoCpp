#include <string>
#include <iostream>

#include "games/horses/horseRacing.h"
#include "games/horses/createHorses.h"
#include "games/horses/horseInputCheck.h"
#include "entities/horses.h"

#include "user/userdata.h"

#define HORSES_COUNT 12

using namespace std;
void horseRacing(){
    Horse* horses = create();
    int totalPoints = 0;

    for (size_t i = 0; i < HORSES_COUNT; i++){
        cout << "Horse " << horses[i].name << " has " << horses[i].points() 
            << " points and " << horses[i].odds << "x payout ratio" << endl;
    }

    cout << "Who do you want to bet on? Answer with horse number" << endl;

    int horse = horseSelectionInput();
    Horse selectedHorse = horses[horse];

    cout << "And how much do you want to bet?" << endl;

    double bet = betInput();
    double* money = getMoney();
    
    if (bet > *money){
        cout << "You do not have that much money. You only have $" << *money << endl;
        return;
    }
    
    updateSpent(bet);
    changeMoney(-bet);

    double potentialPayout = bet * selectedHorse.odds;

    race(horses);
}

bool race(Horse* horses){
    
}