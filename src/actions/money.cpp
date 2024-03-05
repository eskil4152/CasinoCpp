#include <iostream>

#include "user/userdata.h"

using namespace std;
void money(){
    string name = getName();
    double* money = getMoney();

    cout << name << "'s Account" << endl;
    cout << "Balance: $" << *money << endl;
    cout << "\r\n";

    cout << "Press any key to continue\n";
    getc(stdin);
}