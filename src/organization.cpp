#include <iostream>
#include <vector>
#include <algorithm>
#include "organization.hpp"

Organization::Organization(std::string name, std::vector<Organization*> *db){
	this->name = name;
	this->coach = NULL;

	// aggiunge il nuovo oggetto alla lista di organizzazioni
	db->push_back(this);
}

Organization::~Organization(){
	std::cout << "Distr. Organization" << std::endl;
}

Organization::Organization(Organization& old, std::vector<Organization*> *db){
	name = old.name;
	coach = old.coach;

	std::for_each(old.getPlayers()->begin(), old.getPlayers()->end(), [this](Player* pl){this->players.push_back(pl);});

	db->push_back(this);
}

std::string Organization::getName(){
	return name;
}

void Organization::print(){
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "TEAM " << name << std::endl;
	std::cout << std::endl;
	std::cout << "Players" << std::endl;

	if(players.size() > 0){
		// print player list
		for (std::vector<Player*>::iterator i = players.begin(); i != players.end(); ++i) {
			std::cout << (*i)->toString() << std::endl;
		}

	} else {
		std::cout << "NO PLAYERS" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "Coach" << std::endl;

	if (coach != NULL) {

		std::cout << coach->toString() << std::endl;

	} else {
		std::cout << "NO COACH" << std::endl;
	}

	std::cout << "--------------------" << std::endl;

}

// coach methods
Coach* Organization::getCoach(){
	return coach;
}

void Organization::setCoach(Coach* c){
	if(c->hasTeam()){
		throw std::runtime_error("Can't add a coach who is still a part of another team!");
		return;
	}
	coach = c;
	c->setTeam(name);
}

void Organization::removeCoach(){
	coach->unsetTeam();
	coach = NULL;
}

bool Organization::hasCoach(){
	return coach != NULL;
}


// players methods+
void Organization::addPlayer(Player* pl){
	if(pl->hasTeam()){
		throw "Can't add a player who is still a part of another team!";
		return;
	}

	players.push_back(pl);
	pl->setTeam(name);
}

void Organization::removePlayer(std::string nn) {

//	int index = 0;
//	bool found = false;
//
//	// find the index of the player to remove
//	for (std::vector<Player*>::iterator i = players.begin(); i != players.end(); ++i) {
//
//		if ((*i)->getNickname() == nn) {
//			found = true;
//			break;
//		}
//
//		index++;
//	}
//
//
//	if(found == true){
//		players.at(index)->unsetTeam();
//		// remove the player from the vector
//		players.erase(players.begin() + index);
//		return;
//	}

	// riscrittura con algoritmi STL

	std::vector<Player*>::iterator it = std::find_if(players.begin(),players.end(), [nn](Player *pl) {return pl->getNickname() == nn;});

	if(it != players.end()){
		int index = std::distance(players.begin(), it);
		players.at(index)->unsetTeam();
		// remove the player from the vector
		players.erase(players.begin() + index);
		return;
	}


	throw std::runtime_error("Player to remove don't found!") ;


}

Player* Organization::getPlayer(std::string nn) {

//	for (std::vector<Player*>::iterator i = players.begin(); i != players.end(); ++i) {
//
//		if ((*i)->getNickname() == nn) {
//			return *i;
//		}
//	}

	// riscrittura con algoritmi STL
	std::vector<Player*>::iterator it = std::find_if(players.begin(),players.end(), [nn](Player *pl) {return pl->getNickname() == nn;});

	if (it != players.end()) {
			return *it;
	}


	throw "Player don't found!";
}

Player* Organization::getBestPlayer(){

	double maxAvgKD = 0;
	int maxIndex = 0;
	int index = 0;

	for (std::vector<Player*>::iterator i = players.begin(); i != players.end(); ++i) {

		if((*i)->getAvgKD() > maxAvgKD){
			maxAvgKD = (*i)->getAvgKD();
			maxIndex = index;
		}

		index++;
	}

	return players.at(maxIndex);
}

bool Organization::hasPlayer(std::string nn) {

//	for (std::vector<Player*>::iterator i = players.begin(); i != players.end(); ++i) {
//
//		if ((*i)->getNickname() == nn) {
//			return true;
//		}
//	}

	// riscrittura con algoritmi STL
	std::vector<Player*>::iterator it = std::find_if(players.begin(),players.end(), [nn](Player *pl) {return pl->getNickname() == nn;});

	if (it != players.end()) {
		return true;
	}

	return false;
}

std::vector<Player*>* Organization::getPlayers(){
	return &players;
}