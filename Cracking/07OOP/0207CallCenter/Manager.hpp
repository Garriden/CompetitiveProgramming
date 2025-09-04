#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Employee.hpp"

class Manager : public Employee {
public:
    Manager(const int id, const std::string &s) : Employee(id, s) {}
    void Display() const override;
private:

};


#endif