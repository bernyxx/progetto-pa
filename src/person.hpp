/*
 * person.hpp
 *
 *  Created on: 28 set 2022
 *      Author: Kevin
 */

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>


class Person
{
private:
     std::string name;
     std::string surname;
     int age;

public:
    Person(std::string, std::string, int);
    virtual ~Person();
    virtual std::string toString();
    std::string getName();
    std::string getSurname();
    int getAge();
};




#endif /* PERSON_HPP_ */
