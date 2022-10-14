#ifndef RETIRED_HPP_
#define RETIRED_HPP_

#include <memory>
#include "player.hpp"
#include "coach.hpp"

class Retired : public Player, public Coach{
private:
	// true-> retired è stato costruito con un player
	// false -> retired è stato costruito con un coach
	bool isRetiredPlayer;

public:
	// costruttore dato un player
	Retired(std::shared_ptr<Player>);

	// costruttore dato un coach
	Retired(std::shared_ptr<Coach>);

	// distruttore
	~Retired();


	// sono sostanzialmente gli stessi metodi di player e coach
	// con un comportamento diverso per rappresentare meglio una persona
	// che ha smesso di competere

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
