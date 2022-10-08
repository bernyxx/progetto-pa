/*
 * Coach.hpp
 *
 *  Created on: 28 set 2022
 *      Author: Kevin
 */

#ifndef COACH_HPP_
#define COACH_HPP_

#include <string>
#include <vector>
#include "person.hpp"

class Coach : virtual public Person{
private:
	std::string nickname;
	std::string team;
	std::vector<double> matches;

public:
	Coach(std::string, std::string, int, std::string);
	Coach(std::string, std::string, int, std::string, std::vector<double>*);
	virtual ~Coach();

	virtual std::string getNickname();

	virtual bool hasTeam();
	virtual std::string getTeam();
	virtual void setTeam(std::string);
	virtual void unsetTeam();

	// Operator overload for players comparison
	virtual bool operator>(Coach&);
	virtual bool operator<(Coach&);

	virtual std::string toString();

	virtual void addMatch(double);
	virtual double getRating();

	virtual std::vector<double>* getCoachMatches();

};



#endif /* COACH_HPP_ */
