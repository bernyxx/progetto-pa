/*
 * organization.hpp
 *
 *  Created on: 29 set 2022
 *      Author: Kevin
 */

#ifndef ORGANIZATION_HPP_
#define ORGANIZATION_HPP_

#include <vector>
#include "player.hpp"
#include "coach.hpp"

class Organization{
private:
	std::string name;
	std::vector<Player*> players;
	Coach* coach;
	std::vector<int> matches;

public:
	Organization(std::string, std::vector<Organization*>*);
	~Organization();
	std::string getName();
	void print();

	// coach methods
	Coach* getCoach();
	void setCoach(Coach*);
	void removeCoach();
	bool hasCoach();

	// players methods

	void addPlayer(Player*);
	void removePlayer(std::string);
	Player* getPlayer(std::string);
	Player* getBestPlayer();
	bool hasPlayer(std::string);

};




#endif /* ORGANIZATION_HPP_ */
