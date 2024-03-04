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
    User(); // Constructor
    void setName(const std::string& newName);
    std::string getName() const;

    void setMoney(const double& newMoney);
    double getMoney() const;
};

#endif // USER_H
