#include <iostream>
#include <sstream>
#include <algorithm>

#include "player.hpp"
#include "customRound.hpp"


Player::Player(std::string name, std::string surname, int age, std::string nickname, PlayerRole pr, Status st) : Person(name, surname, age){
	this->nickname = nickname;
	team = "";
	role = pr;
	status = st;
}

Player::Player(std::string name, std::string surname, int age, std::string nickname, PlayerRole pr, Status st, std::vector<PlayerMatch*>* matches) : Person(name, surname, age){
	this->nickname = nickname;
	team = "";
	role = pr;
	status = st;
	this->matches = *matches;
}


Player::~Player(){
	std::cout << "Distr. Player" << std::endl;

	// distruggi ogni playermatch contenuto in matches
	std::for_each(matches.begin(), matches.end(), [](PlayerMatch *pm){
			delete pm;
	});

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

// operator overload >
bool Player::operator> (Player& pl){

	if(getAvgKD() > pl.getAvgKD()) return true;
	else return false;
}

// operator overload <
bool Player::operator< (Player& pl){
	return !Player::operator >(pl);
}

std::string Player::toString(){
	std::stringstream ss;

	if (team == "" && matches.size() > 0) {
		// se il giocatore non fa parte di un team ma ha giocato almeno una partita
		ss << "PLAYER | Nickname:" << nickname << " | NO TEAM | Rating: " << getAvgKD();
	} else if (team == "" && matches.size() == 0) {
		// se il giocatore non fa parte di un team e non ha mai giocato partite
		ss << "PLAYER | Nickname:" << nickname << " | NO TEAM";
	} else if (team != "" && matches.size() > 0) {
		// se il giocatore fa parte di un team e ha giocato almeno una partita
		ss << "PLAYER | Nickname:" << nickname << " | Team:" << team << " | Rating: " << getAvgKD();
	} else {
		// se il giocatore fa parte di un team ma non ha giocato partite
		ss << "PLAYER | Nickname:" << nickname << " | Team:" << team;
	}

	return ss.str();
}

void Player::addMatch(PlayerMatch* pm){
	matches.push_back(pm);
}

void Player::printMatches(){

//	for (std::vector<PlayerMatch*>::iterator i = matches.begin(); i != matches.end(); ++i) {
//		int* results = (*i)->getValues();
//		std::cout << "MATCH | Kills:" << results[0] << " | Assists:" << results[1] << " | Deaths:" << results[2] << std::endl;
//	}

	// per ogni match presente nel vettore, stampa le statistiche del giocatore
	std::for_each(matches.begin(), matches.end(), [](PlayerMatch *pm){
		int* results = pm->getValues();
		std::cout << "MATCH | Kills:" << results[0] << " | Assists:" << results[1] << " | Deaths:" << results[2] << std::endl;
	});
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

std::vector<PlayerMatch*>* Player::getPlayerMatches(){
	return &matches;
};








