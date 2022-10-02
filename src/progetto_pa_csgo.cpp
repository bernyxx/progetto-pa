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





int main()
{

	std::vector<Organization*> organizations;

    // std::cout << "CSGO" << std::endl;

    Person *p = new Person("Gino", "Geppetti", 25);
    std::cout << p->toString() << std::endl;
    std::cout << p->getAge() << std::endl;
    delete p;

    Player *pl = new Player("Kevin", "Bernardi", 22, "bernyx", ENTRY, ACTIVE );
    std::cout << pl->toString() << std::endl;
//    std::cout << pl->getRole() << std::endl;
//    std::cout << pl->getStatus() << std::endl;

    Coach* c1 = new Coach("Capo", "Capi", 33, "capituu");
    std::cout << c1->toString() << std::endl;

    Player *p2 = new Player("Kevin", "Second", 22, "ginetti", ENTRY, ACTIVE );

    Organization* org = new Organization("G2", &organizations);
    Organization* org2 = new Organization("Liquid", &organizations);


    org->addPlayer(pl);
    org2->addPlayer(p2);

    pl->unsetTeam();
    org2->addPlayer(pl);
    org->setCoach(c1);

    std::cout << pl->toString() << std::endl;
    std::cout << p2->toString() << std::endl;



//    for (std::vector<Organization*>::iterator i = organizations.begin(); i != organizations.end(); ++i) {
//    	std::cout << (*i)->getName() << std::endl;
//    }
//    org->print();







}
