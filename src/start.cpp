#include "start.h"
#include "entities/user.h"
#include "tools/name.h"

#include <iostream>

using namespace std;

#define MAX_NAME_SIZE 24

void start() {
    User user;

    user.setName(name());

    cout << "Hello, " << user.getName() << "! Welcome to the casino!\n";

    user.setMoney(user.getMoney() + 100);
    cout << "You currently have " << user.getMoney() << " money\n";
}
