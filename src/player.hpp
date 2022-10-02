/*
 * player.hpp
 *
 *  Created on: 28 set 2022
 *      Author: Kevin
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include "person.hpp"
#include "PlayerMatch.hpp"

enum PlayerRole {
	LURKER, ENTRY, SUPPORT, IGL
};

enum Status{
	ACTIVE, BENCHED
};

class Player : public Person{
private:
	std::string nickname;
	std::string team;
	PlayerRole role;
	Status status;
	std::vector<PlayerMatch*> matches;


public:
	Player(std::string, std::string, int, std::string, PlayerRole, Status);
	virtual ~Player();

	PlayerRole getRole();
	void changeRole(PlayerRole);

	Status getStatus();
	void changeStatus(Status);

	std::string getNickname();

	bool hasTeam();
	std::string getTeam();
	void setTeam(std::string);
	void unsetTeam();

	std::string toString();

	bool operator>(Player&);
	bool operator< (Player&);

	void addMatch(PlayerMatch*);
};




#endif /* PLAYER_HPP_ */
