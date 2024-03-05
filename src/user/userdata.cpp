#include "user/userdata.h"
#include "entities/user.h"

#include <string>
#include <iostream>

User user;

std::string getName(){
    return user.getName();
}

void setName(std::string name){
    user.setName(name);
}

double* getMoney(){
    double* money = new double;
    *money = user.getMoney();

    return money;
}

void setMoney(double* changePtr){
    user.changeMoney(*changePtr);
}