#ifndef USER_FUNCTIONS_H
#define USER_FUNCTIONS_H

#include "entities/user.h"
#include <string>

std::string getName();
void setName(std::string* name);
double* getMoney();
void setMoney(double* changePtr);

#endif
