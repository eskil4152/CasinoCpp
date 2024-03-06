#include <string>
#include <iostream>

#include "games/horses/horseRacing.h"
#include "games/horses/createHorses.h"
#include "games/horses/horseInputCheck.h"
#include "entities/horses.h"

#include "tools/checkInput.h"
#include "user/userdata.h"

#define HORSES_COUNT 12

using namespace std;
void horseRacing(){
    cout << "Welcome to Horse Racing!" << endl;
    bool play = true;

    while (play){
        Horse* horses = create();

        for (size_t i = 0; i < HORSES_COUNT; i++){
            cout << "Horse " << horses[i].name << " has " << horses[i].odds 
                << " odds and " << horses[i].payoutRatio << "x payout ratio" << endl;
        }

        cout << "Who do you want to bet on? Answer with horse number" << endl;

        int horse = horseSelectionInput();
        Horse selectedHorse = horses[horse - 1];

        cout << "And how much do you want to bet?" << endl;

        double bet = betInput();
        double* money = getMoney();
        
        if (bet > *money){
            cout << "You do not have that much money. You only have $" << *money << endl;
            return;
        }
        
        updateSpent(bet);
        changeMoney(-bet);

        double potentialPayout = bet * selectedHorse.payoutRatio;

        if (race(horses, selectedHorse)){
            changeMoney(potentialPayout);
            updateEarned(potentialPayout);
        }
        
        play = keepPlayingInput();
    }    
}

bool race(Horse* horses, Horse selectedHorse){
    double totalOdds = 0;

    for (size_t i = 0; i < HORSES_COUNT; i++){
        totalOdds += horses[i].odds;
    }

    double randomNumber = static_cast<double>(rand()) / RAND_MAX * totalOdds;

    double cumulativeOdds = 0;
    for (int i = 0; i < HORSES_COUNT; i++){
        cumulativeOdds += horses[i].odds;
        if (randomNumber <= cumulativeOdds) {
            cout << "The winner is: " << horses[i].name << endl;
            if (horses[i].name == selectedHorse.name){
                return true;
            }
            break;
        }
    }

    cout << "No winner" << endl;
    return false;
}