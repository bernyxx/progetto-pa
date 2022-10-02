/*
 * person.cpp
 *
 *  Created on: 28 set 2022
 *      Author: Kevin
 */

#include "person.hpp"
#include <iostream>
#include <sstream>

Person::Person(std::string name, std::string surname, int age)
{
     this->name = name;
     this->surname = surname;
     this->age = age;
}

 std::string Person::toString()
 {
//     std::string n = "Name:" + name;
//     std::string c = " | Surname:" + surname;
//     std::string a = " | Age:" + std::to_string(age);
//     std::string res = "PERSON | " + n + c + a;

     std::stringstream ss;
     ss << "PERSON | Name:" << name << " | Surname:" << surname << " | Age:" << age;
     std::string s = ss.str();

     return s;
 }

 std::string Person::getName()
 {
     return name;
 }

 std::string Person::getSurname()
 {
     return surname;
 }

int Person::getAge()
{
    return age;
}

Person::~Person()
{
    std::cout << "Distr. Person" << std::endl;
}




