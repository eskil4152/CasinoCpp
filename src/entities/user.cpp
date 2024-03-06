#include "entities/user.h"

User::User() : money(10000.0), spent(0.0), earned(0.0) {}

std::string User::getName() const {
    return name;
}

void User::setName(const std::string& newName) {
    name = newName;
}

double User::getMoney() const {
    return money;
}

void User::changeMoney(const double& change) {
    money += change;
}

double User::getSpent() const {
    return spent;
}

void User::changeSpent(const double& change) {
    spent += change;
}

double User::getEarned() const {
    return earned;
}

void User::changeEarned(const double& change){
    earned += change;
}
