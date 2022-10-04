/*
 * MatchManager.cpp
 *
 *  Created on: 2 ott 2022
 *      Author: Kevin
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "../nlohmann/json.hpp"
#include "organization.hpp"
#include "player.hpp"

using json = nlohmann::json;

class MatchManager {

public:

	static Player* findPlayer(std::vector<Organization*> *db,
			std::string nickname) {

		for (std::vector<Organization*>::iterator i = db->begin();
				i != db->end(); ++i) {
			if ((*i)->hasPlayer(nickname)) {
				Player *pl = (*i)->getPlayer(nickname);
				return pl;
			}
		}
		throw std::runtime_error("Player not found!");
	}

	static Coach* findCoach(std::vector<Organization*> *db,
			std::string nickname) {

		for (std::vector<Organization*>::iterator i = db->begin();
				i != db->end(); ++i) {
			if ((*i)->getCoach()->getNickname() == nickname) {
				Coach *c = (*i)->getCoach();
				return c;
			}
		}
		throw std::runtime_error("Coach not found!");
	}

	static void checkPlayer(Player *pl, std::string team1, std::string team2) {
		if ((pl->getTeam() == team1) || (pl->getTeam() == team2)) {
			return;
		}

		throw std::runtime_error(
				"Player is not part of the team specified in the JSON file!");

	}

	static void checkCoach(Coach *c, std::string team) {
		if ((c->getTeam() == team)) {
			return;
		}

		throw std::runtime_error(
				"Player is not part of the team specified in the JSON file!");
	}

	static void newMatch(std::string filePath, std::vector<Organization*> *db) {

		// parse json file
		std::ifstream f(filePath);
		json data = json::parse(f);

		std::string team1 = data["team1"];
		std::string team2 = data["team2"];

		std::string coach1 = data["coach1"];
		std::string coach2 = data["coach2"];

		int numPlayers = data["numPlayers"];
		int numPlayersPerTeam = numPlayers / 2;

		double sumKD1 = 0;
		double sumKD2 = 0;

		// add match for every player
		for (int i = 0; i < numPlayers; i++) {
			std::string nickname = data["stats"][i]["player"];

			Player *pl = findPlayer(db, nickname);

			// check if the player is part of the team specified in team1/team2 in the JSON file
			checkPlayer(pl, team1, team2);

			int kills = data["stats"][i]["kills"];
			int assists = data["stats"][i]["assists"];
			int deaths = data["stats"][i]["deaths"];

			double kd = round((kills / (double) deaths) * 100) / 100;

			PlayerMatch *pm = new PlayerMatch(kills, assists, deaths, kd);
			pl->addMatch(pm);

			if (i < numPlayersPerTeam) {
				sumKD1 += kd;
			} else {
				sumKD2 += kd;
			}

		}

		// add match for the coach

		// coach for team 1
		Coach *c1 = findCoach(db, coach1);
		checkCoach(c1, team1);
		c1->addMatch(sumKD1 / numPlayersPerTeam);

		// coach for team 2
		Coach *c2 = findCoach(db, coach2);
		checkCoach(c2, team2);
		c2->addMatch(sumKD2 / numPlayersPerTeam);

	}
};

