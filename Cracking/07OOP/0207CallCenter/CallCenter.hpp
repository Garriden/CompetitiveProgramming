#ifndef CALL_CENTER_HPP
#define CALL_CENTER_HPP

#include "Respondent.hpp"
#include "Manager.hpp"
#include <queue>
#include <optional>
#include <memory>

class CallCenter {
public:
    CallCenter() : _employees{}, _freeEmployees{} {
        for(int ii = 0; ii < 10; ++ii) {
            std::unique_ptr<Respondent> respondent = std::make_unique<Respondent>(ii, "Rashid");
            _employees.push_back(respondent.get());
            _freeEmployees.push(std::move(respondent));
        }
        for(int ii = 0; ii < 3; ++ii) {
            std::unique_ptr<Manager> manager = std::make_unique<Manager>(ii, "Josep Lluis");
            _employees.push_back(manager.get());
            _freeEmployees.push(std::move(manager));
        }
    }

    const std::vector<Employee *> GetWorkers() const { return _employees; }
    const std::queue<std::unique_ptr<Employee> > &GetFreeWorkers() const { return _freeEmployees; }

    std::optional< std::unique_ptr<Employee> > RespondentCatchCall() { 
        if(!_freeEmployees.empty()) {
             std::unique_ptr<Employee> employee = std::move(_freeEmployees.front());
            _freeEmployees.pop();
            return employee; 
        } else {
            return std::nullopt;
        }
    }

private:
    std::vector<Employee*> _employees;
    std::queue<std::unique_ptr<Employee> > _freeEmployees;
};


#endif