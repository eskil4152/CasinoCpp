#ifndef USER_FUNCTIONS_H
#define USER_FUNCTIONS_H

#include "entities/user.h"
#include <string>

std::string getName();
void setName(std::string* name);

double* getMoney();
void changeMoney(double change);

double* getSpent();
void updateSpent(double spent);

double* getEarned();
void updateEarned(double earned);

#endif
