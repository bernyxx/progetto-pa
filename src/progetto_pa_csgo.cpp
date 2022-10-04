//============================================================================
// Name        : progetto_pa_csgo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.hpp"
#include "player.hpp"
#include "coach.hpp"
#include "organization.hpp"
#include "matchManager.cpp"

void printOrganizations(std::vector<Organization*> *db) {
	for (std::vector<Organization*>::iterator i = db->begin(); i != db->end();
			++i) {
		std::cout << (*i)->getName() << std::endl;
	}
}

int main() {

	try {
		std::vector<Organization*> organizations;

		Player *p1 = new Player("Kevin", "Bernardi", 22, "bernyx", ENTRY,
				ACTIVE);

		Coach *c1 = new Coach("Capo", "Capi", 33, "capituu");
		Coach *c2 = new Coach("Suini", "Gini", 29, "saigino");

		Player *p2 = new Player("Kevin", "Second", 22, "ginetti", ENTRY,
				ACTIVE);

		Organization *org = new Organization("G2", &organizations);
		Organization *org2 = new Organization("Liquid", &organizations);

		org->addPlayer(p1);
		org2->addPlayer(p2);

		MatchManager::newMatch("D:/Documenti/eclipse_workspace/progetto_pa_csgo/src/test.json", &organizations);
		MatchManager::newMatch("D:/Documenti/eclipse_workspace/progetto_pa_csgo/src/test2.json", &organizations);
		MatchManager::newMatch("D:/Documenti/eclipse_workspace/progetto_pa_csgo/src/test3.json", &organizations);

		p1->printMatches();
		p2->printMatches();

		p1->printStats();
		p2 -> printStats();




	} catch (std::exception &e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

}
