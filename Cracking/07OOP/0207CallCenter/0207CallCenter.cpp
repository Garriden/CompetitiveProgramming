#include "CallCenter.hpp"
#include "Employee.hpp"
#include "Respondent.hpp"
#include <optional>
#include <iostream>

// g++ -std=c++17 0207CallCenter.cpp Respondent.cpp Manager.cpp -o hola

int main()
{
    //Respondent respondent(42, "Kike");
    //respondent.Display();

    CallCenter callCenter;
    //std::vector<Employee *> vR = callCenter.GetWorkers();
    //for(int ii = 0; ii < vM.size(); ++ii) {
    //    std::cout << vM[ii].GetId() << std::endl;
    //}
    //std::cout << q.size() << std::endl;

    for(int ii = 0; ii < 14; ++ii) {
        std::optional<std::unique_ptr<Employee> > employee = callCenter.RespondentCatchCall();
        if(employee.has_value()) {
            employee.value()->Display();
        } else {
            std::cout << "No free employee found." << std::endl;
        }
    }

    return 0;
}