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

class Coach : public Person{
private:
	std::string nickname;
	std::string team;
	std::vector<double> matches;

public:
	Coach(std::string, std::string, int, std::string);
	virtual ~Coach();

	std::string getNickname();

	bool hasTeam();
	std::string getTeam();
	void setTeam(std::string);
	void unsetTeam();

	std::string toString();

	void addMatch(double);
	double getRating();

};



#endif /* COACH_HPP_ */
