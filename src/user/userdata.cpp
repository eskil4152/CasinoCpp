#include "user/userdata.h"
#include "entities/user.h"

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

void changeMoney(double change){
    double* changePtr = new double;
    *changePtr = change;
    
    user.changeMoney(*changePtr);
    delete changePtr;
}

double* getSpent() {
    double* spent = new double;
    *spent = user.getSpent();

    return spent;
}

void updateSpent(double spent){
    double* spentPtr = new double;
    *spentPtr = spent;

    user.changeSpent(*spentPtr);
    delete spentPtr;
}

double* getEarned(){
    double* earned = new double;
    *earned = user.getEarned();

    return earned;
}

void updateEarned(double earned){
    double* earnedPtr = new double;
    *earnedPtr = earned;

    user.changeEarned(*earnedPtr);
    delete earnedPtr;
}
