#include "entities/user.h"
#include "user/userdata.h"

#include <string>
#include <iostream>

User user;

std::string getName(){
    return user.getName();
}

void setName(std::string* name){
    user.setName(*name);
    delete name;
}

double* getMoney(){
    double* money = new double;
    *money = user.getMoney();

    return money;
}

void setMoney(double* changePtr){
    double* oldMoney = getMoney();
    double newMoney = *oldMoney + *changePtr;
}