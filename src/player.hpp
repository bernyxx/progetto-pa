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
#include "playerMatch.hpp"

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

	std::string toString();

	// Player role methods
	PlayerRole getRole();
	void changeRole(PlayerRole);

	// Player status methods
	Status getStatus();
	void changeStatus(Status);

	// Player nickname
	std::string getNickname();

	// Player team methods
	bool hasTeam();
	std::string getTeam();
	void setTeam(std::string);
	void unsetTeam();

	// Operator overload for players comparison
	bool operator>(Player&);
	bool operator< (Player&);

	// Player matches methods
	void addMatch(PlayerMatch*);
	void printMatches();

	// Player stats methods
	int getTotalKills();
	int getTotalAssists();
	int getTotalDeaths();
	double getTotalKD();

	double getAvgKills();
	double getAvgAssists();
	double getAvgDeaths();
	double getAvgKD();

	void printStats();

};




#endif /* PLAYER_HPP_ */
