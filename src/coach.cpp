#include <iostream>
#include <sstream>
#include "coach.hpp"
#include "customRound.hpp"

Coach::Coach(std::string name, std::string surname, int age, std::string nickname) : Person(name, surname, age){
	this->nickname = nickname;
	// campo team viene assegnato quando un player viene aggiunto a dun'organizzazione
	team = "";
}

Coach::Coach(std::string name, std::string surname, int age, std::string nickname, std::vector<double>* matches) : Person(name, surname, age){
	this->nickname = nickname;
	this->matches = *matches;
	// campo team viene assegnato quando un player viene aggiunto a dun'organizzazione
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

// operator overload >
bool Coach::operator>(Coach& c){
	return getRating() > c.getRating();
}

// operator overload <
bool Coach::operator<(Coach& c){
	return !Coach::operator>(c);
}

std::string Coach::toString(){
	std::stringstream ss;
	if(team == "" && matches.size() == 0){
		// se non ha team
		ss << "COACH | Nickname:" << nickname << " | NO TEAM";
	} else if(team == "" && matches.size() > 0){
		// se ha match nel vettore matches ma non ha attualmente un team
		ss << "COACH | Nickname:" << nickname << " | Team:" << team << " | Rating:" << getRating();
	}else if(team != "" && matches.size() > 0){
		// se ha match nel vettore matches
		ss << "COACH | Nickname:" << nickname << " | Team:" << team << " | Rating:" << getRating();
	}else{
		// se NON ha matches ma ha un attualmente team
		ss << "COACH | Nickname:" << nickname << " | Team:" << team;
	}
	return ss.str();
}

void Coach::addMatch(double kd){
	matches.push_back(kd);
}

double Coach::getRating(){
	double total = 0;
	for(double kd: matches){
		total += kd;
	}

	// customRound serve per arrotondare alla seconda cifra decimale
	return customRound(total / (double) matches.size());
}

std::vector<double>* Coach::getCoachMatches(){
	return &matches;
};








