#include "tools/checkInput.h"
#include "start.h"
#include "user/userdata.h"

#include <iostream>

int main(){
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::cout << "Hello and welcome to the casino" << std::endl;

    setName(nameInput());

    start();

    return 0;
}