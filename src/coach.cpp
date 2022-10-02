/*
 * coach.cpp
 *
 *  Created on: 28 set 2022
 *      Author: Kevin
 */

#include "coach.hpp"

#include <iostream>
#include <sstream>

Coach::Coach(std::string name, std::string surname, int age, std::string nickname) : Person(name, surname, age){
	this->nickname = nickname;
	team = "";
}

Coach::~Coach(){
	std::cout << "Distr. Coach" << std::endl;
}

std::string Coach::getNickname(){
	return nickname;
}

bool Coach::hasTeam(){
	return team != "";
}

std::string Coach::getTeam(){
	return team;
}

void Coach::setTeam(std::string t){
	team = t;
}

void Coach::unsetTeam(){
	team = "";
}

std::string Coach::toString(){
	std::stringstream ss;
	if(team == ""){
		ss << "COACH | Nickname:" << nickname << " | NO TEAM";
	} else {
		ss << "COACH | Nickname:" << nickname << " | Team:" << team;
	}

	return ss.str();
}






