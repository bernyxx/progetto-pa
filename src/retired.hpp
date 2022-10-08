/*
 * retired.hpp
 *
 *  Created on: 8 ott 2022
 *      Author: Kevin
 */

#ifndef RETIRED_HPP_
#define RETIRED_HPP_

#include "player.hpp"
#include "coach.hpp"

union vect{
	std::vector<double>* v1;
	std::vector<PlayerMatch*>* v2;
};

class Retired : public Player, public Coach{
private:
	bool isRetiredPlayer;

public:
	Retired(Player*);
	Retired(Coach*);

	~Retired();

	std::string toString();

	std::string getNickname();


	bool hasTeam();
	std::string getTeam();
	void setTeam(std::string);
	void unsetTeam();

	bool operator>(Retired&);
	bool operator<(Retired&);

	void addMatch();

	double getRating();

	PlayerRole getRole();
	void changeRole(PlayerRole);

	Status getStatus();
	void changeStatus(Status);

};




#endif /* RETIRED_HPP_ */
