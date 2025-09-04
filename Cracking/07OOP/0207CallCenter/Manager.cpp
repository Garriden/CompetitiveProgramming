#include "Manager.hpp"
#include <iostream>

void Manager::Display() const
{
    std::cout << "Manager ID: " << _id << ", name: " << _name << std::endl;
}