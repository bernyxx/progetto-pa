#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "../nlohmann/json.hpp"
#include "organization.hpp"
#include "player.hpp"
#include "customRound.hpp"

using json = nlohmann::json;


class MatchManager {

public:

	// restituisce un puntatore ad un player dato l'insieme di organizzazioni (team) e il nickname del giocatore
	static std::shared_ptr<Player> findPlayer(std::vector<Organization*> *db,
			std::string nickname) {

//		for (std::vector<Organization*>::iterator i = db->begin();
//				i != db->end(); ++i) {
//			if ((*i)->hasPlayer(nickname)) {
//				Player *pl = (*i)->getPlayer(nickname);
//				return pl;
//			}
//		}

		// riscritto con algortimo STL
		std::vector<Organization*>::iterator it = std::find_if(db->begin(),db->end(), [nickname](Organization *org) {return org->hasPlayer(nickname);});

		if (it != db->end()) {
			return (*it)->getPlayer(nickname);
		}

		throw std::runtime_error("Player not found!");
	}


	// restituisce un puntatore ad un coach dato l'insieme di organizzazioni (team) e il nickname del coach
	static std::shared_ptr<Coach> findCoach(std::vector<Organization*> *db, std::string nickname) {

//		for (std::vector<Organization*>::iterator i = db->begin();
//				i != db->end(); ++i) {
//			if ((*i)->hasCoach()) {
//				if ((*i)->getCoach()->getNickname() == nickname) {
//					Coach *c = (*i)->getCoach();
//					return c;
//				}
//			}
//
//		}

		// riscritto con algortimo STL
		std::vector<Organization*>::iterator it = std::find_if(db->begin(), db->end(), [nickname](Organization* org){if(org->hasCoach()){return org->getCoach()->getNickname() == nickname;} else {return false;}});

		if(it != db->end()){
			return (*it)->getCoach();
		}


		throw std::runtime_error("Coach not found!");
	}

	// controlla se il player fa parte della squadra
	static void checkPlayer(std::shared_ptr<Player> pl, std::string team) {
		if (pl->getTeam() == team) {
			return;
		}

		throw std::runtime_error(
				"Player is not part of the team specified in the JSON file!");
	}


	// controlla se il coach fa parte della squadra
	static void checkCoach(std::shared_ptr<Coach> c, std::string team) {
		if ((c->getTeam() == team)) {
			return;
		}

		throw std::runtime_error(
				"Player is not part of the team specified in the JSON file!");
	}

	// aggiunge i match per ogni giocatoe di una delle 2 squadre che hanno giocato la partita
	// restituisce il rating della partita (media dei rapporti uccisioni/morti di ogni giocatore)
	// che servirà per attribuire il rating della partita al coach
	static double manageTeam(std::vector<Organization*> *db, int numPlayersPerTeam, bool isTeam1, json data){

		std::string key = "";
		std::string team = "";
		double sumKD = 0;

		if (isTeam1) {
			key = "stats1";
			team = data["team1"];
		} else {
			key = "stats2";
			team = data["team2"];
		}


		for (int i = 0; i < numPlayersPerTeam; i++) {
				std::string nickname = data[key][i]["player"];
				std::shared_ptr<Player> pl = findPlayer(db, nickname);

				// effettua un controllo aggiuntivo per verificare che il giocatore sia effettivamente membro della squadra
				checkPlayer(pl, team);

				int kills = data[key][i]["kills"];
				int assists = data[key][i]["assists"];
				int deaths = data[key][i]["deaths"];

				double kd = customRound(kills / (double) deaths);

				PlayerMatch *pm = new PlayerMatch(kills, assists, deaths, kd);
				pl->addMatch(pm);
				sumKD += kd;
		}

		return customRound(sumKD / (double) numPlayersPerTeam);
	}


	// aggiunge una partita a tutti i giocatori e coach della partita in formato json
	// passata come parametro (viene passato il path)
	static void newMatch(std::string filePath, std::vector<Organization*> *db) {


	/*  STRUTTURA DEL FILE JSON
	 * {
	 * 		"team1" : "nome della squadra 1",
	 * 		"team2" : "nome della squadra 2",
	 * 		"coach1" : "coach della squadra 1",
	 * 		"coach2" : "coach della squadra 1",
	 * 		"numPlayers" : 4 --> numero giocatori totali (10 significa 5 per squadra)
	 *
	 * 		stats1 contiene le statistiche dei giocatori della squadra 1
	 * 		"stats1": [{ "player": "player1", "kills": 10, "assists": 2, "deaths": 5 }, { "player": "player2", "kills": 10, "assists": 2, "deaths": 5 }],
	 *
	 * 		stats2 contiene le statistiche dei giocatori della squadra 2
	 * 		"stats2": [{ "player": "player3", "kills": 10, "assists": 2, "deaths": 5 }, { "player": "player4", "kills": 10, "assists": 2, "deaths": 5 }]
	 * }
	 */

		// parse file json
		std::ifstream f(filePath);
		json data = json::parse(f);


		std::string team1 = data["team1"];
		std::string team2 = data["team2"];

		std::string coach1 = data["coach1"];
		std::string coach2 = data["coach2"];

		int numPlayers = data["numPlayers"];
		int numPlayersPerTeam = numPlayers / 2;


		// aggiungi una partita per ogni giocatore della squadra 1
		double kd1 = manageTeam(db, numPlayersPerTeam, true, data);

		// aggiungi una partita per ogni giocatore della squadra 2
		double kd2 = manageTeam(db, numPlayersPerTeam, false, data);

		// aggiungi la partita ai 2 coach

		// coach team 1
		std::shared_ptr<Coach> c1 = findCoach(db, coach1);
		checkCoach(c1, team1);
		c1->addMatch(kd1);

		// coach team 2
		std::shared_ptr<Coach> c2 = findCoach(db, coach2);
		checkCoach(c2, team2);
		c2->addMatch(kd2);

	}
};

