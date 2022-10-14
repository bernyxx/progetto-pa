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

	// crea un nuovo vettore che contiene tutti i puntatori della vecchia organization
	std::for_each(old.getPlayers()->begin(), old.getPlayers()->end(), [this](std::shared_ptr<Player> pl){this->players.push_back(pl);});

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

	// se l'organizzazione contiene giocatori
	if(players.size() > 0){
		// stampa lista giocatori
		for (std::vector<std::shared_ptr<Player>>::iterator i = players.begin(); i != players.end(); ++i) {
			std::cout << (*i)->toString() << std::endl;
		}

	// se non ci sono giocatori
	} else {
		std::cout << "NO PLAYERS" << std::endl;
	}


	std::cout << std::endl;
	std::cout << "Coach" << std::endl;

	// se l'org. ha un coach
	if (coach != NULL) {

		std::cout << coach->toString() << std::endl;

	// se l'org NON ha il coach
	} else {
		std::cout << "NO COACH" << std::endl;
	}

	std::cout << "--------------------" << std::endl;

}

// coach methods
std::shared_ptr<Coach> Organization::getCoach(){
	return coach;
}

void Organization::setCoach(std::shared_ptr<Coach> c){
	// se il coach fa già parte di un altro team, lancia un'eccezione
	if(c->hasTeam()){
		throw std::runtime_error("Can't add a coach who is still a part of another team!");
		return;
	}
	coach = c;
	c->setTeam(name);
}

void Organization::removeCoach(){
	// bisogna prima rimuovere il nome del team dal campo del coach
	coach->unsetTeam();

	// poi si rimuove il puntatore al coach dall'organization
	coach = NULL;
}

bool Organization::hasCoach(){
	return coach != NULL;
}


// players methods
void Organization::addPlayer(std::shared_ptr<Player> pl){
	// se il player fa già parte di un altro team, lancia un'eccezione
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

	// riscrittura con algoritmo STL

	// trova prima il puntatore al giocatore che possiede il nickname passato come parametro al metodo
	std::vector<std::shared_ptr<Player>>::iterator it = std::find_if(players.begin(),players.end(), [nn](std::shared_ptr<Player> pl) {return pl->getNickname() == nn;});

	// se il player esiste, rimuovilo dal vettore
	if(it != players.end()){
		int index = std::distance(players.begin(), it);
		players.at(index)->unsetTeam();
		// remove the player from the vector
		players.erase(players.begin() + index);
		return;
	}

	// se il player non è stato trovato, lancia un'eccezione
	throw std::runtime_error("Player to remove don't found!") ;


}

std::shared_ptr<Player> Organization::getPlayer(std::string nn) {

//	for (std::vector<Player*>::iterator i = players.begin(); i != players.end(); ++i) {
//
//		if ((*i)->getNickname() == nn) {
//			return *i;
//		}
//	}

	// riscrittura con algoritmi STL
	// trova il puntatore al giocatore che possiede il nickname passato come parametro al metodo
	std::vector<std::shared_ptr<Player>>::iterator it = std::find_if(players.begin(),players.end(), [nn](std::shared_ptr<Player> pl) {return pl->getNickname() == nn;});

	// se il player esiste, restituisci il puntatore (smart pointer)
	if (it != players.end()) {
			return *it;
	}


	throw "Player don't found!";
}

std::shared_ptr<Player> Organization::getBestPlayer(){

	double maxAvgKD = 0;
	int maxIndex = 0;
	int index = 0;

	// trova il giocatore con il massimo AvgKD
	for (std::vector<std::shared_ptr<Player>>::iterator i = players.begin(); i != players.end(); ++i) {

		if((*i)->getAvgKD() > maxAvgKD){
			maxAvgKD = (*i)->getAvgKD();
			maxIndex = index;
		}

		index++;
	}

	// restituiscilo
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
	// trova il puntatore al giocatore che possiede il nickname passato come parametro al metodo
	std::vector<std::shared_ptr<Player>>::iterator it = std::find_if(players.begin(),players.end(), [nn](std::shared_ptr<Player> pl) {return pl->getNickname() == nn;});

	// se esiste, restituisci true, altrimenti restituisci false
	if (it != players.end()) {
		return true;
	}

	return false;
}

std::vector<std::shared_ptr<Player>>* Organization::getPlayers(){
	return &players;
}
