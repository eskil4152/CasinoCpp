#include "tools/checkInput.h"
#include "start.h"
#include "user/userdata.h"

#include "games/blackjack/blackjackDeck.h"

#include <iostream>

using namespace std;
int main(){
    cout << std::endl << std::endl << std::endl << endl;
    cout << "Hello and welcome to the casino" << endl;

    setName(nameInput());
    start();

    return 0;
}