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

		Player *p1 = new Player("Bino", "Sinni", 22, "pino", ENTRY, ACTIVE);
		Player *p2 = new Player("Ginetti", "Bin", 19, "lino", IGL, ACTIVE);
		Player *p3 = new Player("Ginetti", "Bin", 24, "gino", LURKER, ACTIVE);
		Player *p4 = new Player("Ginetti", "Bin", 23, "bino", SUPPORT, ACTIVE);
		Player *p5 = new Player("Ginetti", "Bin", 27, "nino", SUPPORT, ACTIVE);
		Player *p6 = new Player("Ginetti", "Bin", 22, "water", IGL, ACTIVE);
		Player *p7 = new Player("Ginetti", "Bin", 23, "rain", ENTRY, ACTIVE);
		Player *p8 = new Player("Ginetti", "Bin", 28, "snow", LURKER, ACTIVE);
		Player *p9 = new Player("Ginetti", "Bin", 22, "ice", LURKER, ACTIVE);
		Player *p10 = new Player("Ginetti", "Bin", 27, "steam", SUPPORT, ACTIVE);

		Coach *c1 = new Coach("Capo", "Capi", 33, "capituu");
		Coach *c2 = new Coach("Suini", "Gini", 29, "saigino");

		Organization *org = new Organization("G2", &organizations);
		Organization *org2 = new Organization("Liquid", &organizations);

		org->setCoach(c1);
		org2->setCoach(c2);

		org->addPlayer(p1);
		org->addPlayer(p2);
		org->addPlayer(p3);
		org->addPlayer(p4);
		org->addPlayer(p5);
		org2->addPlayer(p6);
		org2->addPlayer(p7);
		org2->addPlayer(p8);
		org2->addPlayer(p9);
		org2->addPlayer(p10);



		// MatchManager::newMatch("D:/Documenti/eclipse_workspace/progetto_pa_csgo/src/test.json", &organizations);
		// MatchManager::newMatch("D:/Documenti/eclipse_workspace/progetto_pa_csgo/src/test2.json", &organizations);
		// MatchManager::newMatch("D:/Documenti/eclipse_workspace/progetto_pa_csgo/src/test3.json", &organizations);

		MatchManager::newMatch("./test.json", &organizations);
		MatchManager::newMatch("./test2.json", &organizations);
		MatchManager::newMatch("./test3.json", &organizations);


		p1->printMatches();
//		p6->printMatches();
//
//		p1->printStats();
//		p6->printStats();
//
//		std::cout << c1->toString() << std::endl;
//		std::cout << c2->toString() << std::endl;
//
//		org->print();
//
//		org2->print();
//
//		std::cout << "Best Player" << std::endl;
//		std::cout << org->getBestPlayer()->toString() << std::endl;




	} catch (std::exception &e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

}
