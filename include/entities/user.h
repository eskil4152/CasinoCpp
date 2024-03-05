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

    std::string getName() const;
    void setName(const std::string& newName);

    double getMoney() const;
    void changeMoney(const double& change);

    double getSpent() const;
    void changeSpent(const double& change);

    double getEarned() const;
    void changeEarned(const double& change);
};

#endif
