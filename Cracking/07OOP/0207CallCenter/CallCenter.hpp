#ifndef CALL_CENTER_HPP
#define CALL_CENTER_HPP

#include <queue>
#include <optional>
#include <memory>

// Forward declarations
class Employee;
class Manager;
class Respondent;

class CallCenter {
public:
    CallCenter();

    const std::vector<Employee*> &GetWorkers() const;
    const std::queue<std::unique_ptr<Employee> > &GetFreeWorkers() const;
    std::optional< std::unique_ptr<Employee> > RespondentCatchCall();
private:
    std::vector<Employee*> _employees;
    std::queue<std::unique_ptr<Employee> > _freeEmployees;
};


#endif