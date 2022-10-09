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
	 // nome
     std::string name;
     // cognome
     std::string surname;
     // età
     int age;

public:
     // costruttore che richiede nome, cognome, età
    Person(std::string, std::string, int);

    // distruttore
    virtual ~Person();

    virtual std::string toString();
    std::string getName();
    std::string getSurname();
    int getAge();
};




#endif /* PERSON_HPP_ */
