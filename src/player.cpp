/*
 * player.cpp
 *
 *  Created on: 28 set 2022
 *      Author: Kevin
 */

#include <iostream>
#include <sstream>
#include <cmath>
#include "player.hpp"

double customRound(double value){
	return (round(value * 100)) / 100;
}

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

	if(getAvgKD() > pl.getAvgKD()) return true;
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

void Player::printMatches(){

	for (std::vector<PlayerMatch*>::iterator i = matches.begin(); i != matches.end(); ++i) {
		int* results = (*i)->getValues();
		std::cout << "MATCH | Kills:" << results[0] << " | Assists:" << results[1] << " | Deaths:" << results[2] << std::endl;
	}
}

int Player::getTotalKills(){
	int total = 0;

	for(PlayerMatch *pm : matches){
		total += pm->getValues()[0];
	}

	return total;
}

int Player::getTotalAssists(){
	int total = 0;

	for(PlayerMatch *pm : matches){
		total += pm->getValues()[1];
	}

	return total;
}

int Player::getTotalDeaths(){
	int total = 0;

	for(PlayerMatch *pm : matches){
		total += pm->getValues()[2];
	}

	return total;
}

double Player::getTotalKD(){
	return customRound(getTotalKills() / (double) getTotalDeaths());
}

double Player::getAvgKills(){
	return customRound(getTotalKills() / (double) matches.size());
}

double Player::getAvgAssists(){
	return customRound(getTotalAssists() / (double) matches.size());
}

double Player::getAvgDeaths(){
	return customRound(getTotalDeaths() / (double) matches.size());
}

double Player::getAvgKD(){
	double totalKD = 0;

	for(PlayerMatch *pm : matches){
			totalKD += pm->getKD();
	}
	return customRound(totalKD / (double) matches.size());
}

void Player::printStats(){
	std::cout << "STATS Player " << nickname << std::endl;
	std::cout << "Total K/D/A: " << getTotalKills() << "/" << getTotalDeaths() << "/" << getTotalAssists() << std::endl;
	std::cout << "KD ratio calculated on total stats: " << getTotalKD() << std::endl;
	std::cout << "Average kills per match: " << getAvgKills() << std::endl;
	std::cout << "Average deaths per match: " << getAvgDeaths() << std::endl;
	std::cout << "Average assists per match: " << getAvgAssists() << std::endl;
	std::cout << "Average KD ratio per match: " << getAvgKD() << std::endl;
}








