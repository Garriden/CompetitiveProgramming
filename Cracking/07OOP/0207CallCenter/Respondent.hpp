#ifndef RESPONDENT_HPP
#define RESPONDENT_HPP

#include "Employee.hpp"

class Respondent : public Employee {
public:
    Respondent(const int id, const std::string &s) : Employee(id, s) {}
    void Display() const override;
private:

};


#endif