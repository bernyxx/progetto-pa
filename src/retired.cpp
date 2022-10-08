/*
 * retired.cpp
 *
 *  Created on: 8 ott 2022
 *      Author: Kevin
 */

#include <iostream>
#include <sstream>
#include "retired.hpp"

Retired::Retired(Player* pl) : Person(pl->getName(), pl->getSurname(), pl->getAge()),Player(pl->getName(), pl->getSurname(), pl->getAge(), pl->getNickname(), pl->getRole(), pl->getStatus(), pl->getPlayerMatches()), Coach(pl->getName(), pl->getSurname(), pl->getAge(), pl->getNickname()){
	isRetiredPlayer = true;
}

Retired::Retired(Coach* c) : Person(c->getName(), c->getSurname(), c->getAge()), Player(c->getName(), c->getSurname(), c->getAge(), c->getNickname(), NONE, RETIRED), Coach(c->getName(), c->getSurname(), c->getAge(), c->getNickname(), c->getCoachMatches()){
	isRetiredPlayer = false;
}

Retired::~Retired(){
	std::cout << "Distr. Retired" << std::endl;
}

std::string Retired::toString(){
	std::stringstream ss;

	ss << "RETIRED | Nickname:" << Player::getNickname();

	return ss.str();
}

std::string Retired::getNickname(){
	return Player::getNickname();
}

bool Retired::hasTeam(){
	return false;
}

std::string Retired::getTeam(){
	return "NO TEAM";
}

void Retired::setTeam(std::string team){
	if(isRetiredPlayer) throw std::runtime_error("Can't set team to a retired player");
	else throw std::runtime_error("Can't set team to a retired coach");
}

void Retired::unsetTeam(){
	if(isRetiredPlayer) throw std::runtime_error("Can't unset team to a retired player");
	else throw std::runtime_error("Can't unset team to a retired coach");
}

bool Retired::operator>(Retired& r){
	return getRating() > r.getRating();
}

bool Retired::operator<(Retired& r){
	return !Retired::operator>(r);
}

void Retired::addMatch(){
	if(isRetiredPlayer) throw std::runtime_error("Can't add matches to a retired player");
	else throw std::runtime_error("Can't add matches to a retired coach");
}

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


void Retired::changeRole(PlayerRole pr){
	if(isRetiredPlayer) throw std::runtime_error("Can't change role to a retired player");
	else throw std::runtime_error("Can't change role to a retired coach");
}

Status Retired::getStatus(){
	return RETIRED;
}

void Retired::changeStatus(Status st){
	if(isRetiredPlayer) throw std::runtime_error("Can't change status to a retired player");
	else throw std::runtime_error("Can't change status to a retired coach");
}










