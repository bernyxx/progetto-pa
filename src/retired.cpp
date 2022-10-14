#include <iostream>
#include <sstream>
#include "retired.hpp"

Retired::Retired(std::shared_ptr<Player> pl) : Person(pl->getName(), pl->getSurname(), pl->getAge()),Player(pl->getName(), pl->getSurname(), pl->getAge(), pl->getNickname(), pl->getRole(), pl->getStatus(), pl->getPlayerMatches()), Coach(pl->getName(), pl->getSurname(), pl->getAge(), pl->getNickname()){
	isRetiredPlayer = true;
}

Retired::Retired(std::shared_ptr<Coach> c) : Person(c->getName(), c->getSurname(), c->getAge()), Player(c->getName(), c->getSurname(), c->getAge(), c->getNickname(), NONE, RETIRED), Coach(c->getName(), c->getSurname(), c->getAge(), c->getNickname(), c->getCoachMatches()){
	isRetiredPlayer = false;
}

Retired::~Retired(){
	std::cout << "Distr. Retired" << std::endl;
}

// override toString()
std::string Retired::toString(){
	std::stringstream ss;

	ss << "RETIRED | Nickname:" << Player::getNickname();

	return ss.str();
}

std::string Retired::getNickname(){
	return Player::getNickname();
}

// un Retired non deve avere un team
bool Retired::hasTeam(){
	return false;
}

// un Retired non deve avere un team
std::string Retired::getTeam(){
	return "NO TEAM";
}

// un Retired non deve avere un team
void Retired::setTeam(std::string team){
	if(isRetiredPlayer) throw std::runtime_error("Can't set team to a retired player");
	else throw std::runtime_error("Can't set team to a retired coach");
}

// un Retired non deve avere un team
void Retired::unsetTeam(){
	if(isRetiredPlayer) throw std::runtime_error("Can't unset team to a retired player");
	else throw std::runtime_error("Can't unset team to a retired coach");
}

// operator overload >
bool Retired::operator>(Retired& r){
	return getRating() > r.getRating();
}

// operator overload <
bool Retired::operator<(Retired& r){
	return !Retired::operator>(r);
}

// un Retired non può prendere parte ad altre partite
void Retired::addMatch(){
	if(isRetiredPlayer) throw std::runtime_error("Can't add matches to a retired player");
	else throw std::runtime_error("Can't add matches to a retired coach");
}

// ottieni il rating in base a come è stato creato retired (se a partite da un player o da un coach)
double Retired::getRating(){
	if(isRetiredPlayer){
		return Player::getAvgKD();
	} else {
		return Coach::getRating();
	}
}

PlayerRole Retired::getRole(){
	return NONE;
}

// un Retired non può cambiare ruolo
void Retired::changeRole(PlayerRole pr){
	if(isRetiredPlayer) throw std::runtime_error("Can't change role to a retired player");
	else throw std::runtime_error("Can't change role to a retired coach");
}

// un Retired può avere solo lo stato Retired e non può essere cambiato
Status Retired::getStatus(){
	return RETIRED;
}

// un Retired può avere solo lo stato Retired e non può essere cambiato
void Retired::changeStatus(Status st){
	if(isRetiredPlayer) throw std::runtime_error("Can't change status to a retired player");
	else throw std::runtime_error("Can't change status to a retired coach");
}










