#include "actions/record.h"
#include "user/userdata.h"

#include <iostream>

using namespace std;
void record(){
    double* spent = getSpent();
    double* earned = getEarned();


    cout << getName() << "'s Stats" << endl;
    cout << "Spent: " << *spent << endl;
    cout << "Earned: " << *earned << endl;
    cout << "\r\n";

    cout << "Press any key to continue\n";
    getc(stdin);
}