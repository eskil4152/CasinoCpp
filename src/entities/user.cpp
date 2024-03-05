#include "entities/user.h"

User::User() : money(1000.0), spent(0.0), earned(0.0) {}

void User::setName(const std::string& newName) {
    name = newName;
}

std::string User::getName() const {
    return name;
}

void User::changeMoney(const double& change) {
    money += change;
}

double User::getMoney() const {
    return money;
}
