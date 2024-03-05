#include <string>
#include <iostream>

#include "tools/name.h"
#include "entities/user.h"

std::string name() {
    std::string name;

    std::cout << "Please enter your name:" << std::endl;
    std::getline(std::cin, name);

    return name;
}