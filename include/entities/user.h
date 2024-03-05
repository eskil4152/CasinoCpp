#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string name;
    double money;
    double spent;
    double earned;

public:
    User();
    void setName(const std::string& newName);
    std::string getName() const;

    void changeMoney(const double& change);
    double getMoney() const;
};

#endif
