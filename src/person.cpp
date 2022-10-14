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




