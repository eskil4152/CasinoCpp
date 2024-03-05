#include <iostream>

#include "user/userdata.h"

using namespace std;
void money(){
    string name = getName();
    double* money = getMoney();

    cout << name << "'s Account" << endl;
    cout << "Balance: $" << *money << endl;
}