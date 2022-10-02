/*
 * player.cpp
 *
 *  Created on: 28 set 2022
 *      Author: Kevin
 */

#include "player.hpp"
#include <iostream>
#include <sstream>

Player::Player(std::string name, std::string surname, int age, std::string nickname, PlayerRole pr, Status st) : Person(name, surname, age){
	this->nickname = nickname;
	team = "";
	role = pr;
	status = st;
}

Player::~Player(){
	std::cout << "Distr. Player" << std::endl;
}

PlayerRole Player::getRole(){
	return role;
}

void Player::changeRole(PlayerRole pr){
	role = pr;
}

Status Player::getStatus(){
	return status;
}

void Player::changeStatus(Status st){
	status = st;
}

std::string Player::getNickname(){
	return nickname;
}

bool Player::hasTeam(){
	return team != "";
}

std::string Player::getTeam(){
	return team;
}

void Player::setTeam(std::string t){
	team = t;
}

void Player::unsetTeam(){
	team = "";
}

bool Player::operator> (Player& pl){

	if(getAge() >= pl.getAge()) return true;
	else return false;
}

bool Player::operator< (Player& pl){
	return !Player::operator >(pl);
}

std::string Player::toString(){
	std::stringstream ss;
	if(team == ""){
		ss << "PLAYER | Nickname:" << nickname << " | NO TEAM";
	} else {
		ss << "PLAYER | Nickname:" << nickname << " | Team:" << team;
	}

	return ss.str();
}

void Player::addMatch(PlayerMatch* pm){
	matches.push_back(pm);
}




