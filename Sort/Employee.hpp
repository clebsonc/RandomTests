//
// Created by clebson on 29/06/16.
//

#ifndef SORT_EMPLOYEE_HPP
#define SORT_EMPLOYEE_HPP

#include <iostream>

class Employee {
private:
    std::string name;
    std::string surname;
    std::string extension;

public:
    Employee();
    Employee(std::string, std::string, std::string);

    std::string getName();
    std::string getSurname();
    std::string getExtension();

    void setName(std::string);
    void setSurname(std::string);
    void setExtension(std::string);

    bool operator<(Employee &);
    bool operator>(Employee &);
};


#endif //SORT_EMPLOYEE_HPP
