#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "string"

class Employee {
public:
    Employee(const int id, const std::string &s) : _id{id}, _name{s} {}
    virtual ~Employee() {}

    virtual void Display() const = 0;
    virtual int GetId() const { return _id; }
    virtual std::string GetName() const { return _name; }
protected:
    int _id;
    std::string _name;
};


#endif