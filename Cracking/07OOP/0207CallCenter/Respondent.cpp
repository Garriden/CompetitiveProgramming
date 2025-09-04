#include "Respondent.hpp"
#include <iostream>

void Respondent::Display() const
{
    std::cout << "Respondent ID: " << _id << ", name: " << _name << std::endl;
}