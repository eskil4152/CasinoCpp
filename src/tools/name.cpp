#include <string>
#include <iostream>

#include "tools/name.h"
#include "entities/user.h"

std::string name() {
    std::string name;

    std::cout << "Welcome to casino! Please enter your name: \n";
    std::getline(std::cin, name);

    //std::cout << "Hello, " << name << "!\n";

    return name;
}