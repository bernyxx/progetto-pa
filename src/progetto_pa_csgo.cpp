#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "person.hpp"
#include "player.hpp"
#include "coach.hpp"
#include "organization.hpp"
#include "matchManager.cpp"
#include "retired.hpp"

// funzione per stampare la lista di organizzazioni contenute nel vettore "db"
void printOrganizations(std::vector<Organization*> *db) {
	std::cout << "----- ORGANIZATIONS LIST -----" << std::endl;
	for (std::vector<Organization*>::iterator i = db->begin(); i != db->end();
			++i) {
		std::cout << (*i)->getName() << std::endl;
	}
	std::cout << "--------------------" << std::endl;
}

// funzione main
int main() {

	try {

		// SETUP OGGETTI

		// vettore di tutte le organizzazioni
		std::vector<Organization*> organizations;

		// creazione di 10 player con smart pointers
		std::shared_ptr<Player> p1(
				new Player("Albero", "Bosco", 22, "pino", ENTRY, ACTIVE));
		std::shared_ptr<Player> p2(
				new Player("Tessuto", "Fibra", 19, "lino", IGL, ACTIVE));
		std::shared_ptr<Player> p3(
				new Player("Ginotto", "Ottino", 24, "gino", LURKER, ACTIVE));
		std::shared_ptr<Player> p4(
				new Player("Mattia", "Binotto", 23, "bino", SUPPORT, ACTIVE));
		std::shared_ptr<Player> p5(
				new Player("Ninotto", "Gianciotto", 27, "nino", SUPPORT,
						ACTIVE));
		std::shared_ptr<Player> p6(
				new Player("Acqua", "Bin", 22, "water", IGL, ACTIVE));
		std::shared_ptr<Player> p7(
				new Player("Acqua", "Dal Cielo", 23, "rain", ENTRY, ACTIVE));
		std::shared_ptr<Player> p8(
				new Player("Passo", "DelTonale", 28, "snow", LURKER, ACTIVE));
		std::shared_ptr<Player> p9(
				new Player("Adamello", "Brescia", 22, "ice", LURKER, ACTIVE));
		std::shared_ptr<Player> p10(
				new Player("Vapore", "Acqueo", 27, "steam", SUPPORT, ACTIVE));

		// creazione di 2 coach con smart pointers
		std::shared_ptr<Coach> c1(new Coach("Capo", "Capi", 33, "capituu"));
		std::shared_ptr<Coach> c2(new Coach("Suini", "Gini", 29, "saigino"));

		// creazione di 2 organizzazioni con smart pointers
		std::shared_ptr<Organization> org(
				new Organization("G2", &organizations));
		std::shared_ptr<Organization> org2(
				new Organization("Liquid", &organizations));

		// assegnazione del coach c1 all'organizzazione "G2"
		org->setCoach(c1);

		// assegnazione del coach c2 all'organizzazione "Liquid"
		org2->setCoach(c2);

		// aggiunta dei player p1-p2-p3-p4-p5 all'organizzazione G2
		org->addPlayer(p1);
		org->addPlayer(p2);
		org->addPlayer(p3);
		org->addPlayer(p4);
		org->addPlayer(p5);

		// aggiunta dei player p6-p7-p8-p9-p10 all'organizzazione Liquid
		org2->addPlayer(p6);
		org2->addPlayer(p7);
		org2->addPlayer(p8);
		org2->addPlayer(p9);
		org2->addPlayer(p10);

		// CARICAMENTO DI 3 PARTITE

		// caricamento da windows con path assoluto
		// caricamento di 3 match
		MatchManager::newMatch(
				"D:/Documenti/eclipse_workspace/progetto_pa_csgo/src/match1.json",
				&organizations);
		MatchManager::newMatch(
				"D:/Documenti/eclipse_workspace/progetto_pa_csgo/src/match2.json",
				&organizations);
		MatchManager::newMatch(
				"D:/Documenti/eclipse_workspace/progetto_pa_csgo/src/match3.json",
				&organizations);

		// caricamento da linux con path relativo
//		MatchManager::newMatch(
//		 		"./match1.json",
//		 		&organizations);
//		 MatchManager::newMatch(
//		 		"./match2.json",
//		 		&organizations);
//		 MatchManager::newMatch(
//		 		"./match3.json",
//		 		&organizations);

		// stampa player 1
		std::cout << p1->toString() << std::endl;

		// stampa la struttura delle 2 organizzazioni
		org->print();
		org2->print();

		// ottieni il miglior giocatore di org1 e stampalo
		std::cout << org->getBestPlayer()->toString() << std::endl;

		// stampa anche la lista di partite giocate
		org->getBestPlayer()->printMatches();

		// stampa anche le sue statistiche
		org->getBestPlayer()->printStats();

		// stampa il coach di org1
		std::cout << org->getCoach()->toString() << std::endl;




		// CREAZIONE DI UNA COPIA DI UN'ORGANIZATION
		Organization org_copy(*org, &organizations);
		org_copy.removeCoach();
		org_copy.print();

		// il campo "team" del coach ha valore ""
		// i player non vengono duplicati intenzionalmente, vengono solo copiati i puntatori
		// il vettore invece � duplicato e non � un semplice riferimento, quindi il vettore
		// dei player dell'organizzazione originale rimane invariato

		// stampa struttura squadra
		org->print();

		// stampa la lista delle squadre del vettore db
		printOrganizations(&organizations);
		// viene stampato 2 volte G2 perch� � stato duplicato

		//creazione di un Retired a partire dal player p5
		std::shared_ptr<Retired> r1(new Retired(p5));
		r1->printStats();

		// prova degli operator overload
		std::cout << (*p1 > *p2) << std::endl;
		std::cout << (*c1 > *c2) << std::endl;

		// grazie agli smart pointer, il tutto viene deallocato automaticamente

	} catch (std::exception &e) {
		// gestione delle eccezioni
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

}
