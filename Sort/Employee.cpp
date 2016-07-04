//
// Created by clebson on 29/06/16.
//

#include "Employee.hpp"

Employee::Employee() { }

Employee::Employee(std::string name, std::string surname, std::string extension):
        name{name}, surname{surname}, extension{extension}{}

std::string Employee::getName(){
    return this->name;
}

std::string Employee::getSurname() {
    return this->surname;
}

std::string Employee::getExtension() {
    return this->extension;
}

void Employee::setName(std::string name){
    this->name = name;
}

void Employee::setExtension(std::string extension){
    this->extension = extension;
}

void Employee::setSurname(std::string surname) {
    this->surname = surname;
}

bool Employee::operator<(Employee & employee) {
    if(this->surname == employee.getSurname()){
        return this->name < employee.getName();
    } else{
        return this->surname < employee.getSurname();
    }
}

bool Employee::operator>(Employee & employee) {
    if(this->surname == employee.getSurname()){
        return this->name > employee.getName();
    } else{
        return this->surname > employee.getSurname();
    }
}
